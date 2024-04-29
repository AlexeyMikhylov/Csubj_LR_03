#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* sourceFile, * destFile;
    char sourceFileName[] = "source.txt";
    char destFileName[] = "reversed.txt";
    char buffer[1000];
    int lines = 0;

    // Открываем исходный файл для чтения
    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Считаем количество строк в исходном файле
    while (fgets(buffer, sizeof(buffer), sourceFile) != NULL)
    {
        lines++;
    }

    // Переходим к последней строке исходного файла
    rewind(sourceFile);

    // Открываем новый файл для записи
    destFile = fopen(destFileName, "w");
    if (destFile == NULL)
    {
        printf("Error poening file\n");
        return 1;
    }

    // Читаем строки из исходного файла в обратном порядке и записываем их в новый файл
    for (int i = lines - 1; i >= 0; i--)
    {
        fseek(sourceFile, 0, SEEK_SET);
        for (int j = 0; j < i; j++)
        {
            fgets(buffer, sizeof(buffer), sourceFile);
        }
        fgets(buffer, sizeof(buffer), sourceFile);
        fputs(buffer, destFile);
    }

    // Закрываем файлы
    fclose(sourceFile);
    fclose(destFile);

    printf("Файл успешно создан с обратным порядком строк.\n");

    return 0;
}