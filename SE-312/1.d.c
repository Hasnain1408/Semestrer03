#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j,flag;
    char str1[5],str2[5],concatenated_str[10];

    gets(str1);
    gets(str2);
    for(i=0; str1[i]; i++)
    {
       concatenated_str[i] = str1[i];
    }

    for(j=0; str1[j]; j++,i++)
    {
       concatenated_str[i] = str2[j];
    }

    concatenated_str[i] = '\0';

    printf(concatenated_str);

    return 0;
}
