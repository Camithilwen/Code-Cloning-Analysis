#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long int a;
    map<long long int,int> mp;
    for(int i=0;i<n;i++){
        cin >> a;
        a *= (-1);
        mp[a]++;
    }
    long long int tmp=0;
    for(auto u:mp){
        if(u.second>=4){
            if(tmp<0){
                cout << tmp*u.first;
                return 0;
            }
            else{
                cout << u.first*u.first;
                return 0;
            }
        }
        else if(u.second>=2){
            if(tmp<0){
                cout << tmp*u.first;
                return 0;
            }
            else tmp=u.first;
        }
    }
    cout << 0;
}