#include<vector>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>
#include <algorithm>
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

int main(){
    string S;
    vector<char> Table(26, 0);
    cin >> S;

    for(int i=0; i<S.size(); i++){
        Table[S[i]-'a'] = 1;
    }
    for(int i=0; i<Table.size(); i++){
        if(Table[i]==0){
            printf("%c\n", 'a'+i);
            exit(0);
        }
    }
    cout << "None\n";
    return 0;
}