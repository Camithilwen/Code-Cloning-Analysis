#include<bits/stdc++.h>
using namespace std;
#define int  long long
#define tc(t)  int t; cin>>t; while(t--)
#define f(n)    for(int i=0;i<n;i++)
#define endl   "\n"







int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     int n,m;
     cin>>n>>m;
     vector<pair<int,string>>v(m);
     vector<pair<int,int>>dp(n,{0,0});
     for(int i=0;i<m;i++){
         int q;
         string verdict;
         cin>>q>>verdict;
         v[i]={q,verdict};
     }

     int correct=0,penality=0;
     for(int i=0;i<m;i++)
     {
       int qn=v[i].first;
       string verdict=v[i].second;
       if(verdict=="WA")
       {
           if(dp[qn-1].second==0)
           {dp[qn-1].first++;}

       } else{
           if(dp[qn-1].second==0) {
               dp[qn - 1].second = 1;
               correct++;
               penality+=dp[qn-1].first;
           }
       }


     }
     cout<<correct<<" "<<penality<<endl;










}