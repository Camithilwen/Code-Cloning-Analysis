#include<iostream>
#include<cstring>

int field[14][14];

void dfs(int r,int c);

int main()
{
	int num;
	char buf[14];
	while(1)
	{
		num=0;
		memset(field,0,sizeof(field));
		for(int i=1;i<=12;i++)
		{
			if(std::cin.eof())break;
			std::cin.getline(buf,14);
			if(buf[0]=='\0')
			{
				i--;
				continue;
			}
			for(int j=1;j<=12;j++)
			{
				field[i][j]=buf[j-1]-'0';
			}
		}
		if(std::cin.eof())break;
		
		for(int i=1;i<=12;i++)
		{
			for(int j=1;j<=12;j++)
			{
				if(field[i][j]==1)
				{
					dfs(i,j);
					num++;
				}
			}
		}
		std::cout<<num<<std::endl;
	}
	return 0;
}

void dfs(int r,int c)
{
	field[r][c]=0;
	if(field[r-1][c]==1){dfs(r-1,c);}
	if(field[r+1][c]==1){dfs(r+1,c);}
	if(field[r][c-1]==1){dfs(r,c-1);}
	if(field[r][c+1]==1){dfs(r,c+1);}
}