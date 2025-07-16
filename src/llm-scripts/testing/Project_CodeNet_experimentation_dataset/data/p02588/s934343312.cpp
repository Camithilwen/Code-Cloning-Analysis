#include <bits/stdc++.h>

int main() {
  int n; std::cin >> n;
  std::vector<std::string> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  // int n = 5;
  // std::vector<std::string> a{"7.5", "2.4", "17.000000001", "17", "16.000000000"};

  /* ピリオドをすべての文字列に加える */
  for (int i = 0; i < n; i++)
    if (a[i].find('.') == std::string::npos) // ピリオドの有無
      a[i].push_back('.');                   // ピリオドを末尾に加える
  
  /* key:val = (c2, c5):cnt */
  std::map<std::pair<int, int>, int> p;

  /* aの素因数2と5の数を数える */
  for (int i = 0; i < n; i++) {
    // a[i].length() => 文字列の長さ
    // a[i].find('.') => .(ピリオド)が存在すればその位置, なければstd::string::npos

    // std::cout << a[i] << " " <<  a[i].length() - a[i].find('.') - 1 << std::endl;
    /* 小数点以下の数 */
    int d_cnt = a[i].length() - a[i].find('.') - 1;
    int c2 = -d_cnt; // 2の数を-d_cntで初期化
    int c5 = -d_cnt; // 5の数を-d_cntで初期化
    
    /* 文字を数字に変換 */
    a[i].replace(a[i].find('.'), 1, ""); // .(ピリオド)を削除 str.replace(開始位置, 長さ, 置き換え後の新たな文字列)
    long long a_ll = std::stoll(a[i].c_str()); // long longに変換
    
    /* 2の数を取得 */
    while (a_ll%2 == 0) {
      ++c2;
      a_ll /= 2;
    }
    /* 5の数を取得 */
    while (a_ll%5 == 0) {
      ++c5;
      a_ll /= 5;
    }

    /* mapに key:val = (c2, c5):数 保持 */
    p[std::pair<int, int>(c2, c5)]++; // keyが存在しない場合は0が追加される
  }

  /* チェック */
  // for (auto itr = p.begin(); itr != p.end(); ++itr)
  //   // std::cout << "(" << (*itr).first.first << ", " << (*itr).first.second << ")" 
  //   //           <<  " " << (*itr).second << std::endl;
  //   std::cout << "(" << itr->first.first << ", " << itr->first.second << ")" 
  //             <<  " " << (*itr).second << std::endl;
  
  long long cnt = 0;
  for (auto itr_1 = p.begin(); itr_1 != p.end(); ++itr_1) {
    int c2_1 = itr_1->first.first;
    int c5_1 = itr_1->first.second;
    int cnt_1 = itr_1->second;

    if (c2_1 >= 0 && c5_1 >= 0)
      cnt += (long long)cnt_1 * (cnt_1-1)/2;

    // if (itr_1->first.first >= 0 && itr_1->first.second >= 0)
    //   cnt += itr_1->second*(itr_1->second-1)/2;

    for (auto itr_2 = std::next(itr_1, 1); itr_2 != p.end(); ++itr_2) {
    int c2_2 = itr_2->first.first;
    int c5_2 = itr_2->first.second;
    int cnt_2 = itr_2->second;
      if (c2_1 + c2_2 >= 0 && c5_1 + c5_2 >= 0)
        cnt += (long long)cnt_1 * cnt_2;
      // if (itr_1->first.first + itr_2->first.first >= 0 && itr_1->first.second + itr_2->first.second >= 0)
      //   cnt += itr_1->second * itr_2->second;
    }

  }
  std::cout << cnt << std::endl;


  return 0;
}