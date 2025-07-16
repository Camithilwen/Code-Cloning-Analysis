#include<bits/stdc++.h>
using namespace std;
vector <string> card,memo;
string suzi,m;
int n,k,ans,p,but;


int main(){

    while(1){

        cin >> n >> k;
        if(n==0&&k==0)break;

        for(int i=0;i<n;i++){
            cin >> m;
            card.push_back(m);
        }

        if(k==2){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i!=j){
                        suzi=card[i]+card[j];
                        but=0;
                        while(1){
                            if(p==ans)break;
                            if(memo[p]!=suzi);
                            else {
                                but++;
                                break;
                            }
                        p++;
                        }
                        p=0;
                        if(but==0){
                                ans++;
                               memo.push_back(suzi);
                    }
                }
                but=0;
            }
        }

    }

        if(k==3){
                 for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        for(int a=0;a<n;a++){
                    if(i!=j&&j!=a&&a!=i){
                        suzi=card[i]+card[j]+card[a];
                        but=0;
                        while(1){
                            if(p==ans)break;
                            if(memo[p]!=suzi);
                            else {
                                but++;
                                break;
                            }
                        p++;
                        }
                        p=0;
                        if(but==0){
                                ans++;
                               memo.push_back(suzi);
                    }
                }
                but=0;
                }
            }
        }

        }

        if(k==4){

                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        for(int a=0;a<n;a++){
                            for(int b=0;b<n;b++){
                    if(i!=j&&i!=a&&i!=b&&j!=a&&j!=b&&a!=b){
                        suzi=card[i]+card[j]+card[a]+card[b];
                        but=0;
                        while(1){
                            if(p==ans)break;
                            if(memo[p]!=suzi);
                            else {
                                but++;
                                break;
                            }
                        p++;
                        }
                        p=0;
                        if(but==0){
                                ans++;
                               memo.push_back(suzi);
                    }
                }
                but=0;
                    }
                }
            }
        }

        }

        cout << ans << endl;
        memo.clear();
        card.clear();
        ans=0;
    }


return 0;
}