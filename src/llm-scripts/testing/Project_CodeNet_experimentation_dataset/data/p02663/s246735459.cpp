#include<bits/stdc++.h>

int main(){
        int h, m, k;
        scanf("%d %d", &h, &m);
        int s = h*60 + m;
        scanf("%d %d", &h, &m);
        int g = h*60 + m;
        scanf("%d", &k);
        printf("%d\n", std::max(0, g-s-k));
        return 0;
}
