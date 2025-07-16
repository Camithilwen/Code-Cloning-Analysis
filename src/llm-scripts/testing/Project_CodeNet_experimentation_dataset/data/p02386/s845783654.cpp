#include<stdio.h>
#include<string.h>
typedef struct {
	char direction[100];
	int num1,num2,num3,num4,num5,num6;
}DICE_t;
int main(){
	int n;
	scanf("%d",&n);
	DICE_t a[n];
	for(int x=0;x<n;x++){
	    scanf("%d %d %d %d %d %d",&a[x].num1,&a[x].num2,&a[x].num3,&a[x].num4,&a[x].num5,&a[x].num6);
	}
	int x,y;
	for(x=0;x<(n-1);x++){
		for(y=(x+1);y<n;y++){
	        int dummy,turn=0;
	        while(turn<24){
		        if(turn%4==0&&turn!=0){
		    	    strcpy(a[y].direction,(turn%8==4 ?"SSEN":"ESEN"));
	    	    }
    		    else{
        			strcpy(a[y].direction,"SEN");
    	    	}
    	        for(int i=0;a[y].direction[i]!=0;i++){
    	            if(a[y].direction[i]=='N'){
		                dummy=a[y].num5;
	            	    a[y].num5=a[y].num1;
	            	    a[y].num1=a[y].num2;
	            	    a[y].num2=a[y].num6;
	        	        a[y].num6=dummy;
	                }
	                else if(a[y].direction[i]=='S'){
		                dummy=a[y].num6;
	            	    a[y].num6=a[y].num2;
	            	    a[y].num2=a[y].num1;
	            	    a[y].num1=a[y].num5;
	            	    a[y].num5=dummy;
	                }
    	    	    else if(a[y].direction[i]=='E'){
		                dummy=a[y].num4;
	        	        a[y].num4=a[y].num6;
	        	        a[y].num6=a[y].num3;
	        	        a[y].num3=a[y].num1;
	        	        a[y].num1=dummy;
	                }
	                else if(a[y].direction[i]=='W'){
	                    dummy=a[y].num1;
    	            	a[y].num1=a[y].num3;
	                	a[y].num3=a[y].num6;
	                	a[y].num6=a[y].num4;
	                	a[y].num4=dummy;
	                }	
    	        }
	        	if(a[x].num1==a[y].num1&&a[x].num2==a[y].num2&&a[x].num3==a[y].num3&&a[x].num4==a[y].num4&&a[x].num5==a[y].num5&&a[x].num6==a[y].num6){
	        		printf("No\n");
	        		goto end;
	        	}
	    	    turn++;
	        }
		}
	}
	printf("Yes\n");
end:	
	
	return 0;
}