#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;
	string::size_type index;
	int num;
	int number;
	int i,j;

	cin >> num;
	getline(cin,str);//ツ催渉可づ個づ「ツづつつセツつッツ禿づ敖債楪づ慊つケ
	for(i=0;i<num;i++)
	{
		getline(cin,str);
		number = 0;
		while((index = str.find("Hoshino") ) != string::npos)
		{
			str.replace(index,7,"Hoshina");
		}
		cout << str << endl;
	}
	return 0;
}