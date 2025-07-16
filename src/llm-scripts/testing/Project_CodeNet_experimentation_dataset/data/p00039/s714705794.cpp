#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)

int main()
{
  string str;
  //  string roman[] = {"I", "V", "X", "L", "C", "D", "M"};
  map<char, int> roman;
  roman['I'] = 1;
  roman['V'] = 5;
  roman['X'] = 10;
  roman['L'] = 50;
  roman['C'] = 100;
  roman['D'] = 500;
  roman['M'] = 1000;

  while(cin>>str){
    int nums[str.size()];
    REP(i,str.size())
      nums[i] = roman[str[i]];

    int dec=0;    
    int begin=0;
    int i=0;
    while(i<str.size()-1){
      if(nums[i] < nums[i+1]){
	for(int j=begin; j<=i; j++){
	  dec += nums[j];
	  nums[j] = 0;
	}
	begin = i+2;
      }
      if(nums[i] > nums[i+1]){
	begin = i+1;
      }
      i++;
    }

    int res=0;
    REP(i,str.size()) res += nums[i];

    cout << res-dec << endl;
  }

  return 0;
}