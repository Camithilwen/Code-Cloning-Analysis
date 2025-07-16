#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
#include <assert.h>
#include <cstring>
#include <set>

using namespace std;

typedef long long ll;
int arr[200001];
int main()
{
    int N;
    cin >> N;
    int temp;
    int i;
    int m = 0;
    ll sum = 0;
    for(i = 0; i < N; i++)
    {
        cin >> temp;
        arr[i] = temp;
        m = max(m,arr[i]);
        sum += m-arr[i];
    }
    
    for(i = N-1; i >= 0; i--)
    {
        
    }

    cout << sum;
}