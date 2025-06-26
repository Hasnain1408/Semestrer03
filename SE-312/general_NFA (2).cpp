#include<vector>
#include<iostream>
using namespace std;
vector<vector<vector<char>>> transi;
vector<char>states,alphas;
char last;

bool traverseNFA(char state,string &str,int Index)
{

    if(Index==str.size())
    {
      cout<<state<<" ";
       return state==last;
    }
    vector<char>nextStates;
    for(int j=0;j<alphas.size();++j)
    {
        if(str[Index]==alphas[j])
        {
            for(char nextState:transi[state-'0'][j])
            {
                nextStates.push_back(nextState);
            }
        }
    }

    cout<<"---*---";
    for(char nextState:nextStates)
    {
        if(traverseNFA(nextState,str,Index + 1))
        {
            cout<<nextState<<" ";
            return true;
        }

    }
    return false;
}

int main()
{
    int numState,numAlphas,i,j;
    cout<<"Enter number of states and number of alphabets\n";
    cin>>numState>>numAlphas;

    states=vector<char>(numState);
    alphas=vector<char>(numAlphas);
    cout<<"Enter states\n";
    for(i=0;i<numState;++i) cin>>states[i];
    cout<<"Enter alphabets\n";
    for(i=0;i<numAlphas;++i) cin>>alphas[i];

    transi=vector<vector<vector<char>>>(numState,vector<vector<char>>(numAlphas));
    for(i=0;i<numState;++i)
    {
        for(j=0;j<numAlphas;++j)
        {
            cout<<"From "<<states[i]<<" through "<<alphas[j]<<" enter where \n";
            char tempStates;
            while(cin>>tempStates and tempStates!='0')
            {
                  transi[i][j].push_back(tempStates);
            }
        }
    }

    string str;
    char start;
    cout<<"Enter start \n";
    cin>>start;
    cout<<"Enter final state\n";
    cin>>last;
    cout<<"Enter the string\n";
    cin>>str;



    if(traverseNFA(start,str,0)) cout<<"\nAccepted\n";
    else cout<<"\nRejected\n";
}
