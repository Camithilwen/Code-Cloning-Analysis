#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define dupl(s) s.erase(unique(s.begin(), s.end()), s.end());//重複取り除き
#include <bits/stdc++.h>
using namespace std;
int sum(vector<int> s){return accumulate(s.begin(),s.end(),0);}
void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    int n;
    cin >> n;
    vector<int> inp;
    map<int,int> a{};
    rep(i,n){
        int k;
        cin >> k;
        a[k]++;
        if(a[k] == 1)inp.push_back(k);
        };
    int cnt = 0;
    rep(i,inp.size())if(a[inp[i]]%2 != 0)cnt++;
    cout << cnt;
}