//Main program
#include <stdio.h>
#include <conio.h>
#include<fstream>
#include<iostream>
#include"Converter.h"
#include"Login.h"
#include"Directory.h"
using namespace std;

int main(int argc, char*argv[])	
{
    int choice;
    Login as;
    if(as.logins())	
    {
        while(choice!=4)
        {
        	mainmenu:
            cout<<"\t\t\t------------------------\n";
            cout<<"\t\t\t|       MAINMENU        |\n";
            cout<<"\t\t\t|     1.ADD A FILE      |\n";
            cout<<"\t\t\t|     2.VIEW A FILE     |\n";
            cout<<"\t\t\t|    3.DELETE A FILE    |\n";
            cout<<"\t\t\t------------------------\n";
            cout<<"\t\t\t\nCHOICE : ";
            cin>>choice;
            switch(choice)
            {
                case 1:
                {
                    ifstream dirfile;
                    Directory a;
                    Converter convobj;
                    std::string str = a.directory();
                    const char *d = str.c_str();
                    string directory;
                    dirfile.open("userdirectory.txt");
                    getline(dirfile,directory);
                    string returnaddress,finalpath;
                    returnaddress=directory+"\\"+a.filename+".bmp";
                    finalpath=directory+"\\"+a.filename+".txt";
                    const char *b=finalpath.c_str();
                    const char *ret = returnaddress.c_str();
                    cout<<"returned string : "<<d;
                    convobj.bmp2bin(d,b);
                    system("cls");
                    break;
                }
                case 2:
                {
                    ifstream dirfile;
                    Directory a;
                    Converter convobj;
                    //std::string *str = a.directory();
                    //const char *d = str.c_str();
                    string directory;
                    dirfile.open("userdirectory.txt");
                    getline(dirfile,directory);
                    string returnaddress,finalpath;
                    returnaddress=directory+"\\"+a.openfile(directory);
                    finalpath=returnaddress+".bmp";
                    const char *ret = returnaddress.c_str();
                    const char *b=finalpath.c_str();
                    cout<<"returned string : "<<ret<<"\n";
                    cout<<"final url : "<<b<<"\n";
                    convobj.bin2bmp(ret,b);
                    a.delay(2);
                    system(b);
                    cin.get();
                    DeleteFile(b);
                    a.delay(2);
                    system("cls");
                    break;
                }
                case 3:
                {
                    ifstream dirfile;
                    Directory a;
                    Converter convobj;
                    string directory;
                    dirfile.open("userdirectory.txt");
                    getline(dirfile,directory);
                    string returnaddress,finalpath;
                    returnaddress=directory+"\\"+a.openfile(directory);
                    const char *ret = returnaddress.c_str();
                    cin.get();
                    DeleteFile(ret);
                    a.delay(2);
                    system("cls");
                    break;

                }
                case 4:
                {
                    return 0;
                }
                default:
                {
                    cout<<"WRONG CHOICE";
                    system("cls");
                    goto mainmenu;
                }
            }
        }
    }
}
