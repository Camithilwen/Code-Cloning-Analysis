#include<iostream>
using namespace std;

int main() {
    string sa, sb, sc;
    cin >> sa >> sb >> sc;
    int na = sa.length() + 1;
    int nb = sb.length() + 1;
    int nc = sc.length() + 1;

    int a = 0, b = 0, c = 0;
    char next = 'a', ans = 'A';
    while(a < na && b < nb && c < nc) {
        if (next == 'a') {
            next = sa[a];
            a++;
            ans = 'A';
        } else if (next == 'b') {
            next = sb[b];
            b++;
            ans = 'B';
        } else {
            next = sc[c];
            c++;
            ans = 'C';
        }
    }

    cout << ans << endl;

}