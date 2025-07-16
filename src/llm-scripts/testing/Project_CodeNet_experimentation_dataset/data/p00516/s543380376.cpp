#include <bits/stdc++.h>
 
using namespace std;

int N, M, A[1111], B[1111], V[1111];
 
int main()
{
    cin >> N >> M;
 
    for (int i = 1; i <= N; i++)
        cin >> A[i];
 
    for (int i = 1; i <= M; i++)
        cin >> B[i];
 
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; i <= N; j++)
        {
            if (A[j] <= B[i])
            {
                V[j]++;
 
                break;
            }
        }
    }
 
    cout << distance(V, max_element(V, V + N)) << endl;
 
    return 0;
}