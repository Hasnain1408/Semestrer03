#include<iostream>
#include<string.h>

using namespace std;

//char test[100];//="000111";
string test;//=NULL;
int pOfZero=0,pOfOne=0;
int x=1,y,z;
int len;
string format;


void separatePower()
{
  cout<<"***"<<endl;
for(int i=0; i<format.size(); ++i)
{
    if(format[i]=='^' && format[i+1]!='n')
    {
        cout<<"#";
        pOfZero=format[i+1];

        break;
    }
    else
    {
     pOfZero=1;
     break;
    }
}

for(int i=0; i<format.size(); ++i)
{
    if(format[i]=='^' && format[i+1]!='n')
    {
        pOfOne=format[i+1];
    }
    else
    {
     pOfOne=1;
    }
}
cout<<format<<endl;
cout<<"pZ= "<<pOfZero<<"  "<<"pOne= "<<pOfOne<<endl;

}

bool isRegular(string str)
{
    int error=0;
    int zeroCount=0,oneCount=0;
    int n =str.size();
    for(int i=0; i<n; ++i)
    {
        if(str[i]=='0' && str[i+1]=='1')
        {
            error++;
        }
        if(error>=2) return false;

    }
    for(int i=0; i<n; ++i)
    {

        if(str[i]=='0')
        {
            zeroCount++;
        }
        else if(str[i]=='1') oneCount++;

    }

    if(pOfZero*zeroCount != pOfOne*oneCount) return false;
    else return true;

}

bool pumping(int k,string test)
{
    int i,j;
    string str;
    str=test[0];
    for(i=0; i<k; ++i)
    {
        for(j=1; j<y; ++j)
        {
            str+=test[j];
        }
    }


    for(j=y+1; j<test.size(); ++j)
    {
        str+=test[j];
    }


    cout<<str<<endl;


//   str+=test[3];
//   str+=test[4];
//   str+=test[5];

    bool x;
    x=isRegular(str);

    return x;
}

int main()
{
    //cin>>pOfZero>>pOfOne;

    //rand()%20;
    cin>>format;
    separatePower();
    cin>>len;
    y=len-1;
    z=((pOfOne+pOfZero)*len)-(len);

    for(int i=0; i<pOfZero*len; ++i)
    {
        test+='0';

    }

    for(int j=pOfZero*len; j<(pOfOne+pOfZero)*len; ++j)
    {
        test+='1';

    }

    cout<<test<<endl;

    for(int i=0; i<10; ++i)
    {
        bool f =pumping(i,test);
        if(!f)
        {
            cout<<"Not regular!"<<endl;
            return 0;
        }
    }

    cout<<"Regular!"<<endl;



    return 0;
}




