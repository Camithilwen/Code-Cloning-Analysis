#include <cstdio>
#include <cstdlib>

using namespace std;

template <class Type>
class Bit {
    public:
    Bit(int n) : size(n + 1) {
        bit = (Type *)calloc(size, sizeof(Type));
    }
    
    ~Bit() {
        free(bit);
    }
    
    void add(int x, Type value) {
        for (x++; x < size; x += x & -x) bit[x] += value;
    }
    
    //[0,x]
    Type sum(int x) {
        Type value = 0;
        
        for (x++; x > 0; x -= x & -x) value += bit[x];
        
        return value;
    }
    
    //[x,y]
    Type get(int x, int y) {
        return sum(y) - sum(x - 1);
    }
    
    private:
    
    int size;
    Type *bit;
};

int a[3][100000];
int b[300000][2];
int c[100000];
int f[100000];

int main() {
    int n, c1 = 0, c2 = 0, i, j;
    long long sum1 = 0, sum2 = 0;
    
    scanf("%d", &n);
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            
            a[i][j]--;
            
            b[a[i][j]][0] = i;
            b[a[i][j]][1] = j;
        }
    }
    
    for (i = 0; i < n * 3; i += 3) {
        int x = b[i][0];
        int y = b[i][1];
        int z = i / 3;
        
        if (z % 2 != y % 2 || x == 1 || b[i + 1][1] != y || b[i + 2][1] != y) {
            puts("No");
            
            return 0;
        }
        
        c[y] = z;
        
        if (x == 0) {
            if (b[i + 1][0] != 1 || b[i + 2][0] != 2) {
                puts("No");
                
                return 0;
            }
        } else {
            if (b[i + 1][0] != 1 || b[i + 2][0] != 0) {
                puts("No");
                
                return 0;
            }
            
            f[y] = 1;
        }
    }
    
    Bit <int> b1(n + 1);
    Bit <int> b2(n + 1);
    
    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sum1 += b1.get(c[i], n);
            b1.add(c[i], 1);
            c1 += f[i];
        } else {
            sum2 += b2.get(c[i], n);
            b2.add(c[i], 1);
            c2 += f[i];
        }
    }
    
    if (sum1 % 2 == c2 % 2 && sum2 % 2 == c1 % 2) {
        puts("Yes");
    } else {
        puts("No");
    }
    
    return 0;
}
