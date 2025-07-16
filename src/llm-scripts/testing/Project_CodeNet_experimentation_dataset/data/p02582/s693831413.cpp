 #include<bits/stdc++.h>
  using namespace std;
  #define       M                        1000000007
  #define       ll                       long long
  #define       FIO                      ios_base::sync_with_stdio(false);cin.tie(NULL)
  #define       ifor(st,lim)             for(int i=st;i<lim;i++)
  #define       jfor(stt,llim)           for(int j=stt;j<llim;j++)
  #define       eifor(st,lim)            for(int i=st;i<=lim;i++)
  #define       ejfor(stt,llim)          for(int j=stt;j<=llim;j++)
  #define       blank                    cout<<'\n' 


void solve()
{ 
   string s; cin>>s;
   
   if(s[0] == s[1] && s[1] == s[2] && s[0] == 'R') cout<<"3";
   else if(s[0] == s[1] && s[0] == 'R') cout<<"2";
   else if(s[1] == s[2] && s[1] == 'R') cout<<"2";
   else if(s[0] == 'R' || s[1] == 'R' || s[2] == 'R') cout<<"1";
   else cout<<"0";   
}
 
  int main()
  {
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int t=1;
  while(t--){
      solve();
     } 
  }