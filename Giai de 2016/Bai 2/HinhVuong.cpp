/* 
   * De bai: Ghi len tap tin 2 so nguyen (Input.txt) 
   *   -Doc tap tin input.txt neu 2 so nguyen thoa dieu kien so lon bang binh phuong so nho 
   *    thi ghi len tap tin output.txt so 1 nguoc lai ghi 0
   *vd: input.txt  2 4
        output.txt 1
        input.txt  3 7
        output.txt 0

*/

#include "stdio.h"
#include "windows.h"

void ghiFile(char *fileName, int soNguyen);
void docFile(char *fileName, int &S_number, int &doDai);

int main()
{
		
	int S_number, doDai;
	int dienTich = 0;
	docFile((char*)"SQUARES.INP", S_number, doDai);
	
	for(int i = S_number; i>=0; i--)
	{
		dienTich += (doDai * 4);
		doDai = (doDai * 4);
	}
	printf("%3d %3d %3d", S_number, doDai, dienTich);
	ghiFile((char*)"SQUARES.OUT", dienTich);
	return 0;
}

void ghiFile(char *fileName, int soNguyen)
{
	FILE *f = fopen(fileName, "wt");
	
	if(f==NULL)
		printf("Loi doc file!");
	else
	{
		fprintf(f, "%3d", soNguyen);
		fclose(f);
		printf("\nDa ghi vao file output!");
	}
}

void docFile(char *fileName, int &S_number, int &doDai)
{
	FILE *f = fopen(fileName, "rt");
	
	if(f==NULL)
		printf("Loi doc file!");
	else
	{
		fscanf(f, "%d", &S_number);
		fscanf(f, "%d", &doDai);
		fclose(f);
	}
}


