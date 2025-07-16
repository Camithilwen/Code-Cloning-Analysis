#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
#include <set>
#include <map>
#include <queue>
#include <limits.h>
#include <bitset>
#include <cmath>

using namespace std;

#define rip(i, n, s) for (int i = (s);i < ( int )( n ); i++)
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef pair<int,int> P;
struct modint {
	long long num;
	long long p;
	modint() {
		num = 0;
		p = 1000000007;
	}
	modint(int x) {
		p = 1000000007;
		num = (long long)x%p;
	}
	modint(long long x) {
		p = 1000000007;
		num = x % p;
	}
	modint operator*(const long long &other) {
		modint ret;
		ret.p = p;
		ret.num = (num*(other%p)) % p;
		return ret;
	}
	void operator*=(const long long &other) {
		num = (num*other) % p;
	}
};

int main(){
    int n,m;
    cin >> n >> m;
    vector<P> da(n+m);
    rip(i,n,0){
        cin >> da[i].first;
        da[i].second=1;
    }
    rip(i,m,0){
        cin >> da[i+n].first;
        da[i+n].second=0;
    }
	set<int> ch;
	rip(i,n,0){
		if(ch.count(da[i].first)){
			cout << 0 << endl;
			return 0;
		}
		else{
			ch.insert(da[i].first);
		}
	}
	ch.clear();
	rip(i,m,0){
		if(ch.count(da[i+n].first)){
			cout << 0 << endl;
			return 0;
		}
		else{
			ch.insert(da[i+n].first);
		}
	}
    modint ans(1);
    int now=n*m,h=0,w=0,cr=0;
    sort(all(da));
    reverse(all(da));
    int co=0;
	while(co<n+m){
		//printf("%d %d %d %d %d %lld\n",now,co,h,w,cr,ans.num);
		if(now<=0){
			cout << 0 << endl;
			return 0;
		}
		if(da[co].first==now){
			if(co<n*m-1){
				if(da[co+1].first==now){
					h++;
					w++;
					cr++;
					co++;
				}
				else{
					if(da[co].second){
						ans*=w;
						h++;
					}
					else{
						ans*=h;
						w++;
					}
					cr++;
				}
			}
			else{
				if(da[co].second){
					ans*=w;
					h++;
				}
				else{
					ans*=h;
					w++;
				}
			}
			co++;
		}
		else{
			if((h*w)-cr>0){
			ans*=(h*w)-cr;
			cr++;
			}
			else{
				cout << 0 << endl;
				return 0;
			}
		}
		now--;
	}
	rip(i,now+1,1){
		ans*=i;
	}
	cout << ans.num << endl;
}