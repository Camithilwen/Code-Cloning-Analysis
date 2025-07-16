#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   /// https://ideone.com/Fd5s8n
  int k;
  cin>>k;
  string s;
  cin>>s;
  if(s.length()<=k)
    cout << s << endl;
  else{
    for(int i=0;i<k;i++)
        cout << s[i];
cout << "..." << endl;
  }

    return 0;

}
