//GROCERY MANEGEMENT

#include <stdio.h> 
#include <string.h> 
#include<stdlib.h>
char username[15];
char password [15];
int n;
// Product Data
FILE *fp;
struct add 
{
    char Category[20];
    char ID[20];
    char Name[20];
    float Price;

};
struct add a[50];
//colours
void red()
{
    printf("\033[0;31m");
}
 
void yellow()
{
  printf("\033[1;33m");
}

void green()
{
    printf("\033[0;32m");
}

void blue()
{
    printf("\033[0;36m");
}

void purple()
{
    printf("\033[0;35m");
}

//features
void Add_Product()
{

int i;

   fp = fopen ("Data.txt", "a");
blue();
printf("Enter The Number Of Items To Be Added :");
scanf("%d",&n);
for(i=0;i<n;i++)
{
blue();
printf("----- Enter The Details Of The Product : %d -----\n",i+1);

printf("Enter The Product Category :");
scanf("%s",&a[i].Category);

printf("Enter The ID Of The Product :");
scanf("%s",&a[i].ID);

printf("Enter The Product Name :");
scanf("%s",&a[i].Name);

printf("Enter The Product Price :");
scanf("%f",&a[i].Price);

fwrite(&a[i], sizeof(a[i]),1,fp);
}
fclose(fp);
}



void Display()
{
    int i=1;
    struct add a1;
fp = fopen("Data.txt","r");
while(fread(&a1,sizeof(a1),1,fp))
{
   purple();
    printf("Details Of The product : %d\n ",i++);

    printf("Product Category : %s\n",a1.Category);
    printf(" Product ID : %s\n",a1.ID);
    printf(" Product Name : %s\n",a1.Name);
    printf(" Product Price : %.2f\n",a1.Price);
    printf("-----------------------------------------------------\n");
     
}
fclose(fp);
}

void search()
{


}


   

int main() 
{
    char user[15] = "admin"; 
    char pass[12] = "123";
    
	int choice; 
    int n = 1;

   
    
do
{
    yellow();
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("                                                  \n");
    printf("               WELCOME TO GROCERY STORE\n");
    printf("                                                  \n");
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("Enter your username:\n"); 
    scanf("%s",&username); 
 
    printf("Enter your password:\n"); 
    scanf("%s",&password); 
    
    if(strcmp(username,user)==0)
    { 
        if(strcmp(password,pass)==0)
        { 
            green();
             
             printf("                                                  \n");
             printf("\nWelcome.Login Success!"); 
             printf("                                                  \n");
            break;
 
        }
        else
        {
            red(); 
            printf("\nwrong password\n"); 
            n++;
        } 
    }
    else
    { 
        red();
        printf("\nUser doesn't exist\n"); 
		n++;
	}


    if(n>5)
    {
    printf("access denied");
    exit(0);
    }
    


} while (n<=5);

 while(1)
 {
    green();
 printf("\nEnter Any Of The Following Choice\n");
 printf("1.Add The Products\n2.Display The Product \n3.Search The Product\n4.Exit\n");
 scanf("%d",&choice);

   switch(choice)
    {
    		case 1: Add_Product();
					break;
			case 2: Display();
					break;
            case 3: search();
                    break;
            case 4: return 0;
        default : printf("Invalid choice");
	}
 
 }
  return 0; 
 
} 