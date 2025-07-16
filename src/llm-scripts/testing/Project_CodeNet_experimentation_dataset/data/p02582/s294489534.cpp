#include<bits/stdc++.h>

#define EB emplace_back
#define int long long
#define F first
#define S second
#define N 500005
#define all(x) x.begin(),x.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

#define rt return

void test_case(){
  
  string s; cin >> s;
  int cnt = 0, ans = 0;
  for(int i = 0; i < 3; i++){
    if(s[i] == 'R') cnt++;
    else{
      ans = max(ans, cnt);
      cnt = 0;
    }
  }
  ans = max(ans, cnt);
  cout << ans;
}

int32_t main(){
	IOS;
	int tt = 1; 
	//cin >> tt;
	while(tt--){
    test_case();
    cout << endl;
	}
	return 0;
}
