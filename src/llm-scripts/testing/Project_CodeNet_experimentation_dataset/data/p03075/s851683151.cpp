#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define fore(i,x,n) for(int i=x;i<n;i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define ordenar(a) sort(all(a))
typedef long long ll;
typedef vector<int> vi;

int a[5], k;

int main(){
    IOS

    fore(i,0,5) cin>>a[i];
    cin>>k;

    fore(i,0,4){
        fore(j,i+1,5){
            if(a[j]-a[i] > k) {
                cout<<":(";
                return 0;
            }
        }
    }

    cout<<"Yay!";
    
    return 0;
}