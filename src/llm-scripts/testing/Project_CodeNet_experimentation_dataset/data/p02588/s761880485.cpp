#include <bits/stdc++.h>
typedef long long       ll;
#define PI                acos(-1)
#define pb                push_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
#define fore(i,b,e)		  for(int i=(int)b;i<(int)e;++i)
#define forr(i,b,e)		  for(int i=(int)b;i<(int)e;++i)
int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
const int INF = 1234567890;

ll toLL(string s) {
	ll res = 0;
	fore (i,0,s.length()) {
		res *= 10LL;
		res += s[i] - '0';
	}
	return res;
}

ll pot[45][20][10];

int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int n;
    cin >> n;
    ll res = 0;
    fore(i, 0, n) {
    	string s;
    	cin >> s;
    	int decimal = 0;
    	fore(j, 0, s.length()) {
    		decimal++;
    		if (s[j] == '.') {
    			decimal = 0;
    		}
    	}
    	if (decimal == (int)s.length()) {
    		decimal = 0;
    	}
    	string s2 = "";
    	fore(j, 0, s.length()) {
    		if (s[j] != '.') {
    			s2 += s[j];
    		}
    	}
    	ll a = toLL(s2);
    	int p2 = 0, p5 = 0;
    	while (a%2 == 0) {
    		p2++;
    		a /= 2;
    	}
    	while (a%5 == 0) {
    		p5++;
    		a /= 5;
    	}
    	//cout << "2^" << p2 << " 5^" << p5 << " con " << decimal << " decimales" << endl << endl;
		pot[p2][p5][decimal]++;
		//if (min(p2, p5) >= decimal*2) res--;
    }
    ll ans = 0;
    res = 0;
    fore(a, 0, 45) {
    	fore(b, 0, 20) {
    		fore(c, 0, 10) {
    			fore(x, 0, 45) {
    				fore(y, 0, 20) {
    					fore(z, 0, 10) {
    						if (x == a && y == b && z == c) {
    							if (pot[a][b][c] > 1 && min(2*a, 2*b) >= 2*c) {
    								ans += pot[a][b][c] * (pot[a][b][c]-1) / 2;
    							}
    						}
    						else if ( min( a+x, b+y ) >= c + z ) {
    							res += pot[a][b][c] * pot[x][y][z];
    						}
    					}
    				}
    			}
    		}
    	}
    }
    cout << res/2 + ans << '\n';
    return 0; 
}
// PLUS ULTRA!