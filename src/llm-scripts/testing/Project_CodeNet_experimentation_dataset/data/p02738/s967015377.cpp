#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    cin>>N>>M;

    vector<vector<long long>> T(3*N, vector<long long>(6*N+1));
    T[0][3*N+1] = 1;
    T[1][3*N-1] = 1;
    T[2][3*N] = 2;
    for (int i=0; i<3*N; i++)
        for (int j=0; j<=6*N; j++)
            if (T[i][j]>0)
                for (int k=1; k<=3; k++)
                    if (i+k<3*N)
                    {
                        long long c = 1;
                        for (int l=0; l<k-1; l++)
                            c *= i+l+2;
                        int d = int(k==1) - int(k==2);
                        T[i+k][j+d] += c*T[i][j];
                        T[i+k][j+d] %= M;
                    }
    long long ans = 0;
    for (int i=3*N; i<=6*N; i++)
    {
        ans += T[3*N-1][i];
        ans %= M;
    }
    cout<<ans<<endl;
}
