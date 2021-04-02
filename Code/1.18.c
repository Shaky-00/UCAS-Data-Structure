#include<stdio.h>
typedef enum {A,B,C,D,E} School;
typedef enum {F,M} Sex;
typedef enum {X,Y,Z} Event;

typedef struct{
    Event event;
    Sex sex;
    School school;
    int score;
}Info;

typedef struct{
    School school;
    int Male_score;
    int Female_score;
    int Total_score;
}Sum;

Info getInput(Info info)
{
    scanf(" %c %c %c", &info.event, &info.sex, &info.school);
    scanf(" %d", &info.score);
    printf("获取数据：%c %c %c %d\n", info.event, info.sex, info.school, info.score);
    return info;
}

Sum Calcuscore(School name, Info info[], int n)
{
    Sum tmp = {0,0,0,0};
    int i;
    tmp.school = name;

    for(i=1; i<=n; i++)
    {
        if(info[i].school == 'A')
        {
            if(info[i].sex == 'M')
            {
                tmp.Male_score += info[i].score;
            }
            if(info[i].sex == 'F')
            {
                tmp.Female_score += info[i].score;
            }
        }
    }
    tmp.Total_score = tmp.Male_score + tmp.Female_score;
    return tmp;
}

void printScore(Sum sum)
{
    if(sum.Male_score != 0)
        printf("%c M %d\n", sum.school, sum.Male_score);
    if(sum.Female_score != 0)
        printf("%c F %d\n", sum.school, sum.Female_score);
    printf("%c %d\n", sum.school, sum.Total_score);
}

int main()
{
    int n = 2;
    int i;
    Info info[n];
    for(i=0; i<n; i++)
    {
        info[i] = getInput(info[i]);
    }
    

    Sum sumA, sumB, sumC, sumD, sumE;
    
    
    sumA = Calcuscore('A', info, n);
    sumB = Calcuscore('B', info, n);
    sumC = Calcuscore('C', info, n);
    sumD = Calcuscore('D', info, n);
    sumE = Calcuscore('E', info, n);

    printScore(sumA);
    printScore(sumB);
    return 0;
}
