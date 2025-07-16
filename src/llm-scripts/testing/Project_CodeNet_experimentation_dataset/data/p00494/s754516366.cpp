#include<bits/stdc++.h>
using namespace std;
 
template<typename T1, typename T2> istream& operator>>(istream& is, pair<T1,T2>& a){ return is >> a.first >> a.second; }
template<typename T1, typename T2> ostream& operator<<(ostream& os, pair<T1,T2>& a){ return os << a.first << " " << a.second; }
template<typename T> istream& operator>>(istream& is, vector< T >& vc){ for(int i = 0; i < vc.size(); i++) is >> vc[i]; return is; }
template<typename T> ostream& operator<<(ostream& os, vector< T >& vc){ for(int i = 0; i < vc.size(); i++) os << vc[i] << endl; return os; }
 
#define ForEach(it,c) for(__typeof (c).begin() it = (c).begin(); it != (c).end(); it++)
#define ALL(v) (v).begin(), (v).end()
#define UNQ(s) { sort(ALL(s)); (s).erase( unique( ALL(s)), (s).end());}

typedef pair< int , int > Pi;
typedef pair< int , Pi > Pii;
typedef long long int64;

int sum[1000000][3];
int sum2[1000000][3];

int main(){
  string str;
  cin >> str;

  for(int i = 0; i < str.size(); i++){
    int pos = string("JOI").find(str[i]);
    if(i) sum[i][pos] = sum[i - 1][pos] + 1;
    else sum[i][pos] = 1;
  }
  for(int i = str.size() - 1; i >= 0; i--){
    int pos = string("JOI").find(str[i]);
    if(i == str.size() - 1) sum2[i][pos] = 1;
    else sum2[i][pos] = sum2[i + 1][pos] + 1;
  }
  

  int ret = 0;
  for(int i = 1; i < str.size() - 1; i++){
    if(sum[i][1] > 0){ // 真ん中'O'の長さに依存してそう( こうさつ
      int J_pos = i - sum[i][1]; //これが'J'の終わり
      int I_pos = i + 1; // これが'I'の始まり
      if(J_pos >= 0 && (sum[J_pos][0] >= sum[i][1] && sum2[I_pos][2] >= sum[i][1])) ret = max( ret, min( sum[i][1], min( sum[J_pos][0], sum2[I_pos][2])));
    }
  }
  cout << ret << endl;
}