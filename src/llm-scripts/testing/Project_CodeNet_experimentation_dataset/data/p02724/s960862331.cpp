#include<iostream>
#include <bits/stdc++.h>
#include<algorithm>
#include <cstring>
#define endl "\n"
#define SRK ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define EPS 1e-6
#define MAX 100000
typedef long long ll;
const ll MOD = 1e9 + 7;
using namespace std;

int N = 1000000;
int NOD[1000000];
void generateNOD()
{
    for (int i = 0; i <= N; i++)
    {
        for (int j = i; j <= N; j += i)
        {
            NOD[j]++;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int yen500 = 1000 * (n / 500);
    int left = n % 500;
    int yen5 = 5 * (left / 5);
    cout << yen500 + yen5 << endl;

}
