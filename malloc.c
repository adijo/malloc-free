
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>


/*
 Author: Aditya Joshi.
 */

struct block_meta
{
  size_t size;
  struct block_meta *next;
  int free;
  int indicator;
  
};

#define META_SIZE sizeof(struct block_meta)
void *global_head = NULL;

struct block_meta* find_empty(size_t size, struct block_meta *curr)
{
  if(curr == NULL)
    {
      return NULL;
    }
  else
    {
      if(curr->free == 1 && curr->size >= size)
	{
	  return curr;
	}
      else
	{
	  return find_empty(size, curr->next);
	}
    }
}



void *allocate(size_t size)
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
  int *arr = allocate(sizeof(int) * 2);
  arr[0] = 1;
  arr[1] = 2;
  printf("%d \n", arr[1]);

  return 0;
}
