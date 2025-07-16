#include <iostream>
#include <numeric>
#include <math.h>
#include <algorithm>
#include <float.h>
#include <limits>
#include <vector> 
#include <string.h>
#include <iomanip>

#define rep(i,a,n) for(ll int (i) = (a);(i) < (n);(i)++)
#define urep(i,a,n) for(ll int (i) = (a);(i) > (n);(i)--)
#define MOD 1000000007
#define INF 2147483647
#define ll long long
#define asort(a) sort(a.begin(),a.end());//昇順ソート
#define usort(a) sort(a.rbegin(),a.rend());//降順ソート

using namespace::std;

int jo(ll int a, ll int b){//累乗
    ll int num=1;
    rep(i,0,b) num=num*a;
    return num;
}
char tobig(char s){//char大文字化
  return (s-0x20);
}
char tolow(char s){//char小文字化
  return (s+0x20);
}
int ctoi(char a){//char->int
  if('0'<=a&&a<='9') return (a-'0');
  return -1;
}

int gcd(ll int a,ll int b) {//最大公約数
  if(a<b) return gcd(b,a);
  int c;
  while ((c=a%b)) {
    a=b;
    b=c;
  }
  return b;
}
int lcm(ll int a,ll int b){//最小公倍数
 return (a*b)/gcd(a,b);
}


int main(){
  string S;cin>>S;
  int AC=0;
  rep(i,0,S.length()-1){
    if(S[i]=='A'&&S[i+1]=='C') AC++;
  }
  cout<<(AC?"Yes":"No");
}




// vector<vector<int>> 変数名(左の個数, vector<int>(右の個数));

//cout<<fixed<<setprecision(n);  //小数点n桁まで表示

//  vector<pair<int,int>> data(N);  //2つのデータを格納、.first/.secondで参照
// pairのソートはfirst優先の昇順
