#include <bits/stdc++.h>

#define NM_MAX 2002

using namespace std;

int n, m;

bool ma[NM_MAX][NM_MAX];

int lg[NM_MAX][NM_MAX];

int v[NM_MAX];

int mxl[NM_MAX];
int mxr[NM_MAX];

stack <int> st;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++)
            ma[i][j] = (s[j - 1] == '#');
    }
    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++)
            ma[i][j] = ma[i][j] ^ ma[i + 1][j] ^ ma[i][j + 1] ^ ma[i + 1][j + 1];
    n--;
    m--;
    for(int i = n; i >= 1; i--)
        for(int j = 1; j <= m; j++)
            if(ma[i][j] == 1)
                lg[i][j] = 0;
            else
                lg[i][j] = lg[i + 1][j] + 1;
    int ans = max(n, m) + 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            v[j] = lg[i][j];
        for(int j = 1; j <= m; j++)
        {
            while(!st.empty() && v[st.top()] >= v[j])
                st.pop();
            if(st.empty())
                mxl[j] = j - 1;
            else
                mxl[j] = j - (st.top() + 1);
            st.push(j);
        }
        while(!st.empty())
            st.pop();
        for(int j = m; j >= 1; j--)
        {
            while(!st.empty() && v[st.top()] >= v[j])
                st.pop();
            if(st.empty())
                mxr[j] = m - j;
            else
                mxr[j] = st.top() - 1 - j;
            st.push(j);
        }
        while(!st.empty())
            st.pop();
        for(int j = 1; j <= m; j++)
            ans = max(ans, (mxl[j] + mxr[j] + 2) * (v[j] + 1));
    }
    cout << ans << "\n";
    return 0;
}
