#include<stdio.h>
#include<math.h>

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

int main()
{
    int g,n,x,y;
	printf("Masukkan nilai n dan g : "); scanf("%d %d", &n, &g);
	printf("masukkan nilai x dan y : "); scanf("%d %d", &x, &y);
    // printf("%d %d %d %d",g,n,x,y);
	int key_X = hitung_key(g,n,x); //alice
	int key_Y = hitung_key(g,n,y); //bob

    printf("nilai X dan Y setelah dihitung : %d %d\n",key_X,key_Y);

    int alice = kunci_simetri(key_Y,n,x); //alice
    int bob = kunci_simetri(key_X,n,y); //bob
    printf("nilai K alice dan K bob setelah dihitung : %d %d \n",alice,bob);
}
