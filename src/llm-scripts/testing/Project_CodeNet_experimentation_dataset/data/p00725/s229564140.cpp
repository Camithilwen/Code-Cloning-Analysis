#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define reep(i,a,b) for(int i=a; i<b; i++)
#define fi first
#define se second

using pii = pair<int,int>;
using vint = vector<char>;
using vvint = vector<vector<char>>;
using bit = bitset<400>;

int w,h;
bool inside(int a, int b){
	return 0<=a&&a<h&&0<=b&&b<w;	
}

int dd[] = {0,1,0,-1,0};


int main(){
	while(cin>>w>>h,w){
		pii start;
		pii goal;
		bit vv(0);		
		rep(i,h) rep(j,w){
			int t;
			cin>>t;
			if(t==1) vv[i*20+j]=1;
			if(t==2){
				start = pii(i,j);
			}
			if(t==3){
				goal = pii(i,j);
			}
		}
		bool ok = false;
		queue<pair<pii,bit>> q;
		q.push(make_pair(start, vv));
		int ans = 20;
		rep(_,11){
			int qs = q.size();
			rep(i,qs){
				pii now = q.front().fi;
				bit vv = q.front().se;
				// rep(ii,h){
				// 	rep(jj,w){
				// 		cout<<vv[ii][jj]<<" ";
				// 	}
				// 	cout<<endl;
				// }
				q.pop();
				rep(j,4){
					pii next = now;
					next.fi += dd[j];
					next.se += dd[j+1];
					// cout<<next.fi<<" "<<next.se<<" "<<inside(next.fi, next.se)<<endl;
					if(inside(next.fi, next.se) && vv[next.fi*20+next.se]==0){
						// cout<<"hoge"<<endl;
						while(inside(next.fi, next.se)&&vv[next.fi*20+next.se]==0){
							// cout<<"vv "<<vv[next.fi*20+next.se]<<endl;
							if(next == goal) ans = min(ans, _+1);
							next.fi += dd[j];
							next.se += dd[j+1];
						}
						if(inside(next.fi, next.se)){
							vv[next.fi*20+next.se] = 0;
							next.fi -= dd[j];
							next.se -= dd[j+1];
							q.push(make_pair(next, vv));
							next.fi += dd[j];
							next.se += dd[j+1];
							vv[next.fi*20+next.se] = 1;
						}
					}
				}
			}
		}
		cout<<(ans<=10?ans:-1)<<endl;
	}
}