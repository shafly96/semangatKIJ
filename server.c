#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <math.h>
#define PORT 8080

int hitung_key(int g, int n, int z) // g n x || g n y
{
    // g pangkat z mod n
    int hasil=1;
    int i;
    for(i=0; i<z; i++){
        hasil*=g;
        hasil = hasil % n;
    }
    //tes = tes%n;
    return hasil;
}

int kunci_simetri(int a, int b, int c) //key_Y,n,g
{
    int hasil2=1;
    int i;
    for(i=0; i<c; i++){
        hasil2*=a;
        hasil2 = hasil2 % b;
    }
    // a pangkat c mod b
    return hasil2;
}

int toString(char a[])
{
	int c, sign, offset, n;
	if(a[0]=='-'){
	sign = -1;
	}

	if(sign==-1){
	offset=1;
	}
	
	else 
	offset=0;
	n=0;

	for(c=offset;a[c]!='\0';c++)
	{
		n=n*10+a[c]-'0';
	}
	if(sign==-1){
	n=-n;
	}
	return n;
}


int *convert_biner(char plaintext){
	//int hasil[8];
 	int *hasil = (int*)malloc(8*sizeof(int));
	int i;
	for(i=7; i>=0; i--){
		hasil[i] = (plaintext >> i) & 1;
	}
	return hasil;
}

int *decimalToBinary(long n) {
   // int remainder[4]; 
	int *remainder = (int*)malloc(4*sizeof(int));
	long binary=0, i = 1, j=3;
	    while(n != 0) {
	        remainder[j] = n%2;
	        j--;
	        n = n/2;
	    }
	    if(j==0) remainder[0] = 0;
	return remainder;
}

