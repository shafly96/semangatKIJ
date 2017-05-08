from socket import socket, AF_INET, SOCK_STREAM
import sys
import signal

#serverAddress = ('10.151.43.42', 5001)
serverAddress = ('localhost', 5005)
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect(serverAddress)

BUFFER_SIZE = 1024

try:
    while True:
        sys.stdout.write('> ')
        message = sys.stdin.readline()
        clientSocket.send(message)
        sys.stdout.write(clientSocket.recv(BUFFER_SIZE))

except KeyboardInterrupt:
    print 'You pressed ctrl+c'
    clientSocket.close()
    sys.exit(0)
