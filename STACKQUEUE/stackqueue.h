#ifndef STACK_QUEUE_H
#define STACK_QUEUE_H

#include <stdbool.h>
#define MAX 20

typedef int StackList;
typedef char String[30];


typedef struct{
	int date;
	int month;
	int year;
} Date;

typedef struct{
	int prodID;
	String prodName;
	int prodQty;
	double prodPrice;
	Date prodExp;
} Product;

typedef struct{
	Product items;
	int link;
} SType;

typedef struct{
	SType data[MAX];
	int avail;
} VirtualSpace;

typedef struct{
	int front;
	int rear;
} Queue;

VirtualSpace newVirtualSpace();


SType initStack(SType *stack);

Product newProduct(int id, String name, int qty, double price, int date, int month, int year);
Date newDate(int date, int month, int year);

int allocSpace(VirtualSpace *vs);
int deallocSpace(VirtualSpace *vs);

void push(VirtualSpace *vs,StackList *list, Product prod);
void pop(VirtualSpace *vs, StackList *list);
Product peek(VirtualSpace vs, Product prod);
bool isEmptyStack();
bool isFullStack();
void displayStack();
void visualize(VirtualSpace vs);



void initQueue(Queue *q);
void enqueue();
void dequeue();
void isEmptyQueue();
void isFullQueue();


#endif
