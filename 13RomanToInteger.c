#include <stdio.h>
#include <string.h>

int romanToInt(char* s) {
    // inefficient fr
    int num = 0;
    int idx = 0;
    int length = strlen(s);

    // M and CM
    while (s[idx] == 'M' || (s[idx] == 'C' && s[idx + 1] == 'M')){
        if (s[idx] == 'M' && (idx < length)){
            num += 1000;
            idx++;
        } else if (s[idx] == 'C' && s[idx + 1] == 'M' && (idx + 1 < length)) {
            num += 900;
            idx += 2;
        }
    };

    // D and CD
    while (s[idx] == 'D' || (s[idx] == 'C' && s[idx + 1] == 'D')){
        if (s[idx] == 'D' && (idx < length)){
            num += 500;
            idx++;
        } else if (s[idx] == 'C' && s[idx + 1] == 'D' && (idx + 1 < length)) {
            num += 400;
            idx += 2;
        }
    };

    // C and XC
    while (s[idx] == 'C' || (s[idx] == 'X' && s[idx + 1] == 'C')){
        if (s[idx] == 'C' && (idx < length)){
            num += 100;
            idx++;
        } else if (s[idx] == 'X' && s[idx + 1] == 'C' && (idx + 1 < length)) {
            num += 90;
            idx += 2;
        }
    };

    // L and XL
    while (s[idx] == 'L' || (s[idx] == 'X' && s[idx + 1] == 'L')){
        if (s[idx] == 'L' && (idx < length)){
            num += 50;
            idx++;
        } else if (s[idx] == 'X' && s[idx + 1] == 'L' && (idx + 1 < length)) {
            num += 40;
            idx += 2;
        }
    };

    // X and IX
    while (s[idx] == 'X' || (s[idx] == 'I' && s[idx + 1] == 'X')){
        if (s[idx] == 'X' && (idx < length)){
            num += 10;
            idx++;
        } else if (s[idx] == 'I' && s[idx + 1] == 'X' && (idx + 1 < length)) {
            num += 9;
            idx += 2;
        }
    };

    // V and IV
    while (s[idx] == 'V' || (s[idx] == 'I' && s[idx + 1] == 'V')){
        if (s[idx] == 'V' && (idx < length)){
            num += 5;
            idx++;
        } else if (s[idx] == 'I' && s[idx + 1] == 'V' && (idx + 1 < length)) {
            num += 4;
            idx += 2;
        }
    };

    // I
    while (s[idx] == 'I'){
        if (idx < length){
            num += 1;
            idx++;
        };
    };

    return num;
}

int main(){
    char str[16];
    scanf("%s", str); getchar();

    int result = romanToInt(str);
    printf("%d\n", result);
    return 0;
}