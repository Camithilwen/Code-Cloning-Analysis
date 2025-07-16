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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int main(){
	int a,b,c;
	while(cin>>a>>b>>c,a+b+c){
		vector<int>in(a+b+c+1,2);
		int n;
		cin>>n;
		vector<vector<int> >tmp(n,vector<int>(4));
		rep(i,n)rep(j,4)cin>>tmp[i][j];
		rep(i,n)if(tmp[i][3]==1){
			in[tmp[i][0]]=1;
			in[tmp[i][1]]=1;
			in[tmp[i][2]]=1;
		}
		rep(i,n){
			int co=0;
			rep(j,3)if(in[tmp[i][j]]!=1)co++;
			if(co==1){
				rep(j,3)if(in[tmp[i][j]]==2)in[tmp[i][j]]=0;
			}
		}
		loop(i,1,a+b+c+1)cout<<in[i]<<endl;
	}
}