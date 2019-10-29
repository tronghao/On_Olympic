#include "stdio.h"
#include "stdlib.h"
#include <string.h> 

long long giaTriLonNhat(char number[]);
int soLonNhatTrongChuoiSo(char number[]);
int chuyenSoThanhChuoi(char number);

int main()
{
	char num1[3000];
	char num2[3000];
	
	//nhap gia tri
	printf("Nhap num 1: ");
	fflush(stdin);
	scanf("%s", &num1);
	
	printf("Nhap num 2: ");
	fflush(stdin);
	scanf("%s", &num2);
	
	long long gtMaxNum1, gtMaxNum2;	
	gtMaxNum1 = giaTriLonNhat(num1);
	gtMaxNum2 = giaTriLonNhat(num2);
	
	printf("kq = %lld", abs(gtMaxNum1 - gtMaxNum2));
	
	return 0;
}

long long giaTriLonNhat(char number[])
{
	int max;
	long long giaTriMax = 0;
	max = soLonNhatTrongChuoiSo(number);
	char tam[4]; int chiSoTam = 0;
	for(int i=0; i<=strlen(number); i++)
	{
		chiSoTam = 0;
		if(chuyenSoThanhChuoi(number[i]) == max)
		{	
			for(int j = i; j<strlen(number) + i; j++)
			{
				int chiSoThat = j;
				if(j>= strlen(number))
					chiSoThat = j - strlen(number);
				tam[chiSoTam] = number[chiSoThat];
				chiSoTam++;
			}
			if(atoi(tam) > giaTriMax)
				giaTriMax = atoi(tam);
		}
	}
	return giaTriMax;
}

//atoi: chuyen chuoi thanh so
int soLonNhatTrongChuoiSo(char number[])
{
	int max = chuyenSoThanhChuoi(number[0]);	
	for(int i=0; i < strlen(number); i++)
	{
		if(chuyenSoThanhChuoi(number[i]) > max)
			max = chuyenSoThanhChuoi(number[i]);
	}
	return max;
}

int chuyenSoThanhChuoi(char number)
{
	return (int)number - 48;
}

