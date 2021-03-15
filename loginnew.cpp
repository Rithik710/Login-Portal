#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;

void welcome();
void login();
void newUser();
void forgot();
void menu();

main()
{
	welcome();
	menu();
}
void welcome()
{
	system("Color 0A"); 
	cout<<"\t\t\t\t\t\t\t\t\t  Welcome Onboard";

	cout<<"\n\n\t\t\t\t\t\t\t\t         Enter Your Choice ";
	cout<<"\n\n\t\t\t\t\t\t\t\t\t  1 => Log In";
	cout<<"\n\t\t\t\t\t\t\t\t   2 => New User ? Register Now!";
	cout<<"\n\t\t\t\t\t\t\t\t   3 => Forgot UserId / Password ? ";
	cout<<"\n\t\t\t\t\t\t\t\t\t  4 => Exit";
		
}



void login()
{
        int count;
        string username,password,usid,pswd;
        system("cls");
     	system("Color 0B");    
    cout << "\nEnter Username: ";
	cin >> username;
	cout << "\nEnter Password: ";
	cin >> password;
        
        ifstream input("UserLoginData");
        while(input>>usid>>pswd)
        {
                if(usid==username && pswd==password)
                {
                        count = 1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nWelcome Dear "<<username<<"\nLOGIN SUCESSFULL\nWe're Glad To Have You On-Board With Us.";
                cin.get();
                cin.get();
                main();
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease Check Your UserId and Password\n";
                main();
        }
}

void newUser()
{
        	system("Color 0C"); 
        string reguser,regpass,ru,rp;
        system("cls");
        cout<<"Enter UserId :";
        cin>>reguser;
        cout<<"\nEnter Password :";
        cin>>regpass;
        
        ofstream reg("UserLoginData",ios::app);
        reg<<reguser<<' '<<regpass<<endl;
        system("cls");
        cout<<"\nUser Registration Successfull . We Are Glad To Have You On-Board With Us";
        main();
        
        
}

void forgot()
{
		system("Color 0E"); 
        int ch;
        system("cls");
        cout<<"Forgot Your Credentials ? No Issues. We're Here For Your Help\n";
        cout<<"1 => Search your ID by Username"<<endl;
        cout<<"2 => Search your ID by Password"<<endl;
        cout<<"3 => Main menu"<<endl;
        cout<<"Enter Your Choice :";
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string searchuser,su,sp;
                        cout<<"\nWhat's the Last UserId You Remember ? ";
                        cin>>searchuser;
                        
                        ifstream searchu("UserLoginData");
                        while(searchu>>su>>sp)
                        {
                                if(su==searchuser)
                                {
                                        count=1;
                                }
                        }
                        searchu.close();
                        if(count==1)
                        {
                                cout<<"\n\nHurray! Account Discovered\n";
                                cout<<"\nYour Password is "<<sp;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"\nSorry, Your UserID Isn't Discovered in Our Records\n";
                                cin.get();
                                cin.get();
                                main();
                        }
                        break;
                }
                case 2:
                {
                        int count=0;
                        string searchpass,su2,sp2;
                        cout<<"\nWhat's the Last Password You Remember ?";
                        cin>>searchpass;
                        
                        ifstream searchp("UserLoginData");
                        while(searchp>>su2>>sp2)
                        {
                                if(sp2==searchpass)
                                {
                                        count=1;
                                }       
                        }
                        searchp.close();
                        if(count==1)
                        {
                                cout<<"\nHurray! Account Discovered \n";
                                cout<<"\nYour UserId is : "<<su2;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"Sorry, Your Password Isn't Discovered in Our Records \n";
                                cin.get();
                                cin.get();
                                main();
                        }
                
                        break;
                }
                
                case 3:
                {
                        cin.get();
                        main();
                }
                default:
                        cout<<"Invalid Choice! Please Try Again!"<<endl;
                        forgot();
        }
}
void menu()
{
	int choice;
	cout<<endl;
	cin>>choice;
	
	switch(choice)
	{
		case 1 : login();
		         break;
		case 2 : newUser();
		         break;
		case 3 : forgot();
		         break;
		case 4 : cout<<"\nThanks For Being Onboard ! \nCreated By Rithik Tripathi";
		         break;
		default : cout<<"\nInvalid Choice!!! Please Try Again!";
		          main();
	}
	
}

