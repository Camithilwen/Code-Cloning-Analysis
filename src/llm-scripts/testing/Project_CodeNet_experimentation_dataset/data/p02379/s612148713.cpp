#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    
    double x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;
    cout<<hypot(x2-x1, y2-y1)<<'\n';
    return 0;
}