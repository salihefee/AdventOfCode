#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    FILE* input = fopen("input.txt", "r");

    char line[100];

    char lineDigits[10] = { 0 };

    int sum = 0;

    while (fgets(line, 100, input)) {
        int index = 0;
        for (int i = 0; i < 100; i++) {
            char current = line[i];
            if (current == '\n' || current == '\0') {
                break;
            }
            if (isdigit(current)) {
                lineDigits[index] = current;
                index++;
            }
        }

        memset(line, 0, sizeof(line));

        int last = lineDigits[index - 1] - '0';
        int first = lineDigits[0] - '0';

        int number = first * 10 + last;

        sum += number;
    }

    printf("%d", sum);

    fclose(input);
}