#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int n;
  cin >> n;
  int odd[100002]={}, even[100002]={};
  int omax=0, emax=0, io, ie;
  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    if(i%2==0){
      odd[a]++;
      if(odd[a]>omax){
        omax = odd[a];
        io = a;
      }
    }else{
      even[a]++;
      if(even[a]>emax){
        emax = even[a];
        ie = a;
      }
    }
  }
  sort(odd, odd+100000, greater<int>());
  sort(even, even+100000, greater<int>());
  int ans;
  if(io!=ie) ans = n - omax - emax;
  else ans = n - max(omax+even[1], odd[1]+emax);
  cout << ans << endl;
  return 0;
}
