#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STACK_SIZE 20
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct{
	int data[STACK_SIZE];
	int top;
}stack;

void initialize(stack *stk){
	stk->top=-1;
}

void push(stack *stk, int c){
	if(stk->top!=STACK_SIZE-1){
		stk->top++;
		stk->data[stk->top]=c;
	}
	else{
		printf("STACK IS FULL !!! YOU CAN'T PUSH A DATA.'");
	}
}

int pop(stack *stk) {
	if(stk->top!=-1){
		return stk->data[stk->top--];
	}
	else{
		printf("STACK IS EMPTY !!! YOU CAN'T POP A DATA.'");
		return 0;
	}	
}

int main(){
	
	char exp[20]="564+-9-'\0'";
	char *e;
	stack s;
	initialize(&s);
	
	for(int i = 0; i<strlen(exp); i++){
		//printf("%c\n",exp[i]);
		if(exp[i]=='+'){
			int n1 = pop(&s);
			int n2 = pop(&s);
			int result = n2+n1;
			push(&s,result);
			printf("push after + : %d\n",result);
		}
		else if(exp[i]=='-'){
			int n1 = pop(&s);
			int n2 = pop(&s);
			int result = n2-n1;
			push(&s,result);
			printf("push after - : %d\n",result);			
		}
		else if(exp[i]=='*'){
			int n1 = pop(&s);
			int n2 = pop(&s);
			int result = n2*n1;
			push(&s,result);
			printf("push after * : %d\n",result);
		}
		else if(exp[i]=='/'){
			int n1 = pop(&s);
			int n2 = pop(&s);
			int result = n2/n1;
			push(&s,result);
			printf("push after / : %d\n",result);
		}
		/*else if(exp[i]>='0' && exp[i]<='9'){
			char temp[2];
			temp[0]=exp[i];
			temp[1]='\0';
			int n = atoi(temp);
			push(&s,n);
			printf("push number : %d\n",n);
		}*/
		else if(isdigit(exp[i])){
			int n = exp[i]-48;
			push(&s,n);
			printf("push number : %d\n",n);
		}
	}
	
	/*e=exp;
	
	while(*e!='\0'){
		printf("%c\n",*e);
		*e++;
	}*/
	
	int result = pop(&s);
	printf("The result is : %d\n",result);
	
	return 0;
}


/*int main(){
	
	char exp[20]="564+-9-";
	char *e;
	stack s;
	initialize(&s);
	
	int n1,n2,n3,number;
	
	e=exp;
	
	while(*e!='\0'){
		
		if(isdigit(*e)){
			number = *e-48;
			push(&s,number);
		}
		else{
			n1=pop(&s);
			n2=pop(&s);
			
			switch(*e){
				case '+':
					n3=n2+n1;
					break;
				case '-':
					n3=n2-n1;
					break;
				case '*':
					n3=n2*n1;
					break;
				case '/':
					n3=n2/n1;
					break;
			}
			push(&s,n3);
		}
		e++;
	}
	printf("Result is = %d\n",pop(&s));
}*/
