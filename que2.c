#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress input string using RLE
void runLengthEncode(char *input, char *output) {
    int len = strlen(input);
    int j = 0; // output index

    for (int i = 0; i < len; i++) {
        int count = 1;

        // Count consecutive repeating characters
        while (i < len - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        output[j++] = input[i];

        // Convert count to string and append
        char countStr[20];
        sprintf(countStr, "%d", count);
        for (int k = 0; countStr[k] != '\0'; k++)
            output[j++] = countStr[k];
    }
    output[j] = '\0';
}

// Function to decompress RLE string
void runLengthDecode(char *input, char *output) {
    int len = strlen(input);
    int j = 0; // output index

    for (int i = 0; i < len; i++) {
        char ch = input[i];

        // Next characters are digits representing count
        char countStr[20];
        int countIndex = 0;

        i++;
        while (i < len && input[i] >= '0' && input[i] <= '9') {
            countStr[countIndex++] = input[i];
            i++;
        }
        countStr[countIndex] = '\0';

        int count = atoi(countStr);
        i--; // adjust index as outer loop will increment i

        // Repeat character count times in output
        for (int k = 0; k < count; k++) {
            output[j++] = ch;
        }
    }
    output[j] = '\0';
}

int main() {
    char inputFile[100], compressedFile[100], decompressedFile[100];
    char inputText[10000], compressedText[20000], decompressedText[10000];

    printf("Enter input filename to compress: ");
    scanf("%s", inputFile);

    FILE *fpIn = fopen(inputFile, "r");
    if (fpIn == NULL) {
        printf("Error: Cannot open input file %s\n", inputFile);
        return 1;
    }

    // Read entire file content
    int idx = 0;
    char ch;
    while ((ch = fgetc(fpIn)) != EOF && idx < sizeof(inputText) - 1) {
        inputText[idx++] = ch;
    }
    inputText[idx] = '\0';
    fclose(fpIn);

    // Compress
    runLengthEncode(inputText, compressedText);

    printf("\nCompressed Data:\n%s\n", compressedText);

    printf("Enter filename to save compressed data: ");
    scanf("%s", compressedFile);

    FILE *fpComp = fopen(compressedFile, "w");
    if (fpComp == NULL) {
        printf("Error: Cannot open file %s for writing.\n", compressedFile);
        return 1;
    }
    fprintf(fpComp, "%s", compressedText);
    fclose(fpComp);

    printf("Compressed data saved to %s\n", compressedFile);

    // Decompress
    runLengthDecode(compressedText, decompressedText);

    printf("\nDecompressed Data:\n%s\n", decompressedText);

    printf("Enter filename to save decompressed data: ");
    scanf("%s", decompressedFile);

    FILE *fpDec = fopen(decompressedFile, "w");
    if (fpDec == NULL) {
        printf("Error: Cannot open file %s for writing.\n", decompressedFile);
        return 1;
    }
    fprintf(fpDec, "%s", decompressedText);
    fclose(fpDec);

    printf("Decompressed data saved to %s\n", decompressedFile);

    return 0;
}
