#include <stdio.h>
#include <string.h>

int main(void){
	int p, sum, d, e, f, s, m, n, i, j, x, max_i;
	double tmp1, eff[50];  
	char str[50][21], C, tmp2[21];
	while(1){
		scanf("%d%*c",&n);
		if(n == 0)
			break;
		for(i = 0;i < n;i++){ 
			j = 0;           
			while((C = getchar()) != ' ')      
				str[i][j++] = C;            
			str[i][j] = '\0';
			scanf("%d",&p); 
			sum = 0;     
			for(j = 0;j < 3;j++){   
				scanf("%d",&x);          
				sum += x;      
			}   
			scanf("%d%d%d%d%d%*c",&d,&e,&f,&s,&m);   
			for(j = 0;j < m;j++)            
				sum += d + e;      
			eff[i] = (double)(m * f * s - p) / sum; // 期作 * 1つの種からできる実の数 * 実の価格 - 種の値段 
		}
		for(i = 0;i < n - 1;i++){   
			max_i = i;           
			for(j = i + 1;j < n;j++){   
				if(eff[max_i] < eff[j])     
					max_i = j;        
				else if(eff[max_i] == eff[j] && strcmp(str[max_i],str[j]) > 0)  
					max_i = j;        
			}           
			if(i != max_i){    
				tmp1 = eff[i];     
				strcpy(tmp2,str[i]);       
				eff[i] = eff[max_i];              
				strcpy(str[i],str[max_i]);          
				eff[max_i] = tmp1;          
				strcpy(str[max_i],tmp2);      
			}       
		}       
		for(i = 0;i < n;i++) 
			printf("%s\n",str[i]);     
		printf("#\n");     
	}
	
	return 0; 
} 