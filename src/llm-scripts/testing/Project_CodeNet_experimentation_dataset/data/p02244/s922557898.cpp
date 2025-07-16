#include <iostream>
using namespace std;
bool board[8][8];
char grid[8][8];
int upperlim = (1 << 8) - 1;

void solve(int row, int ld, int rd, int d)
{
    // cout<<d<<endl;
    if (d == 8)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (board[i][j] && grid[i][j]!='Q') return;  
            }  
        }

        for (int i = 0; i < 8; ++i)
         {
             for (int j = 0; j < 8; ++j)
             {
                 cout<<grid[i][j];
             }
             cout<<endl;
         } 
         return;
    }

    if (row != upperlim)
    { 
        int pos = upperlim & ~(row | ld | rd);
        while (pos)
        { 
            // cout<<"pos:"<<pos<<endl;
            int p = pos & (~pos + 1);
            // cout<<"p:"<<p<<endl;
            int num = p;
            int col = 0;
            while(num != 1) {
                num = num>>1;
                col++;
            }
            grid[d][col] = 'Q';
            pos = pos - p;
            solve(row + p, (ld + p) << 1, (rd + p) >> 1, d+1);
            grid[d][col] = '.';
        } 
    } 

    return;
}


int main()
{
    int k;
    cin>>k;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            board[i][j] = false;
            grid[i][j] = '.';
        }
    }
    for (int i = 0; i < k; i++)
    {
        int r,c;
        cin>>r>>c;
        board[r][c] = true;
    } 
    
    solve(0, 0 , 0, 0);

    return 0;
}