#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080
  
int main(int argc, char const *argv[])
{
	char plaintext[7], key[7], ea[7];
	    struct sockaddr_in address;
	    int sock = 0, valread;
	    struct sockaddr_in serv_addr;
	    char hello[1024];
	    char buffer[1024] = {0};
	    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	    {
		printf("\n Socket creation error \n");
		return -1;
	    }
	  
	    memset(&serv_addr, '0', sizeof(serv_addr));
	  
	    serv_addr.sin_family = AF_INET;
	    serv_addr.sin_port = htons(PORT);
	      
	    // Convert IPv4 and IPv6 addresses from text to binary form
	    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
	    {
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	    }
	  
	    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	    {
		printf("\nConnection Failed \n");
		return -1;
	    }
		int i=1;
		while(1){
		printf("--%d--\n", i);
		printf("Masukan plaintext/chipertext: "); scanf("%s", ea);
		send(sock , ea , strlen(ea) , 0 );
		char y_bob[100];		
		printf("Masukkan nilai y_bob : "); scanf("%s",y_bob);
		    
		    send(sock, y_bob,strlen(y_bob),0);
		    valread = read( sock , buffer, 1024);
		i++;
		    printf("server : %s\n",buffer );
	}
}
