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
void docFile(char *fileName, int &soDoan, int &trongLuong, int mangKhucRac[]);
bool kt2SN(int soNguyen[]);
void ghiFileOutput(char *fileName, int soNguyen);

int main()
{
	
//	int mangKhucRac[10]= {0,11,1,2,1,1,5,10,2,3}, spt = 10;
//	int mangDoan[10], trongLuong = 10;
//	for(int soDoan=1; soDoan<=spt; soDoan++)
//	{
//		int soDoanHopLe = 0;
//		for(int viTriDangXet = 1; viTriDangXet <= spt-(soDoan-1) ; viTriDangXet++ )
//		{
//			int DoanLay=viTriDangXet, kq = 0;
//			while(DoanLay < viTriDangXet+soDoan)
//			{
//				kq += mangKhucRac[DoanLay];
//				DoanLay++;
//			}
//			if(kq <= trongLuong)
//				soDoanHopLe++;
//		}
//		mangDoan[soDoan] = soDoanHopLe;
//	}
//	int kq=0;
//	for(int i=1; i<=spt; i++)
//	{
//		printf("%3d", mangDoan[i]);
//		kq+=mangDoan[i];
//	}
//	
//	printf("\nKq = %d", kq);
	
	int mangKhucRac[50], spt, trongLuong;
	int ketQua=0;
	
	docFile((char*)"TRASH.INP", spt, trongLuong, mangKhucRac);
	
	for(int soDoan=1; soDoan<=spt; soDoan++)
	{
		int soDoanHopLe = 0;
		for(int viTriDangXet = 1; viTriDangXet <= spt-(soDoan-1) ; viTriDangXet++ )
		{
			int DoanLay=viTriDangXet, kq = 0;
			while(DoanLay < viTriDangXet+soDoan)
			{
				kq += mangKhucRac[DoanLay];
				DoanLay++;
			}
			if(kq <= trongLuong)
				soDoanHopLe++;
		}
		ketQua += soDoanHopLe;
	}
	
	ghiFile((char*)"TRASH.OUT", ketQua);
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

void docFile(char *fileName, int &soDoan, int &trongLuong, int mangKhucRac[])
{
	FILE *f = fopen(fileName, "rt");
	
	if(f==NULL)
		printf("Loi doc file!");
	else
	{
		fscanf(f, "%d", &soDoan);
		fscanf(f, "%d", &trongLuong);
		for(int i=1; i<soDoan; i++)
		{
			fscanf(f, "%d", &mangKhucRac[i]);
		}	
		fclose(f);
	}
}


