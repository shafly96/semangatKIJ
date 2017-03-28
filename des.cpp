#include<iostream>
#include<stdio.h>
#include<string.h>
#include<bitset>
#include<stdlib.h>

using namespace std;

void convert_to_biner(string plaintext)
{
    int i,j;
    int biner[8][8];
    int length = plaintext.length();
    cout<<length<<endl;

    for(i=0;i<length;i++)
    {
        cout<<bitset<8>(plaintext[i]);
        cout<<" ";
    }
}

int main()
{
    string plaintext;
    int biner[8][8];
    int i,j;
    cin>>plaintext;
    cout<<plaintext<<endl;

    convert_to_biner(plaintext);
    return 0;
}
