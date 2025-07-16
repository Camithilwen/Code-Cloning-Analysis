// 0514 Quality Checking (????????????)
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0514
// by Equim on 16-12-21

#include <cstdio>

int main()
{
    while (true)
    {
        // INPUT
        int a, b, c, Cases;
        scanf("%d%d%d", &a, &b, &c);
        if (a == 0)
            break;
        scanf("%d", &Cases);
        
        int Result[a + b + c + 1];
        for (int i = 1; i <= a + b + c; i++)
        {
            Result[i] = 2;
        }
        
        int RawData[Cases][4];
        for (int i = 0; i < Cases; i++)
        {
            scanf("%d%d%d%d", &RawData[i][0], &RawData[i][1], &RawData[i][2], &RawData[i][3]);
        }
        
        int Unqualified, QualifiedCount;
        bool HasNewChecked = false;
        
        
        // PROCESS
        do
        {
            HasNewChecked = false;
            
            for (int i = 0; i < Cases; i++)
            {
                if (RawData[i][0] + RawData[i][1] + RawData[i][2] == 0)
                    continue;
                
                if (RawData[i][3] == 1)
                {
                    for (int j = 0; j <= 2; j++)
                    {
                        Result[RawData[i][j]] = 1;
                        RawData[i][j] = 0;
                    }
                    HasNewChecked = true;
                }
                else
                {
                    Unqualified = 0;
                    QualifiedCount = 0;
                    for (int j = 0; j <= 2; j++)
                    {
                        if (Result[RawData[i][j]] == 1 || RawData[i][j] == 0)
                        {
                            RawData[i][j] = 0;
                            QualifiedCount++;
                        }
                        else
                            Unqualified = j;
                    }
                    if (QualifiedCount == 2)
                    {
                        Result[RawData[i][Unqualified]] = 0;
                        RawData[i][Unqualified] = 0;
                        HasNewChecked = true;
                    }
                }
            }
        } while (HasNewChecked);

        
        // OUTPUT
        for (int i = 1; i < a + b + c + 1; i++)
        {
            printf("%d\n", Result[i]);
        }
    }
    return 0;
}