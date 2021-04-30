#include <stdio.h>
 
int main()
{
   int c, first, last, middle, n, search, array[100];
 
   printf("Enter number of elements\n");
   scanf("%d",&n);
 
   printf("Enter %d integers\n", n);
 
   for (c = 0; c < n; c++)
      scanf("%d",&array[c]);
 
   printf("Enter value to find\n");
   scanf("%d", &search);

   front=0;last=n;
   middle=(first+last)/2;

   while(){
   	if(array[middle]>search)
   		last=middle-1;
   		//printf("hello");
   	else if(array[middle]<search)
   		front=middle+1;
   	else{
   		printf("%d found at position %d.", search, middle+1);
        break;
   	}  
   	middle=last+front/2;
   }

   if(first>last)
   	printf("%d is not there in the list.", search);
