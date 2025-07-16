#include<bits/stdc++.h>
using namespace std;
#define intt long long int
#define intu unsigned long long int
#define vi vector<intt>
#define ii pair<int,int>
#define pb push_back
//#define mp make_pair
#define ff first
#define ss second
#define fast_io ios::sync_with_stdio(0);cin.tie(NULL);std::cout.tie(NULL);
# define PI           3.14159265358979323846 
#define all(a) a.begin(),a.end()
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define loop(i,a,b) for (int i = a; i < b; i++)
#define bloop(i,a,b) for (int i = a ; i>=b;i--)
#define tc(t) int t; cin >> t; while (t--)
int mod = 1000000007;
intt gcd(intt a, intt b) {return b ? gcd(b, a % b) : a;}
int lcm(int a, int b) {return a * b / gcd(a, b); }
intt bpow(intt a,intt b) 
{
  intt res = 1;
  while (b > 0) {
    if (b & 1)res = res * a;
      a = a * a;
      b >>= 1;
  }
  return res;
}
intt fact(intt n) { 
   if ((n==0)||(n==1))
      return 1; 
   else
      return (n*fact(n-1))%mod;
}

void go()
{
#ifndef ONLINE_JUDGE
  freopen("IN.txt","r",stdin);
  freopen("OUT.txt","w",stdout);
  #endif
}



int main(){
	go();
	fast_io
  int n;cin>>n;
  vi a(n),b(n);
  for0(i,n){
    cin>>a[i];
  }
  for0(i,n){
    cin>>b[i];
  }
  reverse(all(b));
  int l=0,r=0;
  while(b[r]!=a[r] && r<n){
    r++;l++;
  }
  if(r==n){
    cout << "Yes" <<"\n";
    for(auto it: b)
      cout << it <<" ";
    cout << "\n";
  }
  else{
    while(r<n && a[r]==b[r])
      r++;
    int need=r-l;
    int j=0,left=l,right=r;
    while(j<left && l<r && need){
      if(b[j]!=b[l] && a[j]!=b[l]){
        swap(b[j],b[l]);
        need--;
        l++;
        j++;
      }
      else
        break;
    }
    j=n-1;
    while(j>=right && l<right && need){
      if(b[j]!=b[l] && a[j]!=b[l]){
        swap(b[j],b[l]);
        need--;
        l++;
        j--;
      }
      else
        break;
    }
    if(need)
      cout << "No" <<"\n";
    else{
      cout << "Yes" <<"\n";
      for(auto it: b)
        cout << it <<" ";
      cout << "\n";
    }
  }

}


/*
*/

//9c(n-2)*2














