#include <iostream>
#include <string>
using namespace std;
int main(){
  int i,j,n,k[100],l,len,h;
  string s,out;
  char data[52]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  while(1){
    out="";
    cin >> n;
    if(n==0) break;
    for(i=0;i<n;i++){
      cin >> k[i];
    }
    cin >> s;
    len=s.size();
    for(i=0,l=0;i<len;i++,l++){
      if(l==n) l=0;
      for(j=0;j<52;j++){
	if(s[i]==data[j]){
	  if(j-k[l]<0){
	    h=k[l]-j;
	    out+=data[52-h];
	  }
	  else out+=data[j-k[l]];
	}
      }
    }
    cout << out << endl;
  }
  return 0;
}