#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char ApplicantName[50];
char CareerType[50];
char Advice[100];
float AdviceDate;

//menu ที่เป็นอาหาร แฮ่

void  menu(){
    
     printf("AppicantName : ");
        scanf("%s",ApplicantName);
        printf("CareerType : ");
        scanf("%s",CareerType);
        printf("Advice : ");
        scanf("%s",Advice);
        printf("AdviceData (YYYY-MM-DD) : ");
        scanf("%f",AdviceDate);   

      

        FILE*file=fopen("makiancode.csv","a");
        if (file == NULL)
        {
                printf("can't open file");   
                
        }  
        fprintf(file,"%s,%s,%s,%.2f\n" ,ApplicantName,CareerType,Advice,AdviceDate);   
        fclose(file);

    }

