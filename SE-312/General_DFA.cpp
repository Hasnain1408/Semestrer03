#include<iostream>
#include<stdbool.h>
#include<string.h>

using namespace std;

bool processInput(char* test,int num_state,int num_symbol,int accepting_state[],int starting_state,int transition[][20])
{
    int current_state = starting_state;
    char symbol;
    int path[10];


    int i=0;
    while(test[i] != '\0')
    {
        symbol = test[i];
      /*  if (symbol < 0 || symbol >= num_symbol) {
            return false;
        } */
        current_state = transition[current_state][symbol-'0'];
        path[i] =  current_state;

      /*  if(current_state == -1)
            return false; */

        i++;
    }

    for (i = 0; path[i] != '\0' ; i++) {
        cout<<path[i]<< "->";
        }

     for (i = 0; i < num_state; i++) {
        if (current_state == accepting_state[i]) {
            return true;
        }
        return false;
    }

}

int main()
{
    int num_state,num_symbol,starting_state,num_accepting_state;
    int accepting_state[100],transition[20][20];
    int i,j;

    cout<<"Number of states : ";
    cin>>num_state;

    cout<<"Number of symbol : ";
    cin>>num_symbol;

    for(i=0; i<num_state; ++i)
    {
        for(j=0; j<num_symbol; j++)
        {
            cout<<i<<j<<" : ";
           cin>>transition[i][j];
        }

    }

    cout<<"Starting  state : ";
    cin>>starting_state;

    cout<<"Number of Accepting state : ";
    cin>>num_accepting_state;

    cout<<"Accepting  state : ";
    for(j=0; j<num_accepting_state; j++)
            cin>>accepting_state[j];

    char test[20];
    cin>>test;

    bool isAccepted;
    isAccepted = processInput(test,num_state,num_symbol,accepting_state,starting_state,transition);

    (isAccepted)? cout<<"Accepted\n": cout<<"Rejected\n";
   // cout<<isAccepted<<endl;


    return 0;
}
