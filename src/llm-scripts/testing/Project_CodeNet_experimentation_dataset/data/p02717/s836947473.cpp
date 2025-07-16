/*
    @uthor: Varun Mishra
    "varun21999" ->  Codechef, Codeforce, Hackerrank, Hackerearth;
*/
//#include<boost/multiprecision/cpp_int.hpp>
//using boost::multiprecision::cpp_int;
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
#define int            long long int
#define ull            unsigned int
#define ld             long double
#define pb             push_back
#define pa             pair<int,int>
#define ppa            pair<pair<int,int>,int>
#define pap            pair<int,pair<int,int>>
#define v1d            vector<int>
#define v2d            vector<vector<int> >
#define vpa            vector<pair<int,int>>
#define M              1000000007
#define MN             LLONG_MIN
#define MX             LLONG_MAX
#define ff             first
#define ss             second
#define endl           "\n"
#define v1s            vector<string>
#define all(v)         v.begin(),v.end()
#define S(v)           sort(v.begin(),v.end())
#define RS(v)          sort(v.rbegin(),v.rend())
#define R(v)           reverse(v.begin(),v.end())
#define mxpq(T)        priority_queue <T>
#define mnpq(T)        priority_queue<T,vector<T>,greater<T>>
#define T              int tc;cin>>tc;while(tc--)
#define p2d(v)         for(auto a:v){for(auto b:a)cout<<b<<" ";cout<<endl;}
#define p1d(v)         for(auto a:v)cout<<a<<" ";cout<<endl;
#define ppd(v)         for(auto a:v)cout<<a.ff<<" "<<a.ss<<endl;
#define forIloop(i,n)  for(auto i=0;i<n;i++);
#define forDloop(i,n)  for(auto i=n-1;i>=0;i--);
#define qqq 400005
#define isEven(n)  (!n & 1);
const int MOD = 1e9 + 7;
// bool isEven(int n){
//     return (!(n & 1));
// }
// int popcount(int num){
//     num = num - ((num >> 1) & 0x55555555);
//     num = (num & 0x33333333) + ((num >> 2) & 0x33333333);
//     return ((num + (num >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
// }
// int powerOfTwo(int n){
//     return 1 << n;
// }

// int arr[1000001];
// bool temet = false;


void codeforce2(){
    int a[3]; cin>>a[0]>>a[1]>>a[2];
    swap(a[0], a[1]);
    swap(a[0], a[2]);
    cout << a[0] << " " << a[1] << " " << a[2] << endl; 

    return;
}




int32_t main(){

    cout<<fixed<<setprecision(16);
    cin.sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    /*#ifndef _DEBUG
     freopen("input.txt",  "r",  stdin);
     freopen("output.txt", "w", stdout);
    #endif*/
    //auto start = high_resolution_clock::now();

    // Lucario();
    //codeforceContest();
    //hackerEarth();
    //codeChef();

    // T{
    //     codeforce2();
    // }
    codeforce2();

   /* auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout << "Time: "<<duration.count()<<endl;*/
    return 0;
}