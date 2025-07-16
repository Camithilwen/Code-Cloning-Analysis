#include <iostream>
using namespace std;

char judge(int pm, int pe, int pj)
{
    if(pm == 100 || pe == 100 || pj == 100 || pm + pe >= 180 || pm + pe + pj >= 240) return 'A';
    else if(pm + pe + pj >= 210 || pm + pe + pj >= 150 && (pm >= 80 || pe >= 80)) return 'B';
    return 'C';
}

int main()
{
    int n, pm, pe, pj;
    while(cin >> n, n){
        for(int i = 0; i < n; ++i){
            cin >> pm >> pe >> pj;
            cout << judge(pm,pe,pj) << endl;
        }
    }
}