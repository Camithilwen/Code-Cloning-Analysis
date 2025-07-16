//
//  main.cpp
//  Atcoder1
//
//  Created by Hamske on 2020/09/17.
//  Copyright © 2020 Author. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

//#define pb push_back
//#define mp make_pair
//
//#define F first
//#define S second

typedef long long ll;

#define rept(_i,iv,n,type) for(type _i=(type)(iv);_i<(type)(n);++_i)
//#define repi(_i,iv,n) rept(_i,iv,n,int)
//#define repl(_i,iv,n) rept(_i,iv,n,ll)

#define rept0(_i,n,type) rept(_i,0,n,type)
#define repi0(_i,n) rept(_i,0,n,int)
#define repl0(_i,n) rept(_i,0,n,ll)

//#define repst(_i,iv,n,type) for(type _i=iv;_i<=(type)(n);++_i)
//#define repsi1(_i,n) repst(_i,1,n,int)

#define REPT(_i,iv,_l,n,type) for(type _i=(type)(iv),_l=(type)(n);_i<_l;++_i)
//#define REPI(_i,iv,_l,n) REPT(_i,iv,_l,n,int)
//#define REPL(_i,iv,_l,n) REPT(_i,iv,_l,n,ll)
//
#define REPT0(_i,_l,n,type) REPT(_i,0,_l,n,type)
#define REPI0(_i,_l,n) REPT(_i,0,_l,n,int)
#define REPL0(_i,_l,n) REPT(_i,0,_l,n,ll)


//#define rrept(_i,x,e,type) for(type _i=((type)(x)-1);_i>=e;--_i)
//
//#define rrept0(_i,x,type) rrept(_i,x,0,type)
//
//#define RREPT(_i,x,_e,e,type) for(type _i=((type)(x)-1),_e=(type)(e);_i>=_e;--_i)
//
//#define RREPT0(_i,x,_e,type) RREPT(_i,x,_e,0,type)
//
//#define RREPS(i,x) for(int i=((int)(x));i>0;i--)

//#define all(x) (x).begin(),(x).end()
#define REPV(v,_itr,_end) for(auto _itr=(v).begin(),_end=(v).end();_itr!=_end;++_itr)
#define REPVC(v,_itr,_end) for(auto _itr=(v).cbegin(),_end=(v).cend();_itr!=_end;++_itr)

#define td typedef
//#define tds(stl,type,name) typedef stl<type > name;
#define tdv(type,name) typedef vector<type > name;


//typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<vb > vvb;
typedef vector<int> vi;
typedef vector<vi > vvi;
//typedef vector<ll> vll;
//typedef vector<vll > vvll;

#define MOD7 1'000'000'007
#define MOD9 1'000'000'009

int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    vi A(N);
    REPV(A, itr, end){
        cin>>(*itr);
    }
    ll sum=0;
    int bh=0;
    repi0(i, N){
        if(bh<=A[i]){
            bh=A[i];
        }else{
            sum+=bh-A[i];
        }
    }
    cout<<sum<<endl;
    return 0;
}
