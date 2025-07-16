#include <bits/stdc++.h>

using namespace std;
int n , f[10] , v[10] , x[10] , y[10];
double sol;

double calc (int a , int b){

    if (a == 0)
        return 0;

    return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));

}

void back(int pas , double sum){
    int i;
    if (pas == n + 1){
        sol += sum;
        return;
    }

    for (i = 1 ; i <= n ; i++){
        if (!f[i]){
            f[i] = 1;
            v[pas] = i;
            back(pas + 1 , sum + calc(v[pas - 1] , v[pas]));
            f[i] = 0;
        }
    }

}

int main()
{
    //FILE *fin = fopen ("a.in","r");
    int i;
    cin >> n;
    for (i = 1 ; i <= n ; i++){
        cin >> x[i] >> y[i];
    }

    back(1 , 0.0);

    for (i = 1 ; i <= n ; i++)
        sol /= i;

    cout << setprecision(8) << fixed << sol;

    return 0;
}
