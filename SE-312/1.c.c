#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,flag;
    char str[5];
    gets(str);

    for(i=0; str[i]; i++)
    {
        if(str[i] == '0' || str[i] == '1')
        {

             flag = 1;

        }
       else {
            flag = 0;
            break;

       }
    }

    if(flag)
    {
       printf("W is from Alphabet");
    }else printf("W is  not from Alphabet");
    return 0;
}
