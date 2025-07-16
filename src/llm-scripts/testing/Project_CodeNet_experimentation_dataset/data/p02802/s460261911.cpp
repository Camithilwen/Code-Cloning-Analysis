#include<algorithm>
using namespace std;

#define MAXN 100000

int AC[MAXN] = {};
int WA[MAXN] = {};

int main()
{
    int ACCount = 0;
    int WACount = 0;
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0; i < m; i++)
    {
        int curNum;
        char first, second;
        scanf("%d %c%c", &curNum, &first, &second);
        if(AC[curNum - 1] != 0)
        {
            continue;
        }
        if(first == 'A')
        {
            AC[curNum - 1] = 1;
            WACount += WA[curNum - 1];
            ACCount += 1;
        }
        else
        {
            WA[curNum - 1] += 1;
        }
    }
    printf("%d %d",ACCount, WACount);
}