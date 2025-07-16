// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <stdio.h>
#include <string.h>

int main()
{
int n;
int runner;
int score;
int out;
char nyuuryoku[114514];
    scanf("%d",&n);
        for(int i=0;i<n;i++){
            runner=0;
            score=0;
            out=0;
            while(out<3){
                scanf("%s",nyuuryoku);
                    if(strcmp(nyuuryoku,"HIT")==0){
                        runner=runner+1;
                    }
                    else if(strcmp(nyuuryoku,"HOMERUN")==0){
                        score=score+runner+1;
                        runner=0;
                    }
                    else if(strcmp(nyuuryoku,"OUT")==0){
                        if(out==2&&runner>3){
                            score=score+runner-3;
                        }
                            
                           out=out+1;
                    }
            }
            printf("%d\n",score);
        }
                
}
// GCC reference:
//   https://gcc.gnu.org/

// C++ language references:
//   https://msdn.microsoft.com/library/3bstk3k5.aspx
//   http://www.cplusplus.com/
//   https://isocpp.org/
//   http://www.open-std.org/jtc1/sc22/wg21/

// Boost libraries references:
//   http://www.boost.org/doc/