#include <bits/stdc++.h>
using namespace std;
#define read(n) cin>>n;
#define write(n) cout<<n;
#define loop(x,n) for(int x = 0; x < n; ++x)
#define vector_loop(x,n) for(int i = 0; x < n; i++)
#define vii vector<int> a(n)
typedef pair<int, int> pii;
#define endl "\n"
#define sd(val) scanf("%d", &val)
#define ss(val) scanf("%s", &val)
#define sl(val) scanf("%lld", &val)
#define debug(val) printf("check%d\n", val)
#define all(v) v.begin(), v.end()
#define MP make_pair
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
#define clr(val) memset(val, 0, sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl;
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
	FIO;
	
	int a;
	cin >> a;
	cout << a + a*a + a*a*a;




	return 0;
}