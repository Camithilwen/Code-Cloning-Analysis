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

int main() {
    int n;
    while(cin>>n){
        if(n==0)break;
        queue<int> output;
        ll man[5000]={};
        rep(i,n){
            int a,b,c;
            cin>>a>>b>>c;
            if(man[a]==0){
                output.push(a);
            }
            if(man[a]<1000000){
                man[a]+=(ll)b*c;
            }
        }
//        while(output.size()){cout<<output.front();output.pop();}
        bool flag=true;
        while(output.size()){
            if(man[output.front()]>=1000000){
                cout<<output.front()<<endl;
                flag=false;
            }
            output.pop();
        }
        if(flag)cout<<"NA"<<endl;
    }
    
    return 0;
}