#include<stdio.h>
#include<stdlib.h>

int main()
{
	run();
}

int run()
{
	char line[80];
	FILE *in = fopen("input.txt", "r"), *out = fopen("output.txt", "w");

	processFile(in, out, line);

	fclose(in, out);

	printf("Success\nResult in 'output.txt'\n");
}

int processFile(FILE *fileptrname_1, FILE* fileptrname_2, char row[80])
{
	checkNullFile(fileptrname_1);
	checkNullFile(fileptrname_2);

	while (fgets(row, sizeof(row), fileptrname_1))
	{
		int maxDigit = -1;
		int length = strlen(row);

		for (int i = 0; i < length; i++)
		{
			if (row[i] >= '0' && row[i] <= '9'
				&& (row[i] - '0') > maxDigit)
			{
				maxDigit = row[i] - '0';
			}
		}

		row[length - 1] = maxDigit + '0';
		fprintf(fileptrname_2, "%s\n", row);
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