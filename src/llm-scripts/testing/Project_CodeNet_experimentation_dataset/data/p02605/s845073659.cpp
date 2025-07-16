#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
struct Node
{
    int first , second;
    int dir;
}node[maxn];
// x + y
bool cmp1(const Node & a , const Node & b)
{
    if (a.first + a.second != b.first + b.second)
        return a.first + a.second < b.first + b.second;
    return a.first < b.first;
}
// x - y
bool cmp2(const Node & a , const Node & b)
{
    if (a.first - a.second != b.first - b.second)
        return a.first - a.second < b.first - b.second;
    return a.first < b.first;
}
// x
bool cmp3(const Node & a , const Node & b)
{
    if (a.first!= b.first)
        return a.first < b.first;
    return a.second < b.second;
}
// y
bool cmp4(const Node & a , const Node & b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int check (char g)
{
    if (g == 'U') return 0;
    if (g == 'D') return 1;
    if (g == 'R') return 2;
    return 3;
}
int main()
{
    ios::sync_with_stdio(false);
    int n ; cin >> n;
    for (int i = 1 ; i <= n ; i++){
        cin >> node[i].first >> node[i].second;
        char g;
        cin >> g;
        node[i].dir = check(g);
    }
    int ans = 1e9;
    node[0].first = node[0].second = -1;
    int pos , pos2;

    sort(node + 1 , node + 1 + n , cmp1);
    for (int i = 1 ; i <= n ; i++){
        if (node[i].first + node[i].second != node[i - 1].first + node[i - 1].second){
            pos = pos2 = -1;
        }

        if (node[i].dir == check('U')){
            if (pos != -1)
                ans = min (ans , abs(node[i].first - node[pos].first) * 10);
        }
        if (node[i].dir == check('R')){
            pos = i;
        }

        if (node[i].dir == check('L')){
            if (pos2 != -1)
                ans = min (ans , abs(node[i].first - node[pos2].first) * 10);
        }
        if (node[i].dir == check('D')){
            pos2 = i;
        }
    }

    sort(node + 1 , node + 1 + n , cmp2);
    for (int i = 1 ; i <= n ; i++){
        if (node[i].first - node[i].second != node[i - 1].first - node[i - 1].second){
            pos = pos2 = -1;
        }
        if (node[i].dir == check('L')){
            if (pos != -1)
                ans = min (ans , abs(node[i].first - node[pos].first) * 10);
        }
        if (node[i].dir == check('U')){
            pos = i;
        }

        if (node[i].dir == check('D')){
            if (pos2 != -1)
                ans = min (ans , abs(node[i].first - node[pos2].first) * 10);
        }
        if (node[i].dir == check('R')){
            pos2 = i;
        }

    }

    sort(node + 1 , node + 1 + n , cmp3);
    for (int i = 1 ; i <= n ; i++){
        if (node[i].first != node[i - 1].first){
            pos = -1;
        }
        if (node[i].dir == check('D')){
            if (pos != -1)
                ans = min (ans , abs(node[i].second - node[pos].second) * 5);
        }
        else if (node[i].dir == check('U')){
            pos = i;
        }
    }

    sort(node + 1 , node + 1 + n , cmp4);
    for (int i = 1 ; i <= n ; i++){
        if (node[i].second != node[i - 1].second){
            pos = -1;
        }
        if (node[i].dir == check('L')){
            if (pos != -1)
                ans = min (ans , abs(node[i].first - node[pos].first) * 5);
        }
        else if (node[i].dir == check('R')){
            pos = i;
        }
    }
    if (ans == 1e9) cout << "SAFE" << endl;
    else cout << ans << endl;
    return 0;
}
