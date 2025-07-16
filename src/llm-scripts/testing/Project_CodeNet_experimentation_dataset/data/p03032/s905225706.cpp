#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;
long long int mpown(long long int m, int n);

int bitCount(int bits);
int main()
{
    int n,k;
    cin >> n >>k;
    vector<long long int> v(n);
    for(int i=0;i<n;i++)cin >> v.at(i);
    // vector<vector<long long int>> dp(n+1,vector<long long int>(n+1,0));
    // vector<vector<long long int>> dpm(n+1,vector<long long int>(n+1,0));
    // vector<vector<long long int>> dpmn(n+1,vector<long long int>(n+1,0));
    // dp.at(i).at(j) : 左からi個，右からj個とったときの価値の合計
    // dpmn.at(i).at(j) : 左からi個，右からj個とったときの負の宝石の数
    // dpm.at(i).at(j) : 左からi個，右からj個とったときの負の価値の合計
    int r = min(n,k);
    priority_queue<long long int> mns;
    long long int sv=0;
    long long int temp;
    long long int ans=(-1000000000000);
    for(int a=0;a<=n;a++){
        for(int b=0;b<=r-a;b++){
            
            sv=0;
            priority_queue<long long int> mns;
            for(int i=0;i<a;i++){
                sv+=v.at(i);
                if(v.at(i)<0)
                mns.push(-v.at(i));
            }
            for(int j=0;j<b;j++){
                sv+=v.at(n-j-1);
                if(v.at(n-j-1)<0)
                mns.push(-v.at(n-j-1));
            }
            for(int i=0;i<k-(a+b);i++){
                if(mns.empty()){break;}
                sv+=mns.top();
                mns.pop();
            }
            

            if(ans<sv){ans=sv;
            // cout << a << " " << b << endl;
            }
        }
    }
    cout << ans << endl;
}

int bitCount(int bits)
{
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555); //  2bitごとに計算
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333); //  4bitごとに計算
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f); //  8bitごとに計算
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff); //  16ビットごとに計算
    return (bits & 0x0000ffff) + (bits >> 16);             //  32ビット分を計算
}
long long int mpown(long long int m, int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return m;
    else
    {
        long long int temp = mpown(m, n / 2);
        return temp * temp * (n & 1 ? m : 1);
    }
}