#include "stdio.h"
#include "math.h""

float dienTichTamGiac(int toaDox1, int toaDoy1, int toaDox2, int toaDoy2, int toaDox3, int toaDoy3);

int main()
{
	int toaDo[2000][2] = {{0,0}, {10,0}, {12,12}, {5,10}, {1,0}, {10,11}, {15,12}, {7,10}, {0,0}, {10,0}, {12,12}, {5,10}, {1,0}, {10,11}, {15,12}, {7,10} };
	int dinh1, dinh2, dinh3, soDinh=16;
	float max = -1;
	for(int i = 0; i<soDinh; i++)
	{
		dinh1 = i;
		int j=i+1;
		int dieuKienDungj = i - 1;
		if(dieuKienDungj < 0)
		{
			dieuKienDungj = soDinh - abs(dieuKienDungj);
		}
		while(j!=dieuKienDungj)
		{
			if(j > soDinh - 1)
				dinh2 = j - soDinh;
			else dinh2 = j;
			int k = j+1;
			while(k!=i)
			{
				if(k > soDinh - 1)
					dinh3 = k - soDinh;
				else dinh3 = k;
				//printf("\n%d %d %d", dinh1, dinh2, dinh3);
				float kq = dienTichTamGiac(toaDo[dinh1][0], toaDo[dinh1][1], toaDo[dinh2][0], toaDo[dinh2][1], toaDo[dinh3][0], toaDo[dinh3][1] );
				if(kq > max)
					max = kq;
				//printf(" kq = %f", kq);
				k++;
				if(k > soDinh - 1)
					k = k - soDinh;
			}
			j++;
			if(j>soDinh -1)
				j = j - soDinh;
		}
	}
	
	printf("\nTam giac lon nhat co dien tich: %f", max);
	return 0;
}

float dienTichTamGiac(int toaDox1, int toaDoy1, int toaDox2, int toaDoy2, int toaDox3, int toaDoy3)
{
	float dienTichTamGiac = 0;
	float tu =( (toaDox1*toaDoy2 - toaDoy1*toaDox2) + (toaDox2*toaDoy3 - toaDoy2*toaDox3) + (toaDox3*toaDoy1 - toaDoy3*toaDox1) );
	float mau = 2;
	dienTichTamGiac = abs(tu/mau);
	return dienTichTamGiac;
}
