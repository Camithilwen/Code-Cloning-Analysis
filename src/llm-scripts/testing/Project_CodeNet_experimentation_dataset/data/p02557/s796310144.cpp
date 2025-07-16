#include<bits/stdc++.h>

using namespace std;

#define ii pair<int,int>
#define fi first
#define se second

#define FOR(a,b,c) for(int a=b, __c=c; a<=__c; ++a)

const int N=2e5+5;
int n,a[N],b[N];
int cnt[N],d[N],ans[N];

int32_t main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   cin>>n;
   FOR(i,1,n) cin>>a[i];
   FOR(i,1,n) cin>>b[i];
   FOR(i,1,n) cnt[a[i]]++, cnt[b[i]]++, d[b[i]]++;
   multiset<ii> s;
   FOR(i,1,n) if(d[i]) s.insert({cnt[i],i});
   FOR(i,1,n){
      auto p=*s.rbegin();
      s.erase(p);
      if(p.se==a[i]){
         if(s.empty()) return cout<<"No\n",0;
         p=*s.rbegin();
         s.erase(p);
         s.insert(make_pair(cnt[a[i]],a[i]));
      }
      s.erase(make_pair(cnt[p.se],p.se));
      d[p.se]--;
      cnt[p.se]--;
      if(d[a[i]]) s.erase({cnt[a[i]],a[i]});
      cnt[a[i]]--;
      if(d[p.se]) s.insert({cnt[p.se],p.se});
      if(d[a[i]]) s.insert({cnt[a[i]],a[i]});
      ans[i]=p.se;
   }
   cout<<"Yes\n";
   FOR(i,1,n) cout<<ans[i]<<' ';
}
