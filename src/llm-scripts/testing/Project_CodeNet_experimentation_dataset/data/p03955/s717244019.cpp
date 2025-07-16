#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define endl '\n'
using namespace std;
const int N = 1e5 + 5;

int n, a[4][N];

int inv[2], flip[2];
int label[N];

void add_col(vector <int> v, int id)
{
    if(abs(v[2] - v[0]) != 2 || abs(v[1] - v[0]) != 1 || v[1] % 3 < 2)
    {
        cout << "No" << endl;
        exit(0);
    }

    int parity = !(v[1] & 1);
    if(v[0] > v[2])
        flip[parity]++;

    label[(v[1] + 1) / 3] = id;
    if(id & 1 != parity)
    {
        cout << "No" << endl;
        exit(0);
    }
}

bool vis[N];
int comp_sz;
void DFS(int v)
{
    vis[v] = true;
    comp_sz++;
    if(!vis[label[v]])
        DFS(label[v]);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];

    for(int j = 1; j <= n; j++)
    {
        vector <int> v = {a[1][j], a[2][j], a[3][j]};
        add_col(v, j);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            comp_sz = 0;
            DFS(i);
            inv[i & 1] += (comp_sz - 1);
        }
    }

    inv[0] &= 1;
    inv[1] &= 1;
    flip[0] &= 1;
    flip[1] &= 1;
    if(inv[0] != flip[1] || inv[1] != flip[0])
        cout << "No" << endl;
    else
        cout << "Yes" << endl;

    return 0;
}
