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

void ghiFile(char *fileName, int soNguyen[]);
void docFile(char *fileName, int soNguyen[]);
bool kt2SN(int soNguyen[]);
void ghiFileOutput(char *fileName, int soNguyen);

int main()
{
	char input[] = "input.txt";
	char output[] = "output.txt";
	
	int mangSN[2], mangSNDocTuFile[2];
	
	int kq;
	
	for(int i=0; i<2; i++)
	{
		printf("\nNhap so nguyen thu %d: ", i+1);
		scanf("%d", &mangSN[i]);
	}
	
	ghiFile((char *) input, mangSN);
	docFile((char *) input, mangSNDocTuFile);
	
	printf("\nGia tri trong file Input: ");
	for(int i=0; i<2; i++)
	{
		printf("%4d", mangSNDocTuFile[i]);
	}
	
	if(kt2SN(mangSNDocTuFile) == true)
		kq = 1;
	else
		kq = 0;
	
	ghiFileOutput((char *)output, kq);
	
	
	return 0;
}

void ghiFile(char *fileName, int soNguyen[])
{
	FILE *f = fopen(fileName, "wt");
	
	if(f==NULL)
		printf("Loi doc file!");
	else
	{
		for(int i=0; i<2; i++)
		{
			fprintf(f, "%5d", soNguyen[i]);
		}
		fclose(f);
		printf("Da ghi file!");
	}
}

void ghiFileOutput(char *fileName, int soNguyen)
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

void docFile(char *fileName, int soNguyen[])
{
	FILE *f = fopen(fileName, "rt");
	
	if(f==NULL)
		printf("Loi doc file!");
	else
	{
		for(int i=0; i<2; i++)
		{
			fscanf(f, "%d", &soNguyen[i]);
		}	
		fclose(f);
	}
}

bool kt2SN(int soNguyen[])
{
	int max = 0;
	if(soNguyen[1] > soNguyen[0])
		max = 1;
	
	if(max = 0)
	{
		if(soNguyen[0] / soNguyen[1] == soNguyen[1] && soNguyen[0] % soNguyen[1] ==0)
			return true;
		else return false;
	}
	else
	{
		if(soNguyen[1] / soNguyen[0] == soNguyen[0] && soNguyen[1] % soNguyen[0] ==0)
			return true;
		else return false;
	}
}
