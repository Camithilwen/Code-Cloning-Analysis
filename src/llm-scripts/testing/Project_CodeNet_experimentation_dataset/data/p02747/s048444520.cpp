#include <bits/stdc++.h>//復習必須
#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
#define P pair<int, int>
int main () {
   string s ;
   cin >> s ;
   size_t n = s.length() ;
   bool flag = true ;
   if(n % 2 != 0 ){
       cout << "No" << endl;
       return 0 ;
   }else{
       
       rep(i , n /2){
           if(s[2*i] != 'h' || s[2*i + 1] != 'i'){
               flag = false ;

           }
       }
   }
   if(flag == true){
       cout << "Yes" << endl;
   }else{
       cout << "No" << endl;
   }
    return 0 ;
}

 
