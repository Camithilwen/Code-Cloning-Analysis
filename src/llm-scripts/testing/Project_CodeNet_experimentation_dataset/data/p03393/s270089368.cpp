/**
*    author:  souzai32
*    created: 05.08.2020 01:20:01
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    string s;
    cin >> s;

    int n=s.size();
    vector<bool> alphabet(26);

    if(n==26){
        int i=1;
        while(1){
            if(s.at(n-i)<s.at(n-1-i)) i++;
            else{
                int j=0;
                while(1){
                    if(s.at(n-1-i)<s.at(n-1-j)){
                        s.at(n-1-i)=s.at(n-1-j);
                        break;
                    }
                    else j++;
                }
                
                for(int j=0; j<i; j++) s.pop_back();
                break;
            }

            if(i==26){
                s="-1";
                break;
            }
        }
    }
    else{
        rep(i,n){
            alphabet.at(s.at(i)-'a')=true;
        }

        int i=0;
        char a='a';
        while(1){
            if(alphabet.at(i)) i++;
            else{
                a+=i;
                s.push_back(a);
                break;
            }
        }
    }

    cout << s << endl;
    //cout << s.size() << endl;

    return 0;
}