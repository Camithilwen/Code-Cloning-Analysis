#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

bool isprime(int num)
{
    for(int i = 2; i*i <=num; i++)
    {
        if(num%i==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;cin >> n;
    vector<int> a(n);
    int counter = 0;
    int kouho = 6;
    while(counter < n)
    {
        if(isprime(kouho))
        {
            a[counter] = kouho;
            counter++;
        }
        kouho += 5;
        
    }
    rep(i,n)
    {
        cout << a[i] << " ";
    }
    cout  << endl;
}