#include <stdio.h>


int main()
{
    char str[100],alpha[3]={'A','B','C'};
    int len=0,state=0,i,j;

    gets(str);

    for(j =0; str[j]; j++)
        len++;

    int step[len];

    for(i =0; i<len; i++)
    {
        switch(state)
        {
        case 0:
            if(str[i] == '0') state = 0;
            else    state = 1;
            break;

        case 1:
            if(str[i] == '0') state = 2;
            else    state = 1;
            break;

        case 2:
            if(str[i] == '0') state = 0;
            else    state = 1;
            break;
        }

         step[i] = state;
    }

    for( j=0; j<len; j++)
         printf("%c ->",alpha[step[j]]);

    if(state == 2) printf("String Accepted!\n");
    else printf("String Rejected!\n");

    return 0;
}
