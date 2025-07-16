#include <stdio.h>

int par[12 * 12]; // 島の座標の個数

void init(int n)
{
    for (int i = 0; i < n; i++){
        par[i] = i; // i 番目の頂点のグループは最初は i
    }
}

int find(int x)
{
    if (par[x] == x){
        return (x);
    }
    return (par[x] = find(par[x]));
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    
    if (x != y){
        par[y] = x;
    }
}

int same(int x, int y)
{
    return (find(x) == find(y));
}

int main(void)
{
    int i, j;
    int num;
    int groups[12 * 12];
    char island[13][13];
     
    while (1){
        
        //色々初期化
        num = 0;
        init(12 * 12);
        for (i = 0; i < 12 * 12; i++){
            groups[i] = 0;
        }
        for (i = 0; i < 13; i++){
            for (j = 0; j < 13; j++){
                island[i][j] = 0;
            }
        }
        
        //入力
        for (i = 0; i < 12; i++){
            if (scanf("%s", island[i]) == EOF){
                return (0);
            }
        }
        
        for (i = 0; i < 12; i++){
            for (j = 0; j < 12; j++){
                //001
                //001
                //...みたいな繋がり方
                if (island[i][j] == '1' && island[i + 1][j] == '1'){
                    merge(i * 12 + j, (i + 1) * 12 + j);
                }
                //011
                //...みたいな繋がり方
                if (island[i][j] == '1' && island[i][j + 1] == '1'){
                    merge(i * 12 + j, i * 12 + j + 1);
                }
            }
        }
        
        for (i = 0; i < 12; i++){
            for (j = 0; j < 12; j++){
                if (island[i][j] == '1'){
                    groups[find(i * 12 + j)] = 1;
                }
            }
        }
        
        for (i = 0; i < 12 * 12; i++){
            num += groups[i];
        }
        
        printf("%d\n", num);
    }
    
    return (0);
}