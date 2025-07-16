#include<bits/stdc++.h>
#define fo(i,a,b) for(int i= a ; i < b ; ++i)
#define rep(i,n) fo(i,0,n)
#define pln(n) printf("%lld\n",n)
#define sll(n) scanf("%lld",&n)
#define ss(n) scanf("%s",n)
#define vi vector < int >
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
#define dbg3(x,y,z) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) <<" , "<< #z <<": "<<(z)<<endl; }
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define vll vector<long long>
#define vvi vector<vector<int>>
#define si set<int>
#define tr(c, it) \
for(decltype(c.begin()) it = c.begin(); it!= c.end(); it++)
#define pis pair<int,string>
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c),x) != c.end())
#define mod (int)(1e9 + 7) 

using namespace std;
double dp[301][301][301];

double dfs(int a, int b, int c, int N){
	if(a == 0 && b == 0 && c == 0)return 0.0;
	if(dp[a][b][c] > -0.5)return dp[a][b][c];
	double res = 0;
	double ks = (double)N / (a + b + c);
	if(a){
		res += (ks + dfs(a-1,b,c, N)) * (double)(a)/(a + b + c);		
	}
	if(b){
		res += (ks + dfs(a+1,b-1,c, N)) * (double)(b)/(a + b + c);
	}
	if(c){
		res += (ks + dfs(a,b+1,c-1, N)) * (double)(c)/ (a + b + c);
	}
	return dp[a][b][c] = res;
}

int main(){
	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;
	vector<int> a(n);
	cout << fixed << setprecision(15);
	int one = 0;
	int two = 0;
	int three = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] == 1)one++;
		if(a[i] == 2)two++;
		if(a[i] == 3)three++;
	}
	// dp[i][j][k] = expected no of operations with i 1's , j 2's , k 3's
	double res = dfs(one, two, three, n);
	cout << res << endl; 
	
}