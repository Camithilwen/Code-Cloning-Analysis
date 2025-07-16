#include<iostream>
#include<string>

using namespace std;

void sort(int card[5])
{
	for(int i=0;i<5;i++)
	{
		int max=i;
		for(int j=i+1;j<5;j++)
		{
			if(card[max]<card[j])
			{
				max=j;
			}
		}
		int tmp=card[i];
		card[i]=card[max];
		card[max]=tmp;
	}
}

bool fourcard(int card[5])
{
	if((card[0]==card[1]&&card[1]==card[2]&&card[2]==card[3])||
		(card[1]==card[2]&&card[2]==card[3]&&card[3]==card[4]))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool fullhouse(int card[5])
{
	if((card[0]==card[1]&&card[2]==card[3]&&card[3]==card[4])||
		(card[0]==card[1]&&card[1]==card[2]&&card[3]==card[4]))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool straight(int card[5])
{
	if((card[0]-1==card[1]&&card[1]-1==card[2]&&card[2]-1==card[3]&&card[3]-1==card[4])||
		(card[0]==13&&card[1]==12&&card[2]==11&&card[3]==10&&card[4]==1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool threecard(int card[5])
{
	if((card[0]==card[1]&&card[1]==card[2])||
		(card[1]==card[2]&&card[2]==card[3])||
		(card[2]==card[3]&&card[3]==card[4]))
	{
		return true;
	}
	else{
		return false;
	}
}

bool twopair(int card[5])
{
	if((card[0]==card[1]&&card[2]==card[3])||
		(card[0]==card[1]&&card[3]==card[4])||
		(card[1]==card[2]&&card[3]==card[4]))
	{
		return true;
	}
	else return false;
}

bool onepair(int card[5])
{
	if(card[0]==card[1]||
		card[1]==card[2]||
		card[2]==card[3]||
		card[3]==card[4])
	{
		return true;
	}
	else return false;
}

char *solve(int card[5])
{
	sort(card);
	if(fourcard(card))
	{
		return "four card";
	}
	else if(fullhouse(card))
	{
		return "full house";
	}
	else if(straight(card))
	{
		return "straight";
	}
	else if(threecard(card))
	{
		return "three card";
	}
	else if(twopair(card))
	{
		return "two pair";
	}
	else if(onepair(card))
	{
		return "one pair";
	}
	else
	{
		return "null";
	}
}

int main(void)
{
	int card[5];
	char c;
	while(cin>>card[0])
	{
		for(int i=1;i<5;i++)
		{
			cin>>c>>card[i];
		}
		cout<<solve(card)<<endl;
	}
}