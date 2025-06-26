#include<iostream>
#include<string.h>

using namespace std;

//char test[100];//="000111";
string test;//=NULL;
int x=1,y,z;
int len;

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

    if(zeroCount != oneCount) return false;
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


    for(j=y+1; j<len*2; ++j)
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

    //rand()%20;
    cin>>len;
    y=len-1;
    z=len;

    for(int i=0; i<len; ++i)
    {
        test+='0';

    }

    for(int i=len; i<2*len; ++i)
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


