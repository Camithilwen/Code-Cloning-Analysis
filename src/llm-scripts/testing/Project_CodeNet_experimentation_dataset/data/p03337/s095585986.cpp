#include<bits/stdc++.h>
using namespace std;
void display()
{
    int a, b, ar[3];
    cin>>a>>b;
    ar[0] = a+ b, ar[1] = a - b , ar[2] = a * b;
    sort(ar, ar + 3);
    cout<<ar[2]<<endl;
}
int main(void)
{
    display();
}
