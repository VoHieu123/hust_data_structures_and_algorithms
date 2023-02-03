#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   char buf1[20], buf2[20],buf3[20], dtm[3];

   strcpy( dtm, "A N B");
   sscanf( dtm, "%c %s %c", &buf1, &buf2, &buf3);

   printf("%c %s %c\n", buf1, buf2, buf3);

   return 0; 
}