#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>

struct node{
    int data;
    int exp;
    int *next;
}*head,*temp,*first;

display(struct node *head)
{
    if(head == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%d\t%d\n", head -> data,head->exp);
        display(head->next);
    }
}
struct node* create(){
    int choice =1;
    first=NULL;
    while(choice){
        head=malloc(sizeof(struct node));
        printf("Enter the data of the head node\n");
        scanf("%d",&head->data);
        printf("Enter the power of the expression\n");
        scanf("%d",&head->exp);
        head->next=NULL;
        if(first==NULL)
            first=head;
        else
            temp->next=head;
        temp=head;
        printf("Do you want to continue(Type 0 or 1)?\n");
        scanf("%d", &choice);
    }
    return (first);
}

struct node *add(struct node *ll1,struct node *ll2){
    struct node *lt1,*lt2,*ll3,*front,*t;
    lt1=ll1;
    lt2=ll2;
    front=NULL;
        while(lt1!=NULL&&lt2!=NULL){
        if(lt1->exp==lt2->exp){
            ll3=malloc(sizeof(struct node));
            ll3->data=lt1->data+lt2->data;
            ll3->exp=lt1->exp;
            ll3->next=NULL;
            lt1=lt1->next;
            lt2=lt2->next;

            if(front==NULL)
                front=ll3;
            else
                t->next=ll3;
            t=ll3;
        }
        else if(lt1->exp>lt2->exp){
            ll3=malloc(sizeof(struct node));
            ll3->data=lt2->data;
            ll3->exp=lt2->exp;
            ll3->next=NULL;
            lt2=lt2->next;

            if(front==NULL)
                front=ll3;
            else
                t->next=ll3;
            t=ll3;
        }
        else if(lt1->exp<lt2->exp){
            ll3=malloc(sizeof(struct node));
            ll3->data=lt1->data;
            ll3->exp=lt1->exp;
            ll3->next=NULL;
            lt1=lt1->next;

            if(front==NULL)
                front=ll3;
            else
                t->next=ll3;
            t=ll3;
        }
    }
    while(lt1!=NULL){
        ll3=malloc(sizeof(struct node));
        ll3->data=lt1->data;
        ll3->exp=lt1->exp;
        ll3->next=NULL;
        lt1=lt1->next;

        if(front==NULL) 
            front=ll3;
        else
            t->next=ll3;
        t=ll3;
    }
    while(lt2!=NULL){
            ll3=malloc(sizeof(struct node));
            ll3->data=lt2->data;
            ll3->exp=lt2->exp;
            ll3->next=NULL;
            lt2=lt2->next;

            if(front==NULL)
                front=ll3;
            else
                t->next=ll3;
            t=ll3;
    }
    return front;
}

struct node *unions(struct node *ll1,struct node *ll2){
    struct node *lt1,*lt2,*lt3,*tt,*fr;
    fr=NULL;
    lt1=ll1;
    lt2=ll2;
    while(lt1!=NULL){
        while(lt2!=NULL){
            if(lt1->data==lt2->data){
                lt3=malloc(sizeof(struct node));
                lt3->data=lt1->data;
                lt3->next=NULL;
                if(fr==NULL)
                    fr=lt3;
                else
                    tt->next=lt3;
                tt=lt3;
            }
            lt2=lt2->next;
        }
        lt2=ll2;
        lt1=lt1->next;
    }
    return (fr);
}

int main() {
	struct node *ll1,*ll2,*al3;
    ll1=create();
    ll2=create();
    display(ll1);
    display(ll2);
    al3=unions(ll1,ll2);
    //al3=add(ll1,ll2);
    display(al3);
}