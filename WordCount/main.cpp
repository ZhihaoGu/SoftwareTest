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

int stoplist(string input);
int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "hello world\n";
    int flag0=0,flag1=0,flag2=0,flag3=0,flag4=0;    //arg»ñµÃÊäÈë 
    string input="test.txt";
    string output="result.txt";              //Ä¬ÈÏÎÄ¼ş 
    string stoplistname;
    if(argc>1){
    	input=argv[1];						//»ñÈ¡ÊäÈëÎÄ¼şÃû ¹æ¶¨µÚÒ»¸ö²ÎÊı±ØÎªÊäÈëÎÄ¼şÃû   	
	}   
   	for(int a=2;a<argc;a++){
   		string arg(argv[a]);
   		if(arg=="-c"){
   			flag0=1;
		   }
		if(arg=="-w"){
   			flag1=1;
		   }
		if(arg=="-l"){
   			flag2=1;
		   }
		if(arg=="-a"){
   			flag3=1;
		   }
		if(arg=="-o"){
   			output=argv[a+1];   		
		   }
		if(arg=="-e"){
   			flag4=1;
   			stoplistname=argv[a+1];
		   }
	   }   
   
    FILE* fp;
    int line=0;
    int word=0;
    fp = fopen(input.c_str(),"r");              //¶ÁÈ¡ÎÄ¼ş 
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
		if(i=='\n'){
			noteflag1=0;
			noteflag2=0;
		}

    } while (i!=EOF&&i!=feof(fp));
    int codeline=0;
    codeline=(line-noteline)-unusedline;			//´úÂëĞĞÎªĞĞÊı¼õÈ¥×¢ÊÍºÍ¿ÕĞĞ 
    int unstopedword=0;
	unstopedword=stoplist( input );
	cout<<"·ÇÍ£ÓÃ´ÊÊı£º"<<unstopedword<<"\n";
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
    	fout<<input<<"´úÂëĞĞ/¿ÕĞĞ/×¢ÊÍĞĞ:"<<codeline<<"/"<<unusedline<<"/"<<noteline<<"\n";
	}
	if (flag4==1){
		fout<<input<<"³ıÈ¥Í£ÓÃ´ÊÍâ´ÊÊı£º"<<unstopedword; 
	}
    cout<<"ĞĞÊı:"<<line<<"\n´ÊÊı:"<<word<<"\n×Ö·ûÊı"<<charnum<<"\n";
    cout<<"´úÂëĞĞ/¿ÕĞĞ/×¢ÊÍĞĞ:"<<codeline<<"/"<<unusedline<<"/"<<noteline<<"\n"; 
    cout<<"flag0-4:"<<flag0<<flag1<<flag2<<flag3<<flag4;
    //fout<<flush;
    fout.close();    
    return 0;
}


int stoplist(string input) {
	char currentchar;
	char stopword[50][50];
	int m=0, n=0, sum=0;
	int unstopedword = 0;
	ifstream inputfile(input.c_str());
	ifstream stopfile("stoplist.txt");
	currentchar = stopfile.get();
	while (currentchar != EOF) { 
		if ((currentchar >= 'a'&&currentchar <= 'z') || (currentchar >= 'A'&&currentchar <= 'Z')) {
			do {
				stopword[sum][n++] = currentchar;
				currentchar = stopfile.get();
			} while ((currentchar >= 'a'&&currentchar <= 'z') || (currentchar >= 'A'&&currentchar <= 'Z'));
			stopword[sum][n] = '\0';
			sum++;
			n = 0;
		}
		currentchar = stopfile.get();
	}
	currentchar = inputfile.get();
	char token[50];
	while (currentchar != EOF) {
		for (m = 0; m < 50; m++) {
			token[m] = '\0'; 
		}
		m = 0;
		while (currentchar == ' ' || currentchar == '\n' || currentchar == '\t') {
			currentchar = inputfile.get();
		}
		if ((currentchar >= 'a'&&currentchar <= 'z') || (currentchar >= 'A'&&currentchar <= 'Z')||(currentchar >= '0'&&currentchar <= '9')) {
			do {
				token[m++] = currentchar;
				currentchar = inputfile.get();
			} while ((currentchar >= 'a'&&currentchar <= 'z') || (currentchar >= 'A'&&currentchar <= 'Z')||(currentchar >= '0'&&currentchar <= '9'));
			token[m] = '\0';
			for (n = 0; n < sum; n++) {
				if (strcmp(token, stopword[n]) == 0) { 
					unstopedword--;
					break;
				}
			}
			unstopedword++;
		}
		currentchar = inputfile.get();
	}
	inputfile.close();
	stopfile.close();
	return unstopedword;
}





