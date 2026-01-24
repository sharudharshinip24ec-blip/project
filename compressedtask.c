#include <stdio.h>
#include <stdlib.h>

/* Function to compress file using RLE */
void compressFile() {
    FILE *input, *output;
    char ch, prev;
    int count = 1;

    input = fopen("input.txt", "r");
    output = fopen("compressed.txt", "w");

    if (input == NULL || output == NULL) {
        printf("Error opening file!\n");
        return;
    }

    prev = fgetc(input);

    while ((ch = fgetc(input)) != EOF) {
        if (ch == prev) {
            count++;
        } else {
            fprintf(output, "%c%d", prev, count);
            prev = ch;
            count = 1;
        }
    }

    fprintf(output, "%c%d", prev, count);

    fclose(input);
    fclose(output);

    printf("File compressed successfully.\n");
}

/* Function to decompress RLE file */
void decompressFile() {
    FILE *input, *output;
    char ch;
    int count, i;

    input = fopen("compressed.txt", "r");
    output = fopen("decompressed.txt", "w");

    if (input == NULL || output == NULL) {
        printf("Error opening file!\n");
        return;
    }

    while (fscanf(input, "%c%d", &ch, &count) != EOF) {
        for (i = 0; i < count; i++) {
            fputc(ch, output);
        }
    }

    fclose(input);
    fclose(output);

    printf("File decompressed successfully.\n");
}

int main() {
    int choice;

    printf("DATA COMPRESSION TOOL (RLE)\n");
    printf("1. Compress File\n");
    printf("2. Decompress File\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            compressFile();
            break;
        case 2:
            decompressFile();
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}