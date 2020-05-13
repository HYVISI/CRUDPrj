#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "extras.h"

void swap(Record *a, Record *b){
     Record c;
     c = *a;
     *a = *b;
     *b = c;
}
// Function: defragment()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: 1 if successful, otherwise 0
// - Leave a brief information about the function
int defragment(Record records[],int *count){
	// TODO: Modify this function as you need
	for(int i=0;i<*count-1;i++){
    if(strcmp(records[i].name," ")==0){
    for(int j=i;j<*count-1;j++){
      
        swap(&records[j],&records[j+1]);

      }

    }
    
    }
    	return 0;
  }
	// TODO: return 1 if defragment succeed; return 0 otherwise 



// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void display_stats(Record records[]){
	// TODO: Modify this function as you need
	printf("display_stats(): this function needs to be implemented\n\n"); // TODO: Remove this line
}


// TODO: Add more functions to fulfill the optional requirements
void sort(Record records[],int *count){
  int i=0;
  int j=0;
  int num;
  printf("What are you going to sort by?\n");
  printf("1.position\n");
  printf("2.totalpay\n");
  printf("3.backnum\n");
  printf("Put a number:");
  scanf("%d",&num);
  if(num==2){
    for(int i=0;i<*count-1;i++){
    for(j=0;j<*count-1;j++){
      if(records[j].totalPay<=records[j+1].totalPay){
        swap(&records[j],&records[j+1]);
      }
      }
    }
  }
  else if(num==1){
    for(int i=0;i<*count-1;i++){
      for(j=0;j<*count-1;j++){
        if(strcmp(records[j].position,records[j+1].position)>0){
          swap(&records[j],&records[j+1]);
        }
      }
    }
  }
  else if(num == 3){
	for(int i=0; i<*count-1; i++){
		for(j =0; j<*count-1;j++){
			int num1 = atoi(records[j].back_num);
			int num2 = atoi(records[j+1].back_num);
			if(num1 > num2)
				swap(&records[j],&records[j+1]);
		}
	}
  }

}
