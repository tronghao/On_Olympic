#include<stdio.h>
#include<math.h>
int main()
{
	long long int n, s;
	
//	printf("Nhap so luong hang rao: ");
//	scanf("%lld",&n);
//	long long int a[n];
//	printf("Nhap dien tich toi da: ");
//	scanf("%lld",&s);
//	for(int i=0;i<n;i++)
//	{
//		printf("Nhap chieu dai hang rao thu %d: ",i);
//		scanf("%lld",&a[i]);
//	}
	n=12;
	s=19;
	long long int a[12]={3,4,2,6,5,9,3,9,5,4,6,2};
	long long int b[n];
	for(int i=0;i<n;i++)
	{
		b[i]=a[i];
	}
	for(int i=0;i<n-1;i++)
	for(int j=i+1;j<n;j++)
	{
		if(b[i]>b[j])
		{
			long long int tg=b[i];
			b[i]=b[j];
			b[j]=tg;
		}
	}
	//for(int i=0;i<n;i++)
	//printf("%3d",b[i]);
	long long int mang[n][2];
	int vitri=0;
	long long int biendangxet=b[0];
	int dem=0;
	for(int i=0;i<n;i++)
	{

		if(b[i]==biendangxet) dem++;
		else 
		{
			mang[vitri][0]=biendangxet;
			mang[vitri][1]=dem;
			//printf("\nBien dang xet=%d----",biendangxet);
			//printf("dem=%d",dem);
			dem=1;
			//printf("mang = %d", mang[vitri][1]);
			vitri++;
			biendangxet=b[i];
			
			
			
		}
		if(i==n-1)
		{
			mang[vitri][0]=biendangxet;
			mang[vitri][1]=dem;
		//	printf("\nBien dang xet=%d----",biendangxet);
			//printf("dem=%d",dem);
			vitri++;

		}
	}
	long long int dientich, max=0;
	for(int i=0;i<vitri;i++)
	{
		//printf("\n%3lld-%3lld",mang[i][0],mang[i][1]);	
		if(mang[i][1]==1) mang[i][0]=0;
		
	}
	int mangluu[n][2];
	int pos=0;
	for(int i=0;i<vitri-1;i++)
	for(int j=i+1;j<vitri;j++)
	{
		dientich=mang[i][0]*mang[j][0];
		if(dientich<=s&&dientich>=max) 
		{
			max=dientich;
			mangluu[pos][0]=mang[i][0];
			mangluu[pos][1]=mang[j][0];
			pos++;
		}
	
		
	}
	/*for(int i=0;i<pos;i++)
	printf("\n%3d%3d",mangluu[i][0],mangluu[i][1]);
	printf("%3d",max);*/
	long long int kq[n][2];
	int chay=0;
	for(int i=0;i<pos;i++)
	{
		if(mangluu[i][0]*mangluu[i][1]==max)
		{
			kq[chay][0]=mangluu[i][0];
			chay++;
			kq[chay][0]=mangluu[i][1];
			chay++;
		}
	}

	for(int i=0;i<chay;i++)
	for(int j=0;j<n;j++)
	{
		if(kq[i][0]==a[j])
		{
			kq[i][1]=j;
			break;
		} 
	
	}
	/*for(int i=0;i<chay;i++)
	{
		printf("\n%3lld-%3lld",kq[i][0],kq[i][1]);	
		
	}*/
	long long int kq1,kq2;
	long long int nummin=kq[0][1];
	int chiso;
	for(int i=0;i<chay;i++)
	{
		if(kq[i][1]<nummin) 
		{
			nummin=kq[i][1];
			chiso=i;
		}
	}
	if(chiso%2==0) 
	{
		kq1=kq[chiso][0];
		kq2=kq[chiso+1][0];
	}
	else
	{
		kq2=kq[chiso][0];
		kq1=kq[chiso-1][0];	
	}
	//printf("\n%3lld-%3lld",kq1,kq2);
	int ijkt[4];
	int run=0;
	for(int l=0;l<n;l++)
	{
		if(a[l]==kq1||a[l]==kq2)
		{
			ijkt[run]=l+1;
			run++;
		}
	}
	for(int i=0;i<4;i++)
	printf("%3d",ijkt[i]);		

	return 0;
}
