#include<stdio.h>
 
 int main()
 {
 	int y, a, b, c, d, i;
 	scanf("%d", &y);
 	for(i=y+1;;i++)
 	{
 		a = i%10;
 		b = (i/10)%10;
 		c = (i/100)%10;
 		d = (i/1000);
 		if(a!=b && a!=c && a!=d && b!=c && b!=d && c!=d)
 		{
 			printf("%d", i);
 			break;
		 }
 	}
 	return 0;
 }
