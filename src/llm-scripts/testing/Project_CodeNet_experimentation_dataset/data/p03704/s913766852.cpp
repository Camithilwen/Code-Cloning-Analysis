#include <iostream>
#include <cassert>
#include <climits>
#include <bitset>
#include <stack>
#include <queue>
#include <iomanip>
#include <limits>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

long long int INF = 3e18;
double Pi = 3.1415926535897932384626;

vector<ll> G[500005];
vector<P> tree[500010];
priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop

int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
char dir[] = "DRUL";
//ll bit[500005];
//↓,→,↑,←


#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<x;
#define re(i,n) for(i=0;i<n;i++);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define deba(x) cout<< #x << " = " << x <<endl


ll mod = 1000000007;
ll rui(ll abc,ll bed){
    //abcのbed乗を計算する
    if(bed==0){return 1;}
    else{
        ll ced = rui(abc,bed/2);
        ced *= ced;
        ced %= mod;
        if(bed%2==1){ced*=abc; ced%=mod;}
        return ced;
    }
}
ll gcd(ll number1,ll number2){
    if(number1 > number2){
        swap(number1,number2);
    }
    if(number1 == 0 || number1 == number2){
        return number2;
    }else{
        return gcd(number2 % number1,number1);
    }
}
void YES(bool condition){
    if(condition){
        p("YES");
    }else{
        p("NO");
    }
    return;
}
void Yes(bool condition){
    if(condition){
        p("Yes");
    }else{
        p("No");
    }
    return;
}

ll n,m,num,sum,b,c,d,e,f,g,h,i,j,k,w,ok,ng,l,r,ans;
long double a;
ll x[500005],y[500005];
bool flag,dame;

ll sa[40];
void solve(ll reside,ll a,ll b,bool first){
	//pe(reside);pe(a);p(b);
	if(a == 0){
		//p(reside);
		if(reside == 0){
			ans += b;
			//p(b);
		}
		return;
	}
	if(reside < -1 * 10 * a || 10 * a < reside)return;
	for(int i=-9;i<=9;i++){
		if((reside - i * a) % 10 == 0){
			if(a == 99){
				solve((reside - i * a)/10,a / 100,b * (sa[i + 10] - first) * 10,0);
			}else{
				solve((reside - i * a)/10,a / 100,b * (sa[i + 10] - first),0);
			}
		}
	}
}

int main(){
    cin >> n;
	num = 9;
	ans = 0;
	if(n % 9 != 0){                      
		p(0);return 0;                    
	}
	for(i=0;i<20;i++){
		sa[i] = 10 - abs(10 - i);
	}
	for(int i=0;i<18;i++){
		solve(n,num,1,1);
		//p(num);
		num *= 10;
		num += 9;
	}
	p(ans);
	return 0;
}
