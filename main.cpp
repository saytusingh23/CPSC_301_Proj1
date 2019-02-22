//Saytu Singh
//Assign 1
//CPSC 301
//Used some online references and assistance from tutoring

#include<iostream>
#include<fstream>
#include<cstring>
#include<string>

using namespace std;
struct PERSON
{
    char Name[20];
    float Balance;
};

void Display(PERSON *person, int N)
{
    cout<<setprecision(3)<<fixed;
    cout<<setw(19)<<left<<" Name"<<" Balance"<<endl;
    cout<<"------------------------------"<<endl;
    for(int i=0; i < N; i++)
    {
        cout<<setw(19)<<person[i].Name<<" "<<person[i].Balance<<endl;
    }
}
void Find_Richest(PERSON person, int N){
    int MAX=0;
    for(int i=0; i<N; i++)
    {
        if(person[MAX].Balance<person[i].Balance)
            MAX = i;
    }
    cout<<"The customer with maximum balance is "<<person[MAX].Name<<endl;
}
void Deposit(char CustomName[],PERSON person, int N)
{
    int index = -1;
    for(int i=0; i<N; i++)
    {
        if(strcmp(CustomName,person[i].Name)==0)
        {
            index = i;
        }
}
    if(index == -1)
        cout<<"Sorry, but the cutomer could not be found!"<<endl;
    else
    {
        double deposit;
        cout<<CustomName<<", how much would you like to deposit?";
        person[index].Balance+=deposit;
        cout<<"Your new current balance is "<<person[index].Balance<<endl;
    }
void New_Copy(string firstname, PERSON *person, int N);
    ofstream out;
    out.open(firstname.c_str());
    for(int i=0; i<N; i++)
    {
        out<<person[i].Name<<" "<<person[i].Balance<<endl;
    }
    out.close();
}

//Begins the main function.
int main()
{
    int N=0;
    ifstream data;
    data.open("data.txt");
    if(data.fail())
    {
        cout<<"Sorry, but unable to open the .txt file!";
        return 0;
    }
    string line;
    while(getline(data, line))
    {
        N++;
    }
    PERSON *person = new PERSON[N];
    int i=0;
    string firstname, lastname;
    while(data>>firstname>>lastname>>person[i].Balance)
    {
        strcpy(person[i].Name, (firstname+" "+lastname).c_str());
        i++;
    }
    Display(*person, N);
    Find_Richest(*person, N);
    char CustomName[20];
    cout<<"Please enter your full name to deposit money:";
    cin.getline(CustomName, 20);
    Deposit(CustomName, person, N);
    New_Copy("data.txt", *person, N);
    return 0;
}
