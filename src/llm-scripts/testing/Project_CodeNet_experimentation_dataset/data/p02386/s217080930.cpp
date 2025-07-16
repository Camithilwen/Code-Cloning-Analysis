#include <iostream>
using namespace std;

void direction(char d, int dice[])
{
    int temp;
    switch(d)
    {
        case 'E': temp    = dice[1];
                  dice[1] = dice[4];
                  dice[4] = dice[6];
                  dice[6] = dice[3];
                  dice[3] = temp;
                  break;
        case 'S': temp    = dice[1];
                  dice[1] = dice[5];
                  dice[5] = dice[6];
                  dice[6] = dice[2];
                  dice[2] = temp;
                  break;
        case 'W': temp    = dice[1];
                  dice[1] = dice[3];
                  dice[3] = dice[6];
                  dice[6] = dice[4];
                  dice[4] = temp;
                  break;
        case 'N': temp    = dice[1];
                  dice[1] = dice[2];
                  dice[2] = dice[6];
                  dice[6] = dice[5];
                  dice[5] = temp;
                  break;
        case 'R': temp    = dice[2];
                  dice[2] = dice[3];
                  dice[3] = dice[5];
                  dice[5] = dice[4];
                  dice[4] = temp;
                  break;
    }
    return;
}

int main ()
{
    int n;
    cin >> n;
    
    int dice[n][7], same[n];
    for (int i = 0;i < n;i++) same[i] = true;
    
    for (int i = 0;i < n;i++)
    {
        for (int j = 1;j <= 6;j++)
        {
            cin >> dice[i][j];
        }
    }
    
    
    for (int i = 1;i < n;i++)
    {
        for(int j = 1;j <= 4;j++)
        {
            if (dice[i][1] != dice[0][1])
            {
                direction('N', dice[i]);
            }
            else break;
        }
        if (dice[i][1] != dice[0][1])
        {
            if (dice[i][3] == dice[0][1]) direction('W', dice[i]);
            else if (dice[i][4] == dice[0][1]) direction('E', dice[i]);
            else same[i] = false;
        }
        if (same[i])
        {
            for(int j = 1;j <= 4;j++)
            {
                if (dice[i][2] != dice[0][2])
                {
                    direction('R', dice[i]);
                }
                else break;
            }
            for(int j = 1;j <= 6;j++)
            {
                if (dice[i][j] != dice[0][j])
                {
                    same[i] = false;
                    break;
                }
            }
        }
    }
    
    int alldiff = true;
    for (int i = 1;i < n;i++)
    {
        if (same[i])
        {
            alldiff = false;
            break;
        }
    }
    
    if (alldiff) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}

