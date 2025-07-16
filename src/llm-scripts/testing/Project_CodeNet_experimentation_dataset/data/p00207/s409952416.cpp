#include<iostream>
using namespace std;

int F[102][102];

void
DFS (int Y, int X, int A)
{
  if (F[Y][X] != A)
    return;

  F[Y][X] = 7;

  DFS (Y - 1, X, A);
  DFS (Y, X + 1, A);
  DFS (Y + 1, X, A);
  DFS (Y, X - 1, A);
}

int
main ()
{
  int w, h;
  int xs, ys;
  int xg, yg;
  int n;
  int c, d, x, y;

  while (true)
    {
      cin >> w >> h;
      if (w == 0 && h == 0)
	break;
      cin >> xs >> ys;
      cin >> xg >> yg;
      cin >> n;

      for (int i = 0; i < n; i++)
	{
	  cin >> c >> d >> x >> y;
	  if (d == 0)
	    {
	      for (int a = 0; a < 4; a++)
		{
		  for (int b = 0; b < 2; b++)
		    {
		      F[y + b][x + a] = c;
		    }
		}

	    }
	  else
	    {
	      for (int a = 0; a < 2; a++)
		{
		  for (int b = 0; b < 4; b++)
		    {
		      F[y + b][x + a] = c;
		    }
		}
	    }

	}


      if (F[ys][xs] == 1 || F[ys][xs] == 2 || F[ys][xs] == 3
	  || F[ys][xs] == 4 || F[ys][xs] == 5)
	{
	  DFS (ys, xs, F[ys][xs]);
	}

      if (F[yg][xg] == F[ys][xs])
	{
	  cout << "OK" << endl;
	}
      else
	{
	  cout << "NG" << endl;
	}

    }

  return 0;
}