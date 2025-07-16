#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

bool check(string s){
  if(s == "Vacant") return true;
  else return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  cout << 0 << endl;
  vector<string> s(n);
  cin >> s[0];
  if(check(s[0])) return 0;  
  cout << n-1 << endl;
  cin >> s[n-1];
  if(check(s[n-1])) return 0;
  int lb =0;
  int ub = n-1;
  while(ub - lb>1){
    int mid = (ub+lb)/2;
    cout << mid << endl;
    cin >> s[mid];
    if(check(s[mid])) return 0;
    if((mid - lb)%2==0){
      if(s[mid]==s[lb]){
        lb = mid;
      }
      else{
        ub = mid;
      }
    }
    else{
      if(s[mid]!=s[lb]){
        lb = mid;
      }
      else{
        ub = mid;
      }
    }
  }
  cout << ub << endl;
  cin >> s[ub];
  if(check(s[ub])) return 0;
  cout << lb << endl;
  cin >> s[lb];
  return 0;
    

}
