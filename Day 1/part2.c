#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* getSubstring(char* string, int start, int end);

int main() {
    FILE* input = fopen("input.txt", "r");

    char line[100];

    int lineDigits[10] = { 0 };

    char numberStrings[][6] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    int sum = 0;

    while (fgets(line, 100, input)) {
        int start = 0;
        int end = 0;

        int match = 0;

        int index = 0;

        while (end <= strlen(line) + 1) {
            char* substr = getSubstring(line, start, end);
            for (int i = 0; i < 9; i++) {
                if (isdigit(substr[0])) {
                    lineDigits[index] = substr[0] - '0';
                    index++;
                    match = 1;
                }
                if (strcmp(substr, numberStrings[i]) == 0) {
                    lineDigits[index] = i + 1;
                    index++;
                    match = 1;
                }
                if (match) {
                    start++;
                    end = start;
                    match = 0;
                    break;
                }
            }
            end++;
            if (end == strlen(line)) {
                start += 1;
                end = start;
            }
            free(substr);
        }

        if (index == 0) {
            continue;
        }

        int last = lineDigits[index - 1];
        int first = lineDigits[0];

        int number = first * 10 + last;

        sum += number;

        memset(lineDigits, 0, sizeof(lineDigits));

        index = 0;
    }

    printf("%d", sum);

    fclose(input);
}

char* getSubstring(char* string, int start, int end) {
    int length = end - start + 2;
    char* substring = malloc(length * sizeof(char));
    int index = 0;

    for (int i = start; i <= end; i++) {
        substring[index] = string[i];
        index++;
    }

    substring[index] = '\0';
    return substring;
}