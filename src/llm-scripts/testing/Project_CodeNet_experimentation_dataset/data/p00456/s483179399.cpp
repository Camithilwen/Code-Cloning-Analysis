#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

int main(void)
{
    int wsd[10], ko[10];
    for(int i=0; i<10; i++) cin>>wsd[i];
    for(int i=0; i<10; i++) cin>>ko[i];
    sort(wsd, wsd+10);
    sort(ko, ko+10);
    printf("%d %d\n",wsd[9]+wsd[8]+wsd[7], ko[9]+ko[8]+ko[7]);

    return 0;
}