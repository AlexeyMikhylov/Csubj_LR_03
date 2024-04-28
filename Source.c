#include<stdio.h>
#include<stdlib.h>

int main()
{
	run();
}

int run()
{
	FILE* file = fopen("file.txt", "r");

	openFile(file);

	closeFile(file);

}

int openFile(FILE *fileptrname)
{
	//int max = 0;
	int rows = countFileRows(fileptrname);
	int* maxArr;
	int num, i = 0;
	char c;

	maxArr = (int*)malloc(sizeof(int) * rows);

	for (int r = 0; r < rows; r++)
	{
		maxArr[r] = 0;
	}

	if (fileptrname == NULL)
	{
		puts("error while opening file");
		return 1;
	}

	fseek(fileptrname, 0, SEEK_SET);
	/*for (int r = 0; r < rows; r++)
	{
		fscanf(fileptrname, "%d", &num);
		fscanf(fileptrname, "%c", &c);

		if (num > maxArr[r])
		{
			maxArr[r] = num;
		}

		if (c == "\n")
		{
			i++;
		}
	}*/

	while (!feof(fileptrname))
	{
		fgetc(fileptrname, "%d", &num);
		fgetc(fileptrname, "%c", &c);

		if (num > maxArr[i])
		{
			maxArr[i] = num;
		}
		
		if (c == "\n")
		{
			i++;
		}
	}

	//test
	printf("\n");
	for (int r = 0; r < rows; r++)
	{
		printf("\t%d", maxArr[r]);
	}

}

int countFileRows(FILE* fileptrname)
{
	char c;
	int rows = 0;

	fseek(fileptrname, 0, SEEK_SET);
	while (!feof(fileptrname))
	{
		c = fgetc(fileptrname);
		if (c == '\n')
		{
			rows++;
		}
	}

	return rows;
}



int closeFile(FILE *fileptrname)
{
	fclose(fileptrname);
}