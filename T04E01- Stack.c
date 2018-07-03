#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"


struct strNode{
	Type data;
	struct strNode *prior;
};

typedef struct strNode Node;

struct strStack{
	Node *top;
	int size;
};

Stack createStack(){
	Stack new=(Stack)malloc(sizeof(struct strStack));
	if(new==NULL)
		return NULL;
	new->top=NULL;
	new->size=0;
	return new;
}

bool push(Stack who, Type data){
	Node *newNode=(Node *)malloc(sizeof(Node));
	if(newNode==NULL)
		return false;
	newNode->prior=who->top;
	newNode->data=data;  //Cuidado aquÃ­
	who->size+=1;
	who->top=newNode;
	return true;
}

Type pop(Stack who){
	if (who->top==NULL)
		return NULL;

	Type temp;
	Node *tempNode;
	temp=who->top->data;
	who->size--;
	tempNode=who->top;
	who->top=who->top->prior;
	free(tempNode);
	return temp;
}

Type top(Stack who){
	if (who->top==NULL)
		return NULL;
	return who->top->data;
}

bool isEmpty(Stack who){
	if (who->size==0)
		return true;
	else
		return false;
}

bool balancedBrackets(char *exp){
	int i;
	Stack s1;
	s1= createStack();
	for(i=0; i<strlen(exp); i++){
		if(exp[i]== '(' || exp[i]=='[')
			push(s1, &exp[i]);
		if(exp[i]== ')' || exp[i]==']'){
			if(isEmpty(s1) == true){
				printf("False\n");
				return false;
			}
			else if (pop(s1)!= exp){
				printf("False\n");
				return false;
			}
		}
	}
		if(isEmpty(s1)==true)
			return true;
		else
			return false;
}

void destroyStack(Stack who){
	while(isEmpty(who)!=true)
		pop(who);
	free(who);
}
