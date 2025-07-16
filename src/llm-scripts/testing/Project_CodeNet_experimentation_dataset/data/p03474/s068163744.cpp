#include <iostream>
//#include <vector>
#include <string>
//#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
//#define NIL -1
//#define INFTY 1000000000000000000

int main(){
    LL a;
    LL b;
    string s;
    bool is_ok=true;
    cin >> a >> b;
    cin >> s;
    if(a+b+1!=s.size()){
        is_ok=false;
    }else if(s[a]!='-'){
        is_ok=false;
    }else{
        for(LL i=0; i<a; i++){
            LL tmp=s[i]-'0';
            if(tmp<0 || tmp>9){
                is_ok=false;
            }
        }
        for(LL i=a+1; i<a+b+1; i++){
            LL tmp=s[i]-'0';
            if(tmp<0 || tmp>9){
                is_ok=false;
            }
        }
    }

    if(is_ok==true){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
