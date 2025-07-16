#include <bits/stdc++.h>		//万能头文件 
using namespace std;

int main()
{
	string a;
	int pos=0;		//记录位置 
	cin>>a;
	a=a+"D";		//为防止最后一个字母是"A",添加一个不是"C"的字母 
	while(1)
	{
		pos=a.find("A",pos);		//find()函数查找位置 
		if(pos<0)		//如果没找到，返回-1 
		{
			cout<<"No"<<endl;		//endl养成好习惯 
			break;		//跳出循环 
		}
		if(a[pos+1]=='C')		//判断"A"下一个是不是"C"
		{
			cout<<"Yes"<<endl;
			break;		//跳出循环
		}
		pos++;		//下一次从pos+1找起 
	}
	return 0;
}