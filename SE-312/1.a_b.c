#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j,size,length=0;


    for(i=0; i<5; i++)
    {
        size = rand()%10;
      //  printf("%d\n",size);
        char str[size];
        for(j=0; j<size; j++)
        {
         if(!(j%2))
          str[j] = '0';
         else  str[j] = '1';

        }
        str[size] = '\0';

         printf(" String : %s\n",str);

        for(j=0; str[j]; j++)
        {
          length++;
        }

        printf("Length : %d\n",length);

        length =0;


    }


    return 0;
}
