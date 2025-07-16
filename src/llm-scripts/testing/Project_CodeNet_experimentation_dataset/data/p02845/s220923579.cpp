#include <iostream>
#include <vector>
//#include <string>
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
 
#define MOD 1000000007
//#define MAX 100100
//#define NIL -1

int main() {
    int n;
    cin >> n;
    vector<LL> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    LL ans=1;
    vector<LL> rgb(3, 0);
    for(int i=0; i<n; i++){
        LL tmp=0;
        for(int j=0; j<3; j++){
            if(a[i]==rgb[j]){
                tmp++;
            }
        }
        ans=(ans*tmp)%MOD;
        for(int j=0; j<3; j++){
            if(a[i]==rgb[j]){
                rgb[j]++;
                break;
            }
        }
    }

    //for(int i=0; i<3; i++){
    //    cout << rgb[i] << endl;
    //}

    cout << ans << endl; 

    return 0;
}