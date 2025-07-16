#include "bits/stdc++.h"

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back

int main(){
	int n;
	cin>>n;
	rep(loop,n){
		int rui[5]={};
		string s;
		int o=0;
		int p=0;
		while(cin>>s){
			if(s=="HIT"){
				if(rui[3]==1)p++;
				rui[3]=rui[2];
				rui[2]=rui[1];
				rui[1]=1;
			}
			if(s=="OUT"){
				o++;
				if(o>=3)break;
			}
			if(s=="HOMERUN"){
				p+=1+rui[3]+rui[2]+rui[1];
				rui[3]=0;
				rui[2]=0;
				rui[1]=0;
			}
		}
		cout<<p<<endl;
	}
}