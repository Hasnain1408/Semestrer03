#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    scanf("%d",&n);

    for(int i =0; i<pow(2,n); i++)
    {
        int show_binary[n],num;
        num = i;
        for(int j=n-1; j>=0; j--)
        {
            show_binary[j] = num%2;
            num /= 2;
        }
        printf("\n");

        for(int k=0; k<n; k++)
            printf("%d",show_binary[k]);
    }
    return 0;
}
