#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int main(){
	char a;
	int j = 0,o = 0,i = 0;
	int jlv = 0,olv = 0,ilv = 0;
	int mx = 0;
	while(scanf("%c",&a) != EOF){
        if(a == 10)break;
        if(a == 'J'){
            if(o != 0 || i != 0 || o != 0 && i != 0){
                j = o = i = jlv = olv = ilv = 0;
            }
            if(j == 0){
                j++;
            }
            else j++;
            //printf("j   j = %d o = %d i = %d jlv = %d olv = %d ilv = %d\n",j,o,i,jlv,olv,ilv);
        }
        if(a == 'O'){
            if(j != 0){
                jlv = j;
                j = 0;
            }
            if(i != 0){
                i = ilv = 0;
                jlv = 0;
            }
            if(o == 0) o++,olv = o;
            else o++,olv = o;
            //printf("o   j = %d o = %d i = %d jlv = %d olv = %d ilv = %d\n",j,o,i,jlv,olv,ilv);
        }
        if(a == 'I'){
            if(olv != 0){
                j = o = 0;
            }
            if(olv == 0)j = 0;
            if(jlv != 0 && olv != 0){
                j = o = 0;
                i++;
                ilv = i;
            }
            if(jlv >= olv && ilv >= olv)mx = max(mx,olv);
            //printf("i   j = %d o = %d i = %d jlv = %d olv = %d ilv = %d\n",j,o,i,jlv,olv,ilv);
        }
	}
	cout << mx << endl;
	return 0;
}