int main(int argc, char const *argv[])
{
    char key[7], ea[7];
    int kunci;
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "berhasil";
     
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
     
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
     
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, 
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                       (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
	while(1){
        valread = read( new_socket , ea, 1024);
	
	char plaintext[]="kij1234";
	int flag=1;
	int g_diffie=3, n_diffie=353;
	int alice; //x
	char y_bob[100];
	valread = read(new_socket,y_bob,1024);
	int bob = toString(y_bob);
	printf("Masukkan nilai X : ");scanf("%d",&alice);	//alice	
	printf("nilai X dari alice dan nilai Y dari bob : %d %d\n",alice,bob);
	/* diffie helman */
	int key_X = hitung_key(g_diffie,n_diffie,alice); //alice
	int key_Y = hitung_key(g_diffie,n_diffie,bob); //bob
	printf("nilai X dan Y setelah dihitung %d %d\n",key_X , key_Y);
	int alice_2 = kunci_simetri(key_Y,n_diffie,alice);
	int bob_2 = kunci_simetri(key_X,n_diffie,bob);
	/* end of diffie helman */
	printf("nilai K alice dan K bob setelah dihitung : %d %d\n",alice_2,bob_2);
		
	int ip[64]={
		58,	50,	42,	34,	26,	18,	10,	2,
		60,	52,	44,	36,	28,	20,	12,	4,
		62,	54,	46,	38,	30,	22,	14,	6,
		64,	56,	48,	40,	32,	24,	16,	8,
		57,	49,	41,	33,	25,	17,	9,	1,
		59,	51,	43,	35,	27,	19,	11,	3,
		61,	53,	45,	37,	29,	21,	13,	5,
		63,	55,	47,	39,	31,	23,	15,	7
	};
	int pc1[56]={
		57,	49,	41,	33,	25,	17,	9,
		1,	58,	50,	42,	34,	26,	18,
		10,	2,	59,	51,	43,	35,	27,
		19,	11,	3,	60,	52,	44,	36,
		63,	55,	47,	39, 31,	23,	15,
		7,	62,	54,	45,	38,	30,	22,
		14,	6,	61,	53,	45,	37,	29,
		21, 13,	5,	28,	20,	12,	4
	};
	int pc_1[56]={
		57,	49,	41,	33,	25,	17,	9,
		1,	58,	50,	42,	34,	26,	18,
		10,	2,	59,	51,	43,	35,	27,
		19,	11,	3,	60,	52,	44,	36,
		63,	55,	47,	39, 31,	23,	15,
		7,	62,	54,	45,	38,	30,	22,
		14,	6,	61,	53,	45,	37,	29,
		21, 13,	5,	28,	20,	12,	4
	};
	int putaran[16]={
		1, 1, 2, 2, 2, 2, 2, 2,
		1, 2, 2, 2, 2, 2, 2, 1
	};
	int pc_2[48]={
		14,	17,	11,	24,	1,	5,
		3,	28,	15,	6,	21,	10,
		23,	19,	12,	4,	26,	8,
		16,	7,	27,	20,	13,	2,
		41,	52,	31,	37,	47,	55,
		30,	40,	51,	45,	33,	48,
		44,	49,	39,	56,	34,	53,
		46,	42,	50,	36,	29,	32
	};
	int ekspansi[48]={
		32,	1,	2,	3,	4,	5,
		4,	5,	6,	7,	8,	9,
		8,	9,	10,	11,	12,	13,
		12,	13,	14,	15,	16,	17,
		16,	17,	18,	19,	20,	21,
		20,	21,	22,	23,	24,	25,
		24,	25,	26,	27,	28,	29,
		28,	29,	30,	31,	32,	1
	};
	int last[64]={
		40,	8,	48,	16,	56,	24,	64,	32,
		39,	7,	47,	15,	55,	23,	63,	31,
		38,	6,	46,	14,	54,	22,	62,	30,
		37,	5,	45,	13,	53,	21,	61,	29,
		36,	4,	44,	12,	52,	20,	60,	28,
		35,	3,	43,	11,	51,	19,	59,	27,
		34,	2,	42,	10,	50,	18,	58,	26,
		33,	1,	41,	9,	49,	17,	57,	25
	};
	int pbox[32]={
		16,	7,	20,	21,	29,	12,	28,	17,
		1,	15,	23,	26,	5,	18,	31,	10,
		2,	8,	24,	14,	32,	27,	3,	9,
		19,	13,	30,	6,	22,	11,	4,	25
	};
	int sbox[8][64]={
		{
			14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7,
			 0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8,
			 4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0,
			15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13
		},
		{
			15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10,
			 3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5,
			 0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15,
			13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9
		},
		{
			10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8,
			13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1,
			13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7,
			 1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12
		},
		{
			 7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15,
			13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9,
			10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4,
			 3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14
		},
		{
			 2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9,
			14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6,
			 4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14,
			11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3
		},
		{
			12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11,
			10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8,
			 9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6,
			 4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13
		},
		{
			 4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1,
			13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6,
			 1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2,
			 6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12
		},
		{
			13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7,
			 1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2,
			 7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8,
			 2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11
		}
	};
	int *p, i, j, k, n, m, hasil[64], hasil_pc_1[56], *hasil_key, hasil_ip[64], l[32], r[32], pc1_l[28], pc1_r[28], pc2_l[28], pc2_r[28], chipertext[64], temp1, temp2;
	for (i=0; i<8; i++){
		p = convert_biner(plaintext[i]); //convert biner plaintext
		k=7;
		int a=i*8, b=(i+1)*8;
		for(j=a; j<b; j++){
			hasil[j] = *(p+k);
			k--;
		}
	}


	hasil_key = decimalToBinary(alice_2);
	
	//for (i=0; i<8; i++){
		//p = convert_biner(key[i]); //convert biner key
		//k=7;
		//int a=i*8, b=(i+1)*8;
		//for(j=a; j<b; j++){
			//hasil_key[j] = *(p+k);
			//k--;
		//}
	//}

	for(i=0; i<64; i++){
		int a = ip[i];
		hasil_ip[i] = hasil[a-1]; //masukin ke tabel ip
	}
	
	k=32;
	
	for(i=0; i<32; i++){  //mecah jadi dua
		 l[i] = hasil_ip[i];
		 r[i] = hasil_ip[k];
		 k++;
	} 
	
	for(i=0; i<64; i++){*hasil_key
		hasil_pc_1[i] = hasil_key[pc_1[i]-1]; //masukin key ke pc 1
	}
	
	k=28;

	for(i=0; i<28; i++){  //mecah jadi dua pc 1
		 pc1_l[i] = hasil_pc_1[i];
		 pc1_r[i] = hasil_pc_1[k];
		 k++;
	} 
	
	int hasil_pbox[32];
	
	for(i=0; i<16; i++){ 
		k=putaran[i];
		n=28-putaran[i];
		
		if(k==1){ //geser-geser
			temp1 = pc1_l[0];
			for(j=0; j<27; j++) pc2_l[j] = pc1_l[j+1]; 
			pc2_l[27] = temp1;
			
			temp1 = pc1_r[0];
			for(j=0; j<27; j++) pc2_r[j] = pc1_r[j+1]; 
			pc2_r[27] = temp1;
		}
		
		if(k==2){ //geser-geser
			temp1 = pc1_l[0];
			temp2 = pc1_l[1];
			for(j=0; j<26; j++) pc2_l[j] = pc1_l[j+2]; 
			pc2_l[26] = temp1;
			pc2_l[27] = temp2;
			
			temp1 = pc1_r[0];
			temp2 = pc1_r[1];
			for(j=0; j<26; j++) pc2_r[j] = pc1_r[j+2]; 
			pc2_r[26] = temp1;
			pc2_r[27] = temp2;
		}
		
		k=28;
		int hasil_pc_2[56];
		
		for(j=0; j<28; j++){ //jadiin satu left ama right
			pc1_l[j] = pc2_l[j];
			hasil_pc_1[j] = pc1_l[j];
			pc1_r[j] = pc2_r[j];
			hasil_pc_1[k] = pc1_r[j];
			k++;
		}
		
		for(j=0; j<56; j++) hasil_pc_2[j] = hasil_pc_1[pc_2[j]-1]; //masukin key ke pc 2
		
		int hasil_ekspansi[48];
		
		for(j=0; j<48; j++) hasil_ekspansi[j] = r[ekspansi[j]-1]; //masukin ke ekspansi
		
		int hasil_xor[48];
		
		for(j=0; j<48; j++){
			if(hasil_pc_2[j]==hasil_ekspansi[j]) hasil_xor[j]=0;  //nge-xor
			else hasil_xor[j]=1;
		}
		
//		for(j=0; j<48; j++) printf("%d ", hasil_xor[j]);
//		printf("\n\n");
		
		int x=0, j=0, y=0;
		int baris=0;
		int kolom=0;
		int ketemu=0;
		int hasil_sbox[32];
		int *biner;
		
		for(x=0; x<48;){
			baris=(hasil_xor[x]*2)+(hasil_xor[x+1]*1);
			kolom=(hasil_xor[x+2]*8)+(hasil_xor[x+3]*4)+(hasil_xor[x+4]*2)+(hasil_xor[x+5]*1);
//			printf("%d %d\n", baris, kolom);
			if(baris>0) baris=16*(baris-1);
			else if(baris==0) baris=16*(baris);
			baris=baris+kolom;
			ketemu=sbox[j][baris];
//			printf("%d\n", ketemu);
			biner = decimalToBinary(ketemu);
			hasil_sbox[y] = *(biner);
			hasil_sbox[y+1] = *(biner+1);
			hasil_sbox[y+2] = *(biner+2);
			hasil_sbox[y+3] = *(biner+3);
			y=y+4;
			x=x+6;
			j++;
		}
		
//		for(x=0; x<32; x++) printf("%d ", hasil_sbox[x]);
		
		for(j=0; j<32; j++){
			int a = pbox[j];
			hasil_pbox[j] = hasil_sbox[a-1]; //masukin ke tabel pbox
		}
		
		for(j=0; j<48; j++){
			if(hasil_pbox[j]==l[j]){ //nge-xor
				l[j]=r[j];
				r[j]=0;  
			}
			else {
				l[j]=r[j];
				r[j]=1;
			}
		}
	}
	
	k=32;
	
	for(j=0; j<32; j++){ //jadiin satu left ama right
		hasil[j] = l[j];
		hasil[k] = r[j];
		k++;
	}
	
	for(j=0; j<64; j++){
		int a = last[j];
		chipertext[j] = hasil[a-1]; //masukin ke tabel invers p
	}
	
//	for(j=0; j<64; j++) printf("%d", chipertext[j]);
	
	for(j=0; j<64; j++){
		if(chipertext[j]==ea[j]) hasil[j]=0; //OFB 
		else hasil[j]=1;
	}


    for(j=0; j<64; j++) printf("%d", hasil[j]);
	printf("\n");
    send(new_socket , hello , strlen(hello) , 0 );
		
}
}
