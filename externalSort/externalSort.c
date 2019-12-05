//Samuel Lewright
//External Sorting

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void CounterSort(int length)
{
  //set count array all to 0
  int count[10] = {0};
  FILE *fp;

  //open the unsorted text file
  fp = fopen("unsorted.txt", "r");
  printf("Unsorted File: ");
  int z;
  char c;
  z = 0;
  c = fgetc(fp);
  while(c != EOF)
  {
    z = c - '0';
    printf("%d", z);
    count[z]++;
    c = fgetc(fp);
  }
  fclose(fp);
  int h;
  printf("\n");
  for(h = 0; h < 10; h++){
    printf("%d", count[h]);
  }

FILE *fp2;
fp2 = fopen("sorted.txt", "w");
int i;
for(i = 0; i <10; i++)
{
  int c = count[i];
  if(c==1)
  {
    fprintf(fp2, "%d", i);
  }
  if(c > 1)
  {
    int m;
    for(m = c; m >= 1; m--)
    {
      fprintf(fp2, "%d", i);
    }
  }
}
fclose(fp2);

}


int main()
{
    FILE *fp;
    int count = 0;
    char c;
    fp = fopen("unsorted.txt", "r");
    while(fscanf(fp, "%c", &c) != EOF){
      count++;
    }
    fclose(fp);
    int length = count;

   if(length != 0){
     printf("\n");
     CounterSort(length);
   }
   else{
     printf("File is empty. ");
   }
}
