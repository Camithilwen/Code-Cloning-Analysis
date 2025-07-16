 #include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int a[n];
  for(int i=0;i<n;i++){
  	cin >> a[i];
  }
  int len=0;
  sort(a,a+n);
  for(int i=n-1;i>=n-k;i--){
  	len+=a[i];
  }
  cout << len << endl;
}

