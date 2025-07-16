
#include<iostream>
using namespace std;

struct Test{
  int A[3];
  bool R;
};

Test tests[1000];
int info[301], M[3], N;

int main()
{
  while(true)
  {
    for(int i = 0; i <= 300; i++)
      info[i] = 2;
  
    cin >> M[0] >> M[1] >> M[2];
    if(!(M[0] || M[1] || M[2]))
      break;
    cin >> N;
    for(int i = 1; i <= N; i++)
     cin >> tests[i].A[0] >> tests[i].A[1] >> tests[i].A[2] >> tests[i].R;

    bool b = true;
    while(b)
    {
      b = false;
      for(int i = 1; i <= N; i++)
      {
        if(tests[i].R)
        {
          for(int j = 0; j < 3; j++)
          {
            if(info[tests[i].A[j]] != 1)
            {
              info[tests[i].A[j]] = 1;
              b = true;
            }
          }
        }
        else
        {
          int tmp = 0;
          bool f = false;
          for(int j = 0; j < 3; j++)
          {
            tmp += info[tests[i].A[j]] == 1;
          }
          if(tmp == 2)
          {
            for(int j = 0; j < 3; j++)
            {
              if(info[tests[i].A[j]] == 2)
              {
                info[tests[i].A[j]] = 0;
                b = true;
              }
            }
          }
        }
      }
    }
    for(int i = 1; i <= M[0] + M[1] + M[2]; i++)
    {
       cout << info[i] << endl;
    }
  }
}