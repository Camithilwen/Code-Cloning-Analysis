#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<vector>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<time.h>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define rp(a) while(a--)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double EPS=1e-10;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int main(){
	int n;
	cin>>n;
	string s;
	getline(cin,s);
	while(n--){
		getline(cin,s);
		if(s.size()>6)rep(i,s.size()-6)if(s.substr(i,7)=="Hoshino")s[i+6]='a';
		cout<<s<<endl;
	}
}