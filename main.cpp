//
//  main.cpp
//  作业1
//
//  Created by Zhihao on 2018/3/18.
//  Copyright © 2018年 Zhihao. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
//#include 
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "汉字测试\n";
    int flag0=0,flag1=0,flag2=0,flag3=0;    //arg������� 
    
    string input="test.txt";
    string output="reslt.txt";              //Ĭ���ļ� 
    
    if(argc>1){
    	input=argv[1];
    	
	}
   
    
    for(int p=2;p<argc;p++){
    	string arg(argv[p]);
    	flag0 = flag0||arg=="-c";
    	flag1 = flag1||arg=="-w";
    	flag2 = flag2||arg=="-l";
	}
	
    if(argc>1){
    	string arg(argv[argc-2]);
    	if(arg=="-o"){
    		//std::cout<<6;
    		output=argv[argc-1];
		}
	}
    
    
//    for (int p=1; p<argc; p++) {            //检测parameter
//        if (strcmp(argv[p],"-c")) {
//            flag0=1;
//            std::cout<<flag0<<flag1<<flag2<<"\n";
//        }else{
//            if (strcmp(argv[p],"-w")) {
//                flag1=2;
//                std::cout<<flag0<<flag1<<flag2<<"\n";
//            }else{
//                if (strcmp(argv[p],"-l")) {
//                    flag2=3;
//                    std::cout<<flag0<<flag1<<flag2<<"\n";
//                }else{
//                    //input=argv[p];
//                }
//            }
//        }
//        if (strcmp(argv[p],"-o")) {
//            flag3=1;
//            p++;
//            //output=argv[p];
//        }
//    }
    
    char* charinput = new char[input.length()+1];
    strcpy(charinput,input.c_str());
    FILE* fp;
    int line=0;
    int word=0;
    fp = fopen(charinput,"r");              //��ȡ�ļ� 
    
    if (fp == NULL) {
        cout<<"Fail to read file"<<endl;
        return 0;
    }
    
    int i;
    line=1;
    int charnum=-1;
    do{
        i=fgetc(fp);
        if (i=='\n') {
            line++;                        //ͳ������ 
        }
        charnum++;                          //ͳ���ַ� 
    } while (i!=EOF&&i!=feof(fp));

    rewind(fp);

    word=0;
    int j=0;
    int flag=0;
    for (j=fgetc(fp); j!=EOF; j=fgetc(fp)) {
        if (j==' '||j=='\n'||j==',') {
            flag=0;
        }
        else{
            if (flag==0) {
                flag=1;
                word++;                     //ͳ�ƴ��� 
            }
        }
    }
    //std::cout<<flag0<<flag1<<flag2<<"\n";
    std::cout<<"����:"<<line<<"\n����:"<<word<<"\n�ַ�����"<<charnum<<std::endl;
    
    ofstream fout;                          //������ļ� 
    fout.open(output.c_str());
    
    //flag0=flag1=flag2=1;
    
    if (flag0==1) {
        fout<<input;
        fout<<"�ַ�����"<<charnum<<"\n";
    }
    
    if (flag1==1) {
        fout<<input;
        fout<<"����:"<<word<<"\n";
    }
    
    if (flag2==1) {
        fout<<input;
        fout<<"����:"<<line<<"\n";
    }
    
    //fout<<"����:"<<line<<"\n����:"<<word<<"\n�ַ���"<<charnum<<"\n";
    //fout<<flush;
    fout<<"ceshi\n";
    fout.close();
    
    return 0;
}







