#include <string>
#include <vector>
using namespace std;

vector<int> border(vector<int> S)
{
    int n = (int)S.size();
    vector<int> B(n+1);

    B[0] = -1;
    int j = -1;
    for (int i=1; i<=n; i++)
    {
        while (j>=0 && S[i-1]!=S[j])
            j = B[j];
        j++;
        B[i] = j;
    }

    return B;
}

//  B = border(P)
vector<int> search(vector<int> T, vector<int> P, vector<int> B)
{
    int n = (int)T.size();
    int m = (int)P.size();

    vector<int> A;
    int j = 0;
    for (int i=0; i+m<=n;)
    {
        if (j<m && T[i+j]==P[j])
        {
            j++;
            if (j==m)
                A.push_back(i);
        }
        else
        {
            i += j-B[j];
            if (j>0)
                j = B[j];
        }
    }
    return A;
}

#include <iostream>

int main()
{
    int N;
    cin>>N;
    vector<int> a(N), b(N);
    for (int &t: a)
        cin>>t;
    for (int &t: b)
        cin>>t;

    vector<int> ax(N), bx(N);
    for (int i=0; i<N; i++)
    {
        ax[i] = a[i]^a[(i+1)%N];
        bx[i] = b[i]^b[(i+1)%N];
    }
    for (int i=0; i<N-1; i++)
        ax.push_back(ax[i]);

    vector<int> K = search(ax, bx, border(bx));
    for (int k: K)
        cout<<k<<" "<<(a[k]^b[0])<<endl;
}
