#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <string>
#include <functional>
#include <cassert>
#include <cmath>
#define SIZE 200005
#define MOD 1000000007
 
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

char str[SIZE];

int main(){
    int n;
    scanf("%d", &n);
    scanf("%s", &str);
    
    char pre_s = str[0];
    int left = 1;
    int right = 0;
    int reverse = 1;
    ll ret = 1;
    for(int i=1; i<2*n; i++)
    {
        if(pre_s == str[i]) reverse *= -1;
        if(reverse == 1) left++;
        else if(reverse == -1)
        {
            ret = (ret * (left - right)) % MOD;
            right++;
        }
        pre_s = str[i];
    }
    if(left == right && (str[0] == 'B' || str[2*n-1] == 'B'))
    {
        for(int i=1;i<=n;i++) ret = (ret * i) % MOD;
    }
    else ret = 0;
    printf("%lld\n", ret);

    return 0;
}
