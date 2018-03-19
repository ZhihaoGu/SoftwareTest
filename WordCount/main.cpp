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
    //std::cout << "hello world\n";
    int flag0=0,flag1=0,flag2=0,flag3=0,flag4=0;    //arg»ñµÃÊäÈë 
    
    string input="test.txt";
    string output="reslt.txt";              //Ä¬ÈÏÎÄ¼ş 
    
    if(argc>1){
    	input=argv[1];						//»ñÈ¡ÊäÈëÎÄ¼şÃû    	
	}
   
    for(int p=2;p<argc;p++){
    	string arg(argv[p]);
    	flag0 = flag0||arg=="-c";
    	flag1 = flag1||arg=="-w";
    	flag2 = flag2||arg=="-l";
    	flag3 = flag3||arg=="-a"; 
	}
	
    if(argc>1){
    	string arg(argv[argc-2]);
    	if(arg=="-o"){
    		output=argv[argc-1];			//»ñÈ¡Êä³ö 
		}
	}

    char* charinput = new char[input.length()+1];
    strcpy(charinput,input.c_str());
    FILE* fp;
    int line=0;
    int word=0;
    fp = fopen(charinput,"r");              //¶ÁÈ¡ÎÄ¼ş 
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
            line++;                        //Í³¼ÆĞĞÊı 
        }
        charnum++;                         //Í³¼Æ×Ö·û 
    } while (i!=EOF&&i!=feof(fp));

    rewind(fp);								//·µ»ØÎÄ¼şÍ·²¿ 

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
                word++;                     //Í³¼Æ´ÊÊı 
            }
        }
    }

    rewind(fp);
    
    int unusedline=0;
    int unusedflag=0;
    do{	
        i=fgetc(fp);						//Í³¼Æ¿ÕĞĞ£¬ÈôÏàÁÚÁ½×Ö·û³ı¿Õ¸ñÍâ¾ùÎª»»ĞĞÔòÓĞÒ»¿ÕĞĞ 
        if(i!=' '){
        	if (i=='\n') {
        		if(unusedflag==1){
					unusedline++;
				}
	        	if(unusedflag==0){
	        		unusedflag=1;  
				}				
        	}else{
        	unusedflag=0;
			}
		}        
    } while (i!=EOF&&i!=feof(fp));
    
    rewind(fp); 
    
    int noteline=0;
    int noteflag1=0;
    int noteflag2=0;
    do{	
        i=fgetc(fp);
        if(i=='/'&&noteflag2==0){			//Í³¼Æ×¢ÊÍĞĞ 
        	if(noteflag1==1){
        		noteline++;
        		noteflag2=1;
			}
			if(noteflag1==0){
				noteflag1=1;
			}
		}
		
		if(i='\n'){
			noteflag1=0;
			noteflag2=0;
		}
		        
    } while (i!=EOF&&i!=feof(fp));
    
    int codeline=0;
    codeline=(line-noteline)-unusedline;			//´úÂëĞĞÎªĞĞÊı¼õÈ¥×¢ÊÍºÍ¿ÕĞĞ 
      
    //std::cout<<"ĞĞÊı:"<<line<<"\n´ÊÊı:"<<word<<"\n×Ö·ûÊı£º"<<charnum<<std::endl;
    
    ofstream fout;                          //Êä³öµ½ÎÄ¼ş 
    fout.open(output.c_str());
    

    if (flag0==1) {							//°´ÒªÇóĞ´ÈëÎÄ¼ş 
        fout<<input;
        fout<<"×Ö·ûÊı£º"<<charnum<<"\n";
    }
    
    if (flag1==1) {
        fout<<input;
        fout<<"´ÊÊı:"<<word<<"\n";
    }
    
    if (flag2==1) {
        fout<<input;
        fout<<"ĞĞÊı:"<<line<<"\n";
    }
    if (flag3==1){
    	fout<<input<<"´úÂëĞĞ£º"<< codeline<<"\n";
    	fout<<input<<"×¢ÊÍĞĞ£º"<< noteline<<"\n";
    	fout<<input<<"¿Õ  ĞĞ£º"<< unusedline<<"\n";
	}
    //fout<<"ĞĞÊı:"<<line<<"\n´ÊÊı:"<<word<<"\n×Ö·ûÊı"<<charnum<<"\n";
    //fout<<flush;
    fout.close();    
    return 0;
}








