#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>

using namespace std;

int main()
{
    int a;
    int b[3];
    string s;
    
    cin >> s;
    a = s[0] - '0';
    for (int i = 1;i <= 3;i++){
        b[i-1] = s[i] - '0';
    }
    
    int f[3];
    int c[3];
    for (int i = 0;i < (1<<3);i++){
        for (int j = 0;j < 3;j++){
            if ((i>>j)%2){
                f[2-j] = 1;
                c[2-j] = b[2-j];
            }
            else {
                f[2-j] = 0;
                c[2-j] = -b[2-j];
            }
        }
        if (a+c[0]+c[1]+c[2] == 7){
            break;
        }
    }
    cout << a;
    for (int i = 0;i < 3;i++){
        if (f[i]){
            cout << "+" << b[i];
        }
        else {
            cout << "-" << b[i];
        }
    }
    cout << "=7" << endl;
}
