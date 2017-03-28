#include<stdio.h>

int *convert_biner(char plaintext){
	int i, hasil[8];
	for(i=7; i>=0; i--){
		hasil[i] = (plaintext >> i) & 1;
	}
	return hasil;
}


int main(){
	char plaintext[7], key[7];
	printf("Masukan plaintext: "); scanf("%s", plaintext);
	printf("Masukan key: "); scanf("%s", key);
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
		57, 49, 41, 33, 25, 17, 9,
		1, 58, 50, 42, 34, 26, 18,
		10, 2, 59, 51, 43, 35, 27,
		19, 11, 3, 60, 52, 44, 36,
		63, 55, 47, 39, 31, 23, 15,
		7, 62, 54, 45, 38, 30, 22,
		14, 6, 61, 53, 45, 37, 29,
		21, 13, 5, 28, 20, 12, 4
	};
	int *p, i, j, k, hasil[64], hasil_pc_1[56], hasil_key[64], hasil_ip[64], l[32], r[32];
	for (i=0; i<8; i++){
		p = convert_biner(plaintext[i]); //convert biner plaintext
		k=7;
		int a=i*8, b=(i+1)*8;
		for(j=a; j<b; j++){
			hasil[j] = *(p+k);
			k--;
		}
	}
	
	for (i=0; i<8; i++){
		p = convert_biner(key[i]); //convert biner key
		k=7;
		int a=i*8, b=(i+1)*8;
		for(j=a; j<b; j++){
			hasil_key[j] = *(p+k);
			k--;
		}
	}

	for(i=0; i<64; i++){
		int a = ip[i];
		hasil_ip[i] = hasil[a-1]; //masukin ke tabel ip
	}
	
	k=32;
	
	for(i=0; i<32; i++){  //mecah jadi dua
		 l[i] = hasil_ip[i];
		 r[k] = hasil_ip[k];
		 k++;
	} 
	
	for(i=0; i<56; i++) printf("%d ", pc1[i]);
	
	for(i=0; i<56; i++){
//		int a = pc_1[i];
//		hasil_pc_1[i] = hasil_key[a-1]; //masukin key ke tabel pc-1
//		printf("%d.%d ", i, hasil_key[a-1]);
	}
//	
//	printf("\n");
//	
//	for(i=0; i<56; i++) printf("%d ", hasil_pc_1[i]);
}
