#ifndef LOGIN_H
#define LOGIN_H
#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include <direct.h>
#include<windows.h>
#define _WIN32_WINNT 0x0500
using namespace std;

class Login	//class that has attributes like username,password,etc...
{

    private:
        int count,choice;
        string user,pass,u,p,userdirpath;
        string reguser,regpass,ru,rp;
        int ch;
    public:
    const char* username;
    string ExePath() {
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);
}

    bool login()
    {
    	char ch[20];
        system("cls");
        cout<<"please enter the following details"<<endl;
        cout<<"USERNAME :";
        cin>>user;
        cout<<"PASSWORD :";
		cin>>pass;	
        ifstream input("database.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)

                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        userdirpath=ExePath()+"\\"+user;
        const char *userdirpaths = userdirpath.c_str();
        fstream file;
        file.open("userdirectory.txt",ios::out);
        if(!file)
        {
            cout<<"Error in creating file!!!"<<endl;

        }

        file<<userdirpaths;
        //closing the file
        file.close();
        if(count==1)
        {
                cout<<"\nHello"<<user<<"\nLOGIN SUCESS\nWe're glad that you're here.\nThanks for logging in\n";
                return(true);

        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
                login();
        }
    }
    void registr()
    {
        system("cls");
        cout<<"Enter the username :";
        cin>>reguser;
        std::string str = "D:\\Conv\\Converter\\bin\\Debug\\"+reguser;
        const char* username;
        username = str.c_str();
        mkdir(username);
        userdirpath=ExePath()+"\\"+username;
        const char *userdirpaths = userdirpath.c_str();
        fstream file;
        file.open("userdirectory.txt",ios::out);
        if(!file)
        {
            cout<<"Error in creating file!!!"<<endl;

        }

        file<<userdirpaths;
        //closing the file
        file.close();
        cout<<"\nEnter the password :";
        cin>>regpass;
        ofstream reg("database.txt",ios::app);
        reg<<reguser<<' '<<regpass<<endl;
        system("cls");
        cout<<"\nRegistration Sucessful\n";
        logins();


    }
    void forgot()
    {
        system("cls");
        cout<<"Forgotten ? We're here for help\n";
        cout<<"1.Search your id by username"<<endl;
        cout<<"2.Search your id by password"<<endl;
        cout<<"3.Main menu"<<endl;
        cout<<"Enter your choice :";
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string searchuser,su,sp;
                        cout<<"\nEnter your remembered username :";
                        cin>>searchuser;

                        ifstream searchu("database.txt");
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
                                cout<<"\n\nHurray, account found\n";
                                cout<<"\nYour password is "<<sp;
                                cin.get();
                                cin.get();
                                system("cls");
                                logins();
                        }
                        else
                        {
                                cout<<"\nSorry, Your userID is not found in our database\n";
                                cout<<"\nPlease kindly contact your system administrator for more details \n";
                                cin.get();
                                cin.get();
                                logins();
                        }
                        break;
                }
                case 2:
                {
                        int count=0;
                        string searchpass,su2,sp2;
                        cout<<"\nEnter the remembered password :";
                        cin>>searchpass;

                        ifstream searchp("database.txt");
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
                                cout<<"\nYour password is found in the database \n";
                                cout<<"\nYour Id is : "<<su2;
                                cin.get();
                                cin.get();
                                system("cls");
                                logins();
                        }
                        else
                        {
                                cout<<"Sorry, We cannot found your password in our database \n";
                                cout<<"\nkindly contact your administrator for more information\n";
                                cin.get();
                                cin.get();
                                logins();
                        }

                        break;
                }

                case 3:
                {
                        cin.get();
                       logins();
                }
                default:
                        cout<<"Sorry, You entered wrong choice. Kindly try again"<<endl;
                        forgot();
        }


}
        bool logins()
        {
            cout<<"\t\t\t***********************************************************************\n\n\n";
            cout<<"\t\t\t                         I D - G U A R D                               \n\n\n";
            cout<<"\t\t\t                      Welcome to login page                               \n\n";
            cout<<"\t\t\t***********************        MENU        *******************************\n\n";
            cout<<"\t\t\t\t1.LOGIN"<<endl;
            cout<<"\t\t\t\t2.REGISTER"<<endl;
            cout<<"\t\t\t\t3.FORGOT PASSWORD (or) USERNAME"<<endl;
            cout<<"\t\t\t\t4.Exit"<<endl;
            cout<<"\n\t\t\t\tEnter your choice :";
            cin>>choice;
            cout<<endl;
            switch(choice)
            {
                case 1:
                        login();
                        break;
                case 2:
                        registr();
                        break;
                case 3:
                        forgot();
                        break;
                case 4:
                        cout<<"Thanks for using this program\nThis program is created by \nDeepan and Sanjeev\n\n";
                        break;
                default:
                        system("cls");
                        cout<<"You've made a mistake , give it a try again\n"<<endl;
                        logins();
            }

        }

};

#endif // LOGIN_H
