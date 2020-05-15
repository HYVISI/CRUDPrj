#include <stdio.h>
#include <string.h>
#include "base.h"
#include "extras.h"
#include "record.h"
int  count=0;
int count1=0;
#define MAX_RECORDS 1000
// function prototypes
void input_handler(int input, Record[]);
void display_menu();
void clearBuffer(void){
     //입력버퍼에 문자가 들어있으면,
     //문자를 모두 소모하여 버퍼를 비워버림
     //단순히 사용만하고 저장하지 않으면 비워지게 되는 원리 이용
     while (getchar() != '\n');
}


// main function
int main(){
	Record records[MAX_RECORDS];
	int user_input=0;
	while(user_input!=99){
    if(count1>0){
      clearBuffer();
    }
		display_menu();
		printf("\nSelect a menu> ");
		//fgets(user_input, 64, stdin);
    scanf("%d",&user_input);
		//user_input[strlen(user_input)-1] = '\0';
		input_handler(user_input, records);
	}

	return 0;
}


// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
void input_handler(int input, Record records[]){

	// TODO: Modify this function as you need

	if(input==1){
    add_a_record(records, &count);
    count1++;
  }
	else if(input==2){
    print_all_records(records,&count);
    count1++;	
  }
	else if(input==3)
  {
    	searchplayer(records,&count);
      count1++;
  }
	else if(input==4)
  {
    		deleteplayer(records,&count);
        count1++;

  }
  else if(input==5){
    readfile(records,&count);
    count1++;
  }
  else if(input==6){
    readfile2(records,&count);
    count1++;
  }
  else if(input==7){
    writefile(records,&count);
    count1++;
  }
  else if(input==8){
    update(records,&count);
    count1++;
  }
  else if(input==9){
    defragment(records, &count);
    count1++;
  }

  else if(input==10){
    Record recordcopy[MAX_RECORDS];
    sort(records,&count);
  }
	else if(input == 11){
		searchBacknum(records, &count);
	}
	else if(input == 12){
		searchTotalPay(records, &count);
	}
    

	else if(input==99)
		printf("Terminating... bye!\n"); // Quit - no operation (an empty statement with a semi-colon)
	else
		printf("Unknown menu: %d \n\n", input);
}



// Function: display_menu()
// Input: none
// Output: none
// - Leave a brief information about the function
void display_menu(){

	// TODO: Modify this function as you need

	printf("******************************\n");
	printf(" Membership management system \n");
	printf("******************************\n");
	printf(" 1. Add a new membber\n");
	printf(" 2. Print all members\n");
	printf(" 3. Print memeber by condition\n");
	printf(" 4. Delete member\n");
  printf(" 5. Read file\n");
  printf(" 6. Read file2(overwrite)\n");
  printf(" 7. Write file\n");
  printf(" 8. Update\n");
  printf(" 9. Defragment\n");
  printf(" 10. Sort\n");
	printf(" 11. Search(backnum)\n");
	printf(" 12. Search(totalpay)\n");
	printf(" 99. Quit\n");
}
