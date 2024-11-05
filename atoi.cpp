#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
class Solution {
public:

    int myAtoi(string s) {
        ll ans = 0;
        bool positive = true;

        ll i=0;
        ll n= s.size();
        //white spaces 
        while(s[i] == ' '){
            i++;
            if(i== n){
                return ans;
            }
        }

        // sign
        if(s[i] == '+'){
            i++;
        }else if(s[i] == '-'){
            positive = false;
            i++;
        }

        if(i== n){
            return ans;
        }
        // leading 0's
        while(s[i] == '0'){
            i++;
            if(i== n){
                return ans;
            }
        }

        ll j=0;
        while(s[i]>=48 && s[i]<=57){
            if(j == 0){
                ans += s[i]-48;
                j++;
                i++;
                if(i== n){
                    break;
                }
            }else{
                ans = ans*10 + s[i]-48;

                if(ans>pow(2,31)-1&&positive==true){
                return pow(2,31)-1;
            }
            if(ans> pow(2,31)&&positive==false){
                return (-1*pow(2,31));
            }
                i++;
                if(i== n){
                    break;
                }
            }

           
        }
        // // sign
        if(!positive){
            ans *= -1;
        }
        //  if(ans>pow(2,31)-1){
        //         return pow(2,31)-1;
        //     }
        //     if(ans< (-1*pow(2,31))){
        //         return (-1*pow(2,31));
        //     }
        // // round off
        // if(ans < -pow(2,31)){
        //     ans = -pow(2,31);
        // }else if(ans > pow(2,31)-1){
        //     ans = pow(2,31)-1;
        // }
        return (int)ans;
    }
};

class Solution1 {
public:
   static double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
      double ans= x*myPow(x,n-1);
      if(ans>pow(2,31)){
        return pow(2,31);
      } 
      return ans;
    } 
 };

int main(){
    Solution obj;
  cout<< Solution1::myPow(2,2);
}