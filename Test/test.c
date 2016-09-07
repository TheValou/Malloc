#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char *a, *b;
 
  a = malloc(100);
  if (a != NULL) 
    {
      printf("test\n");
      memset(a, 'x', 100);
      b = realloc(a, 200);
      if (b != NULL) {
	// Fill the rest of the memory.
	memset(b + 100, 'y', 100);
	// Check it got a copy of a as expected.
	free(b);
      } else {
	printf("Fail malloc\n");
	// Easy to miss: free a on realloc failure!
	free(a);
      }
    }
  else
    printf("Fail malloc\n");
}

