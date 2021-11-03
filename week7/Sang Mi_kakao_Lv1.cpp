#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int solution(const char* s) {
    int answer = 0;
    char* str = (char*)calloc(51, sizeof(char));
    strcpy(str, s);
    int digit = 0;
    while (*str)
    {

        if (isdigit(*str))
        {
            answer = answer * 10 + *str - '0';
        }
        else
        {
            if (!strncmp(str, "zero", 4))
                answer = answer * 10 + 0;
            if (!strncmp(str, "one", 3))
                answer = answer * 10 + 1;
            if (!strncmp(str, "two", 3))
                answer = answer * 10 + 2;
            if (!strncmp(str, "three", 5))
                answer = answer * 10 + 3;
            if (!strncmp(str, "four", 4))
                answer = answer * 10 + 4;
            if (!strncmp(str, "five", 4))
                answer = answer * 10 + 5;
            if (!strncmp(str, "six", 3))
                answer = answer * 10 + 6;
            if (!strncmp(str, "seven", 5))
                answer = answer * 10 + 7;
            if (!strncmp(str, "eight", 5))
                answer = answer * 10 + 8;
            if (!strncmp(str, "nine", 4))
                answer = answer * 10 + 9;
        }
        str++;
    }
    return answer;
}