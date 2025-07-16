#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>
#include<set>
using namespace std;
long long int mpown(long long int m, int n);
long long int bign=1000000007;
int bitCount(int bits);

int main()
{
    long long int n,m,k;
    cin >> n >> m >> k;
    // vector<vector<long long int>> comb(n*m,vector<long long int>(k-1,0));
    // vector<long long int> comb(max(n,m));
    long long int comb = 1;
    if(k!=2){
    vector<long long int> inv(k-1);
    inv.at(1)=1;
    // cout << "a"<<endl;
    for(int i=2;i<k-1;i++){
        inv.at(i) = bign-inv.at(bign%i)*(bign/i)%bign;
    }
    
    
    for(int i=1;i<=k-2;i++){
        comb = (((comb*(n*m-2-i+1))%bign)*inv.at(i))%bign;
    }
    }
    long long int ans=0;
    long long int temp=0;
    // comb.at(0).at(0)=1;
    // for(long long int i=1;i<n*m-1;i++){
    //     for(long long int j=0;j<=min(k-2,i);j++){
    //         // cout << "a " << endl;
    //         comb.at(i).at(j)=(j>0? (comb.at(i-1).at(j-1)+comb.at(i-1).at(j))%bign:comb.at(i-1).at(j));
    //         // cout << i << "," << j << "," << comb.at(i).at(j) << endl;
    //     }
    // }


    for(int d=1;d<=n-1;d++){
        
        temp = ((((((comb*d)%bign)*m)%bign)*m)%bign)*(n-d);
        temp %= bign;
        ans=(ans+temp)%bign;
    }
    for(int d=1;d<=m-1;d++){
        temp = ((((((comb*d)%bign)*n)%bign)*n)%bign)*(m-d);
        temp %= bign;
        ans=(ans+temp)%bign;
    }
    cout << ans << endl;
    
    return 0;
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