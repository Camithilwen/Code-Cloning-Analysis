#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <tuple>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <functional>
#define _LIBCPP_DEBUG 0
using namespace std;


int main(void){
    int l,r;
    cin >> l >> r;
    int mi=2018*2018;
    for (int  i = l; i<r; i++)
    {   
        int L=i%2019;
        for (int j = i+1; j <= r; j++)
        {
            int R=j%2019;
            int ama=(L*R)%2019;
            if (ama<mi)
            {
                mi=ama;
                if (mi==0)
                {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
    }
    cout << mi << endl;
    
}
