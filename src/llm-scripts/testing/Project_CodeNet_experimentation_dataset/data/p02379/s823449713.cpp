#include <iostream>
#include <cmath>
#include <cstdio>

int main()
{
    using namespace std;
    
    double x1, x2, y1, y2;
    double dis;
        
    cin >> x1 >> y1 >> x2 >> y2;
    
    dis = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    printf("%.8lf\n", dis); 
    
    return 0;
}