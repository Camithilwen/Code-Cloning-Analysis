#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	int n;
	int E=0,out=0,score=0,base=0;
	
	cin >> n ;
	for(;;)
	{
		if(E==n)
			break;
		cin >> str ;
		if(str=="OUT")
		{
			out++;
		}
		else if(str=="HIT")
		{
			base++;
			if(base==4)
			{
				score++;
				base--;
			}
		}
		else
		{
			score+=base+1;
			base=0;
		}
		
		if(out==3)
		{
			cout << score << endl;
			out=base=score=0;
			E++;
		}
	}
}