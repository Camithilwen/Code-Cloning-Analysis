#include <stdio.h>
#include <string.h>

#define HIT 1
#define HR 2
#define OUT 3

int main(void){
    int outCnt, pt;
    int runner; // use bits
    char event[8];
    int eventID;
    int n;
    bool endInning;
    
    scanf("%d", &n);    
    for (int i=0; i<n; i++){
        endInning = false;
        outCnt = runner = pt = 0;
        while (!endInning){
            scanf("%s", event);
            if (event[0]=='O') eventID=OUT;
            else if (event[1]=='I') eventID=HIT;
            else eventID=HR;
            switch (eventID){
            case HIT:
                if (runner & 0x4) pt++;
                runner = (runner<<1) & 0x7;
                runner |= 0x1;
                break;
            case HR:
                pt++;
                if (runner & 0x4) pt++;
                if (runner & 0x2) pt++;
                if (runner & 0x1) pt++;
                runner = 0;
                break;
            case OUT:
                if (++outCnt == 3) endInning = true;
                break;
            }
        }
        printf("%d\n",pt);
    }
    
    return 0;
}