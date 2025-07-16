#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);
#define ADD +
#define SUBTRACT -
#define MULTIPLY *
#define DIVIDE /
#define MOD %
#define INCREMENT(x) ++x
#define DECREMENT(x) --x
#define in(a,b) cin>>a>>b;
#define out(a,b) cout<<a<<endl<<b<<endl;
#define scan(a) scanf("%d",&a);
#define print(a) printf("%d\n",a);
#define scanii(a,b) scanf("%d %d",&a,&b);
#define printii(a,b) printf("%d\n%d\n",a,b);
#define scaniii(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define ll long long
#define ull unsigned long long
#define sll signed long long
#define pi acos(-1)
#define mod 1000000007
#define TRUE 1
#define FALSE 0
#define ZERO 0
#define MP make_pair
#define F first
#define S second
#define f1(i,a) for(int i=0;i<a;++i)
#define f2(i,a) for(int i=a-1;i>=0;--i)
#define en puts("");
#define elif else if
typedef ll int lli;
typedef sll int slli;
typedef ull int ulli;
const int sz=10000;
using namespace std;

int clue();
int result();
void show();
bool check(int n) {
    for(int i=2;i*i<=n;++i) {
        if(n%i==0)
        return false;
    }
    return true;
}


// bool cmp(pair<int,int>p,pair<int,int>q) {
//     // return p.first>q.first;//descending by first
//     // return p.first<q.first;//ascending by first
//     // return p.second>q.second;//descending by second
//     return p.second<q.second;//ascending by second
// }

bool cmp(int p,int q) {
    return p>q;//descending
    // return p<q;//ascending
}


int main() {

    int t;
    // cin>>t;
    t=1;
    while(t-->0) {
        clue();
    }

    return 0;
}
int clue() {

    string s;
    cin>>s;
    int cnt;
    if(s=="SUN") {
        cnt=7;
    }
    elif(s=="MON") {
        cnt=6;
    }
    elif(s=="TUE") {
        cnt=5;
    }
    elif(s=="WED") {
        cnt=4;
    }
    elif(s=="THU") {
        cnt=3;
    }
    elif(s=="FRI") {
        cnt=2;
    }
    elif(s=="SAT") {
        cnt=1;
    }

    cout<<cnt<<endl;

    
    // ()?cout<<"1"<<endl:cout<<"0"<<endl;
    
    return 0;
}