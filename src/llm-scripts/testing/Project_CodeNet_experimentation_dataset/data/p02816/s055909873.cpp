/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
vector<int> each[30];
int n,bit[200000+1][30];
int z[700000+1];
string b[30];
void z_function(string S){
//	cout<<S<<endl;
	int len=S.length();
	S='$'+S;
	int l,r;
	memset(z,0,sizeof(z));
	rb(i,2,len)
		if(S[i]!=S[i-1]) break;
		else z[2]++;
	l=2,r=z[2]+1;
	rb(i,3,len){
		if(i<=r){
			z[i]=z[i-(l)+1];
			z[i]=min(z[i],r-i+1);
			if(z[i]+i-1==r){
				int ite=z[i]+1;
				rb(j,r+1,len){
					if(S[j]!=S[ite++]) break;
					z[i]++;
				}
				l=i,r=i+z[i]-1;
			}
		}
		else{
			int ite=1;
			rb(j,i,len){
				if(S[j]!=S[ite++]) break;
				z[i]++;
			}
			l=i,r=i+z[i]-1;
		}
	}
}
int a[200000+1],sb[200000+1];
void run(int is){
	string A="";
	rb(i,1,n)
		A+=char('0'+bit[i][is]);
	z_function(A+'&'+b[is]+b[is]);
	rb(i,n+3,n+2+n){
		if(z[i]==n){
			each[is].PB(n+2+n-i);
		}
	}
	rb(i,1,n)
		if(A[i-1]=='0') A[i-1]='1';
			else A[i-1]='0';
	z_function(A+'&'+b[is]+b[is]);
	rb(i,n+3,n+2+n){
		if(z[i]==n){
			each[is].PB(n+2+n-i);
		}
	}
}
int main(){
	fastio;
	cin>>n;
	rb(i,1,n)
	{
		int ai;
		cin>>ai;
		a[i]=ai;
		rep(j,30)
		{
			bit[i][j]=bool(ai&(1<<j));
		}
	}
	rep(i,30)
		b[i]="";//return 0;
	rb(i,1,n){
		int bi;
		cin>>bi;
		sb[i]=bi;
		rep(j,30){
			b[j]+=char('0'+(bool)(bi&(1<<j)));
		}
	}
	rep(i,30){
		run(i);
		sort(ALL(each[i]));
	}
	rep(i,n){
		int ok=1;
		rep(j,30){
			if(binary_search(ALL(each[j]),i)){
				
			}
			else ok=0;
		}	if(ok) cout<<i<<" "<<(a[1+i] ^ sb[1])<<endl;
	}
	return 0;
}
