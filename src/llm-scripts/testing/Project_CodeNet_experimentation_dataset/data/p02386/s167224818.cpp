#include <iostream>
#include <complex>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

void rotate(int a[], string str)
{
    for(auto itr = str.begin(); itr != str.end(); ++itr)
    {
        int tmp;
        switch (*itr) {
            case 'N':
                tmp = a[0];
                a[0] = a[1];
                a[1] = a[5];
                a[5] = a[4];
                a[4] = tmp;
                break;
            case 'S':
                tmp = a[0];
                a[0] = a[4];
                a[4] = a[5];
                a[5] = a[1];
                a[1] = tmp;
                break;
            case 'W':
                tmp = a[3];
                a[3] = a[0];
                a[0] = a[2];
                a[2] = a[5];
                a[5] = tmp;
                break;
            case 'E':
                tmp = a[2];
                a[2] = a[0];
                a[0] = a[3];
                a[3] = a[5];
                a[5] = tmp;
                break;
        }
    }
}

int isSame(int a[], int b[])
{
    bool flag;
    for (int i = 0; i < 6; ++i) {
        flag = false;
        for (int j = 0; j < 6; ++j) {
            if (a[i] == b[j]) {
                flag = true;
                break;
            }
        }
        if (flag==false)
            break;
    }

    if (flag == false) {
        return 0;
    }

    int t = b[0], f = b[1];

    if (t == a[5])
            rotate(a, "NN");
    else if (t == a[1])
            rotate(a, "N");
    else if (t == a[3])
            rotate(a, "E");
    else if (t == a[2])
            rotate(a, "W");
    else if (t == a[4])
            rotate(a, "S");

    if (f == a[3])
            rotate(a, "ESW");
    else if (f == a[2])
            rotate(a, "WSE");
    else if (f == a[4])
                rotate(a, "SENWSE");

    for (int i = 0; i < 6; ++i) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}


int main(void)
{
    int a[100][6], n;

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 6; ++j)
            cin >> a[i][j];

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (i == j)
                continue;
            if (isSame(a[j], a[i]) == 1) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}





