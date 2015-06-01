#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>


/*
 Author: Aditya Joshi.
 */

void *malloc(size_t size)
{
  void *p = sbrk(0);
  void *request = sbrk(size);
   if(request == (void *) -1)
   {
     return NULL;
   } 
   else
   {
      return p;
   } 

}

int main()
{
   int *arr = malloc(sizeof(int) * 2);
   arr[0] = 1;
   arr[1] = 2;
   printf("%d \n", arr[1]);

 return 0;
}
