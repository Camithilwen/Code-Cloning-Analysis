#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin>>n;
    int ans = -1;
    int l=1,r=n-1;
    cout << 0 << endl;
    string s;
    cin>>s;
    string fi = s;
    if(s == "Vacant") return 0;
    
    cout << n-1 << endl;
    cin>>s;
    string la = s;
    if(s=="Vacant")return 0;

    while(true){
        int mid = (l+r)/2;
        cout << mid << endl;
        cin >> s;
        if(s == "Vacant")return 0;
        if(mid%2 == 0){
            if(s == fi) l = mid;
            else r = mid;
        }
        else{
            if(s == la) l = mid;
            else r = mid;
        }
    }

}