#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    int N;
    cin>>N;
    string s;
    cin>>s;
    vector<string> tmp;
    tmp.push_back("SS");
    tmp.push_back("SW");
    tmp.push_back("WS");
    tmp.push_back("WW");
    string ans;
    bool aru = false;
    for(int i=0;i<4;++i){
        bool tmparu = true;
        ans = tmp[i];
        for(int j=2;j<N;++j){
            if(ans[j-1]=='S'){
                if(s[j-1]=='x'){
                    if(ans[j-2]=='S'){
                        ans += 'W';
                    }
                    else{
                        ans += 'S';
                    }
                }
                else {
                    if(ans[j-2]=='S'){
                        ans += 'S';
                    }
                    else{
                        ans += 'W';
                    }
                }
            }
            else {
                if(s[j-1]=='x'){
                    if(ans[j-2]=='S'){
                        ans += 'S';
                    }
                    else {
                        ans += 'W';
                    }
                }
                else {
                    if(ans[j-2]=='S'){
                        ans += 'W';
                    }
                    else {
                        ans += 'S';
                    }
                }
            }
        }
        if(ans[N-1]=='S'){
            if(s[N-1]=='x'){
                if(ans[N-2]=='S'){
                    if(ans[0]!='W')tmparu = false;
                }
                else {
                    if(ans[0]!='S')tmparu = false;
                }
            }
            else{
                if(ans[N-2]=='S'){
                    if(ans[0]!='S')tmparu = false;
                }
                else{
                    if(ans[0]!='W')tmparu = false;
                }
            }
        }
        else {
            if(s[N-1]=='x'){
                if(ans[N-2]=='S'){
                    if(ans[0]!='S')tmparu=false;
                }
                else{
                    if(ans[0]!='W')tmparu=false;
                }
            }
            else{
                if(ans[N-2]=='S'){
                    if(ans[0]!='W')tmparu=false;
                }
                else{
                    if(ans[0]!='S')tmparu=false;
                }
            }
        }
        if(ans[0]=='S'){
            if(s[0]=='x'){
                if(ans[N-1]=='S'){
                    if(ans[1]!='W')tmparu=false;
                }
                else{
                    if(ans[1]!='S')tmparu=false;
                }
            }
            else{
                if(ans[N-1]=='S'){
                    if(ans[1]!='S')tmparu=false;
                }
                else{
                    if(ans[1]!='W')tmparu=false;
                }
            }
        }
        else{
            if(s[0]=='x'){
                if(ans[N-1]=='S'){
                    if(ans[1]!='S')tmparu=false;
                }
                else{
                    if(ans[1]!='W')tmparu=false;
                }
            }
            else{
                if(ans[N-1]=='S'){
                    if(ans[1]!='W')tmparu=false;
                }
                else{
                    if(ans[1]!='S')tmparu=false;
                }
            }
        }
        if(tmparu){
            aru=true;
            break;
        }
    }
    if(aru)cout<<ans<<endl;
    else cout<<-1<<endl;
}
