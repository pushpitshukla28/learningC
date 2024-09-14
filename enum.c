#include<stdio.h>
#include <stdlib.h>
int main(){
typedef enum {RED , GREEN , BLUE , PINK , ORANGE} color;
color fav;
int i;
printf("Enter favourite colour from RED(0) , GREEN(1) , BLUE(2) , PINK(3) and ORANGE(4) \n");
scanf("%d" , &i);
fav = (color)i;
switch (fav)
{
case RED:
    printf("WOW RED\n");
    break;
case ORANGE:
    printf("WOW ORANGE\n");
    break;
case PINK:
    printf("WOW PINK\n");
    break;
case BLUE:
    printf("WOW BLUE\n");
    break;
case GREEN:
    printf("WOW GREEN\n");
    break;                
    

default:
    break;
}
}
 