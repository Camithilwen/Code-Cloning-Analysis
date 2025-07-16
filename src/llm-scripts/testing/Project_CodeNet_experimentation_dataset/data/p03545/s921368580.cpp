#include <iostream>
#include <vector>
using namespace std;
typedef long long int LLI;

void formula(int arr[], int step, string st_ans, int ans, vector <string> & all)
{
	string tmp1 = st_ans, tmp2 = st_ans;
	if( step < 4 )
	{
		tmp1 += "+";
		tmp1 += (char)(arr[step]+'0');
		formula(arr, step+1, tmp1, ans+arr[step], all);
		
		tmp2 += "-";
		tmp2 += (char)(arr[step]+'0');
		formula(arr, step+1, tmp2, ans-arr[step], all);
	}else{
		if( ans == 7 )
			all.push_back(st_ans+"=7");
	}
}
int main()
{
	vector <string> ans;
	char take;
	int arr[4];
	for(int i = 0; i < 4; i++)
	{
		cin >> take;
		arr[i] = take - '0';
	}
		
	string start = "";
	start += (char)(arr[0]+'0');
	
	formula(arr,1,start,arr[0], ans);
	
	cout << ans[0];
}