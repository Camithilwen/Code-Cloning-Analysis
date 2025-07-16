#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    int i;
    long double sum=0;
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
        sum+=a[i];
    }
    const long double eps=1e-12;
    long double min=HUGE_VAL;
    int mini=0;
    sum/=n;
    for(i=0; i<n; i++) {
        double tmp=fabs(a[i]-sum);
        if(tmp<min-eps) {
            min=tmp;
            mini=i;
        }
    }
    printf("%d\n", mini);

    return 0;
}

