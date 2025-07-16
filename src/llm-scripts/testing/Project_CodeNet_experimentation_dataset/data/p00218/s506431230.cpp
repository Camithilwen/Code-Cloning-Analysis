#include<cstdio>
int main(){
    int n;
    for(;;){
        scanf("%d",&n);
        if(n==0) break;
        for(int i=0;i<n;i++){
            int p[3];
            char r='C';
            for(int j=0;j<3;j++){
                scanf("%d",&p[j]);
            }
            int sum=0,sumb=0;
            for(int j=0;j<3;j++){
                if(p[j]==100){
                    r='A';
                }
                sum+=p[j];
                if(j!=2) sumb+=p[j];
            }
            if(r=='C'){
                if(sumb/2>=90||sum/3>=80) r='A';
                else if(sum/3>=70) r='B';
                else if(sum/3>=50 && (p[0]>=80 || p[1]>=80)) r='B';
            }
            printf("%c\n",r);
        }
    }
}