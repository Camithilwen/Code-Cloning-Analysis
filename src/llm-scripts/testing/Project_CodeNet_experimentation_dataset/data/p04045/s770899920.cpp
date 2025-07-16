#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

bool CheckPayable(int x, vector<int> D){
  // x中にDが含まれていなければtrue,含まれていればfalse
  while(x>0){
    for(int i=0;i<D.size();i++){
      if(x%10 == D[i])return false;
    }
    x /= 10;
  }
  return true;
}

int main(){
  int N,K;
  cin >> N >> K;
  // N < 10000なので全列挙でもイケる？
  vector<int> D(K);
  rep(i,K)cin >> D[i];

  int ans = N;
  while(true){
    if(CheckPayable(ans, D)){
      cout << ans << endl;
      break;
    }
    ans++;
  }

}

/*
1:条件から支払い可能な数字を列挙してN以上であれば出力する
2:Nから支払額を1ずつ大きくして支払い可能であれば出力する全列挙
1の組み合わせのCpp実装むずそうなので2の方針で

数字の支払い可能か如何をどうやって判別しよう
*/