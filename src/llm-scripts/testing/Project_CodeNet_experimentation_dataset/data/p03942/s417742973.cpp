#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000100;

using namespace std;

int n;
char a[N];
char b[N];
int last[N][26];

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                for(int j = 0; j < 26; j++){
                        last[i][j] = last[i - 1][j];
                }
                last[i][a[i] - 'a'] = i;
        }
        bool good = true;
        for(int i = 1; i <= n; i++){
                cin >> b[i];
                if(a[i] != b[i]){
                        good = false;
                }
        }
        if(good){
                cout << 0 << "\n";
                return 0;
        }

        queue < int > v;
        int res = 0, gg = n;
        for(int i = n; i >= 1; i--){
                if(gg > i){
                        gg = i;
                }
                if(a[gg] == b[i]){
                        continue;
                }

                int h = last[gg][b[i] - 'a'];
                if(h == 0){
                        cout << -1 << "\n";
                        return 0;
                }
                gg = h;
                while(!v.empty() && v.front() - v.size() >= i){
                        v.pop();
                }
                v.push(h);
                res = max(res, (int)v.size());
        }
        cout << res << "\n";
}
