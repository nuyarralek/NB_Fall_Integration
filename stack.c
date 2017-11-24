#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definitions.h"

/******************************
*createStack
* creates a new stack
******************************/
void createStack(STACK *s)
{
	STACK_ELEMENT *head = malloc(sizeof(STACK_ELEMENT));
	head->prev = NULL;
	strcpy(head->name, "END OF THE LINE");
	s->head = head;
	return;
}
/********************************************
*push
* pushs an item onto the STACK stack
*********************************************/
void Push(STACK *s, char cityName[])
{
	STACK_ELEMENT *temp;
	temp = s->head;
	s->head = malloc(sizeof(STACK_ELEMENT));
	strcpy(s->head->name, cityName);
	s->head->prev = temp;
	return;
}

/************************************
*pop
* returns last item off the stack
*************************************/
struct STACK_ELEMENT Pop(STACK *s)
{
	STACK_ELEMENT *temp;
	STACK_ELEMENT p;
	temp = s->head;
	p = *temp;
	s->head = s->head->prev;
	free(temp);
	return p;
}

/***********************************************
*peek
* returns top  item without destruction
************************************************/
struct STACK_ELEMENT Peek(STACK *s)
{
	return *(s->head);
}
