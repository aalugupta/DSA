#include<iostream>
using namespace std;

 void bin_to_dec(int n){
        int pow=1;
        int dec=0;
        while(n>0){
        int rem=n%10;
        dec=dec+rem*pow;
        pow=pow*2;
        n=n/10;
        }
        cout<<dec;
    }
    void dec_to_bin(int n){
        int pow=1;
        int bin=0;
        while(n>0){
        int rem=n%2;
        bin=bin+rem*pow;
        pow=pow*10;
        n=n/2;
        }
        cout<<bin;
    }

int main(){
    // dec to bin
     dec_to_bin(7);

     cout<<endl;

     //bin_to_dec
     bin_to_dec(111);
    return 0;
}