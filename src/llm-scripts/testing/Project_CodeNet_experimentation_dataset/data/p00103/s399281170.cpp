#include<cstdio>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int point=0;
        int base=0;
        int out=0;
        while(out!=3){
            char s[8];
            scanf(" %s",s);
            switch(s[1]){
                case 'I':
                    base++;
                    if(base==4){
                        point++;
                        base--;
                    }
                    break;
                case 'U':
                    out++;
                    break;
                case 'O':
                    point+=base+1;
                    base=0;
                    break;
            }
        }
        printf("%d\n",point);
    }
    return 0;
}