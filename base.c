#include <stdio.h>
#include <string.h>
#include "base.h"

// Function: print_all_records()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void print_all_records(Record records[],int* count){
	// TODO: Modify this function as you need
	//printf("print_all_records(): this function needs to be implemented\n\n");
  int i=0;
  printf("backnum       name        workTime        pay       totalpay        position\n");
  printf("-------------------------------------------------------------------------\n");
  for(int i=0;i<*count;++i){
    printf("%-8s",records[i].back_num);
    printf("%12s",records[i].name);
    printf("%10.d",records[i].workTime);
    printf("%18.d",records[i].pay);
    printf("%10.d",records[i].totalPay);
    printf("%18s\n",records[i].position);
  }

}


// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void add_a_record(Record records[],int *count){
	// TODO: Modify this function as you need
	//printf("add_a_record(): this function needs to be implemented\n\n");
  printf("put a backnumber of player : ");
  scanf("%s",records[*count].back_num);
  fflush(stdin);
  printf("put a name of player: ");
  scanf("%s",records[*count].name);
  fflush(stdin);
  printf("put a playing time: ");
  scanf("%d",&records[*count].workTime);
  fflush(stdin);
  printf("put a Hourly wage: ");
  scanf("%d",&records[*count].pay);
  fflush(stdin);
  records[*count].totalPay=(records[*count].pay)*(records[*count].workTime);
  printf("put a position: ");
  scanf("%s",records[*count].position);
  fflush(stdin);
  (*count)++;
}


// TODO: Add more functions to fulfill the requirements

void searchplayer(Record records[],int* count){
  int i,j;
  int num=0;
  char plyname[20];
  char position[10];
  printf("What would you like to search for?\n");
  printf("1. name\n");
  printf("2. position\n");
  printf("enter a number:");
  scanf("%d",&num);
  if(num==1){
    printf("Enter a name:");
    scanf("%s",plyname);
    for(i=0;i<*count;i++){
      if(strcmp(records[i].name,plyname)==0){
        printf("\n");
        printf("name: %s\n",records[i].name);
        printf("worktime: %d hours\n",records[i].workTime);
        printf("hourly wage: %d\n",records[i].pay);
        printf("total wage: %d\n",records[i].totalPay);
        printf("position: %s\n",records[i].position);
    }
  }
  }
  if(num==2){
    printf("Enter a position:");
    scanf("%s",position);
    for(i=0;i<*count;i++){
      if(strcmp(records[i].position,position)==0){
        printf("\n");
        printf("name: %s\n",records[i].name);
        printf("worktime: %d hours\n",records[i].workTime);
        printf("hourly wage: %d\n",records[i].pay);
        printf("total wage: %d\n",records[i].totalPay);
        printf("position: %s\n",records[i].position);
    }
  }
  }


 

}
void deleteplayer(Record records[],int* count){
  char plyname[20];
  printf("Enter a name: ");
  scanf("%s",plyname);
  for(int i=0;i<*count;i++){
    if(strcmp(records[i].name,plyname)==0){
      //printf("\n");
        strcpy(records[i].back_num," ");
         strcpy(records[i].name," ");
         records[i].workTime=0;
         records[i].pay=0;
         records[i].totalPay=records[i].workTime*records[i].pay;
         strcpy(records[i].position," ");
      
    }
  }
}
int update(Record records[],int *count){
  char c[10]="yes";
  int num=10;
  int pay=0;
  int worktime=0;
  char player[20]="";
  while(strcmp(c,"yes")==0){
    printf("Which player do you want to Update?");
    scanf("%s",player);
    for(int i=0;i<=*count;i++){
      if(strcmp(records[i].name,player)==0){
        printf("Which one do you want to update?\n");
        printf("1.Pay\n");
        printf("2.Worktime  :");
        scanf("%d",&num);
        if(num==1){
          printf("Enter updated pay:");
          scanf("%d",&pay);
          records[i].pay=pay;
        }
        if(num==2){
          printf("Enter updated worktime:");
          scanf("%d",&worktime);
          records[i].workTime=worktime;
        }
      }
      records[i].totalPay=(records[i].pay)*(records[i].workTime);
    }
    printf("Do you want to update more?\n");
    printf("yes/no :");
    scanf("%s",c);
    }
    printf("it's updated!!\n");

    return 0;
}


int readfile(Record records[],int* count) {
  FILE *fp = NULL;
   fp=fopen("report.txt", "r");
  int i=*count;
  char a[100]="";

  if (fp == NULL) {
    printf("can't find file! \n");
    return 0;
  }
  while(1){
    if(feof(fp)!=0){
      break;
    }
    fscanf(fp,"%s\n",a);
    fscanf(fp,"%s %s\n",a,records[i].back_num);
    fscanf(fp,"%s %s\n",a,records[i].name);
    fscanf(fp,"%s %d\n",a,&records[i].workTime);
    fscanf(fp,"%s %d\n",a,&records[i].pay);
    fscanf(fp,"%s %d\n",a,&records[i].totalPay);
    fscanf(fp,"%s %s\n",a,records[i].position);
    fscanf(fp,"%s\n",a);

    
    //fscanf(fp,"%s %s %d %d %f %s\n",records[i].back_num,records[i].name,&records[i].workTime,&records[i].pay,&records[i].totalPay,records[i].position);
    i++;
  }
  (*count)=i;
  fclose(fp);
  return 0;

 
}
int readfile2(Record records[],int* count){
  FILE *fp = NULL;
   fp=fopen("report.txt", "r");
  int i=0;
  char a[100]="";

  if (fp == NULL) {
    printf("can't find file! \n");
    return 0;
  }
  while(1){
    if(feof(fp)!=0){
      break;
    }
    
    fscanf(fp,"%s\n",a);
    fscanf(fp,"%s %s\n",a,records[i].back_num);
    fscanf(fp,"%s %s\n",a,records[i].name);
    fscanf(fp,"%s %d\n",a,&records[i].workTime);
    fscanf(fp,"%s %d\n",a,&records[i].pay);
    fscanf(fp,"%s %d\n",a,&records[i].totalPay);
    fscanf(fp,"%s %s\n",a,records[i].position);
    fscanf(fp,"%s\n",a);
    i++;
  }
  (*count)=i;
  fclose(fp);
  return 0;
}

int writefile(Record records[],int *count){
  FILE *fp=NULL;
  fp = fopen("report.txt","w");
  //fprintf(fp,"backnum       name        workTime        pay       totalpay        position\n");

  for(int i=0;i<*count;i++){
    fprintf(fp,"-------------------------------------------------------------------------\n");
    fprintf(fp,"BackNumber: ");
    fprintf(fp,"%s\n",records[i].back_num);
    fprintf(fp,"Name: ");
    fprintf(fp,"%s\n",records[i].name);
    fprintf(fp,"WorkTime: ");
    fprintf(fp,"%d\n",records[i].workTime);
    fprintf(fp,"Pay: ");
    fprintf(fp,"%d\n",records[i].pay);
    fprintf(fp,"TotalPay: ");
    fprintf(fp,"%d\n",records[i].totalPay);
    fprintf(fp,"Position: ");
    fprintf(fp,"%s\n",records[i].position);
    fprintf(fp,"-------------------------------------------------------------------------\n");
  }

   fclose(fp);
   printf("Success writng.\n");
   return 0;
}
