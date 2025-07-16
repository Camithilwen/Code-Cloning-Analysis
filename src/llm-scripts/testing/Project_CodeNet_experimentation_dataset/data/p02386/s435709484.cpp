#include<cstdio>

int comparedice(void);
class dice{
private:
	int a,b,c,d,e,f;
public:
	void setnumber(void);
	void E(void);
	void W(void);
	void S(void);
	void N(void);
	void R(void);
	void V(void);
	int frontside(int x,int y);
	int putme(char me);
};

void dice::setnumber(void){
scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
}


void dice::E(void){
int a1=a,c1=c,d1=d,f1=f;
a=d1;
c=a1;
d=f1;
f=c1;
}

void dice::W(void){
int a1=a,c1=c,d1=d,f1=f;
a=c1;
c=f1;
d=a1;
f=d1;
}

void dice::S(void){
int a1=a,b1=b,e1=e,f1=f;
a=e1;
b=a1;
e=f1;
f=b1;
}

void dice::N(void){
int a1=a,b1=b,e1=e,f1=f;
a=b1;
b=f1;
e=a1;
f=e1;
}

int dice::frontside(int x,int y){
int i=0,a1,b1,c1,d1,e1,f1;
while(1){
	a1=a;
	b1=b;
	c1=c;
	d1=d;
	e1=e;
	f1=f;
	a=b1;
	b=c1;
	c=a1;
	d=f1;
	e=d1;
	f=e1;
	i++;
	if(i==4)break;
}

if (b!=x){
	a=e1;
	b=f1;
	c=d1;
	d=c1;
	e=a1;
	f=b1;
}
//printf("%d %d %d %d %d %d\n",a,b,c,d,e,f);
i=0;
while (b!=x){
	a1=a;
	b1=b;
	c1=c;
	d1=d;
	e1=e;
	f1=f;
	a=b1;
	b=c1;
	c=a1;
	d=f1;
	e=d1;
	f=e1;
	i++;
	if(i==4)break;
}
if(i==4){ return 0;}
i=0;
while(c!=y){
	a1=a;
	c1=c;
	d1=d;
	f1=f;
	a=d1;
	c=a1;
	d=f1;
	f=c1;
	i++;
	if(i==5) break;
}
if(i==5) {return 0;}
return 1;
}

int dice::putme(char me){
if(me=='a'){
return a;
}else if(me=='b'){
return b;
}else if(me=='c'){
return c;
}else if(me=='d'){
return d;
}else if(me=='e'){
return e;
}else {
return f;
}
}
int comparedice(dice,dice);
int main(void){
int n;
scanf("%d",&n);
dice koro[n];
int i,j;
for (i=0;i<n;i++){
	koro[i].setnumber();
}
for (i=0;i<n;i++){
	for(j=0;j<i;j++){
		if (comparedice(koro[i],koro[j])==0){
			printf("No\n");
		}
		if (comparedice(koro[i],koro[j])==0){return 0;}
	}
}
printf("Yes\n");
return 0;
}
int comparedice(dice koro1,dice koro2){
int i,j;
for(i=0;i<3;i++){
	for(j=0;j<4;j++){
		if(
		(koro1.putme('a')==koro2.putme('a'))
		&&(koro1.putme('b')==koro2.putme('b'))
		&&(koro1.putme('c')==koro2.putme('c'))
		&&(koro1.putme('d')==koro2.putme('d'))
		&&(koro1.putme('e')==koro2.putme('e'))
		&&(koro1.putme('f')==koro2.putme('f'))
	){return 0;}
		koro2.E();
	}
koro2.E();
koro2.N();
}
koro2.N();
koro2.E();
koro2.E();
for(i=0;i<3;i++){
	for(j=0;j<4;j++){
		if(
	(koro1.putme('a')==koro2.putme('a'))
	&&(koro1.putme('b')==koro2.putme('b'))
	&&(koro1.putme('c')==koro2.putme('c'))
	&&(koro1.putme('d')==koro2.putme('d'))
	&&(koro1.putme('e')==koro2.putme('e'))
	&&(koro1.putme('f')==koro2.putme('f'))
	){return 0;}
		koro2.E();
	}
koro2.E();
koro2.N();
}
return 1;
}