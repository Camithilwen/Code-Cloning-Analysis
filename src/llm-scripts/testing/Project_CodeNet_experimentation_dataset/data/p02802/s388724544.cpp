#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int n, m;
    cin>>n>>m;
    if(n == 0 || m == 0){
        cout<<"0 0";
        return 0;
    }    
    bool accepted[n];
    unordered_map<int, int> ma;
    for(int i = 0; i < n; i++){
        accepted[i] = false;
    }
    for(int i = 0; i < m; i++){
        int p; string s;
        cin>>p>>s;
        p-=1;
        if(s == "AC"){
            accepted[p] = true;
        }else{
            if(!accepted[p]){
                if(ma.find(p) == ma.end()){
                    ma[p] = 1;
                }else
                {
                    ma[p]++;
                }
                
            }
        }
    }                 
    int correct = 0, penalties = 0;
    for(int i = 0; i < n; i++){
        if(accepted[i]){
            correct++;
            penalties += ma[i];
        }
    }                         
    cout<<correct<<" "<<penalties;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
    return 0;
}