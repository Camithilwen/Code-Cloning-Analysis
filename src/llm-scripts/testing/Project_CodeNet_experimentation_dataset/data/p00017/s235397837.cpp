#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cstdio>

#define REP(n) for(int i = 0;i < n;i++)
#define LLREP(n) for(long long int  i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 1000000007

int main(){

    string s;
    int tmp = 0;
    while(getline(cin,s)){
        for(int i = 0;i < 26;i++){
            string tmp(s);
            for(int j = 0;j < s.length();j++){

                if(isalpha(s[j])){
                    tmp[j] = (s[j]-'a'+i)%26 + 'a';
                }
            }
               
            if(tmp.find("the")!=-1||tmp.find("this")!=-1||tmp.find("that")!=-1) {
                cout << tmp << endl;
                break;  
            }
        }
        
    }


    return 0;
}
