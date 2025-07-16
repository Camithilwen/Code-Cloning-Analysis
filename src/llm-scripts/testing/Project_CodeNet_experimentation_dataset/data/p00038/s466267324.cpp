#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <iomanip>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <bitset>
#include <vector>
#include <cstdio>
#include <ctime>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

#define dump(x)  cerr << #x << " = " << (x) << endl
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back

bool isLeep(int n){
    if((n%4==0 && n%100!=0) || n%400==0){
        return true;
    }
    else return false;
}


int main() {
    int a[5]={};
    char ch;
    while(cin>>a[0]>>ch>>a[1]>>ch>>a[2]>>ch>>a[3]>>ch>>a[4]){
        sort(a,a+5);
        if( (a[0]==a[1] && a[1]==a[2] && a[2]==a[3]) || (a[1]==a[2] && a[2]==a[3] && a[3]==a[4]) )cout<<"four card"<<endl;
        else if( (a[0]==a[1] && a[1]==a[2] && a[3]==a[4]) || (a[0]==a[1] && a[2]==a[3] && a[3]==a[4]) )cout<<"full house"<<endl;
        else if( (a[0]+1==a[1] && a[1]+1==a[2] && a[2]+1==a[3] && a[3]+1==a[4]) || (a[0]==1 && a[1]==10 && a[2]==11 && a[3]==12 && a[4]==13) )cout<<"straight"<<endl;
        else if( (a[0]==a[1] && a[1]==a[2]) || (a[1]==a[2] && a[2]==a[3]) || (a[2]==a[3] && a[3]==a[4]) )cout<<"three card"<<endl;
        else if( (a[0]==a[1] && (a[2]==a[3] || a[3]==a[4] )) || (a[1]==a[2] && a[3]==a[4]) )cout<<"two pair"<<endl;
        else if( a[0]==a[1] || a[1]==a[2] || a[2]==a[3] || a[3]==a[4] )cout<<"one pair"<<endl;
        else cout<<"null"<<endl;
    }
    
    return 0;
}