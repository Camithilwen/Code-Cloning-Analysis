#include<bits/stdc++.h>
using namespace std;

int is_prime(int n){
  if(n<2) return 0;
  else if(n==2) return 1;
  else if(n%2==0) return 0;

  double sqrtNum = sqrt(n);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main(){
  int n;
  cin >> n;
  int cnt=0;
  int cal=11;
  vector<int> ans;
  while(cnt!=n){
    if(is_prime(cal)){
      if(cal%5==1){
        ans.push_back(cal);
        cnt++;
        //cout << cal << endl;
      }
    }

    cal++;
  }
  for(int i=0;i<n;++i){
    if(i!=n-1) cout << ans[i] << " ";
    else cout << ans[i] << endl;
  }

  return 0;
}
