#include<iostream>
#include<algorithm>

using namespace std;


void CFL_L(string str)
{
    cout<<"Leftmost:";
    cout<<"S=> ";
    cout<<"A1B=> ";

    string temp="A1B";

    int i;
    for(i=0; str[i]!='1'; ++i)
    {
        temp='0'+temp;
        cout<<temp<<"=> ";
    }

    temp.erase(temp.begin() + i);
    cout<<temp<<"=> ";


    for(i=i+1; i<str.size(); ++i)
    {


        if(str[i]=='0')
        {


            temp[i]='0';
            temp.push_back('B');

            cout<<temp<<"=> ";

        }
        else  if(str[i]=='1')
        {

            temp[i]='1';
            temp.push_back('B');
            cout<<temp<<"=> ";
        }
    }

    temp.pop_back();
    cout<<temp<<endl;


}

void CFL_R(string str)
{
    cout<<"Rightmost:";
    cout<<"S=> ";
    cout<<"A1B=> ";

    string temp="A1B";

    int i,j;
    for(j=0; str[j]!='1'; ++j);

    int index=2;
    for(i=j+1; i<str.size(); ++i)
    {


        if(str[i]=='0')
        {


            temp[index++]='0';
            temp.push_back('B');

            cout<<temp<<"=> ";

        }
        else  if(str[i]=='1')
        {

            temp[index++]='1';
            temp.push_back('B');
            cout<<temp<<"=> ";
        }
    }

    temp.pop_back();
    cout<<temp<<"=> ";

     for(i=0; str[i]!='1'; ++i)
    {
        temp='0'+temp;
        cout<<temp<<"=> ";
    }

    temp.erase(temp.begin() + i);
    cout<<temp<<endl;

}


int main()
{
    string str;
    cout<<"Input : "<<endl;
    cin>>str;
    CFL_L(str);
    cout<<endl;
    CFL_R(str);
    return 0;
}

