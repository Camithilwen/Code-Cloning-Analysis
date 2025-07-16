#include <bits/stdc++.h>
using namespace std;

int	main()
{
  int		nb_min, nb_max, nb;
  int		count = 0;
  string	str, rev;
  
  cin >> nb_min >> nb_max;
  nb = nb_min;
  while (nb <= nb_max)
  {
    str = to_string(nb);
    rev = str;
    reverse(rev.begin(), rev.end());
    if (str == rev)
      count++;
    nb++;
  }
  cout << count << endl;
}