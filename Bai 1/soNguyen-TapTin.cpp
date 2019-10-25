// De bai: Ghi 1 so nguyen nhap tu ban phim len tap tin, sau do doc tap tin vua ghi ra man hinh.

#include "stdio.h"
#include "windows.h"

void ghiFile(int soNguyen);
void docFile(int &soNguyen);

int main()
{
	int soNguyen, giaTriDoc;
	printf("\nNhap so nguyen: ");
	scanf("%d", &soNguyen);
	
	ghiFile(soNguyen);
	docFile(giaTriDoc);
	
	printf("\nGia tri so trong file: %d", soNguyen);
	
	return 0;
}

void ghiFile(int soNguyen)
{
	FILE *f = fopen("tapTinSoNguyen.txt", "wt");
	
	if(f==NULL)
		printf("Loi doc file!");
	else
	{
		fprintf(f, "%3d", soNguyen);
		fclose(f);
		printf("Da ghi file!");
	}
}

void docFile(int &soNguyen)
{
	FILE *f = fopen("tapTinSoNguyen.txt", "rt");
	
	if(f==NULL)
		printf("Loi doc file!");
	else
	{
		fscanf(f, "%d", &soNguyen);
		fclose(f);
	}
}
