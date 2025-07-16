#include <bits/stdc++.h>
using namespace std;
#define int long long
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

signed main(){
    string A; cin>>A;

    //ナイーブに考えれば答えはnC2通り
    // ただし、選択した部分が回文になっていればそれは同じ結果になるのと、
    // 両端の文字が同じならばその両端を除いた部分をひっくり返すのと同じ結果になる
    // したがって
    // 回文の数
    // (各文字に関して同じペアの数 C 2)の和 - そのうち回文の数
    // をnC2から差っ引けばよい
    // と思ったんだけれど、これって回文の数がキャンセルするから、a-zの数を数えればOKなもんだいじゃね?

    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    map<char, int> char_num;
    for(int i=0;i<26;i++){
        char_num[alphabet[i]] = 0;
    }
    int length= A.size();
    rep(i, length){
        char_num[A[i]] +=1;
    }

    int answer = length*(length-1)/2;

    for(int i=0;i<26;i++){
        answer -= char_num[alphabet[i]]*(char_num[alphabet[i]]-1)/2;
    }
    cout<<answer+1<<endl;




    return 0;
}