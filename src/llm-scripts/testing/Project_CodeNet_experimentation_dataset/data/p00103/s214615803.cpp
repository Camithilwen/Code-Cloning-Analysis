#include<string>
#include<iostream>

using namespace std;

int main()
{
	int n;	cin>>n;
	string s;
	int runner=0,out=0,score=0;
	while(cin>>s){
		if(s=="HIT"){
			runner<<=1;
			if(runner&8)runner&=~8,score++;
			runner|=1;
		}
		else if(s=="HOMERUN"){
			for(int i=0;i<3;i++){
				runner<<=1;
				if(runner&8)runner&=~8,score++;
			}
			score++;
		}
		else{
			out++;
			if(out==3)	cout<<score<<endl,runner=out=score=0;
		}
	}
	return 0;
}