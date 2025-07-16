#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
using ll = int64_t;
using Graph = vector<vector<int> >;
const ll M = 1000000007;

int main(){
    int h,w;
    cin >> h >> w;
    char s[h+2][w+2];
    for(int i=0;i<h+2;i++){
        if(i==0 || i==h+1){
            for(int j=0;j<w+2;j++) s[i][j]='.';
        }else{
            for(int j=0;j<w+2;j++){
                if(j==0 || j==w+1){
                    s[i][j]='.';
                }else{
                    cin >> s[i][j];
                }
            }
        }
    }

    /*for(int i=0;i<h+2;i++){
        for(int j=0;j<w+2;j++){
            cout << s[i][j];
        }
        cout << endl;
    }*/

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(s[i][j]=='#'){
                if(s[i+1][j]=='.' && s[i-1][j]=='.' && s[i][j+1]=='.' && s[i][j-1]=='.'){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    
    cout << "Yes" << endl;
}