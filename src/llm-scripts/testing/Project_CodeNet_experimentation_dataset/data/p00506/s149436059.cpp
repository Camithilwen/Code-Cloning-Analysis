#include<iostream>
#include<map>
using namespace std;

int main()
{
  int n;
  cin >> n;
  map<int,int> ans;
  for(int i=0;i<n;i++)
    {
      int num;
      cin >> num;
      for(int j=1;j<=num/2;j++)
	{
	  if(num%j == 0)
	    ans[j]++;
	}
      ans[num]++;
    }

  for(map<int,int>::iterator it = ans.begin();it != ans.end();it++)
    if((*it).second >= n)
      cout << (*it).first << endl;
    
  return 0;
}