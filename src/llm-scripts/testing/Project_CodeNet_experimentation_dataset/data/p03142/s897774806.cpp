#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> tree(N);
    vector<int> n_in(N);
    for (int i = 0; i < N - 1 + M; i++)
    {
        int Ai, Bi;
        cin >> Ai >> Bi;
        Ai--;
        Bi--;
        tree.at(Ai).push_back(Bi);
        n_in.at(Bi) += 1;
    }

    int r;
    for (int i = 0; i < N; i++)
    {
        if (n_in.at(i) == 0)
        {
            r = i;
            break;
        }
    }

    vector<int> l;
    queue<int> q;
    q.push(r);
    while (q.size())
    {
        int n = q.front();
        q.pop();

        l.push_back(n);
        for (auto &&e : tree.at(n))
        {
            n_in.at(e)--;
            if (n_in.at(e) == 0)
            {
                q.push(e);
            }
        }
    }

    vector<int> p(N, 0);
    for (auto &&n : l)
    {
        for (auto &&e : tree.at(n))
        {
            p.at(e) = n + 1;
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << p.at(i) << endl;
    }
}