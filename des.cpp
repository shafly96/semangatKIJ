#include<iostream>
#include<stdio.h>
#include<string.h>
#include<bitset>
#include<stdlib.h>

using namespace std;

/*void initial_partition()
{
    int ip[8][8] = {{58,50,42,34,26,18,10,2}, {60,52,44,36,28,20,12,4},
                    {62,54,46,38,30,22,14,6}, {64,56,48,40,32,24,16,8},
                    {57,49,41,33,25,17,9,1},  {59,51,43,35,27,19,11,3},
                    {61,53,45,37,29,21,13,5}, {63,55,47,39,31,23,15,7}
                   }
}*/

void convert_to_biner(string text)
{
    int i,j;
    int biner[64];
    int length = text.length();

    for(i=0;i<length;i++)
    {
        cout<<bitset<8>(text[i]);
        cout<<" ";
    }

}

int main()
{
    string plaintext;
    string key;
    int i,j;
    cout<<"enter plaintext to encrypt: ";
    getline(cin, plaintext);
    cout<<"enter key: ";
    cin>>key;

    cout<<"plaintext to biner : "<<endl;
    convert_to_biner(plaintext);
    cout<<endl<<endl;
    cout<<"key to biner : "<<endl;
    convert_to_biner(key);
    return 0;
}
