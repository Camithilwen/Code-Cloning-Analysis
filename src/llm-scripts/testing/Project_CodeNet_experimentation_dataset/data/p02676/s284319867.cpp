#include <bits/stdc++.h>
#include <iostream>
#include <math.h>    //pow(x,y)=x^y 99999とかの場合+1するif文
#include <algorithm> //sort(a.begin(), a.end());reverse(a.begin(), a.end());
#include <ctime>     //実行時間を測る
#define ll long long
#define vecvec(h, w, name) vector<vector<ll>> name(h, vector<ll>(w));
#define rep(init, i, n) for (ll i = init; i < (n); i++)
#define rev(s) reverse(s.begin(), s.end())
#define sor(v) sort(v.begin(), v.end()) //昇順
#define PI 3.14159265358979323846264338327950L
//コード自動整形 Shift + Option + F @vscode
//変数名一括置換　command+fn+f2 @vscode
using namespace std;
using vec = vector<ll>;
//function
ll facctorialMethod(ll k);     //階乗を出力する
ll modpow(ll a, ll n, ll mod); // a^n mod を計算する
ll gcd(ll a, ll b);            //最大公約数
ll lcm(ll a, ll b);            //最小公倍数
//

//struct
// UnionFind
// coding: https://youtu.be/TdR816rqc3s?t=726
// comment: https://youtu.be/TdR816rqc3s?t=6822
struct UnionFind
{
  vector<ll> d;
  UnionFind(ll n = 0) : d(n, -1) {}
  ll find(ll x)
  { //根っこを返す
    if (d[x] < 0)
      return x;
    return d[x] = find(d[x]); //根っこの場所を貼り付ける
  }
  bool unite(ll x, ll y)
  { //くっつける操作、連結成分の情報整理 ABC177,157D参照
    x = find(x);
    y = find(y);
    if (x == y)
      return false;
    if (d[x] > d[y])
      swap(x, y); //dはマイナスをかけたサイズだからxの方がサイズ小さいようにする
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  //find(i)でi番目の属しているグループ番号を出力
  bool same(ll x, ll y) { return find(x) == find(y); } //同じ集合に属しているかを判定
  ll size(ll x) { return -d[find(x)]; }                //あるID、xが所属するグループに所属するIDの数を得る ABC177,157D参照
};
//

/////main/////
int main()
{
  int clock_on = 0; //提出時は0!!!!!!!!!!!!!!!!!
  int time_clock = clock();
  //
ll K;string S;
cin>>K>>S;
if(S.size()<=K){cout<<S<<endl;return 0;}
else{
    cout<<S.substr(0,K)<<"..."<<endl;
    
}

  //
  if (clock_on == 1)
    printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - time_clock) / CLOCKS_PER_SEC);
  return 0;
}
/////main/////

/////function/////
//階乗を出力する
ll facctorialMethod(ll k)
{
  ll sum = 1;
  for (ll i = 1; i <= k; ++i)
  {
    sum *= i;
  }
  return sum;
}

// a^n mod を計算する
ll modpow(ll a, ll n, ll mod)
{
  ll res = 1;
  while (n > 0)
  {
    if (n & 1)
      res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

//最大公約数
ll gcd(ll a, ll b)
{
  if (a % b == 0)
  {
    return b;
  }
  else
  {
    return gcd(b, a % b);
  }
}

//最小公倍数
ll lcm(ll a, ll b)
{
  return a * b / gcd(a, b);
}