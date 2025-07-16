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
vector<vector<char> >in(14,vector<char>(14));
int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};
void func(int a,int b){
	in[a][b]=0;
	rep(k,4)if(in[a+x[k]][b+y[k]]!=0)func(a+x[k],b+y[k]);
}


int main(){
	char d;
	while(cin>>d){
		rep(i,12)rep(j,12){
			if(!i&&!j)in[i+1][j+1]=d;
			else cin>>in[i+1][j+1];
			if(in[i+1][j+1]=='0')in[i+1][j+1]=0;else in[i+1][j+1]=1;
		}
		int out=0;
		rep(i,12)rep(j,12)if(in[i+1][j+1]!=0){
			out++;
			func(i+1,j+1);
		}
		cout<<out<<endl;
	}
}