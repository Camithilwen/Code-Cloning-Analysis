//Be Name Khoda, Besmellah Rahmane Rahim, In The Name Of God;
//#include<bits/stweight++.h>
#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>
#include <stdio.h>
#include <string.h>
#include<iomanip>
#include<unordered_map>
#include<unordered_set>
#include <fstream>
 
using namespace std;
const int N = 1000 + 5;
int a[N];
int n,m;
vector<int> ans;
 
int main()
{
    cin >> n >> m;
    int cnt = 0;
    for(int i = 1; i <= m; ++i) 
    {
        cin >> a[i];
        cnt += a[i] % 2;
    }
    if (cnt > 2)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    for(int i = 2; i < m; i++) 
    {
        if (a[i] % 2) 
        {
            if (a[1] % 2)
            {
                swap(a[i], a[m]);
            }
            else
            {
                swap(a[i], a[1]);
            }
        }
    }
    for (int i = 1; i <= m; i++) 
    {
        cout << a[i] << " ";
    }
    cout << endl;
    if (m == 1 && a[1] == 1) 
    {
        ans.push_back(1);
    }
    else 
    {
        if (m == 1)
        { 
            ans.push_back(a[1] - 1);
            ans.push_back(1);
        }
        else 
        {
            if (a[1] != 1) 
            {
                ans.push_back(a[1] - 1);
            }
            for (int i = 2; i < m; i++) 
            {
                ans.push_back(a[i]);
            }
            ans.push_back(a[m] + 1);
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) 
    {
        cout << ans[i] << " ";
    }
}