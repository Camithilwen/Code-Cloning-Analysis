# include <iostream>
using namespace std;

int N;
int K;
int A[100005];
int maximum=0;
int factor;

int gcd (int a, int b)
{
    if (b==0)
    {
        return a;
    }

    else
    {
        return gcd(b, a%b);
    }
}

int main()
{
    cin>>N;
    cin>>K;

    for (int i=1; i<=N; i++)
    {
        cin>>A[i];
        maximum=max(maximum, A[i]);
        if (i==1)
        {
            factor=A[i];
        }

        else
        {
            factor=gcd(factor, A[i]);
        }
    }

    if (K>maximum)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    if (K%factor!=0)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    cout<<"POSSIBLE"<<endl;
}