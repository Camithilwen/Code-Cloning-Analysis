#include<bits/stdc++.h>
using namespace std;
vector<vector<string>>ans={
        {"-1"},                 //0
        {"-1"},                 //1
        {"-1"},                 //2
        {                       //3
         "..a",
                "..a",
                "bb."
        },
        {                       //4
         "abcc",
                "abdd",
                "eefg",
                "hhfg"
        },
        {                       //5
         "..abc",
                "..abc",
                "ddeff",
                "gge.h",
                "iijjh"
        },
        {                       //6
         "...abc",
                "...abc",
                "d.ee.f",
                "dgg..f",
                "hhi.jj",
                "kkill."
        },
        {
         "....abc",
                "....abc",
                "....def",
                "....def",
                "gghh..i",
                "jjkk..i",
                "llmmnn."
        }
};
int n;
void printA(vector<string>ans){
    for(auto x:ans){
        cout<<x<<endl;
    }
}
void manage(vector<string>ans,int prev){
    for(auto x:ans){
        cout<<string(prev,'.')
            <<x
            <<string(n-prev-x.length(),'.')
            <<endl;
    }
}
void rec(int n,int prev){
    if(n==0)return;
    if(n>9&&n!=13||n==6){
//        cout<<6<<" ";
        manage(ans[6],prev);
        rec(n-6,prev+6);

    }
    else if(n>8||n%5==0){
//        cout<<5<<" ";
        manage(ans[5],prev);
        rec(n-5,prev+5);
    }
    else{
//        cout<<"4"<<" ";
        manage(ans[4],prev);
        rec(n-4,prev+4);
    }
}
int main(){
    cin>>n;

    if(n<8)printA(ans[n]);
//    for(int i=9;i<30;i++){
//        rec(i,0);
//        cout<<endl;
//    }
    else rec(n,0);

}
//..abc
//..abc
//ddeff
//gge.h
//iijjh

//abcc
//abdd
//eefg
//hhfg

//..a
//..a
//bb.

