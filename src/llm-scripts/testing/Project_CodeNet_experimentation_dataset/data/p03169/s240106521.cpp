#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

typedef long int ll;

double solve(vector<vector<vector<double>>>& dp,vector<vector<vector<bool>>>& memo,int a,int b,int c,int n)
{

    if (a<0 || b<0 || c<0) return 0;
    if (a==0 && b==0 && c==0) return 0;

    if (memo[a][b][c]) return dp[a][b][c];


    double den = double(a) + double(b) + double(c);

    double A = (double(a)/den) * solve(dp,memo,a-1,b,c,n);

    double B = (double(b)/den) * solve(dp,memo,a+1,b-1,c,n);

    double C = (double(c)/den) * solve(dp,memo,a,b+1,c-1,n);

    memo[a][b][c] = true;

    double ex = double(n)/den;
    dp[a][b][c] = A + B + C + ex;

    //cout<<dp[a][b][c]<<endl;

    return dp[a][b][c];
}

int main()
{
    int N;
    cin>>N;

    int a = 0;
    int b = 0;
    int c = 0;

    for (int i=0;i<N;++i)
    {
        int x;
        cin>>x;

        if (x==1) ++a;
        if (x==2) ++b;
        if (x==3) ++c;
    }

    vector<vector<vector<double>>> dp(N+1,vector<vector<double>>(N+1,vector<double>(N+1)));
    vector<vector<vector<bool>>> memo(N+1,vector<vector<bool>>(N+1,vector<bool>(N+1)));

    cout<<setprecision(14)<<solve(dp,memo,a,b,c,N)<<endl;

    return 0;
}
