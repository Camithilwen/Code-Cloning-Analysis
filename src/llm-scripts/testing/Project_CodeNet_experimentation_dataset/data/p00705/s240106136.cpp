#include <bits/stdc++.h>
using namespace std;
const int dx[]={1,0,0,-1,1,-1,-1,1,2,0,-2,0};
const int dy[]={0,1,-1,0,1,1,-1,-1,0,2,0,-2};
const int INF = 1<<30;
const double EPS = 1e-8;
#define PB push_back
#define mk make_pair
#define fr first
#define sc second
#define reps(i,j,k) for(int i = (j); i < (k); ++i)
#define rep(i,j) reps(i,0,j)
#define MOD 1000000007
#define lengthof(x) (sizeof(x) / sizeof(*(x)))
typedef pair<int,int> Pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
int main(){
	int N,Q;
	while(scanf("%d%d",&N,&Q),(N|Q)){
		int s[128]={0};
		int length = 0;
		rep(i,N){
			int c;
			scanf("%d",&c);
			rep(j,c){
				int t;
				scanf("%d",&t);
				s[t]++;
				length = max(length,t);
			}
		}
		length++;
		int ans = 0;
		int index = 0;
		rep(i,length){
			if(s[i]>=Q && ans < s[i]){
				ans = s[i];
				index = i;
			}
		}
		printf("%d\n",index);
	}
	return 0;
}