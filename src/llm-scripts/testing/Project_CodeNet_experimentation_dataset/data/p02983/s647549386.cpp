/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

long long remindersReps[2019];

int main()
{
    int L, R;
    cin >> L >> R;
    
    for(int i = 0; i < 2019; ++i)
    {
        remindersReps[i] = -1;
    }
    
    int el_lim = L +2020;
    if(R < el_lim)
        el_lim = R;
    for(int i = L; i <= el_lim ; ++i )
    {
        remindersReps[i%2019] = i;
    }
    
    long long reminders[2019];
    
    for(int i = 0; i< 2019;++i)
    {
        if(remindersReps[i]!=1)
            reminders[i] = remindersReps[i]%2019;
    }
    
    long long min = 3000;
    
    long long respL, respR;
    
    for(int i = 0; i < 2019; ++i)
    {
        for(int j = 0; j < 2019; ++j)
        {
            if(remindersReps[i] >= remindersReps[j] ||  remindersReps[i] == -1 || remindersReps[j] == -1)
                continue;
            
            long long temp = (reminders[i]*reminders[j])%2019;
            if( temp < min )
            {
                min = temp;
                respL = remindersReps[i];
                respR = remindersReps[j];
            }
        }
    }
    
    cout << min; 
}


