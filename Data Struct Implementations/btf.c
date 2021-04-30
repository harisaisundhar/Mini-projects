#include<stdio.h>
#include<stdlib.h>

typedef struct BT{
	int data;
	struct BT *left;
	struct BT *right;
}node;

node * create(){
	int x;
	printf("Enter the element (-1 to exit) \t");
	scanf("%d",&x);
	if(x==-1)
			return NULL;
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data=x;
	printf("Enter the data of the left node of %d\n",x);
	temp->left=create();
	printf("Enter the data of the right node of %d \n",x);
	temp->right=create();
	return temp;
}

void inorder(node *root){
	if(root){
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
}

int main(void){
	node *root;
	root=create();
	printf("hello \n");
	inorder(root);
}