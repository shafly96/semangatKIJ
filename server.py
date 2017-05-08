from socket import socket, AF_INET, SOCK_STREAM, SOL_SOCKET, SO_REUSEADDR
from select import select
import sys
import os
import binascii

def text_to_bits(text, encoding='utf-8', errors='surrogatepass'):
    bits = bin(int(binascii.hexlify(text.encode(encoding, errors)), 16))[2:]
    return bits.zfill(8 * ((len(bits) + 7) // 8))

def text_from_bits(bits, encoding='utf-8', errors='surrogatepass'):
    n = int(bits, 2)
    return int2bytes(n).decode(encoding, errors)

def int2bytes(i):
    hex_string = '%x' % i
    n = len(hex_string)
    return binascii.unhexlify(hex_string.zfill(n + (n & 1)))

serverAddress = ('', 5005)
serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
serverSocket.bind(serverAddress)
serverSocket.listen(3)

CONNECTION_LIST = [serverSocket]
BUFFER_SIZE = 1024
print "Server started"
try:
    while True:
        reads, writes, errors = select(CONNECTION_LIST, [], [])
        for sock in reads:
            if sock == serverSocket:
                clientSocket, clientAddress = serverSocket.accept()
                CONNECTION_LIST.append(clientSocket)

            else:
                msg = sock.recv(BUFFER_SIZE)
                msg = msg[:-1]
                perintah = msg.partition(" ")
                result = text_to_bits(msg)
                print sock.getpeername(), msg+' : '+result
                result2 = list(result)
                print result2
                i = 0
                while i < len(result2):
                    print "angka : {}{}{}".format(result2[i],result2[i+1],result2[i+2])
                    i+=3
                if msg:
                    sock.send(msg+' received by server\n')
                else:
                    print sock.getpeername() , '((this user disconnected))'
                    sock.close()
                    CONNECTION_LIST.remove(sock)

except KeyboardInterrupt:
    print 'You pressed ctrl+c'
    serverSocket.close()
    sys.exit(0)
