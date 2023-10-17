#include<stdio.h>
#include<conio.h>
int main()
{int tong=0,tich=1,dem=0,i;
 int a[10],n;
 printf("nhap so phan tu cua mang: ");
 scanf("%d", &n);
 for( int i=0; i<n ;i++)
 { 
   printf("gia tri cua mang a[%d]:",i);
   scanf("%d", &a[i]);
   }
  	printf("\n so phan tu khi nhap vao mang la:\n");
   for(int i=0; i<n; i++)
    {
	printf("a[%d]=%d \n", i,a[i]);
  }
   for(i=0;i<n;i++)
    { tong=tong+a[i];
    tich=tich*a[i];
    dem=dem+1;
    } 
	printf("\n tong mang=%d",tong);
	printf("\n tich mang=%d",tich);
	printf("\n so phan tu chan=%d",dem);
	   return 0;
}
    
    
