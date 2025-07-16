#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int time(int a,int b,int c,int d,int e,int m){
	int ret =  a+b+c+d+e;
	rep(i,m-1){
		ret += d+e;
	}
	return ret;
}
bool cmp(const pair<double,string>&a,const pair<double,string>&b){
	if( fabs(a.first-b.first) < 1e-8){
		return a.second < b.second;
	}
	return a.first > b.first;
}
int main(){
	int n;
	
	while(cin >> n , n){
		vector< pair<double,string> > data(n);
		rep(i,n){
			string l; int p,a,b,c,d,e,f,s,m;
			cin >> l >> p >> a >> b >> c >> d >> e >> f >> s >> m;
			data[i].first = (double)(f*s*m-p)/time(a,b,c,d,e,m);
			data[i].second = l;
		}
		sort(data.begin(),data.end(),cmp);
		rep(i,n){
			cout << data[i].second << endl;
		}
		cout << "#" << endl;
	}
}