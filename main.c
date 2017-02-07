#include <stdio.h>
#include <stdlib.h>

#define WORDSIZE 32

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
int main(){
    printf("Informe um valor:\n");
    int a;
    scanf("%d", &a);
    printf("\n");
    int *ptr = binToDec(a);
    int i = 0;
    for(i=0;i<WORDSIZE;i++){
        printf("%d", ptr[i]);
    }
    return 0;
}
