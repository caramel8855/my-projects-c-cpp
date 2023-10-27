#include <stdio.h>

void encryptFile(FILE *inputFile, FILE *outputFile, int shift) {
    char ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A') + shift) % 26 + 'A';
        } else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a') + shift) % 26 + 'a';
        }
        fputc(ch, outputFile);
    }
}

void decryptFile(FILE *inputFile, FILE *outputFile, int shift) {
    char ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A') - shift + 26) % 26 + 'A';
        } else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a') - shift + 26) % 26 + 'a';
        }
        fputc(ch, outputFile);
    }
}

int main() {
    FILE *inputFile, *outputFile;
    int shift;
    
    // Open input file in read mode
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Cannot open input file.\n");
        return 1;
    }
    
    // Open output file in write mode
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Cannot create output file.\n");
        fclose(inputFile);
        return 1;
    }
    
    // Get the shift value from the user
    printf("Enter the shift value for encryption: ");
    scanf("%d", &shift);
    
    // Encrypt the file
    encryptFile(inputFile, outputFile, shift);
    printf("File encrypted successfully.\n");

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);
    
    // Decrypt the file (for demonstration purposes)
    inputFile = fopen("output.txt", "r");
    outputFile = fopen("decrypted_output.txt", "w");
    
    // Decrypt the file
    decryptFile(inputFile, outputFile, shift);
    printf("File decrypted successfully.\n");
    
    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);
    
    return 0;
}