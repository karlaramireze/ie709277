/*
 * Stack.h
 *
 *  Created on: 02/07/2018
 *      Author: Usuario
 */

#ifndef STACK_H_
#define STACK_H_

typedef enum {false, true} bool;

typedef void* Type;

typedef struct strStack *Stack;

Stack createStack();

void destroyStack(Stack);

bool push(Stack, Type);

Type pop(Stack);

Type top(Stack);

bool isEmpty(Stack);

bool balancedBrackets(char* );


#endif /* STACK_H_ */
