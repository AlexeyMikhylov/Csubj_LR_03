#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* inputFile, * outputFile;
    char inputFileName[] = "input.txt";
    char outputFileName[] = "output.txt";
    char line[100];

    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), inputFile))
    {
        int maxDigit = -1;
        int length = strlen(line);

        for (int i = 0; i < length; i++)
        {
            if (line[i] >= '0' && line[i] <= '9' && (line[i] - '0') > maxDigit)
            {
                maxDigit = line[i] - '0';
            }
        }

        line[length - 1] = maxDigit + '0';
        fprintf(outputFile, "%s\n", line);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Success, result in file %s\n", outputFileName);

    return 0;
}