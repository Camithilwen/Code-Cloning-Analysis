#include <bits/stdc++.h>

using namespace std;

const int lim = 4e4, Nmax = 505;
typedef long long ll;

int i, j;
ll a[Nmax][Nmax];
vector<int> primes;
bool used[lim+2];

void run_primes()
{
    int i;
    for(i=2; i<=lim; ++i)
        if(!used[i])
        {
            primes.push_back(i);
            for(j=i*i; j<=lim; j+=i) used[j] = 1;
        }
}

int main()
{
   // freopen("input", "r", stdin);

    run_primes();

    int n, N;
    cin >> N;
    n = N + ((N&1)^1);

    for(i=0; i<n; ++i)
        for(j=0; j<n; ++j)
            if(!((i+j)&1)) a[i][j] = (ll) primes[(i+j)/2] * primes[(i-j)/2 + n + 1];

    for(i=0; i<n; ++i)
        for(j=0; j<n; ++j)
            if((i+j)&1)
            {
                if(j && j<n-1) a[i][j] = a[i][j-1] * a[i][j+1] + 1;
                    else a[i][j] = a[i-1][j] * a[i+1][j] + 1;
            }

    for(i=0; i<N; ++i)
        for(j=0; j<N; ++j)
            cout << a[i][j] << " \n"[j==N-1];

    return 0;
}
