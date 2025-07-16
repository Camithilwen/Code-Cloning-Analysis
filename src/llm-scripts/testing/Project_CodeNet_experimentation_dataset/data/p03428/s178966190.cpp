#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
using namespace std;
using P = complex<double>;
using lli = long long int;
using T = lli;
bool cmp_x(const P& p, const P& q)
{
    if (p.real() != q.real())
        return p.real() < q.real();
    return p.imag() < q.imag();
}
T dot(P a, P b)
{
    //内積
    return (conj(a) * b).real();
}
T cross(P a, P b)
{
    //det
    return (conj(a) * b).imag();
}
vector<P> convex_hull(P* ps, int n)
{
    sort(ps, ps + n, cmp_x);
    int k = 0;
    vector<P> qs(n * 2);
    rep(i, n)
    {
        while (k > 1 && cross((qs[k - 1] - qs[k - 2]), (ps[i] - qs[k - 1])) <= 0)
            k--;
        qs[k++] = ps[i];
    }
    for (int i = n - 2, t = k; i >= 0; i--) {
        while (k > t && cross((qs[k - 1] - qs[k - 2]), (ps[i] - qs[k - 1])) <= 0)
            k--;
        qs[k++] = ps[i];
    }
    qs.resize(k - 1);
    return qs;
}
P x[100005];
int main()
{
    int n;
    cin >> n;
    T a, b;

    map<lli,map<lli,int>> idx;
    map<lli,map<lli,int>> prev;


    vector<P> Y;
    rep(i, n)
    {
        cin >> a >> b;
        x[i] = P(a, b);
        Y.push_back(x[i]);
        prev[a][b] = i;
    }
    
    vector<P> con = convex_hull(x, n);
    if(n==2){
        cout << 0.5 << "\n" << 0.5 << endl;
        return 0;
    }
    int cnt = 0;
    for(auto s:con)
    {
        idx[s.imag()][s.real()] = cnt++;
    }
    int k = con.size();
    vector<double> ans ;
    rep(i,n){
        if(idx[Y[i].imag()].find(Y[i].real())==idx[Y[i].imag()].end()){
            ans.push_back(0.0);
            continue;
        }
        int id = idx[Y[i].imag()][Y[i].real()];
        P l = con[(id-1+k)%k];
        P c = Y[i];
        P r = con[(id+1+k)%k];
        using Pd = complex<double>;
        Pd l_c = (l+c);l_c/=2.0;
        Pd r_c = (r+c);r_c/=2.0;
        double rad =    M_PI - abs(arg((r_c - c) / (l_c - c)));
        ans.push_back(rad);
    }
    double total = 0.0;
    rep(i,n)total += ans[i];
    rep(i,n){
        printf("%.10f\n",ans[i]/total);
    }
}
