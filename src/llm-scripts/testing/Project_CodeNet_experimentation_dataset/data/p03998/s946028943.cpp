#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    char turn = 'a';
    string a, b, c;
    int i = 0, j = 0, k = 0;
    cin >> a >> b >> c;
    while (i <= a.size() && j <= b.size() && k <= c.size()) 
    {
        if (turn == 'a') 
            turn = a[i++];
        else if (turn == 'b') 
            turn = b[j++];
        else 
            turn = c[k++];
    }
    if (i > a.size()) cout << "A" << endl;
    else if (j > b.size()) cout << "B" << endl;
    else cout << "C" << endl;
}