#include<bits/stdc++.h>
using namespace std;

using ll=long long;

int main(){
    vector<vector<ll>> a(500,vector<ll>(500,0));
    vector<int> isPrime(5000,true);
    vector<ll> primes;
    for(int i=2;i<isPrime.size();i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j=2;j<isPrime.size();j+=i){
                isPrime[j]=false;
            }
        }
    }
    set<ll> vs;
    swap(primes[0],primes[213]);
    swap(primes[1],primes[224]);
    swap(primes[2],primes[171]);
    for(int i=499;i>=0;i--){
        for(int j=i%2;j<500;j+=2){
            a[i][j]=primes[i/2]*primes[j/2];
            int tmp=2;
            while(vs.count(a[i][j])){
                a[i][j]=a[i][j]/(tmp-1)*tmp;
                tmp++;
            }
            vs.insert(a[i][j]);
        }
    }
    auto isRange=[](int x,int y){
        return 0<=x && x<500 && 0<=y && y<500;
    };
    auto lcm=[](ll x,ll y){
        return x/__gcd(x,y)*y;
    };
    int dx[]={0,1,0,-1};
    int dy[]={1,0,-1,0};

    for(int i=0;i<500;i++){
        for(int j=(i+1)%2;j<500;j+=2){
            ll v=1;
            for(int k=0;k<4;k++){
                if(isRange(i+dx[k],j+dy[k])){
                    v=lcm(v,a[i+dx[k]][j+dy[k]]);
                }
            }
            a[i][j]=v;
            int tmp=2;
            while(vs.count(a[i][j]+1)){
                a[i][j]=a[i][j]/(tmp-1)*tmp;
                tmp++;
            }
            a[i][j]++;
            if(a[i][j]<=1e15) vs.insert(a[i][j]);
        }
    }
    ios_base::sync_with_stdio(false);
    
    int n;
    cin>>n;
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j+1<n;j++){
            if(a[i][j]>1e15){
                cnt++;
                cerr<<i<<" "<<j<<endl;
                vs.insert(a[i][j]);
            }
            cout<<a[i][j]<<" ";
        }
        cout<<a[i][n-1]<<"\n";
    }
    cerr<<cnt<<endl;
    return 0;
}