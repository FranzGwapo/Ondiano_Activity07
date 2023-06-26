#include <stdio.h>
#include <stdlib.h>
#include "stackqueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	VirtualSpace mySpace = newVirtualSpace();
	int choice1 = 0;
	int choice2 = 0;
	StackList StkList = -1;
	StackList QueueList = -1;
	Product p;
	
	int id, qty, date, month, year;
	String name;
	double price;
	
//	//		system("cls");
//		printf("MENU\n");
//		printf("MAIN MENU\n");
//		printf("---------------------\n");
//		printf("Choose a List to be added:\n");
//		printf("1. Stack List\n2. Queue List\n");
//		printf("Choice: ");	
//		scanf("%d", &choice1);
	do{
		system("cls");
		printf("MENU\n");
		printf("MAIN MENU\n");
		printf("---------------------\n");
		printf("Choose a List to be added:\n");
		printf("1. Stack List\n2. Queue List\n");
		printf("Choice: ");	
		scanf("%d", &choice1);
		switch(choice1){
			case 1: 
				printf("STACK LIST\n");
				printf("1. Push\n2. Pop\n3. Peek\n4. IsFull\n5. IsEmpty\n6. Display\n");
				printf("Choice: ");
				scanf("%d", &choice2);
				switch(choice2){
					case 1:
						printf("PUSH\n");
						printf("Enter the id of a Product: ");
						scanf("%d", &id);
						printf("Enter the name of a Product: ");
						scanf("%s", &name);
						printf("Enter the quantity of a Product: ");
						scanf("%d", &qty);
						printf("Enter the price of a Product: ");
						scanf("%lf", &price);
						printf("Enter the day of expiry of a Product: ");
						scanf("%d", &date);
						printf("Enter the month of a Product: ");
						scanf("%d", &month);
						printf("Enter the year of a Product: ");
						scanf("%d", &year);
						p = newProduct(id, name, qty, price, date, month, year);
						push(&mySpace, &StkList, p);
						printf("PUSH DISPLAY\n");
						display(mySpace, StkList);
						break;
					
					case 2:
						printf("PUSH\n");
						pop(&mySpace, &StkList);
						break;
					case 6:
						printf("DISPLAY: ");
						display(mySpace, StkList);
					default:
						break;
				}
				break;
			case 2:
				printf("QUEUE LIST\n");
				printf("1. Enqueue\n2. Dequeue\n3. Front\n4. IsFull\n5. IsEmpty\n6. Display\n");
				printf("Choice: ");
				scanf("%d", &choice2);
				break;
			case 0:
				printf("Thank you!\n");
			default:
				printf("Invalid choice...\n");
		}
		printf("\n");
		system("pause");
	} while(choice1!=0);
	
	
	return 0;
}
