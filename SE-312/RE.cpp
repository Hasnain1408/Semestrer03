#include<iostream>
using namespace std;
int main()
{
    int numofstates, numofsymbols;
    cin>>numofstates>>numofsymbols;
    int transition[numofstates][numofsymbols];
    string re[numofstates][numofstates][numofstates];
    int i,j,k;
    for(i=0;i<numofstates;i++)
    {
        for(j=0;j<numofsymbols;j++)
        {
            cin>>transition[i][j];
        }
    }
    for(i=0;i<numofstates;i++)
    {
        for(j=0;j<numofstates;j++)
        {
            int flag=0;
            if(i==j)
            {
                 re[0][i][j]="e";
                 flag=1;
            }
            for(k=0;k<numofsymbols;k++)
            {
                if(transition[i][k]==j)
                {
                    if(flag==1)
                    re[0][i][j]+="+";
                    re[0][i][j]+=to_string(k);
                    flag =1;
                }
            }
            if(flag==0)
                re[0][i][j]="#";
        }
    }
    for(i=0;i<numofstates;i++)
    {
        for(j=0;j<numofstates;j++)
        cout<<"re[0]["<<i+1<<"]"<<"["<<j+1<<"]="<<re[0][i][j]<<endl;
    }
    for(k=1;k<numofstates;k++)
    {
        for(i=0;i<numofstates;i++)
        {
            for(j=0;j<numofstates;j++)
            {
                re[k][i][j]=re[k-1][i][j]+"+"+re[k-1][i][k-1]+"("+re[k-1][k-1][k-1]+")*"+re[k-1][k-1][j];
            }
        }
    }
    for(k=1;k<numofstates;k++)
    {
        for(i=0;i<numofstates;i++)
        {
            for(j=0;j<numofstates;j++)
            {
                cout<<"re["<<k<<"]"<<"["<<i+1<<"]"<<"["<<j+1<<"]="<<re[k][i][j]<<endl;
            }
        }
    }
}
