#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<iomanip>
#include<cstdio>
using namespace std;
class bank 
{
    char acname[20],bankname[20];
    int bel, acnum;
    public :
void create();
void display();
void balancecheck();
void credit();
void withdraw();
void delete_ac();
void update_ac();
};
void bank::create()
{
cout<<"Enter bank name you want to create account..."<<endl;
cin>>bankname;
cout<<"ENter your name"<<endl;
cin>>acname;
cout<<"Enter belence in your account (mini 1000)"<<endl;
cin>>bel;
if(bel<1000)
{
    cout<<"Your bank balance should be 1000+"<<endl;
}
srand(time(NULL));
acnum=rand()%10000+1;
cout<<"Your account number is: "<<acnum;
 ofstream fout;
    fout.open("bank.txt",ios::app);
    if(fout.is_open())
    {
        fout<<acnum<<endl;
        fout<<bankname<<endl;
        fout<<acname<<endl;
        fout<<bel<<endl;
    fout.close();

        cout<<endl<<"Data is written to the file"<<endl;
    }
    else
    cout<<"data cant written"<<endl;
}
void bank::display()
{ const int size =80;
    char data[size];
    ifstream fin;
    fin.open("bank.txt",ios::in);
   // cout<<endl<<"file data is : ";
    while(fin)
    {
        fin.getline(data, size);
        cout<<endl<<data;
 
    }
    fin.close();
}
void bank::balancecheck()
{
    int accountnumber;
    cout<<"Enter your account number"<<endl;
    cin>>accountnumber;
    /*ifstream fin;
    fin.open("bank.txt",ios::in);
    if(!fin.is_open()){
    cout<<"file cannot be open"<<endl;
    return;
    }
    bool accountfound =false;
    while(fin>>acnum)
    {
        fin.ignore();//to new line ignore
        fin.getline(bankname,20);
        fin.getline(acname,20);
        fin>>bel;
        fin.ignore();
        if(acnum==accountnumber)
        {
            accountfound=true;
        cout<<"your bank name is : "<<bankname<<endl;
        cout<<"account name is: "<<acname<<endl;
        cout<<"your bank balance is: "<<bel<<endl;        break;
        }

    }
    if(!accountfound)
    cout<<"Account not found"<<endl;
    fin.close();*/
    ifstream fin("bank.txt");
ofstream temp("temp.txt", ios::app);
bool accountfound=false;
while(fin>>acnum>>bankname>>acname>>bel)
{
    if(acnum==accountnumber)
    {
        temp<<acnum<<" "<<endl;
            temp<<bankname<<" "<<endl;
            temp<<acname<<" "<<endl;
            temp<<bel<<endl;
        accountfound=true;
    }

}
 fin.close();
        temp.close();
       remove("bank.txt");
        rename("temp.txt","bank.txt");
        if(accountfound)
        {
           cout<<" your balence is: "<<bel<<endl; 
        }
        else if (!accountfound)
        {
             cout<<"account not found"<<endl;
        }       
}
void bank::withdraw()
{
int accountnumber, withdraw_am;
cout<<"Enter account number "<<endl;
cin>>accountnumber;
cout<<"Enter amount you withdraw "<<endl;
cin>>withdraw_am;
ifstream fin("bank.txt");
ofstream temp("temp.txt",ios::app);
bool accountfound=false;
while(fin>>acnum>>bankname>>acname>>bel)
{
    if(acnum==accountnumber)
    {
        if(bel>=withdraw_am)
        {
            bel-=withdraw_am;
            accountfound=true;
        }
        else
        {
            cout<<"balence is less than to withdraw amount"<<endl;
            temp<<acnum<<" ";
            temp<<bankname<<" ";
            temp<<acname<<" ";
            temp<<bel<<endl;
            continue;
        }
    }
            temp<<acnum<<" "<<endl;
            temp<<bankname<<" "<<endl;
            temp<<acname<<" "<<endl;
            temp<<bel<<endl;
}
        fin.close();
        temp.close();
       remove("bank.txt");
        rename("temp.txt","bank.txt");
if(accountfound)
{
    cout<<"withdrawal succesfull. your balence is "<<bel<<endl;

}
else if (!accountfound)
{
    cout<<"account not found"<<endl;
}
}
void bank::delete_ac()
{
int accountnumber;
cout<<"Enter account number "<<endl;
cin>>accountnumber;
ifstream fin("bank.txt");
ofstream temp("temp.txt",ios::app);
bool accountfound=false;
while(fin>>acnum>>bankname>>acname>>bel)
{
    if(acnum!=accountnumber)
    {
       
            temp<<acnum<<" "<<endl;
            temp<<bankname<<" "<<endl;
            temp<<acname<<" "<<endl;
            temp<<bel<<endl;
    }
    else if(acnum==accountnumber)
    //if(acnum!=accountnumber)
    {
         accountfound=true;
    }
}
        fin.close();
        temp.close();
       remove("bank.txt");
        rename("temp.txt","bank.txt");
if(accountfound)
{
    cout<<"account delete succesfull."<<endl;

}
else if (!accountfound)
{
    cout<<"account not found"<<endl;
}
}
void bank::credit()
{
int accountnumber, credit_am;
cout<<"Enter account number "<<endl;
cin>>accountnumber;
cout<<"Enter amount you credit "<<endl;
cin>>credit_am;
ifstream fin("bank.txt");
ofstream temp("temp.txt",ios::app);
bool accountfound=false;
while(fin>>acnum>>bankname>>acname>>bel)
{
    if(acnum==accountnumber)
    {
       
        bel+=credit_am;
            accountfound=true;
    }
            temp<<acnum<<" ";
            temp<<bankname<<" ";
            temp<<acname<<" ";
            temp<<bel<<endl;
}
        fin.close();
        temp.close();
       remove("bank.txt");
        rename("temp.txt","bank.txt");
if(accountfound)
{
    cout<<"credited succesfull. your balence is "<<bel<<endl;

}
else if (!accountfound)
{
    cout<<"account not found"<<endl;
}
}
void bank::update_ac()
{
int accountnumber;
cout<<"Enter account number "<<endl;
cin>>accountnumber;
ifstream fin("bank.txt");
ofstream temp("temp.txt",ios::app);
bool accountfound=false;
while(fin>>acnum>>bankname>>acname>>bel)
{
    if(acnum!=accountnumber)
    {
       
            temp<<acnum<<" "<<endl;
            temp<<bankname<<" "<<endl;
            temp<<acname<<" "<<endl;
            temp<<bel<<endl;
            cout<<"first file written succesfully";
    }
    else if(acnum==accountnumber)
    {
         
         cout<<"you are only update your name"<<endl;
         cout<<"Enter your new name"<<endl;
         cin>>acname;
         accountfound=true;
    }
}
  fin.close();
 temp.close();
 ifstream fin1("bank.txt");
 ofstream marge("marge.txt",ios::app);
 while(fin>>acnum>>bankname>>acname>>bel)
{
            marge<<acnum<<" "<<endl;
            marge<<bankname<<" "<<endl;
            marge<<acname<<" "<<endl;
            marge<<bel<<endl;
            cout<<"first file written succesfully"<<endl;
}
fin1.close();
ifstream temp2("temp.txt");
 while(fin>>acnum>>bankname>>acname>>bel)
{
            marge<<acname<<" "<<endl;
            marge<<bankname<<" "<<endl;
            marge<<acnum<<" "<<endl;
            marge<<bel<<endl;
            cout<<"second file written succesfully"<<endl;
}
temp2.close();
marge.close();
remove("bank.txt");
remove("temp.txt");
rename("marge.txt","bank.txt");
if(accountfound)
{
    cout<<"account holder name update succesfully."<<endl;

}
else if (!accountfound)
{
    cout<<"account not found"<<endl;
}
}
int main()
{
    int n;
    bank b;
    while(true){
    cout<<"-_________________________________._._________________________________________-"<<endl;
    cout<<"1)create account"<<endl;
    cout<<"2)Display all the account"<<endl;
    cout<<"3)check balance in account"<<endl;
    cout<<"4)withdraw"<<endl;
    cout<<"5)credit"<<endl;
    cout<<"6)delete account"<<endl;
    cout<<"7)update details"<<endl;
    cout<<"8)you want to exit"<<endl;
    cin>>n;
    switch (n)
    {
   case 1:
    b.create();
    break;
    case 2:
    b.display();
    break;
    case 3 :
    b.balancecheck();
    break;
    case 4:
    b.withdraw();
    break;
    case 5:
    b.credit();
    break;
    case 6:
    b.delete_ac();
    break;
    case 7: 
    b.update_ac();
    break;
    case 8:
    exit(0);
    default :
    cout<<"invailid coice"<<endl;
    }
    }
    return 0;
}