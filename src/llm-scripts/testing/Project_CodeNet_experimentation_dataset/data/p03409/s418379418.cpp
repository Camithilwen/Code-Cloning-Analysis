#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define DD double
#define Pb push_back
#define Bp pop_back
#define Pf push_front
#define Fp pop_front
#define Ub upper_bound
#define Lb lower_bound
#define In insert
#define All(x) x.begin(), x.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define X first
#define Y second
#define mx1 10
#define mx2 110
#define mx3 1010
#define mx4 10010
#define mx5 100010
#define mx6 1000010

typedef vector<LL> Vl;
typedef vector<DD> Vd;
typedef vector<bool> Vb;
typedef vector<Vl> VVl;
typedef pair<LL, LL> Pll;
typedef pair<DD, DD> Pdd;
typedef vector<Pll> Vpl;
typedef vector<Pdd> Vpd;
typedef queue<LL> Ql;
typedef stack<LL> Sl;
typedef deque<LL> Dl;

LL _set(LL N, LL pos) {return N = N | (1 << pos);}
LL _reset(LL N, LL pos) {return N = N & ~(1 << pos);}
bool _check(LL N, LL pos) {return (bool)(N & (1 << pos));}
bool _upper(char a) {return a >= 'A' && a <= 'Z';}
bool _lower(char a) {return a >= 'a' && a <= 'z';}
bool _digit(char a) {return a >= '0' && a <= '9';}

LL dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
LL dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

///**************************DONE****************************///

typedef struct
{
    int x, y, col;
} pt;

bool cmp(pt A, pt B)
{
    if(A.x != B.x)
        return A.x < B.x;
}

pt P[2 * mx2];

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> P[i].x >> P[i].y, P[i].col = 1;
    for(int i = n; i < 2 * n; i++)
        cin >> P[i].x >> P[i].y, P[i].col = 2;

    sort(P, P + 2 * n, cmp);

    priority_queue<int> pq;
    int ans = 0;
    for(int i = 0; i < 2 * n; i++){
        if(P[i].col == 2){
            if(pq.size() == 0)
                continue;

            queue<int> q;
            while(!pq.empty()){
                int t = pq.top();
                pq.pop();

                if(t < P[i].y){
                    ans++;
                    break;
                }

                q.push(t);
            }

            while(!q.empty()){
                int t = q.front();
                pq.push(t);
                q.pop();
            }
        }
        else
            pq.push(P[i].y);
    }

    cout << ans << '\n';
    return 0;
}
