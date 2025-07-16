#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool SortComp(pair<int, int> num1, pair<int, int> num2)
{
	if(num1.second > num2.second)
		return true;
	else if(num1.second < num2.second)
		return false;
	else if(num1.first < num2.first)
		return true;
	else
		return false;
}

int main(void)
{
	while(1)
	{
		int num, min;
		cin>>num>>min;
		if(num == 0 && min == 0)
			break;

		vector<pair<int, int> > arr(101);
		for(int i= 0; i < 101; i++)
			arr[i].first= i+1;

		for(int i= 0; i < num; i++)
		{
			int days;
			cin>>days;

			for(int j= 0; j < days; j++)
			{
				int input;
				cin>>input;
				arr[input-1].second++;
			}
		}

		sort(arr.begin(), arr.end(), SortComp);
		if(arr[0].second < min)
			cout<<0<<endl;
		else
			cout<<arr[0].first<<endl;
	}
}