#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j,flag=0,x ,len=0;

    char str[100];
    gets(str);

    for(j=0; str[j]; j++)
        {
          len++;
        }



    if(len%2 == 1) flag =0;
    else{

         for(i=0; i<len/2; i++)
         {
             if(str[i] == str[len-i-1]) flag =1;
             else {
                    flag =0;
                    break;
             }
         }

    }


    if(flag)
    {
       printf("W is palindromic");
    }else printf("W is  not palindromic");
    return 0;
}
