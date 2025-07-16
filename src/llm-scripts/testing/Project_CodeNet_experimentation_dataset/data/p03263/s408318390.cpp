#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
//コンビネーションを10^9+7で割った余りを求める
const int MOD=1000000007;
int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<int>> c(h,vector<int> (w));
    bool p=false;
    rep(i,h){
        rep(j,w){
            cin>>c[i][j];
        }
    }
    int l=0,r=0;
    int ans=0;
    string s="";
    while(1){
        
        if(c[l][r]%2!=0 && !p){
            p=true;
            if(l==h-1 && h%2==0 && r==0){}
            else if(l==h-1 && h%2==1 && r==w-1){}
            //cout<<l+1<<" "<<r+1<<" ";
            else{
                s+=to_string(l+1)+" "+to_string(r+1)+" ";
            }
        }
        else if(c[l][r]%2==0 && p){
            //cout<<l+1<<" "<<r+1<<endl;
            ans++;
            if(l==h-1 && h%2==0 && r==0 || l==h-1 && h%2==1 && r==w-1){
                s+=to_string(l+1)+" "+to_string(r+1)+"\n";
                break;
            }
            s+=to_string(l+1)+" "+to_string(r+1)+"\n";

            s+=to_string(l+1)+" "+to_string(r+1)+" ";
            //cout<<l+1<<" "<<r+1<<" ";
        }
        else if(c[l][r]%2!=0 && p){
            p=false;
            //cout<<l+1<<" "<<r+1<<endl;
            s+=to_string(l+1)+" "+to_string(r+1)+"\n";
            ans++;
        }
        else{//c[l][r]が偶数でコインを持ってない

        }
        
       //cout<<l<<" "<<r<<endl;
       if(l==h-1 && h%2==0 && r==0){
           break;
       }
       if(l==h-1 && h%2==1 && r==w-1){
           break;
       }
        if(r==w-1 && l%2==0){
            l++;
            continue;
        }
        if(r==0 && l%2==1){
            l++;
            continue;
        }
        if(l%2==0){
            r++;
        }
        else{
            r--;
        }
    }
    cout<<ans<<endl;
    cout<<s;
}