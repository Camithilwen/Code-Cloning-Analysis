#include<bits/stdc++.h>
using namespace std;

struct Point{
	int x,y,idx;
	bool operator<(const Point& rhs)const{
		return x==rhs.x?y<rhs.y:x<rhs.x;
	}
}P[100];

bool bad(const Point& p1,const Point& p2,const Point& p3){
	return 1LL*(p3.x-p1.x)*(p2.y-p1.y)-1LL*(p2.x-p1.x)*(p3.y-p1.y)<=0;
}
vector<Point> convex(int n){
	sort(P,P+n);
	vector<Point> res;
	for(int i=0;i<n;i++){
		while(res.size()>=2&&bad(res[res.size()-2],res[res.size()-1],P[i]))
			res.pop_back();
		res.emplace_back(P[i]);
	}
	for(int i=n-2,t=res.size();i>=0;i--){
		while(res.size()>t&&bad(res[res.size()-2],res[res.size()-1],P[i]))
			res.pop_back();
		res.emplace_back(P[i]);
	}
	res.pop_back();
	return res;
}
double ans[100];
const double pi = acos(-1);
inline double dist(int x,int y){
	return sqrt(1LL*x*x+1LL*y*y);
}
double calc(const Point& p1,const Point& p2,const Point& p3){
	long long int dot=1LL*(p3.x-p2.x)*(p2.x-p1.x)+1LL*(p3.y-p2.y)*(p2.y-p1.y);
	double tmp=dot/(double)dist(p2.x-p1.x,p2.y-p1.y)/(double)dist(p3.x-p2.x,p3.y-p2.y);
	double ang = acos(tmp);
	return ang/(2*pi);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>P[i].x>>P[i].y,P[i].idx=i;
	auto res = convex(n);
	if(res.size()==2){
		ans[res[0].idx]=0.5;
		ans[res[1].idx]=0.5;
	}
	else{
		for(int j=0;j<res.size();j++){
			int i=(j+(res.size()-1))%res.size();
			int k=(j+1)%res.size();
			ans[res[j].idx] = calc(res[i],res[j],res[k]);
		}
	}
	cout<<fixed<<setprecision(10);
	for(int i=0;i<n;i++)
		cout<<ans[i]<<'\n';
}
