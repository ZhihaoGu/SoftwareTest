//
//  main.cpp
//  ä½œä¸š1
//
//  Created by Zhihao on 2018/3/18.
//  Copyright Â© 2018å¹´ Zhihao. All rights reserved.
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
    //std::cout << "æ±‰å­—æµ‹è¯•\n";
    int flag0=0,flag1=0,flag2=0,flag3=0;    //arg»ñµÃÊäÈë 
    
    string input="test.txt";
    string output="reslt.txt";              //Ä¬ÈÏÎÄ¼þ 
    
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
    
    
//    for (int p=1; p<argc; p++) {            //æ£€æµ‹parameter
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
    fp = fopen(charinput,"r");              //¶ÁÈ¡ÎÄ¼þ 
    
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
            line++;                        //Í³¼ÆÐÐÊý 
        }
        charnum++;                          //Í³¼Æ×Ö·û 
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
                word++;                     //Í³¼Æ´ÊÊý 
            }
        }
    }
    //std::cout<<flag0<<flag1<<flag2<<"\n";
    std::cout<<"ÐÐÊý:"<<line<<"\n´ÊÊý:"<<word<<"\n×Ö·ûÊý£º"<<charnum<<std::endl;
    
    ofstream fout;                          //Êä³öµ½ÎÄ¼þ 
    fout.open(output.c_str());
    
    //flag0=flag1=flag2=1;
    
    if (flag0==1) {
        fout<<input;
        fout<<"×Ö·ûÊý£º"<<charnum<<"\n";
    }
    
    if (flag1==1) {
        fout<<input;
        fout<<"´ÊÊý:"<<word<<"\n";
    }
    
    if (flag2==1) {
        fout<<input;
        fout<<"ÐÐÊý:"<<line<<"\n";
    }
    
    //fout<<"ÐÐÊý:"<<line<<"\n´ÊÊý:"<<word<<"\n×Ö·ûÊý"<<charnum<<"\n";
    //fout<<flush;
    fout<<"ceshi\n";
    fout.close();
    
    return 0;
}







