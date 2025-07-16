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
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> num(n,0);
    for(int i=0;i<m;i++){
        int s,c;
        cin >> s >> c;
        if(num.size()>=2 && s==1 && c==0){
            cout << -1 << endl;
            return 0;
        }
        if(num.at(s-1)==0 || num.at(s-1)==c){
            num.at(s-1)=c;
        }else{
            cout << -1 << endl;
            return 0;
        }
    }

    if(num.at(0)==0 && num.size()>=2) num.at(0)=1;
    for(int i=0;i<n;i++) cout << num.at(i);
    cout << endl;
}