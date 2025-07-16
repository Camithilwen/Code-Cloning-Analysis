#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    int n;
    cin>>n;
    int A,B,C,D;
    int sum=0;
    A=n/1000,n%=1000;
    B=n/100,n%=100;
    C=n/10,n%=10;
    D=n;
    string s="=7";
    vector<int>num={A,B,C,D};
    vector<char>op(3);
    /*考え方:
    全探索を考える（オーダー的にもOK)
     ・opの入れ方は+か-の2通り
     ・op1,op2,op3がある
     ->2^3通り ->ビット全探索orループ*/
    for(int bit=0;bit<(1<<3);bit++){
        bitset<3>s(bit);
        /*operantの決定*/
        for(int l=0;l<3;l++){
            if(s.test(l)){//bitがいならtrue
                op[l]='+';
            }else{
                op[l]='-';
            }
        }
        sum+=A;
        rep(l,3){
            if(op[l]=='+'){
                sum+=num.at(l+1);
            }else{
                sum-=num.at(l+1);
            }
        }
        if(sum==7){
            cout<<A<<op.at(0)<<B<<op.at(1)<<C<<op.at(2)<<D;
            cout<<"=7"<<endl;
            return 0;
        }else{
            sum=0;
        }
    }
}