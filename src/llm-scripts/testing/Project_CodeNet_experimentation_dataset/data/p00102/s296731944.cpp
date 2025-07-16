#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
signed main(){
        int a;
        while( scanf("%lld", &a) != EOF ){
                if(a==0) break;
                vector<vector<int>> m(a+1,vector<int>(a+1,0));
                for(int i=0;i<a;i++){
                        int s = 0;
                        for(int j=0;j<a;j++){
                                int b;
                                scanf("%lld", &b);
                                m[i][j] = b;
                                s += b;
                        }
                        m[i][a] = s;
                }
                for(int j=0;j<a+1;j++){
                        int s = 0;
                        for(int i=0;i<a;i++){
                                s += m[i][j];
                        }
                        m[a][j] = s;
                }
                for(int i=0;i<a+1;i++){
                        for(int j=0;j<a+1;j++){
                                printf("%5lld", m[i][j]);
                        }
                        printf("\n");
                }
        }
        return 0;
}