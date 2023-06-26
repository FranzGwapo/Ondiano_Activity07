#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackqueue.h"

VirtualSpace newVirtualSpace(){
	VirtualSpace vs;
	int i;
	for(i=0;i<MAX;++i){
		vs.data[i].items = newProduct(0,"",0,0,0,0,0);
		vs.data[i].link = i-1;
	}
	vs.avail = MAX-1;
	
	return vs;
}

Product newProduct(int id, String name, int qty, double price, int date, int month, int year){
	Product p;
	
	p.prodID = id;
	strcpy(p.prodName, name);
	p.prodQty = qty;
	p.prodPrice = price;
	p.prodExp = newDate(date, month, year);
	
	return p;
}

Date newDate(int date, int month, int year){
	Date d;
	d.date = date;
	d.month = month;
	d.year = year;
	
	return d;
}

int allocSpace(VirtualSpace *vs){
	int retVal = vs->avail;
	
	if(retVal!=-1){
		vs->avail = vs->data[vs->avail].link;
		return retVal;
	}
}

int deallocSpace(VirtualSpace *vs){
	
}

void push(VirtualSpace *vs,StackList *list , Product prod){
	StackList temp = allocSpace(vs);
	
	if(temp!=-1){
		vs->data[temp].link = *list;
		*list = temp;
		vs->data[temp].items = prod;
	}
}

void pop(VirtualSpace *vs, StackList *list){
	
	if(*list != -1 && *list < MAX){
		vs->data[*list].link = vs->avail;	
		vs->data[*list].items = newProduct(0,"",0,0,0,0,0);
		vs->avail = *list;
	}
}

void display(VirtualSpace vs, StackList list){
	int i;
	printf("%5s | %30s | %s\n", "INDEX", "ELEMENTS", "NEXT");
	
	printf("---------------------------------------------\n");
	for(i=0;i<MAX;++i){
		printf("%5d | ", i);
		if(vs.data[i].items.prodID == 0){
			printf("%30s | ","EMPTY");
		}
		else{
			printf("%4d - %23s | ", vs.data[i].items.prodID, vs.data[i].items.prodName);
		}
		printf("%d\n", vs.data[i].link);
	}
	printf("---------------------------------------------\n");
	printf("AVAILABLE: %d\n\n", vs.avail);
}



