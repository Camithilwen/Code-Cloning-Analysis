#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<utility>
#include<cmath>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
#define pi acos(-1)
#define all(v) v.begin(),v.end()
using namespace std;

const double eps = 1e-8;
const double INF = 1e12;

typedef pair<int,int> P;
typedef double Real;
typedef complex<Real> Point;
typedef vector<Point> G;

double cross(const Point& a,const Point& b){//calculate ad-bc(vector product)
	return imag(conj(a)*b);
}

struct L:public vector<Point>{//line data
	L(const Point &a,const Point &b){
		push_back(a);
		push_back(b);
	}
};

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
	string s[12];
	int dt[12][12];
	while(cin>>s[0]){
		loop(i,1,12)cin>>s[i];
		rep(i,12){
			rep(j,12){
				dt[i][j]=(int)(s[i][j]-'0');
			}
		}
		int ans=0;
		rep(i,12){
			rep(j,12){
				if(dt[i][j]){
					ans++;
					queue<P> que;
					P now(j,i);
					que.push(now);
					while(!que.empty()){
						now=que.front();
						que.pop();
						if(now.second>=12 ||now.first<0 || now.second<0 || now.first>=12)continue;
						if(dt[now.second][now.first]==0)continue;
						dt[now.second][now.first]=0;
						rep(k,4){
							now.first+=dx[k];
							now.second+=dy[k];
							que.push(now);
							now.first-=dx[k];
							now.second-=dy[k];
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}