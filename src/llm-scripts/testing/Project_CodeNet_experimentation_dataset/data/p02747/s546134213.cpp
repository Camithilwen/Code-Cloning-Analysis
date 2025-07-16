#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define repo(i,N) for(int i = 1; i < (N); i++)
//#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
//#define num 1000000007
#define pi acos(-1.0)
//cout << fixed << setprecision (10);   小数点以下１０桁まで
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'大文字'+=32;    で小文字に
//string s = to_string(int数);
//int n = stoi(string文字列);

int main() {
  string a;
  cin >>a;
  
  cout << (a=="hi" || a=="hihi" || a=="hihihi" ||
           a=="hihihihi" || a=="hihihihihi"?"Yes":"No") << endl;
  
}
