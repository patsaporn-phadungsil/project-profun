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

void Search_menu()
{
    {
        char line[200];
        char search[100];
        int found = 0, count = 0;
        FILE *file = fopen("makiancode.csv", "r");
        printf("Search data: ");
        scanf("%s", search);

        while(fgets(line, sizeof(line), file) != NULL)
        {
                if(strstr(line, search))
            {
                    if(count < 1)
                {
                    printf("+----------+------------+-------------+----------------+\n");
                    printf("| Name     | Product Type   | Rating | Evaluation date  |\n");
                    printf("+----------+------------+-------------+----------------+\n");
                }
            
            char *ApplicantName = strtok(line, ",");
            char *CareerType = strtok(NULL, ",");
            char *Advice = strtok(NULL, ",");
            char *AdviceDate = strtok(NULL, "\n");

            printf("| %-8s | %-14s | %-6s | %-16s | %-3d |\n", ApplicantName, CareerType, Advice, AdviceDate);
            found = 1;   
            printf("+----------+------------+-------------+----------------+\n");
            }
            count++;
        }
       
 if(found != 1) printf("Data is not found.\n");
        fclose(file);
    }

}

            fclose(file);

    

void Update_menu()
{
    int count = 0, i = 1;
    char updateStatus;
    FILE *file = fopen("makiancode.csv", "r");
    int num;
    char line[200];
    printf("Update data");
    while(fgets(line, sizeof(line), file) != NULL)
    {
        if(count < 1){
            printf("+----------+------------+-------------+----------------+\n");
            printf("| Seller Name  | Product Type  | Rating | Evaluation date  |\n");
            printf("+----------+------------+-------------+----------------+\n");
        }
            
        char *ApplicantName = strtok(line, ",");
        char *CareerType = strtok(NULL, ",");
        char *Advice = strtok(NULL, ",");
        char *AdviceDate = strtok(NULL, "\n");

        printf("| %-8s | %-14s | %-6s | %-16s | %-3d |\n", ApplicantName, CareerType, Advice, AdviceDate, i);
        printf("+----------+------------+-------------+----------------+\n");
        count++;
        i++;
    }
}

void menu() // แบบคร่าวๆ
{

    int select;
    printf("\n=== Adive Career ===\n");
    printf("1.Add \n");
    printf("2.Search menu\n");
    printf("3.Update menu\n");
    printf("4.Delete menu\n");
    printf("please select the menu : ");
    scanf("%d",&select);
        switch (select)
        {
            case 1:Add_menu();
            break;
            case 2:Search_menu();
            break;
            case 3:Update_menu();
            break;
            //case 4:(Delete_menu); //จะมาทำอีกที
            // break;

        }
      
}
int main()
{
    menu();
    return 0;
}
  