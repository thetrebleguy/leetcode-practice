#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
    char* str = malloc(100 * sizeof(char));
    str[0] = '\0';

    // 4 digits.. (1000 - 3999)
    while (num >= 1000){
        strcat(str, "M"); 
        num -= 1000;
    }; 

    // 3 digits.. (100 - 999)
    while (num >= 100){
        // 900
        if (num >= 900){
            strcat(str, "CM"); 
            num -= 900;
        } else if (num >= 500){
            strcat(str, "D"); 
            num -= 500;
        } else if (num >= 400){
            strcat(str, "CD"); 
            num -= 400;
        } else {
            strcat(str, "C"); 
            num -= 100;
        };
    };

    // 2 digits.. (10 - 99)
    while (num >= 10){
        if (num >= 90){
            strcat(str, "XC");
            num -= 90;
        } else if (num >= 50){
            strcat(str, "L");
            num -= 50;
        } else if (num >= 40){
            strcat(str, "XL");
            num -= 40;
        } else {
            strcat(str, "X");
            num -= 10;
        };
    };

    // 1 digit
    while (num > 0){
        if (num == 9){
            strcat(str, "IX");
            num -= 9;
        } else if (num >= 5){
            strcat(str, "V");
            num -= 5;
        } else if (num == 4){
            strcat(str, "IV");
            num -= 4;
        } else {
            strcat(str, "I");
            num -= 1;
        };
    };

    return str;
}

int main(){
    int num;
    scanf("%d", &num);

    char result[101];
    strcpy(result, intToRoman(num));

    printf("%s\n", result);

    return 0;
}