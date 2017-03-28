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
	int *p, i, j, k, n, m, hasil[64], hasil_pc_1[56], hasil_key[64], hasil_ip[64], l[32], r[32], pc1_l[28], pc1_r[28], pc2_l[28], pc2_r[28], temp1, temp2;
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
		 r[i] = hasil_ip[k];
		 k++;
	} 
	
	for(i=0; i<64; i++){
		hasil_pc_1[i] = hasil_key[pc_1[i]-1]; //masukin key ke pc 1
	}
	
	k=28;

	for(i=0; i<28; i++){  //mecah jadi dua pc 1
		 pc1_l[i] = hasil_pc_1[i];
		 pc1_r[i] = hasil_pc_1[k];
		 k++;
	} 
	
	for(i=0; i<1; i++){ 
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
		
	}
}
