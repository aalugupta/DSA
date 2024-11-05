#include <iostream>
using namespace std;

int main(){
    //DIAMOND PATTERN
//     int n=20;
//     for(int i=1;i<=n;i++){
//     for(int j=1;j<=n-i;j++){
//         cout<<" ";
//     }
//     for(int j=1;j<=2*i-1;j++){
//         cout<<"*";
//     }
//     for(int j=1;j<=n-1;j++){
//         cout<<" ";
//     }
//     cout<<endl;
//     }
//     for(int i=n;i>=1;i--){
//     for(int j=1;j<=n-i;j++){
//         cout<<" ";
//     }
//     for(int j=1;j<=2*i-1;j++){
//         cout<<"*";
//     }
//     cout<<endl;
//     }
//     return 0;
// }
 // BUTTERFLY PATTERN
int n=15;
    for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
        cout<<"*";
    }
    for(int j=1;j<=2*(n-i);j++){
        cout<<" ";
    }
     for(int j=1;j<=i;j++){
        cout<<"*";
    }
    cout<<endl;
    }
    for(int i=n;i>=1;i--){
    for(int j=1;j<=i;j++){
        cout<<"*";
    }
    for(int j=1;j<=2*(n-i);j++){
        cout<<" ";
    }
     for(int j=1;j<=i;j++){
        cout<<"*";
    }
    cout<<endl;
    }
    return 0;
}