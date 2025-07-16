#include<cstdio>

int main(){
    int n;
    bool a,b,c;
    char event[20];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int score=0;
        a=b=c=false;
        int out =0;
        while(1){
            scanf("%s", event);
            if(event[1]=='I'){
                if(c)score++;
                c=b;
                b=a;
                a=true;
            }else if(event[1]=='O'){
                score++;
                if(a)score++;
                if(b)score++;
                if(c)score++;
                a=b=c=false;
            }else out++;
            if(out==3){
                printf("%d\n", score);
                break;
            }
        }
    }
    return 0;
}

