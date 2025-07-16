#include<iostream>
using namespace std;
int main()
{
    int n, a, b, c, d, i, j, team[100], score[100];
    cin >> n;
    for (i = 1; i <= n; i++) {
        team[i] = 0;
    }
    for (i = 0; i < n*(n - 1) / 2; i++) {
        cin >> a >> b >> c >> d;
        if (c > d)
            team[a] += 3;
        else if (c < d)
            team[b] += 3;
        else {
            team[a]++;
            team[b]++;
        }
    }
    for(i=1;i<=n;i++){
        score[i] = 1;
        for (j = 1; j <= n; j++) {
            if (team[i] < team[j]) 
                score[i]++;
        }
    }
    for (i = 1; i <= n; i++) {
        cout << score[i] << endl;
    }
    return 0;
}

