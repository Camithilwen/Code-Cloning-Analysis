#include<stdio.h> 
  
int main(){ 
  int tab[101][3]; 
  int n,a,b,c,d,e,i,j,k,m,t,max,mx,cnt,cn; 
  for(i=0;i<101;i++){ 
    tab[i][0]=0; 
    tab[i][1]=i; 
    tab[i][2]=0; 
  } 
  scanf("%d",&n); 
  m=n*(n-1)/2; 
  for(k=0;k<m;k++){ 
    scanf("%d %d %d %d",&a,&b,&c,&d); 
    if(c>d){ 
      tab[a][0]+=3; 
    }else if(c<d){ 
      tab[b][0]+=3; 
    }else if(c==d){ 
      tab[a][0]++; 
      tab[b][0]++; 
    } 
  } 
  //for(i=1;i<=n;i++)printf("%d\n",tab[i][0]); 
  for(i=n;i>0;i--){ 
    for(j=1;j<i;j++){ 
      if(tab[j][0]<tab[j+1][0]){ 
    t=tab[j][0]; 
    tab[j][0]=tab[j+1][0]; 
    tab[j+1][0]=t; 
  
    t=tab[j][1]; 
    tab[j][1]=tab[j+1][1]; 
    tab[j+1][1]=t; 
      } 
    } 
  } 
  cnt=1; 
  cn=1; 
  //for(i=1;i<=n;i++)printf("%d %d\n",tab[i][0],tab[i][1]); 
  t=tab[1][0]; 
  tab[1][2]=cnt; 
  for(i=2;i<=n;i++){ 
    if(tab[i][0]==t){ 
      tab[i][2]=cnt; 
      cn++; 
    }else{ 
      cnt+=cn; 
      cn=1; 
      t=tab[i][0]; 
      tab[i][2]=cnt; 
    } 
      
  } 
  
  //for(i=1;i<=n;i++)printf("%d %d\n",tab[i][0],tab[i][2]); 
  
  for(i=n;i>0;i--){ 
    for(j=1;j<i;j++){ 
      if(tab[j][1]>tab[j+1][1]){ 
    t=tab[j][2]; 
    tab[j][2]=tab[j+1][2]; 
    tab[j+1][2]=t; 
      
    t=tab[j][1]; 
    tab[j][1]=tab[j+1][1]; 
    tab[j+1][1]=t; 
      } 
    } 
  } 
  for(i=1;i<=n;i++)printf("%d\n",tab[i][2]); 
  return 0; 
} 