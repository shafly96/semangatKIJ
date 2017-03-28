#include<stdio.h>

int main(){
	char plaintext[8];
	scanf("%s", plaintext);
	
	int biner[8][8];
	int i, j, hasil[8];
	for (i = 0; i < 8; i++){
			hasil[i] = (plaintext[0] >> i) & 1;
	}
	for (i = 0; i < 8; i++){
			printf("%d", hasil[i]);
	}
}
