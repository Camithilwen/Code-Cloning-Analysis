#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

struct Info{
	int succeed_num;
};

int main(){

	char* buf = new char[1000001];
	char pre;
	Info J_data,O_data;
	J_data.succeed_num = O_data.succeed_num = 0;

	scanf("%s",buf);

	int index,tmp,max_level;

	for(index = 0; buf[index] != 'J' && buf[index] != '\0';index++);

	pre = buf[index];

	if(pre == '\0'){
		printf("0\n");
		return 0;
	}

	max_level = 0;
	tmp = 0;
	for(;buf[index] != '\0';){
		if(pre == buf[index]){
			tmp++;

			if(buf[index+1] == '\0'){
				if(pre == 'I' && O_data.succeed_num <= J_data.succeed_num && O_data.succeed_num <= tmp){
					max_level = max(max_level,O_data.succeed_num);
				}
			}
			index++;
		}else{
			switch(pre){
			case 'J':
				if(buf[index] == 'O'){
					J_data.succeed_num = tmp;
					O_data.succeed_num = 0;
					pre = 'O';
				}else{
					for(;buf[index] != 'J' && buf[index] != '\0';index++);
					J_data.succeed_num = 0;
					O_data.succeed_num = 0;
					pre = 'J';
				}
				break;
			case 'O':
				if(buf[index] == 'I'){
					O_data.succeed_num = tmp;
					pre = 'I';
				}else{
					O_data.succeed_num = 0;
					pre = 'J';
				}
				break;
			case 'I':

				if(O_data.succeed_num <= J_data.succeed_num && O_data.succeed_num <= tmp){
					max_level = max(max_level,O_data.succeed_num);
				}
				J_data.succeed_num = 0;
				O_data.succeed_num = 0;

				if(buf[index] == 'J'){
					pre = 'J';
				}else{
					for(;buf[index] != 'J' && buf[index] != '\0';index++);
					pre = 'J';
				}
				break;
			}
			tmp = 0;
		}
	}

	printf("%d\n",max_level);

	return 0;
}