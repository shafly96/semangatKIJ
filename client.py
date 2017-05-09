from socket import socket, AF_INET, SOCK_STREAM
import sys
import signal

#serverAddress = ('10.151.43.42', 5001)
serverAddress = ('localhost', 5005)
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect(serverAddress)

BUFFER_SIZE = 1024

def enkripsi(public_key,n,plaintext):
    cipher = [(ord(char)** public_key) %n for char in plaintext]
    return cipher

try:
    while True: 
        sys.stdout.write('> ')
        message = sys.stdin.readline()
        clientSocket.send(message)
        tampung = clientSocket.recv(BUFFER_SIZE)
        sys.stdout.write(tampung)
        tampung = tampung.split(" ")
        print tampung[1]
        print tampung[3]
        e = int(tampung[1])
        n = int(tampung[3])
        
        message_enkrip = enkripsi(e,n,message)
        print message_enkrip
        a = ''.join(map(lambda x: str(x), message_enkrip))
        print a
        jumlah = str(len(message_enkrip))
        clientSocket.send(jumlah)
        i=0
        while 1:
            if i==len(message_enkrip): break
            print message_enkrip[i]
            clientSocket.send(str(message_enkrip[i]))
            i+=1
        sys.stdout.write(clientSocket.recv(BUFFER_SIZE))

except KeyboardInterrupt:
    print 'You pressed ctrl+c'
    clientSocket.close()
    sys.exit(0)
