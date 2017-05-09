from socket import socket, AF_INET, SOCK_STREAM, SOL_SOCKET, SO_REUSEADDR
from select import select
import sys
import os
import binascii
import random

def decrypt(key, n, ciphertext):
    plain = [chr((char ** key) % n) for char in ciphertext]
    return ''.join(plain)

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

serverAddress = ('', 5005)
serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
serverSocket.bind(serverAddress)
serverSocket.listen(3)

CONNECTION_LIST = [serverSocket]
BUFFER_SIZE = 1024
print "Server started"

#langkah 1
p = 61
q = 53
                
#langkah 2
n = p*q
                
#langkah3
phi = (p-1)*(q-1)
#print n
#print phi

#langkah 4
e = random.randrange(1, phi)

cek = gcd(e, phi)
while cek != 1:
    e = random.randrange(1, phi)
    cek = gcd(e, phi)
    #print e

#langkah 5
cek2 = e%phi
d = 1
while cek2 != 1:
    d+=1
    cek2 = (d*e)%phi
#print d

#langkah 6
print "private key ",d
print "public key ",e
print "\n"

try:
    while True:
        reads, writes, errors = select(CONNECTION_LIST, [], [])
        for sock in reads:
            if sock == serverSocket:
                clientSocket, clientAddress = serverSocket.accept()
                CONNECTION_LIST.append(clientSocket)

            else:
                tampung = sock.recv(BUFFER_SIZE)
                msg = tampung
                sock.send('public {} n {}\n'.format(e,n))
                jumlah = sock.recv(BUFFER_SIZE)
                print jumlah
                jumlah = int(jumlah)
                hasil = []
                i=0
                while 1:
                    if i==jumlah: break
                    hasil.append(int(sock.recv(BUFFER_SIZE)))
                    print hasil[i]
                    i+=1
                dekrip = decrypt(d,n,hasil)
                print dekrip
                
                if msg:
                    sock.send('data diterima\n')
                else:
                    print sock.getpeername() , '((this user disconnected))'
                    sock.close()
                    CONNECTION_LIST.remove(sock)

except KeyboardInterrupt:
    print 'You pressed ctrl+c'
    serverSocket.close()
    sys.exit(0)
