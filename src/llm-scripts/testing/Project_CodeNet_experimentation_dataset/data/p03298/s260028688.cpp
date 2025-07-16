#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

void all_enum(string R, string B, string &S, map<string,int> &m){
    int i=(int)R.size()+B.size();
    if(i==(int)S.size()){
        string key_=R+","+B;
        //cout << key_ << endl;
        if(m.count(key_)){
            m[key_]++;
        }else{
            m[key_]=1;
        }
        return;
    }
    
    all_enum(R+S[i],B,S,m);
    all_enum(R,B+S[i],S,m);
}

ll count_pattern(string R, string B, string &T, map<string,int> &m){
    int i=(int)R.size()+B.size();
    if(i==(int)T.size()){
        string key_=R+","+B;
        //cout << key_ << endl;
        if(m.count(key_)){
            return m[key_];
        }else{
            return 0;
        }
    }

    ll cnt=0;
    cnt+=count_pattern(R+T[i],B,T,m);
    cnt+=count_pattern(R,B+T[i],T,m);
    return cnt;
}

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    string T=S.substr(N,N);
    reverse(T.begin(),T.end());
    S=S.substr(0,N);

    map<string,int> m;

    all_enum("","",S,m);
    //cout << "_______" << endl;
    cout << count_pattern("","",T,m) << endl;

}