#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int day;
    int month;
    int year;
} DATE;
typedef struct {
    int hour;
    int min;
    int sec;
}TIME;
typedef struct{
    DATE date;
    TIME time;
}STAMP;

int main(){
    STAMP s1;
    s1.date.day = 10;
    s1.date.month = 8;
    s1.date.year =2004;
    s1.time.hour= 15;
    s1.time.min=30;
    s1.time.sec=17;
    STAMP s2 = {{15,8,2003}, {20,30,15}};
    //s2 ={{15,8,2003}, {20,30,15}}; THIS METHOD IS WRONG FOR INITIALZING WHILE DECLARATION

    STAMP s3;
    STAMP *ptr;
    ptr = &s3;


    printf("DOB of s1 %d/%d/%d \n" , s1.date.day , s1.date.month , s1.date.year);
    printf("Time of birth of s1 %d:%d:%d\n" , s1.time.hour , s1.time.min , s1.time.sec);
    printf("DOB of s2: %d/%d/%d \n", s2.date.day , s2.date.month , s2.date.year);
    //Pointer to Structure
    ptr->date.day = 5;
    ptr ->date.month = 10;
    printf("%d" , (ptr->date.day));


}
