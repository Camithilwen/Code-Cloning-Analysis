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
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double EPS=1e-10;
const int inf=1e8;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vi in(n);
	rep(i,n)cin>>in[i];
	vi out(n,0);
	rep(i,m){
		int a;
		cin>>a;
		rep(j,n)if(a>=in[j]){
			out[j]++;
			break;
		}
	}
	int ma=-1;
	rep(i,n)ma=max(ma,out[i]);
	rep(i,n)if(ma==out[i])cout<<i+1<<endl;
	
	}