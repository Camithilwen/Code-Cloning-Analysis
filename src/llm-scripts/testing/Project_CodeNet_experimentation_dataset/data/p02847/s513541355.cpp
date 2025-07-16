#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef set<int> si;
typedef set<string> ss;
typedef map<int,int> mii;
typedef map<string,int>msi;
typedef map<string,string>mss;
void solve(){
    string inp,weeks[7];
    weeks[0]="MON";
    weeks[1]="TUE";
    weeks[2]="WED";
    weeks[3]="THU";
    weeks[4]="FRI";
    weeks[5]="SAT";
    weeks[6]="SUN";
    cin>>inp;
    int n;
    for(int i=0;i<7;i++){
        if(weeks[i]==inp){
            n=i;
        }
    }
    int res = 6-n;
    if(res==0){
        res=7;
    }
    cout<<res<<endl;
}
int main(){
    int t;
    t=1;
    while(t--){
       solve();
    }
    return 0;
}
