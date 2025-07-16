#include <bits/stdc++.h>

using namespace std;

int main(){
        int N;
        int out=0;
        cin>>N;
        N*=3;
        string str;
        int ans=0;
        int run=0;
        while(out<N){
                cin>>str;
                if(str=="HIT"){
                        run++;
                        if(run>=4){
                                ans++;
                                run--;
                        }
                }
                else if(str=="OUT"){
                        out++;
                        if(out%3==0){
                                cout<<ans<<endl;
                                ans=0;
                                run=0;
                        }
                }
                else if(str=="HOMERUN"){
                        run++;
                        ans+=run;
                        run=0;
                }
        }

return 0;
}