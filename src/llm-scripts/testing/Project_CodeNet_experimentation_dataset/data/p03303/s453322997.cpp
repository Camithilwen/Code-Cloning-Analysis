#include <bits/stdc++.h>
using namespace std;


int main() {
string S;
int w;
cin>>S>>w;

int i=0;
while(i<S.size()){
  cout<<S[i];
  i+=w;
}
cout<<endl;
}
