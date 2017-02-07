#include <stdio.h>
#include <stdlib.h>

#define WORDSIZE 4

int* binToDec(int number){
    int *num = (int *)malloc(sizeof(int) * WORDSIZE);
    int dividend = (number > 0)? number : (number * -1);
    int i = WORDSIZE - 1;
    while(dividend != 0){
        num[i] = dividend % 2;
        dividend = dividend / 2;
        i--;
    }
    if(number > 0){
        while(i >= 0){
            num[i] = 0;
            i--;
        }
    } else {
        while(i >= 0){
            num[i] = 1;
            i--;
        }
    }
    return num;
}
void complement_of_two(int *number){
    int i = WORDSIZE - 1;
    int state = 0;
    while(i >= 0){
        if(state){
            number[i] = (number[i] == 1)? 0 : 1;
        }
        if(number[i] == 1){
            state = 1;
        }
        i--;
    }
}
int main(){
    int *ptr = binToDec(2);
    int i = 0;
    for(i=0;i<WORDSIZE;i++){
        printf("%d", ptr[i]);
    }
    printf("\n");
    int *pt = ptr;
    complement_of_two(pt);
    for(i=0;i<WORDSIZE;i++){
        printf("%d", pt[i]);
    }
    return 0;
}
