#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int MOD=1e9+7;
const long double Pi=acos(-1);
using  P=pair<ll,ll>;
ll gcd(ll a,ll b){//aとbの最大公約数を返す//計算量は0(log(max(a,b))
  if(a%b==0){return b;}
  else{return gcd(b,a%b);}
}
ll lcm(ll a,ll b){//aとbの最小公倍数を返す//計算量は0(log(max(a,b))
  return a*b/gcd(a,b);
}
ll pow(ll x,ll y){//x^yを返す//計算量は0(log(y))
  ll tmp=x,res=1;
  while(y){
    if(y%2){res=res*tmp%MOD;}
    y>>=1;
    tmp=tmp*tmp%MOD;
  }
  return res;
}
ll nature(ll a){//絶対値を返す
  if(a>=0){return(a);}
  else{return(-1*a);}
}
ll prime(ll a){//素数なら1を返す//計算量は0(sqrt(a))
  if(a==2){return 1;}
  else if(a%2==0 || a==1){return 0;}
  for(ll i=3;i*i<=a;i+=2){if(a%i==0){return 0;}}
  return 1;
}
vector<int> Z;
void z_algorithm(string str){//計算量はO(str.size())
  Z.resize(str.size());
  Z.at(0)=str.size();
  int m=1,n=0;
  while(m<(int)str.size()){
    while(m+n<(int)str.size()&&str.at(n)==str.at(m+n)){n++;}
    Z.at(m)=n;
    if(n==0){
      m++;
      continue;
    }
    int k=1;
    while(k+Z.at(k)<n){
      Z.at(m+k)=Z.at(k);
      k++;
    }
    m+=k;
    n-=k;
  }
}
vector<vector<int>> vec;
vector<vector<int>> now;
bool dfs(int i){
    int ii=now.at(i).at(0);
    if(ii==-1){return false;}
    if(now.at(ii).at(0)==i){return true;}
    else{return false;}
}
int main(){
    int N;
    cin>>N;
    vec.resize(N,vector<int>(N-1));
    now.resize(N,vector<int>(0));
    vector<int> enemy(N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1;j++){
            int a;
            cin>>a;
            vec.at(i).at(j)=a-1;
            if(j==0){
                now.at(i).push_back(a-1);
            }
        }
        enemy.at(i)=0;
    }
    ll count=0;
    ll day=0;
    //countはN(N-1)/2まで
    while(count<N*(N-1)/2){
        unordered_map<int,int> mp;
        int memo=count;
        day++;
        for(int i=0;i<N;i++){
            //cout<<count<<" "<<i<<endl;
            if(dfs(i) && mp[i]==0 && mp[now.at(i).at(0)]==0 && now.at(i).at(0)!=-1){
                count++;
                int a=i;
                int b=now.at(i).at(0);
                enemy.at(a)++;
                enemy.at(b)++;
                mp[a]=1;
                mp[b]=1;
                //cout<<a<<" "<<b<<"   "<<enemy.at(a)<<" "<<enemy.at(b)<<endl;
                if(enemy.at(a)<N-1){
                    //cout<<a<<" "<<b<<" "<<enemy.at(a)<<endl;
                    now.at(a).at(0)=vec.at(a).at(enemy.at(a));
                }
                else{
                    now.at(a).at(0)=-1;
                }
                if(enemy.at(b)!=N-1){
                    //cout<<" "<<a<<" "<<b<<" "<<enemy.at(b)<<endl;
                    now.at(b).at(0)=vec.at(b).at(enemy.at(b));
                }
                else{
                    now.at(b).at(0)=-1;
                }
            }
        }
        if(memo==count){
            cout<<-1<<endl;
            return 0;
        }
        mp.clear();
    }
    cout<<day<<endl;
}