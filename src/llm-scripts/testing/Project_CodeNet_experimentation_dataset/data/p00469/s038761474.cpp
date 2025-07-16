#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<set>
#include<string.h>
#include<ctype.h>

using namespace std;

int arr[10];
int sub[10];
int n,k;
int now = 0;
int cont;
int c = 0;

set<int> visit2;

void saiki(int[],int);

int main()
{
	for(;;)
	{
		visit2.clear();
		int i;
		c = 0;
		now = 0;
		
		scanf("%d",&n);
		scanf("%d",&k);
		if(n == 0 && k == 0){
			break;
		}
		
		for(i = 0; i < n; i++){
			scanf("%d",&arr[i]);
		}
		for(i = 0; i < n; i++){
			sub[0] = arr[i];
	//		printf("\næªJ[hF%d\n",arr[i]);
			saiki(sub,1);
			now++;
		}
		cout <<visit2.size()-c << endl;
	}
}

void saiki(int temp[], int kk)
{
	//k:TõK
	int used[50] = {0};
	int i;
	int t = 0;
	char str[256] = "";
	
	for(i = 0; i < kk; i++){
		sprintf(str+strlen(str),"%d",temp[i]);
	}
	
	t = atoi(str);
	
	if(kk == k){
		
		visit2.insert(t);
		return;
	}
	else{ 
		int j;
		
//		cout << "*t = " << t << endl;
		
		for(i = 0; i < kk; i++){
			for(j = 0; j < n; ++j ){     
				if( used[j] == 0 && arr[j] == temp[i] ){
//					printf("J[h%dÍgpÏÝ\n",arr[j]);
					used[j] = 1;
					break;
				}
			}
		}
		
		for(i = 0; i < n; i++){
			if(used[i] == 0){
				temp[kk] = arr[i];
				used[i] = 1;
				saiki(temp, kk+1);
				used[i] = 0;
			}
		}
	}
}
			