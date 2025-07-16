#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W)), B(H, vector<int>(W));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> A.at(i).at(j);
        }
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> B.at(i).at(j);
        }
    }

    vector<vector<int>> d(H, vector<int>(W));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            d.at(i).at(j) = abs(A.at(i).at(j) - B.at(i).at(j));
        }
    }

    auto to_id = [&](int i, int j) {
        return i * W + j;
    };
    vector<vector<bool>> dp(H * W, vector<bool>(80 * 160 + 1));
    dp.at(to_id(0, 0)).at(d.at(0).at(0)) = true;
    for (int i = 1; i < H; i++)
    {
        for (int k = 0; k < 80 * 160 + 1; k++)
        {
            if (dp.at(to_id(i - 1, 0)).at(k))
            {
                dp.at(to_id(i, 0)).at(abs(k + d.at(i).at(0))) = true;
                dp.at(to_id(i, 0)).at(abs(k - d.at(i).at(0))) = true;
            }
        }
    }
    for (int j = 1; j < W; j++)
    {
        for (int k = 0; k < 80 * 160 + 1; k++)
        {
            if (dp.at(to_id(0, j - 1)).at(k))
            {
                dp.at(to_id(0, j)).at(abs(k + d.at(0).at(j))) = true;
                dp.at(to_id(0, j)).at(abs(k - d.at(0).at(j))) = true;
            }
        }
    }
    for (int i = 1; i < H; i++)
    {
        for (int j = 1; j < W; j++)
        {
            for (int k = 0; k < 80 * 160 + 1; k++)
            {
                if (dp.at(to_id(i - 1, j)).at(k))
                {
                    dp.at(to_id(i, j)).at(abs(k + d.at(i).at(j))) = true;
                    dp.at(to_id(i, j)).at(abs(k - d.at(i).at(j))) = true;
                }
                if (dp.at(to_id(i, j - 1)).at(k))
                {
                    dp.at(to_id(i, j)).at(abs(k + d.at(i).at(j))) = true;
                    dp.at(to_id(i, j)).at(abs(k - d.at(i).at(j))) = true;
                }
            }
        }
    }
    for (int k = 0; k < 80 * 160 + 1; k++)
    {
        if (dp.at(to_id(H - 1, W - 1)).at(k))
        {
            cout << k << endl;
            break;
        }
    }
    return 0;
}
