#include <bits/stdc++.h>
using namespace std;
const int inf = 1001001001;
int main(){
	string str;
  	cin >> str;
  	vector<int> num;
  	for(int i=0;i<str.size();i++){
      num.push_back(str.at(i)-'0');
    }
  	
  	reverse(num.begin(),num.end());
  	num.push_back(0);
  	int n=num.size();	
  
  	// 下からi桁目までに使用する紙幣の最小
  	// j=0のときは繰り下がりなし、j=1のときは繰り下がりあり
  	vector<vector<int>> dp(n+1,vector<int>(2));
  	for(int i=0;i<n+1;i++){
      for(int j=0;j<2;j++){
        dp.at(i).at(j) = inf;
      }
    }
  	dp.at(0).at(0) = 0;
  
  	//状態(i,j)が確定しているときに状態(ni,nj)を計算する
  	for(int i=0;i<n;i++){
      for(int j=0;j<2;j++){
        int x = num.at(i);
        x += j;
        for(int a=0;a<10;a++){
          int ni = i+1;
          int nj = 0;
          int b = a-x;
          if(b<0){
            b += 10;
            nj = 1;
          }
          dp.at(ni).at(nj) = min( dp.at(ni).at(nj), dp.at(i).at(j)+a+b );
        }
      }
    }
  
  	//n桁全て確定したときに繰り下がりはあってはいけない
  	cout << dp.at(n).at(0) << endl;
  
  	return(0);
}