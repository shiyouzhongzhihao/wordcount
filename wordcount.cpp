#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <parameter> <input_file_name>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int count = 0;
    char c;
    int isWord = 0;

    if (strcmp(argv[1], "-c") == 0) {
        while ((c = fgetc(file)) != EOF) {
            count++;
        }
        printf("Character count: %d\n", count);
    } else if (strcmp(argv[1], "-w") == 0) {
        while ((c = fgetc(file)) != EOF) {
            if (c == ' ' || c == ',' || c == '\n' || c == '\t') {
                isWord = 0;
            } else if (!isWord) {
                isWord = 1;
                count++;
            }
        }
        printf("Word count: %d\n", count);
    } else {
        printf("Invalid parameter.\n");
        return 1;
    }

    fclose(file);
    return 0;
}

