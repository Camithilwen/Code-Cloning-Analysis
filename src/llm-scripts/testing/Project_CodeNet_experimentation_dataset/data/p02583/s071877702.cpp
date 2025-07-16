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
#define f1(i,a) for(int i=0;i<a;++i)
#define f2(i,a) for(int i=a-1;i>=0;--i)
#define pi acos(-1)
#define mod 1000000007
#define TRUE 1
#define FALSE 0
#define ZERO 0
#define MP make_pair
#define F first
#define S second

#define END puts("");
#define elif else if
typedef ll int lli;
typedef sll int slli;
typedef ull int ulli;
const int sz=10000;
using namespace std;

int clue();
int result();
void show();
bool check();

int main() {
    clue();
    return 0;
}
int clue() {


    //O(n^3) solution

    int n;
    cin>>n;
    lli a[n];
    f1(i,n) {
        cin>>a[i];
    }

    lli count=0;
    lli p,q,r;
    f1(i,n-2) {
        for(int j=i+1;j<n-1;++j) {
            for(int k=j+1;k<n;++k) {
                if(a[i]!=a[j]&&a[j]!=a[k]&&a[i]!=a[k]) {
                    p=a[i]+a[j];
                    q=a[j]+a[k];
                    r=a[k]+a[i];
                    if(p>a[k]&&q>a[i]&&r>a[j]) {
                        ++count;
                    }
                }
            }
        }
    }

    cout<<count<<endl;
    return 0;
}