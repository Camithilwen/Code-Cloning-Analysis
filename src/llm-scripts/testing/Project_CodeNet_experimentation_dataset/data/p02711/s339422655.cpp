#include<iostream>
//#include<algorithm>
#include<cmath>
#include<string>
//#include<set>
//#include<vector>
#include<iomanip>
using namespace std;
int main(){

    int n;
    cin >> n;
    if(n%10==7){cout<<"Yes"; return 0;}
    else{n/=10;}
    if(n%10==7){cout<<"Yes"; return 0;}
    else{n/=10;}
    if(n%10==7){cout<<"Yes"; return 0;}
    else{n/=10;}
    cout<<"No";
    return 0;
}
