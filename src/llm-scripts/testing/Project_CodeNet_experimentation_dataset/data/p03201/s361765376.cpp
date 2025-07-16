#include <bits/stdc++.h>

using namespace std;

const int max_n = 2e5 + 5;

int tab[max_n];

map<int, int> zliczanie;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, wynik = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> tab[i];
        zliczanie[tab[i]]++;
    }
    sort(tab, tab + n);
    for (int i = n - 1; i >= 0; i--){
        if (!zliczanie[tab[i]])
            continue;
        zliczanie[tab[i]]--;
        if (zliczanie[(2 << __lg(tab[i])) - tab[i]]){
            zliczanie[(2 << __lg(tab[i])) - tab[i]]--;
            wynik++;
        }
    }
    cout << wynik << "\n";
    return 0;
}