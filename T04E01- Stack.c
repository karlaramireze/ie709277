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
		//Si se encuentra un parEntesis o corchete que abre
		//se hace push
		if(exp[i]== '(' || exp[i]=='[')
			push(s1, &exp[i]);

		//Si se encuentra un parentesis o corchete que cierra
		else if(exp[i]== ')' || exp[i]==']'){
			//Si la pila estA vacIa significa que estA desbalanceado
			//Se hace pop
			if(isEmpty(s1) != true){
				pop(s1);
				return false;
			}
			else
				return true;
		}
	}
}

void destroyStack(Stack who){
	while(isEmpty(who)!=true)
		pop(who);
	free(who);
}
