#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<stdio.h>
#include<vector>
using namespace std;
#define int long long
#define rep(s,i,n) for(int i=s;i<n;i++)
#define c(n) cout<<n<<endl;
#define ic(n) int n;cin>>n;
#define sc(s) string s;cin>>s;
#define mod 1000000007
#define inf 1000000000000000007
#define f first
#define s second
#define mini(c,a,b) *min_element(c+a,c+b)
#define maxi(c,a,b) *max_element(c+a,c+b)
//printf("%.12Lf\n",);
int keta(int x){
	rep(0,i,30){
		if(x<10){
			return i+1;
		}
		x=x/10;
	}
}
int gcd(int x,int y){
	int aa=x,bb=y;
	rep(0,i,1000){
		aa=aa%bb;
		if(aa==0){
			return bb;
		}	
		bb=bb%aa;
		if(bb==0){
			return aa;
		}
	}
}	
int lcm(int x,int y){
	int aa=x,bb=y;
	rep(0,i,1000){
		aa=aa%bb;
		if(aa==0){
			return x/bb*y;
		}	
		bb=bb%aa;
		if(bb==0){
			return x/aa*y;
		}
	}
}
bool p(int x){
	if(x==1)return false;
	rep(2,i,sqrt(x)+1){
		if(x%i==0&&x!=i){
			return false;
		}
	}	
	return true;
}
int max(int a,int b){
	if(a>=b)return a;
	else return b;
}
int min(int a,int b){
	if(a>=b)return b;
	else return a;
}	
int n2[41];		
int nis[41]; 
int nia[41];
int mody[41];
int nn;
int com(int n,int y){
	int ni=1;
	for(int i=0;i<41;i++){
		n2[i]=ni;
		ni*=2;
	}
	int bunsi=1,bunbo=1;
	rep(0,i,y)bunsi=(bunsi*(n-i))%mod;
	rep(0,i,y)bunbo=(bunbo*(i+1))%mod;
	mody[0]=bunbo;
	rep(1,i,41){
		bunbo=(bunbo*bunbo)%mod;
		mody[i]=bunbo;
	}
	rep(0,i,41)nis[i]=0;
	nn=mod-2;
	for(int i=40;i>=0;i-=1){
		if(nn>n2[i]){
			nis[i]++;
			nn-=n2[i];
		}
	}
	nis[0]++;
	rep(0,i,41){
		if(nis[i]==1){
			bunsi=(bunsi*mody[i])%mod;
		}
	}
	return bunsi;
}
int yakuwa(int n){
	int sum=0;
	rep(1,i,sqrt(n+1)){
		if(n%i==0)sum+=i+n/i;
		if(i*i==n)sum-=i;
	}
	return sum;
}	
bool hei(int n){
	rep(0,i,100){
		if(i*i==n){
			return true;
		}
	}
	return false;
}
int pow(int b,int a){	
	int aa=1;
	rep(0,i,a)aa*=b;	
	return aa;
}
int a[114514];
int sum[114514];
signed main(){
	ic(n) ic(k)
	c(n-k+1)
}