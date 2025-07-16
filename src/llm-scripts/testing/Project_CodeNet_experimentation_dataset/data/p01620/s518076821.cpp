#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;

  while(cin>>n&&n){
    vector<int> k(n);

    for(int i=0;i<n;++i)
      cin>>k[i];

    string s;cin>>s; 
    vector<char> c;

    for(int i=0;i<s.size();++i){
      c.emplace_back(s.at(i));
      int key = k[i%k.size()];
      while(key!=0){
        int tmp;
        if(key>26){
          key -= 26;
          tmp = 26;
        }else{
          tmp = key;
          key -= key;
        }

        if(c[i]>='A'&&c[i]<='Z'){
          c[i] -= tmp;
          if(c[i]<'A'){
            char sub = 'A' - c[i] - 1;
            c[i] = 'z' - sub;
          }
        }
        else if(c[i]>='a'&&c[i]<='z'){
          c[i] -= tmp;
          if(c[i]<'a'){
            char sub = 'a' - c[i] - 1;
            c[i] = 'Z' - sub;
          }
        }
      }
      cout<<c[i];
    }
    cout<<endl;
  }

  return EXIT_SUCCESS;
}