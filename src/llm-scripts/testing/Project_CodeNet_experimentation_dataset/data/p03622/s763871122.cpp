///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
//                       _oo0oo_                         //
//                      o8888888o                        //
//                      88" . "88      ------ hzt1       //
//                      (| -_- |)                        //
//                      0\  =  /0                        //
//                    ___/`---'\___                      //
//                  .' \|     |// '.                     //
//                 / \|||  :  |||// \                    //
//                / _||||| -:- |||||- \                  //
//               |   | \  -  /// |     |                 //
//               | \_|  ''\---/''  |_/ |                 //
//               \  .-\__  '-'  ___/-. /                 //
//             ___'. .'  /--.--\  `. .'___               //
//          ."" '<  `.___\_<|>_/___.' >' "".             //
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |           //
//         \  \ `_.   \_ __\ /__ _/   .-` /  /           //
//     =====`-.____`.___ \_____/___.-`___.-'=====        //
//                       `=---='                         //
//                                                       //
//                                                       //
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~       //
//                                                       //
//                 God-He Bless All.                     //
//           This Code Will Never Explode.               //
//                                                       //
//                                                       //
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<vector>
#define pb push_back
#define mp make_pair
#define xx first
#define yy second
#define rep(i,a,b) for(int i=(a),i##_end_=(b);i<=i##_end_;i++)
#define dwn(i,a,b) for(int i=(a),i##_end_=(b);i>=i##_end_;i--)
using namespace std;
const int Size=1<<16;
char buffer[Size],*head,*tail;
inline char Getchar() {
    if(head==tail) {
        int l=fread(buffer,1,Size,stdin);
        tail=(head=buffer)+l;
    }
    if(head==tail) return -1;
    return *head++;
}
inline int read() {
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    return x*f;
}
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1000010;
const int mod=998244353;
int fac[maxn],ifac[maxn];
int reC(int n,int m) {return (ll)ifac[n]*fac[m]%mod*fac[n-m]%mod*ifac[2]%mod;}
int C(int n,int m) {return (ll)fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
void init(int n) {
	ifac[0]=ifac[1]=fac[0]=1;
	rep(i,1,n) fac[i]=(ll)fac[i-1]*i%mod;
	rep(i,2,n) ifac[i]=(ll)(mod-mod/i)*ifac[mod%i]%mod;
	rep(i,1,n) ifac[i]=(ll)ifac[i-1]*ifac[i]%mod;
}
int main() {
	int n,m;
	n=read();m=read();init(n+m);
	int ans=0;
	rep(i,1,min(n,m)) (ans+=(ll)C(2*i,i)*C(n+m-2*i,n-i)%mod)%=mod;
	ans=(ll)ans*reC(n+m,n)%mod;
	printf("%d\n",(ans+max(n,m))%mod);
	return 0;
}
