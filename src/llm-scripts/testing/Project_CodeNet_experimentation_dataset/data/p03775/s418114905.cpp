#include<vector>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#define INF 100000000000000
using namespace std;
typedef long long llong;

//int isalpha(char ch): ch がアルファベットなら true を返す
//int isdigit(char ch): ch が数字なら true を返す
//int islower(char ch): ch が小文字なら true を返す
//int isupper(char ch): ch が大文字なら true を返す
//int tolower(char ch): ch の小文字を返す
//int toupper(char ch): ch の大文字を返す

//string型
//size()	文字数を返す
//insert()	（指定した場所に）文字・文字列を挿入する
//erase()	（指定した場所の）文字・文字列を削除する
//clear()	すべての文字を削除する
//substr()	文字列の（指定した）部分文字列を返す
//replace()	（指定した）部分文字列を新しい文字列に置換する
//文字列の比較は、<=や==などを使え
//replace関数を使い、簡単に文字列を置換
//リバース関数：reverse(str.begin(), str.end());
//map<type, type> dict;で宣言
//グラフ理論用変数
//vector<vector<llong> > graph(N);

//ソート
//降順sort(v.begin(), v.end(), std::greater<Type>());

//大文字から小文字へんかん
//w[i] = w[i]-'A'+'a';

bool isprime(llong num){
    if(num==1){
        return false;
    }
    if(num==2){
        return true;
    }
    for(int i=2; i<=sqrt(num); i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

//約数列挙
void EnumerateFactor(vector<vector<llong> > &factor_list, llong num){
    llong cnt=0;
    for(int i=1; i<=sqrt(num); i++){
        if(num%i==0){
            factor_list[cnt].push_back(i);
            factor_list[cnt].push_back(num/i);
            cnt++;
        }
    }
}

int main(){
    llong n;
    llong ans=INF;
    llong temp=-1*INF;
    vector<vector<llong> > factor_list(100000);
    string A, B;

    scanf("%lld", &n);
    EnumerateFactor(factor_list, n);
    for(int i=0; i<factor_list.size(); i++){
        if(factor_list[i].size()==0){
            break;
        }
        A = to_string(factor_list[i][0]);
        B = to_string(factor_list[i][1]);
        temp = max(A.size(), B.size());
        ans  = min(temp, ans);
    }
    cout << ans << endl;
    return 0;

}