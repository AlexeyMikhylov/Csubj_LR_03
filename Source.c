#include<stdio.h>
#include<stdlib.h>

int main()
{
	run();
}

int run()
{
	char lines = 0;
	char buffer[80];
	FILE* in = fopen("source.txt", "r"), * out = fopen("reversed.txt", "w");

	if (processFile(in, out, lines, buffer) == 0)
	{
		printf("Success\nResult in 'reversed.txt'\n");
	}
	else
	{
		printf("Error\n");
	}

	fclose(in, out);
}

int processFile(FILE* fileptrname_1, FILE* fileptrname_2, char rows, char word[80])
{
	//
	checkNullFile(fileptrname_1);

	//считаем количество строк в исходном файле
	fseek(fileptrname_1, 0, SEEK_SET);
	while (fgets(word, sizeof(word), fileptrname_1) != NULL)
	{
		rows++;
	}
	
	// Переходим к последней строке исходного файла
	rewind(fileptrname_1);

	//
	checkNullFile(fileptrname_2);
	
	// Читаем строки из исходного файла в обратном порядке и записываем их в новый файл
	for (int i = rows - 1; i >= 0; i--)
	{
		fseek(fileptrname_1, 0, SEEK_SET);

		for (int j = 0; j < i; j++)
		{
			fgets(word, sizeof(word), fileptrname_1);
		}

		fgets(word, sizeof(word), fileptrname_1);
		fputs(word, fileptrname_2);
	}

	return 0;
}

int checkNullFile(FILE* fileptrname)
{
	if (fileptrname == NULL)
	{
		puts("Error opening file");
		return 1;
	}

	return 0;
}