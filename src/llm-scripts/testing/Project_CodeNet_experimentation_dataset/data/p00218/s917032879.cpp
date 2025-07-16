#include <stdio.h>

void grade(int students)
{
    while(students != 0) {
        for(int i = 0; i < students; ++i) {
            int math, english, japanese;
            scanf("%d %d %d", &math, &english, &japanese);
            int mean = (math + english + japanese) / 3;
            if ((math == 100) || (english == 100) || (japanese == 100)) {
                printf("A\n");
            } else {
                if (((math + english) / 2 >= 90) || mean >= 80) {
                    printf("A\n");
                } else if ((mean >= 70) || ((mean >= 50) && ((math >= 80) || (english >= 80)))) {
                    printf("B\n");
                } else {
                    printf("C\n");
                }
            }
        }
        scanf("%d", &students);
    }
}

int main(void)
{
    int students;
    scanf("%d", &students);
    grade(students);
    return 0;
}