#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define MOD 1000000007ULL;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	string S;
  	cin>>S;
  	bool alpha[26];
  	string ans;
  	rep(i,26) alpha[i]=false;
  	rep(i,S.size()){
		alpha[S[i]-'a']=true;
    }
  	
  	if(S.size()<26){
     	 rep(i,26){
			if(alpha[i]==false){
             	ans=S;
              	ans.push_back('a'+i);
              	break;
            }
         }
    }else if(S=="zyxwvutsrqponmlkjihgfedcba"){
     	ans="-1";
    }else{
     	string T=S;
      	next_permutation(S.begin(),S.end());
    	int j=0;
      	while(S[j]==T[j]){
         	ans.push_back(S[j]);
          	j++;
        }
      	ans.push_back(S[j]);
    }
  
  
  	cout<<ans<<endl;
}