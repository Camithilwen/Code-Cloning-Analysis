#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
#include<iterator>
#include<cmath>
#include<functional>
#include<map>
using namespace std;

int main(){
    int N;
    cin >> N;
    map<int, int>  o, e;
    for(int i=0; i<N/2; i++){
        int ot, et;
        cin >> ot;
        cin >> et;
        o[ot]++;
        e[et]++;
    }
    int r = N;
    int ei = 0;
    int oi = 0;
    int so = 0;
    int se = 0;
    int me = 0;
    int mo = 0;
    for (auto it = o.begin(); it != o.end(); it++){
        if(mo < it->second){
            so = mo;
            mo = it->second;
            oi = it->first;
        }else if(so < it -> second){
            so = it->second;
        }
    }
    for (auto it = e.begin(); it != e.end(); it++){
        if(me < it->second){
            se = me;
            me = it->second;
            ei = it->first;
        }else if(so < it -> second){
            se = it->second;
        }
    }
    if(ei == oi){
        if (so == 0 && se == 0){
            r -= N/2;
        }else if(so > se){
            r -= so + me;
        }else{
            r -= se + mo;
        }
    }else{
        r -= me + mo;
    }
    cout << r << endl;
}

