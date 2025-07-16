#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int N, x;
    cin >> N >> x;
    int a[N];
    for(int i = 0; i < N; i++)
        cin >> a[i];

    sort(a, a + N);
    
    int cnt = 0, i = 0;
    while(x >= a[i] && i < N){
        cnt++;
        x -= a[i++];
    }
    if(i == N && x > 0)
        cnt--;

    cout << cnt << endl;
    return 0;
}