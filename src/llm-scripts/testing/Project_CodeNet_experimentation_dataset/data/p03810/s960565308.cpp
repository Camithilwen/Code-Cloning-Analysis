#include <iostream>
using namespace std;

int gcd(int n, int m){
    if(n % m == 0) return m;
    return gcd(m, n % m);
}

int main()
{
    int n;
    cin >> n;
    int a[100005];
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n == 1){
        cout << "Second" << endl;
        return 0;
    }
    if(n == 2){
        if(a[0] % 2 == a[1] % 2) cout << "Second" << endl;
        else cout << "First" << endl;
        return 0;
    }
    bool first = true;
    while(true){
        int m = 2;
        int l = 0;
        int c = 0;
        for(int i = 0; i < n; i++){
            m = min(m, a[i]);
            if(a[i] % 2) c++;
            else l = 1 - l;
        }
        if(l == 1){
            if(first) cout << "First" << endl;
            else cout << "Second" << endl;
            return 0;
        }
        else if(c > 1 || m == 1){
            if(first) cout << "Second" << endl;
            else cout << "First" << endl;
            return 0;
        }
        else{
            for(int i = 0; i < n; i++) a[i] = a[i] / 2 * 2;
            int g = 0;
            for(int i = 0; i < n; i++) g = gcd(g, a[i]);
            for(int i = 0; i < n; i++) a[i] /= g;
        }
        first = !first;
    }
}
