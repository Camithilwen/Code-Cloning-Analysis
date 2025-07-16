#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const long long INF=INT_MAX/4;
const long long MOD=998244353;
const double EPS=1e-14;
const bool DEBUG=false;

const string YES = "YES";
const string NO = "NO";
const string Yes = "Yes";
const string No = "No";

template<class T>
void debug(T head){
    if(DEBUG){
        cout<<head<<endl;
    }
}

template <class Head, class... Body>
void debug(Head head, Body... body){
    if(DEBUG){
        cout<<head<<" ";
        debug(body...);
    }
}

/////
void answer(ll sx, ll sy, ll tx, ll ty){
    for(int i=sy; i<ty; ++i){
        cout<<"U";
    }
    for(int i=sx; i<tx; ++i){
        cout<<"R";
    }
    for(int i=sy; i<ty; ++i){
        cout<<"D";
    }
    for(int i=sx; i<tx; ++i){
        cout<<"L";
    }

    cout<<"L";
    for(int i=sy; i<ty+1; ++i){
        cout<<"U";
    }
    for(int i=sx; i<tx+1; ++i){
        cout<<"R";
    }
    cout<<"D";

    cout<<"R";
    for(int i=sy; i<ty+1; ++i){
        cout<<"D";
    }
    for(int i=sx; i<tx+1; ++i){
        cout<<"L";
    }
    cout<<"U";
    cout<<endl;

    return;
}

/////

int main(int argc, char* argv[]){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout.precision(16);

    ll sx, sy, tx, ty;
    cin>>sx>>sy>>tx>>ty;
    answer(sx, sy, tx, ty);

    return 0;
}
