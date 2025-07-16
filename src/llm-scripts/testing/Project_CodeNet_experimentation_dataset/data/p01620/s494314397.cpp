#include<bits/stdc++.h>

using namespace std;

int main(){

  int n;

  while(cin>>n,n){

	vector<int> k(n);
	string s;

	for(int i=0;i<n;++i)
	  cin>>k[i];

	cin>>s;

	int key=0;
	
	for(int i=0;i!=s.size();++i){
	  for(int j=0;j<k[key];++j){
		if(s[i]=='a')
		  s[i]='Z';
		else  if(s[i]=='A')
		  s[i]='z';
		else
		  s[i]--;
	  }
	  if(key==n-1)
		key=0;
	  else
		key++;
	}

	cout<<s<<endl;
	
  }

}

