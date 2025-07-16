#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int now[4];
char C[4], op[2] = {'+', '-'};

int main(){
  for (int i = 0; i < 4; i++){
    cin >> C[i];
    now[i] = C[i] - '0';
  }

  for (int i = 0; i < 8; i++){
    int val = now[0], num = i;

    for (int j = 1; j < 4; j++){
      val += pow(-1, num % 2) * now[j];
      num /= 2;
    }

    if (val == 7){
      num = i;
      cout << now[0];
      for (int j = 1; j < 4; j++){
        cout << op[num%2] << now[j];
        num /= 2;
      }

      cout << "=7" << endl;

      return 0;
    }

  }

  return 0;
}
