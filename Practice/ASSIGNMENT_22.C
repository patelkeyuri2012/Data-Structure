// 22. Write a command line argument program that copies content of a file into another file.

#include <stdio.h>
#include <stdlib.h>

void copyFile(const char *sourceFileName, const char *destinationFileName)
{
    FILE *sourceFile, *destinationFile;
    char ch;

    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL)
    {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL)
    {
        perror("Error opening destination file");
        fclose(sourceFile);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(sourceFile)) != EOF)
    {
        fputc(ch, destinationFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);

    printf("File copy successfully : %s to %s\n", sourceFileName, destinationFileName);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    copyFile(argv[1], argv[2]);

    return 0;
}
