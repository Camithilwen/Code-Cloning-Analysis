#include <cstdio>
using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int c = 0;
    for(int i = a; i <= b; i++) {
        int p = i % 10, q = i / 10000 % 10;
        int r = i / 10 % 10, s = i / 1000 % 10;
        if(p == q && r == s)
            c++;
    }

    printf("%d\n", c);
}