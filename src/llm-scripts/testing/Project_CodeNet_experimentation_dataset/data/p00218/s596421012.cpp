#include <cstdio>


int n, sum, p[3];
bool f;

int main(){
    while(scanf("%d", &n) != EOF){
        if(n == 0) break;

        for(int i = 0; i < n; i++){
            f = false;
            scanf("%d %d %d", &p[0], &p[1], &p[2]);
            sum = p[0] + p[1] + p[2];

            for(int j = 0; j < 3; j++)
            if(p[j] == 100){
                printf("A\n");
                f = true;
                break;
            }

            if(f) continue;
            if(p[0] + p[1] >= 180){
                printf("A\n");
                continue;
            }
            if(sum >= 240){
                printf("A\n");
                continue;
            }
            if(sum >= 210){
                printf("B\n");
                continue;
            }
            if(sum >= 150 && (p[0] >= 80 || p[1] >= 80)){
                printf("B\n");
                continue;
            }
            printf("C\n");

        }
    }


    return 0;
}