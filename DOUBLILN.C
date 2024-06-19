#include<conio.h>
#include<stdio.h>

void addbeg();
void show();
int val;


struct node {
	struct node *prev;
	int data;
	struct node *next;
}*start, *temp, *curr, *newnode;

void add_beg();
void show();

void add_beg()
{
	clrscr();
	printf("\nEnter the Value\n");
	scanf("%d",&val);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=val;
	if(start==NULL)
	{
		newnode->next=NULL;
		newnode->prev=NULL;
		start=newnode;
	}
	else
	{
		newnode->prev=NULL;
		newnode->next=start;
		start->prev=newnode;
		start=newnode;
	}
	printf("\n");
}

void show(){
	clrscr();
	printf("\nDoubly linked list\n");
	temp=start;
	do{
		printf("<-%d->",temp->data);
		temp=temp->next;
	}while(temp!=NULL);
}

void main()
{
	int ch;
	clrscr();
	do
	{
		printf("\n\nSelect Operation\n");
		printf("1.Add_at_start\t2.Add_in_between\t3.Add_at_end\t4.Del_at_start\n5.Del_at_Between\t6.Del_at_End\t7.Show\t8.Exit\n");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			add_beg();
			break;
		case 7:
			show();
			break;
		case 8:
			exit(0);
			break;
		default:
			printf("\nWrong Operation\n");
		}
	} while (ch <= 8 && ch!=0);

	getch();
}

