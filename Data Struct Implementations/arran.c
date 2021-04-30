#include <stdio.h>
#include <stdlib.h>

int count=0;

struct node
{
    int data;
    struct node *next;
};

struct node *concat( struct node *start1,struct node *start2)
{
    struct node *ptr;
    if(start1==NULL)
    {
    	if(start2==NULL)   
        	return 0;
        else
        	return start2;
    }
    ptr=start1;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=start2;    
    return start1;
}

struct node *eve_concat( struct node *front1,struct node *front2)
{
    struct node *ptr1,*ptr2,*head,*front3,*t;
    int cot=2;
    front3=NULL;
    if(front1==NULL)
    {
    	if(front2==NULL)   
        	return 0;
        else
        	return front2;
    }
    ptr1=front1;
    ptr2=front2;
    while(cot&&ptr1!=NULL&&ptr2!=NULL) {
    head=malloc(sizeof(struct node));
    if(cot%2==0){
    	head->data=ptr1->data;
    	ptr1=ptr1->next;
    	printf("s");
	}	
    else {
    	head->data=ptr2->data;
    	ptr2=ptr2->next;
    	printf("d");
    }
    head->next=NULL;
    if(front3==NULL)
    	front3=head;
    else
    	t->next=head;
    t=head;
    cot++;
	}
	return front3;
}

void display(struct node *front)
{
    if(front == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        count++;
        printf("%d\n", front -> data);
        display(front->next);
    }
}

void swap(struct node *a, struct node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSort(struct node *start)
{
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;
 
    /* Checking for empty list */
    if (ptr1 == NULL)
        return;
 
    do
    {
        swapped = 0;
        ptr1 = start;
 
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);

    struct node *emp = start;
    printf("\n");
    while (emp!=NULL)
    {
        printf("%d ", emp->data);
        emp = emp->next;
    }
}


int main()
{
    struct node *temp,*front1,*front2,*head,*con;
    front1=NULL;
    front2=NULL;
    int count = 0;
    int choice = 1;
    printf("Enter the first linked list \n");
    while (choice) {
    	head=malloc(sizeof(struct node));
    	scanf("%d",&head->data);
    	head->next=NULL;
    	if(front1==NULL) 
    		front1=head;
    	else
    		temp->next=head;
    	temp=head;
    	printf("Enter the choice \t");
    	scanf("%d",&choice);
    }

    choice = 1;
    printf("Enter the second linked list \n");
    while (choice) {
    	head=malloc(sizeof(struct node));
    	scanf("%d",&head->data);
    	head->next=NULL;
    	if(front2==NULL) 
    		front2=head;
    	else
    		temp->next=head;
    	temp=head;
    	printf("Enter the choice \t");
    	scanf("%d",&choice);
    }

    con=eve_concat(front1,front2);
    display(con);
    printf("The number is elements is %d \n",count);
    bubbleSort(con);
    display(con);
 }
