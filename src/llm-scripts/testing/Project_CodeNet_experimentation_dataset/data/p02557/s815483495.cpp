#include <iostream> 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mk make_pair
#define MAX 1000001
ll prime[MAX];
#define FAST           ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define gcd __gcd
// ll rec(vector<vector<ll> >& dp,vector<ll>& arr,int n,int i,int k,int w)
// {
//   ll ans=0;
//   if(i>=n)
//     return 0;

//   if(dp[i][k]!=-1)
//     return dp[i][k];


//   if(k!=0)
//   ans=max(rec(dp,arr,n,i+1,w,w),arr[i]+rec(dp,arr,n,i+1,k-1,w));
//   else
//   ans=max(rec(dp,arr,n,i+1,k,w),rec(dp,arr,n,i+1,w,w));

//   return dp[i][k]=ans;

// }

//ll t[400008];
// void build(vector<ll>& a, int v, int tl, int tr) {
//     if (tl == tr) {
//         t[v] = a[tl];
//     } else {
//         int tm = (tl + tr) / 2;
//         build(a, v*2, tl, tm);
//         build(a, v*2+1, tm+1, tr);
//         t[v] = max(t[v*2] ,t[v*2+1]);
//     }
// }

// ll maxi(int v, int tl, int tr, int l, int r) {
//     if (l > r) 
//         return 0;
//     if (l == tl && r == tr) {
//         return t[v];
//     }
//     int tm = (tl + tr) / 2;
//     return max(maxi(v*2, tl, tm, l, min(r, tm)) ,maxi(v*2+1, tm+1, tr, max(l, tm+1), r));
// }



// void update(int v, int tl, int tr, int pos, ll new_val) {
//     if (tl == tr) {
//         t[v] = new_val;
//     } else {
//         int tm = (tl + tr) / 2;
//         if (pos <= tm)
//             update(v*2, tl, tm, pos, new_val);
//         else
//             update(v*2+1, tm+1, tr, pos, new_val);
//         t[v] = max(t[v*2] ,t[v*2+1]);
//     }
// }


struct hash_pair {
   template <class T1, class T2>
   size_t operator()(const pair<T1, T2>& p) const{
      auto hash1 = hash<T1>{}(p.first);
      auto hash2 = hash<T2>{}(p.second);
      return hash1 ^ hash2;
   }
};


int temp[1000002]={0};

void sieve()
{
  temp[1]=1;
  for(int i=2;i<1000002;i++)
  {
    if(temp[i]==0)
    { temp[i]=i;
      for(int j=i*2;j<1000002;j+=i)
      { 
        if(temp[j]==0)
        temp[j]=i;
      }
    }
  }

}

int dfs(int i,vector<vector<int> > &g,vector<int>& p,vector<int>& c)
{
  int sub=1;
  for(auto x:g[i])
  {
    if(p[i]!=x)
    {
      p[x]=i;
      sub+=dfs(x,g,p,c);
    }
  }

  return c[i]=sub;
}


int main() { 

int n;
cin>>n;
int a[n],fa[n+1]={0};
int b[n],fb[n+1]={0};

for(int i=0;i<n;i++)
{
  cin>>a[i];
  fa[a[i]]++;
}

for(int i=0;i<n;i++)
{
  cin>>b[i];
  fb[b[i]]++;
}
int flag=0;

for(int i=1;i<=n;i++)
{
  if(fa[i]+fb[i]>n)
  {
    flag=1;
    break;
  }
}
if(flag)
{
  cout<<"No"<<"\n";
  return 0;
}

 cout<<"Yes"<<"\n";

reverse(b,b+n);

int i=0;
int j=0;

while(i<n)
{
  if(a[i]!=b[i])
    { i++;
      continue;}

  swap(b[i],b[j]);
  j++;

}

i=n-1;
j=n-1;

while(i>=0)
{
  if(a[i]!=b[i])
    { i--;
      continue;}

  swap(b[i],b[j]);
  j--;


}

 for(int i=0;i<n;i++)
  cout<<b[i]<<" ";
cout<<"\n";

return 0;
}
/*
1
4
1 2
2 3
3 4
*/
