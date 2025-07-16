#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <set>
#include <iomanip>
#include <deque>
#include <stdio.h>
using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int (i)=(int)(n)-1;i>=0;i--)
#define REMOVE(Itr,n) (Itr).erase(remove((Itr).begin(),(Itr).end(),n),(Itr).end())
#define PB_VEC(Itr1,Itr2) (Itr1).insert((Itr1).end(),(Itr2).begin(),(Itr2).end())
#define UNIQUE(Itr) sort((Itr).begin(),(Itr).end()); (Itr).erase(unique((Itr).begin(),(Itr).end()),(Itr).end())
#define LBOUND(Itr,val) lower_bound((Itr).begin(),(Itr).end(),(val))
#define UBOUND(Itr,val) upper_bound((Itr).begin(),(Itr).end(),(val))
typedef long long ll;

int main(){
    
    int t; cin>>t;
    REP(kai,t){
        int out=0;
        int point=0;
        bool rui[3]={false,false,false};
        while(true){
            string s; cin>>s;
            if(s=="OUT"){
                out++;
                if(out==3)goto nextf;
            }else if(s=="HOMERUN"){
                point++;
                REP(j,3)if(rui[j])point++;
                REP(j,3)rui[j]=false;
            }else{
                if(rui[2])point++;
                rui[2]=rui[1];
                rui[1]=rui[0];
                rui[0]=true;
            }
        }
    nextf:;
        cout<<point<<endl;
    }
    
    return 0;
}