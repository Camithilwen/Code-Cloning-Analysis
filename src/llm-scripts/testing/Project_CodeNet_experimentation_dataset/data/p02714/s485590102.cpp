#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;

    long long n,r,g,b;
    cin>>n;
    string s;
    cin>>s;

    r=0;
    g=0;
    b=0;

    for(int i=0;i<n;i++) {
        if(s[i]=='R')r++;
        else if (s[i]=='G')g++;
        else if (s[i]=='B')b++;
    }

    int count =0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int k=2*j-i;

            if(i>=j||k>=n||k<=j) continue;

            if(s[i]!=s[j]&&s[i]!=s[k]&&s[j]!=s[k]) count++;
        }
    }

    cout<<r*g*b-count<<endl;
}
