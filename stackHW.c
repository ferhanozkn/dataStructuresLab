#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STACK_SIZE 20
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



typedef struct{
	char data[STACK_SIZE];
	int top;
}stack;

void initialize(stack *stk){
	stk->top=-1;
}

void push(stack *stk, char c){
	if(stk->top!=STACK_SIZE-1){
		stk->top++;
		stk->data[stk->top]=c;
	}
	else{
		printf("\nSTACK IS FULL !!! YOU CAN'T PUSH A DATA.\n");
	}
}


char pop(stack *stk) {
	if(stk->top!=-1){
		return stk->data[stk->top--];
	}
	else{
		printf("\nSTACK IS EMPTY !!! YOU CAN'T POP A DATA.\n");
		return '\0';
	}	
}

bool isEmpty(stack *stk){
	return stk->top==-1;
}


int main(int argc, char *argv[]) {
	
	/*char exp[20]="{{{{}}}}'\0'";
	stack s;
	initialize(&s);
	
	for(int i = 0; i<strlen(exp); i++){
		if(exp[i]=='{'){
			push(&s,exp[i]);
		}
		else if(exp[i]=='}'){
			char ch = pop(&s);
			if(ch=='\0'){
				printf("Parantezler Esit Degildir!!!");
				return 0;
			}
		}	
	}
	
	if(isEmpty(&s)==true){
		printf("Parantezler Esit.");	
	}
	else{
		printf("Parantezler Esit Degildir!!!");
	}
	
	return 0;*/
	
	FILE* ptr;
    char cx;
    stack s;
	initialize(&s);
 
    ptr = fopen("input.txt", "r");
 
    if (NULL == ptr) {
        printf("Dosya Acilmadi!!!\n");
    }
 
    printf("Dosya Icerigi : \n");
 

    do {
        cx = fgetc(ptr);
        printf("%c", cx);
        
 		if(cx=='{'){
			push(&s,cx);
		}
		else if(cx=='}'){
			char ch = pop(&s);
			if(ch=='\0'){
				printf("Parantezler Esit Degildir!!!");
				return 0;
			}
		}	

    } while (cx != EOF);
 	
 	if(isEmpty(&s)==true){
		printf("Parantezler Esit.");	
	}
	else{
		printf("Parantezler Esit Degildir!!!");
	}
	
    fclose(ptr);
    return 0;
}