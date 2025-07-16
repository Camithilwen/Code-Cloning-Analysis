#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5;
const int MAXM = 100;

int N, M;
vector<int> V1, V2, A, B;

int main()
{
    int i, j;

    scanf("%d%d", &N, &M);
    int cnt=0;
    for(i=1; i<=M; i++)
    {
        int X; scanf("%d", &X);
        if(X%2) V2.push_back(X), cnt++;
        else V1.push_back(X);
    }
    if(cnt>2) return !printf("Impossible");

    if(cnt>0) A.push_back(V2[0]);
    for(i=0; i<V1.size(); i++) A.push_back(V1[i]);
    if(cnt>1) A.push_back(V2[1]);

    if(A.size()==1)
    {
        if(A[0]>1) B.push_back(A[0]-1);
        B.push_back(1);
    }
    else
    {
        B.push_back(A[0]+1);
        for(i=1; i+1<A.size(); i++) B.push_back(A[i]);
        if(A.back()>1) B.push_back(A.back()-1);
    }

    for(i=0; i<A.size(); i++) printf("%d ", A[i]);
    printf("\n%d\n", B.size());
    for(i=0; i<B.size(); i++) printf("%d ", B[i]);
}
