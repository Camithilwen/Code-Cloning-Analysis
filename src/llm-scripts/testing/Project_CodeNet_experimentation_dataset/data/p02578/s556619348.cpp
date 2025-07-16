#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using Vec = vector<int>;

int mod=1000000007;

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; 
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}


int main(){

int n;
ll sum=0;
cin>>n;
Vec vec(n);
for(int i=0;i<n;i++){
    cin>>vec[i];
}
for(int i=0;i<n-1;i++){
  if(vec[i]>vec[i+1]){
      sum+=vec[i]-vec[i+1];
      vec[i+1]=vec[i];
  }

}
cout<<sum<<endl;

}
