#include <stdio.h>
#include <string.h>

int main(){

    char tulisanA[11];
    char tulisanB[11];
    char tulisanC[11];

    scanf("%s %s %s", &tulisanA, &tulisanB, &tulisanC);

    int panjangA = strlen (tulisanA);
    int panjangB = strlen(tulisanB);

    if(tulisanA[panjangA-1] == tulisanB[0] && tulisanB[panjangB-1] == tulisanC[0]){
        puts("YES");
    }
    else{
        puts("NO");
    }
	return 0;
}

