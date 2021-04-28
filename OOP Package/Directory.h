#ifndef DIRECTORY_H
#define DIRECTORY_H
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include<fstream>
#include<windows.h>
#include<stdio.h>
#include<time.h>
using namespace std;

class Directory
{
    private:

            string dir;
            int dir_choice,fol_no,folder_choice,wordcount,i;
            char menu_choice;
            vector<string> files ;
    public:
    string directorised,filename;
    Directory()
    {
        wordcount=0;
        i=0;
    }
    void delay(float number_of_seconds)
    {
        // Converting time into milli_seconds
        int milli_seconds = 1000 * number_of_seconds;
        // Stroing start time
        clock_t start_time = clock();
        // looping till required time is not acheived
        while (clock() < start_time + milli_seconds);
    }
    string ExePath()
    {
        char buffer[MAX_PATH];
        GetModuleFileName( NULL, buffer, MAX_PATH );
        string::size_type pos = string( buffer ).find_last_of( "\\/" );
        return string( buffer ).substr( 0, pos);
    }



        int getdir (string dir, vector<string> &files)
        {
            DIR *dp;
            struct dirent *dirp;
            if((dp  = opendir(dir.c_str())) == NULL)
            {
                cout << "Error(" << errno << ") opening " << dir << endl;
                return errno;
            }

            while ((dirp = readdir(dp)) != NULL)
            {
                files.push_back(string(dirp->d_name));
            }
            closedir(dp);
            return 0;
        }
        string openfile(string dir)
        {
            files.clear();
            getdir(dir,files);
            for (unsigned int i = 0;i < files.size();i++)
            {
                cout <<i+1<<"." <<files[i] << endl;
            }
            cout<<"Enter the file number you want to open : ";
            cin>>fol_no;
            dir=dir+files[fol_no-1];
            filename=files[fol_no-1];
            return filename;

        }
        string directory()
        {
            files = vector<string>();
            menu_choice='y';
            topmenu:
            cout<<"Enter the drive to search for :-\n";
            cout<<"1. C:\\\n";
            cout<<"2. D:\\\n";
            cout<<"3. F:\\\n";
            cout<<"4. G:\\\n";
            cout<<"Enter Your Choice : ";
            cin>>dir_choice;
            switch(dir_choice)
            {
                case 1:
                {
                    dir = "C:\\";
                    system("cls");
                    break;
                }
                case 2:
                {
                    dir = "D:\\";
                    system("cls");
                    break;
                }
                case 3:
                {
                    dir = "F:\\";
                    system("cls");
                    break;
                }
                case 4:
                {
                    dir = "G:\\";
                    system("cls");
                    break;
                }
            }
            while(menu_choice!='x')
            {
                getdir(dir,files);
                for (unsigned int i = 0;i < files.size();i++)
                {
                    cout <<i+1<<"." <<files[i] << endl;
                }
                navigate:
                cout<<"---------------------------\n";
                cout<<"Enter your choice\n";
                cout<<"1.Open folder\n";
                cout<<"2.Open file\n";
                cout<<"3.Back\n";
                cout<<"Press 4 to quit\n";
                cout<<"---------------------------\n";
                folderchoice:
                cout<<"\nChoice : ";
                cin>>folder_choice;
                if(folder_choice>4)
                {
                    cout<<"\nWrong choice, Re-Enter the choice";
                    goto folderchoice;
                }
                switch(folder_choice)
                {
                    case 1:

                        {
                            cout<<"\nEnter the folder number you want to enter : ";
                            cin>>fol_no;
                            dir=dir+files[fol_no-1];
                            cout<<dir;
                            system("cls");
                            files.clear();
                            getdir(dir,files);
                            for (unsigned int i = 0;i < files.size();i++)
                            {
                                cout <<i+1<<"." <<files[i] << endl;
                            }
                            dir=dir+"\\";
                            goto navigate;
                            break;
                        }
                    case 2:
                    {
                        cout<<"Enter the file number you want to open : ";
                        cin>>fol_no;
                        dir=dir+files[fol_no-1];
                        filename=files[fol_no-1];
                        std::string str = dir;
                        const char *c = str.c_str();
                        cout<<"Actual file path : "<<c<<"\n";
                        directorised=c;
                        ShellExecute(NULL, "open",c, NULL, NULL, SW_SHOWDEFAULT);
                        return(dir);
                        /*
                        fstream file; //object of fstream class

                       //opening file "sample.txt" in out(write) mode
                       file.open("directory.txt",ios::out);

                       if(!file)
                       {
                           cout<<"Error in creating file!!!"<<endl;
                           return 0;
                       }
                       //write text into file
                       file<<c;
                       //closing the file
                       file.close();


                        //CopyFile(c, "C:\\Users\\TEMP.CS2K16.006\\Documents\\copied.bmp", TRUE);
                        //DeleteFile(c);
                        */

                        system("cls");
                        //goto topmenu;
                        break;
                    }
                    case 3:
                    {
                        system("cls");
                        files.clear();
                        goto topmenu;
                        break;
                    }

                }
            }
        }
        string address;
        string copyfile()
        {






            fstream file;
            file.open("directory.txt",ios::in);

               if(!file)
               {
                   cout<<"Error in opening file!!!"<<endl;
                   return 0;
               }
               // Read in the sentence from the file
                getline(file, address);

               //read untill end of file is not found.
               //to read single character

                return(address);
                file.close();
                DeleteFile("G:\\Package\\ID-Guard\\directory.txt");
                //close file
                    }

};

#endif // DIRECTORY_H
