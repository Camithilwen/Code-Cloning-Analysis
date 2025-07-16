#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;

static vector<int> P={2};
template<class T>
T next_prime(T x){
    int size=P.size();
    
    if(x<P[size-1]){
        int begin=0,end=size;
        while(end-begin>1){
            int c=(begin+end)/2;
            if(x<P[c]){
                end=c;
            }else{
                begin=c;
            }
        }
        return P[begin];
    }

    T res=P[size-1];
    while(true){
        res++;
        bool prime=true;
        for(int i=0;i<size;i++){
            if(P[i]<=sqrt((double)res)){
                if(res%P[i]==0){
                    prime=false;
                    break;
                }
            }else{
                break;
            }
        }

        if(prime){
            P.push_back(res);
            size++;
            if(res>x){
                break;
            }
        }
    }

    return res;
}

template<class T>
bool prime(T x){
    if(x==next_prime(x-1)) return true;
    return false;
}

int N;
vector<int> a;

int main(){
    cin>>N;

    int prev=1;
    while(N!=0){
        int p=next_prime(prev);
        if(p%10==1){
            a.push_back(p);
            N--;
        }
        prev=p;
    }

    repr(e,a) cout<<e<<' ';
    cout<<endl;
}