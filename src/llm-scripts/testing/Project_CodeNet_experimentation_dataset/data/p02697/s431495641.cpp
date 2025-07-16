#include <bits/stdc++.h>
using namespace std;

void Main()
{
    int n, m;
    cin >> n >> m;
    int a[m], b[m];
    int j = 0;

    int sp = 0;
    for (int i = 0; i < m/2; i++)
    {
        a[i] = j;
        j++;
        sp++;
    }
    int sp2 = sp;
    if(m % 2 == 1){
        a[sp] = j;
        j++;
        b[sp] = j;
        j++;
        sp++;
    }
    for (int i = 0; i < m/2; i++)
    {
        b[sp2-i-1] = j;
        j++;
    }

    for (int i = 0; i < m/2; i++)
    {
        a[i+sp] = j;
        j++;
    }
    j++;
    for (int i = 0; i < m/2; i++)
    {
        b[sp2-i-1+sp] = j;
        j++;
    }
    for (int i = 0; i < m; i++){
        cout << a[i]+1 << " " << b[i]+1 << endl;
    }

}

int main(int argc, char **argv)
{
    Main();
    return 0;
}
