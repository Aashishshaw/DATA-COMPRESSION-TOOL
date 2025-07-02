#include <stdio.h>
#include <string.h>

// Function to perform Run-Length Encoding compression
void runLengthEncode(char *input, char *output) {
    int len = strlen(input);
    int count = 1;
    int j = 0;  // output index

    for (int i = 0; i < len; i++) {
        count = 1;
        // Count consecutive repeated characters
        while (i < len - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // Store the character in output
        output[j++] = input[i];

        // Convert count to string and store in output
        char countStr[10];
        sprintf(countStr, "%d", count);

        for (int k = 0; countStr[k] != '\0'; k++) {
            output[j++] = countStr[k];
        }
    }
    output[j] = '\0';  // Null-terminate the output string
}

int main() {
    char input[1000];
    char compressed[2000]; // Output buffer (larger than input)

    printf("Enter a string to compress (including spaces):\n");
    // Use fgets to read spaces
    fgets(input, sizeof(input), stdin);

    // Remove trailing newline if any
    size_t ln = strlen(input) - 1;
    if (input[ln] == '\n') {
        input[ln] = '\0';
    }

    runLengthEncode(input, compressed);

    printf("\nOriginal string:\n%s\n", input);
    printf("Compressed string (RLE):\n%s\n", compressed);

    // Save compressed output to a file
    FILE *fp = fopen("compressed.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    fprintf(fp, "%s", compressed);
    fclose(fp);
    printf("\nCompressed data saved to file 'compressed.txt'.\n");

    return 0;
}
