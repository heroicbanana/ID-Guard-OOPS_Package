#ifndef CONVERTER_H
#define CONVERTER_H
#include <stdio.h>
#include<fstream>
#include<iostream>
#include<string.h>
#include<strings.h>
using namespace std;

class Converter
{
    public:
        int i;
        char result;
        Converter()
        {
            result=0;
        }
        void bmp2bin(const char* infile,const char*outfile)
        {
            int i;
            FILE *ptr_bmp_in;
            FILE *ptr_text_out;
            int c;
            ptr_bmp_in=fopen(infile,"rb");
            ptr_text_out=fopen(outfile,"w");
            if(!ptr_bmp_in)
            {
                printf("Unable to open file\n");

            }

            while((c=fgetc(ptr_bmp_in)) != EOF)
                {
                    for( i=0;i<=7;i++)
                    {
                        if(c&(1<<(7-i)))
                        {
                            fputc('1',ptr_text_out);
                        }
                        else
                        {
                            fputc('0',ptr_text_out);
                        }
                    }
                }


                fclose(ptr_bmp_in);
                fclose(ptr_text_out);
                cout<<"Writing done\n";
        }
        char bytefromtext(unsigned char* text)
        {
            char result = 0;
            for( i=0;i<8;i++)
            {
                if(text[i]=='1')
                {
                    result |= (1 << (7-i));
                }
            }
            return result;
        }

        void bin2bmp(const char* infile,const char* outfile)
        {

            FILE *ptr_txt_in;
            FILE *ptr_bmp_out;
            unsigned char buf[8];
            int c;
            int j = 0;
            ptr_txt_in=fopen(infile,"r");
            ptr_bmp_out=fopen(outfile,"wb");
            if(!ptr_txt_in)
            {
                cout<<"Unable to open file\n";
            }

            while((c=fgetc(ptr_txt_in)) != EOF)
                {
                    buf[j++] = c;
                    if(j==8)
                    {
                        fputc(bytefromtext(buf),ptr_bmp_out);
                        j=0;
                    }
                }
                fclose(ptr_txt_in);
                fclose(ptr_bmp_out);
                cout<<"Writing done\n";
            }
};


#endif // CONVERTER_H
