#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;  cin >> n;
  vector<long long>a(n);  for(int i=0;i<n;i++)  cin >> a.at(i);
  vector<long long>b(n);  for(int i=0;i<n;i++)  cin >> b.at(i);
  vector<long long>c(n);  for(int i=0;i<n;i++)  cin >> c.at(i);
  sort(a.begin(),a.end());
  sort(c.begin(),c.end());

  long long ans = 0;
  for(int i=0;i<n;i++){
    auto Iter = lower_bound(a.begin(),a.end(),b.at(i));
    long long count_a = Iter - a.begin();

    Iter = upper_bound(c.begin(),c.end(),b.at(i));
    long long count_c = n - (Iter - c.begin());

    ans += count_a * count_c;
  }
  cout << ans << endl;
}