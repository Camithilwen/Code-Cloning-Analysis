#include <bits/stdc++.h>
using namespace std;

int main(){

  int N,Q;
  string S;

  cin >> N;
  cin >> S;
  cin >> Q;

  vector<int> k(Q);
  for (int i = 0; i < Q ; i++){
    cin >> k.at(i);
  }

  for (int i = 0; i < Q ; i++){

    long long dnum = 0,mnum = 0,dmnum = 0,ans = 0;

    for (int j = 0 ; j < N ; j++){

      if (j >= k.at(i)){

	if (S.at(j-k.at(i)) == 'D'){
	  dnum -= 1;
	  dmnum -= mnum;
	}else if (S.at(j-k.at(i)) == 'M'){
	  mnum -= 1;
	}
      }

      if (S.at(j) == 'D'){
	dnum += 1;
      }else if (S.at(j) == 'M'){
	mnum += 1;
	dmnum += dnum;
      }else if (S.at(j) == 'C'){
	ans += dmnum;
      }

    }

    cout << ans << endl;

  }

  return 0;
}
