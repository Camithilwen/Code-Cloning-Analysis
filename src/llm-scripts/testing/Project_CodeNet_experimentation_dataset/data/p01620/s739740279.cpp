#include<iostream>
#include<map>
#include<string>
#include<vector>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef int Def;
typedef vector<Def> vi;
typedef pair<Def,Def> pii;
int main(){
	int n;
	while(cin>>n,n){
		vi in(n);
		rep(i,n)cin>>in[i];
		string s;
		cin>>s;
		rep(i,s.size()){
			int t=in[i%n];
			if(t>=26){
				t-=26;
				if(islower(s[i]))s[i]=toupper(s[i]);
				else s[i]=tolower(s[i]);
			}
			if(islower(s[i])){
				s[i]-=t;
				if(s[i]<'a')s[i]='Z'-('a'-s[i])+1;
			}else{
				s[i]-=t;
				if(s[i]<'A')s[i]='z'-('A'-s[i])+1;
			}
		}
		cout<<s<<endl;
	}
}
