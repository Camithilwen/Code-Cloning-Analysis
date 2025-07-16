#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n,k,c[10],l[10],e[10000],d,a,b;
	while(true){
		cin>>n;
		cin>>k;
		if(n==0 && k==0){
			break;
		}
		for(int i=0;i<n;i++){
			cin>>c[i];
			if(c[i]>=10){
				l[i]=100;
			}
			else{
				l[i]=10;
			}
		}
		d=0;
		if(k==2){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					b=0;
					if(i!=j){
						a=c[i]*l[j]+c[j];
						for(int k=0;k<d;k++){
							if(a==e[k]){
								goto Exit1;
							}

						}
						e[d]=a;
						d++;
Exit1:
						a=0;
					}
				}
			}
		}

		if(k==3){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					for(int m=0;m<n;m++){
						b=0;
						if(i!=j && (j!=m && m!=i)){
							a=c[i]*(l[j]*l[m])+c[j]*l[m]+c[m];
							for(int k=0;k<d;k++){
								if(a==e[k]){
									goto Exit2;
								}
							}
							e[d]=a;
							d++;
Exit2:
							a=0;
						}

					}
				}
			}
		}

		if(k==4){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					for(int m=0;m<n;m++){
						for(int o=0;o<n;o++){
							b=0;
							if(((i!=j && o!=i) && (j!=m && m!=i)) && (o!=j && o!=m)){
								a=c[i]*(l[j]*l[m]*l[o])+c[j]*(l[m]*l[o])+c[m]*l[o]+c[o];
								for(int k=0;k<d;k++){
									if(a==e[k]){
										goto Exit3;
									}
								}
								e[d]=a;
								d++;
Exit3:
								a=0;
							}
						}

					}
				}
			}
		}

		std::cout<<d<<endl;
	}
	return 0;
}