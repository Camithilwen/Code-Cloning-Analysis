//https://codeforces.com/blog/entry/64250?#comment-576206

#include<bits/stdc++.h>
#define ll double

ll dp[301][301][301];
ll solve(int one, int two, int three, int& n)
{
    if(one < 0 || two < 0 || three < 0)
        return 0;
    if(three == 0 && two == 0 && one == 0)
        return 0;
 
    if(dp[one][two][three] > 0)
        return dp[one][two][three];
 
    int remaining = one + two + three;
    ll exp_val = n + one * solve(one - 1, two, three, n) 
                   + two * solve(one + 1,two - 1, three, n) 
                   + three * solve(one, two + 1, three - 1, n);
 
    return dp[one][two][three] = exp_val / remaining;
}
 
int main()
{
    using namespace std;
    int n;
   
    cin >> n;
  
    int one = 0, two = 0, three = 0;

    for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if(x == 1) one++;
      else if(x == 2) two++;
      else three++;
    }

    memset(dp, -1, sizeof(dp));
   
    cout << fixed << setprecision(9) << solve(one, two, three, n);
    
    return 0;
}
