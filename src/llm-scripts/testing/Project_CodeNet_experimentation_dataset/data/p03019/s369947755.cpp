#include <algorithm>
#include <cmath>
#include <iostream>

#define MAX_N 100000

using namespace std;

struct Test
{
    long long score, upper, lower;

    long long sum();
};

Test tests[MAX_N];
long long cum[MAX_N + 1];
long long N, X;
long long aokiScore;

bool cmp( Test u, Test v ) { return u.sum() > v.sum(); }

long long Test::sum() { return upper * ( X - score ) + lower * score; }

bool isok( long long k )
{
    long long q = k / X;
    long long r = k % X;

    if ( q == N ) return true;

    long long total = cum[q];

    for ( int i = 0; i < N; ++i )
    {
        long long tmp = total;

        if ( i < q )
        {
            tmp -= tests[i].sum();
            tmp += tests[q].sum();
        }

        tmp += min( r, tests[i].score ) * tests[i].lower;
        tmp += max( 0LL, r - tests[i].score ) * tests[i].upper;

        if ( tmp >= aokiScore ) return true;
    }

    return false;
}

int main()
{
    N = 0;
    aokiScore = 0;
    cin >> N >> X;

    for ( int i = 0; i < N; ++i )
    {
        cin >> tests[i].score >> tests[i].lower >> tests[i].upper;
        aokiScore += tests[i].score * tests[i].lower;
    }

    sort( tests, tests + N, cmp );

    for ( int i = 0; i < N; ++i ) cum[i + 1] = cum[i] + tests[i].sum();

    long long l = 0;
    long long r = N * X;

    while ( l < r )
    {
        long long mid = ( l + r ) / 2;

        if ( isok( mid ) )
            r = mid;
        else
            l = mid + 1;
    }

    cout << l << endl;

    return 0;
}
