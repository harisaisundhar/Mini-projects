#include<stdio.h>
#include<stdlib.h>

typedef struct BST{
	int data;
	struct BST *left;
	struct BST *right;
}node;

node *create(){
	node *temp;
	temp=(node *)malloc(sizeof(node));
	printf("Enter the data of the node \t");
	scanf("%d",&temp->data);
	temp->left=temp->right=NULL;
	return temp;
}

void insert(node *root,node *temp){
	if(root->data>temp->data){
		if(root->left)
			insert(root->left,temp);
		else
			root->left=temp;
	}
	if(root->data<temp->data){
		if(root->right)
			insert(root->right,temp);
		else
			root->right=temp;
	}
}

int search(node *root,int key){
	while(root){
		if(key<root->data)
			root=root->left;
		else if(key>root->data)
			root=root->right;
		else
			return 1;
	}
	return 0;
}

node *del(node *root,int key){
	node *t;
	t=root;
	while(t){
		if(key<t->data)
			t=t->left;
		else if(key>root->data)
			t=t->right;
		else{
			t=NULL;
			return root;
		}
	}
	return root;
}

struct node * minValueNode(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}

struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->key = temp->key;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int max(node *root){
	if(!root)
		return 0;
	int r=root->data;
	int rl=max(root->left);
	int rr=max(root->right);
	if(rl>r)
		r=rl;
	if(rr>r)
		r=rr;
	return r;
}

int size(node *root){
	if(!root)
		return 0;
	return (size(root->left)+1+size(root->right));
}

int count(node *root){
	if(!root)
		return 0;
	return (count(root->left)+root->data+count(root->right));
}

void leaf(node *root){
	if(!root)
		return;
	if((!root->left)&&(!root->right))
		printf("%d",root->data);
	if(root->left)
		leaf(root->left);
	if(root->right)
		leaf(root->right);
}

void inorder(node *root){
	if(root){
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
}

void preorder(node *root){
	if(root){
		printf("%d",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node *root){
	if(root){
		postorder(root->left);
		postorder(root->right);
		printf("%d",root->data);
	}
}

int main(void){
	int choice;
	node *root=NULL,*temp;

	do{
		temp=create();
		if(root==NULL)
			root=temp;
		else
			insert(root,temp);

		printf("Enter the choice to continue \t");
		scanf("%d",&choice);
	}while(choice);

	printf("\n");
	int ele;
	printf("Enter the element to search \t");
	scanf("%d",&ele);
	root=del(root,ele);
	printf("The search element 0/1 is %d \n",search(root,ele));
	printf("The sum of all the elements in th tree is %d \n",count(root));
	printf("The total elements in th tree is %d \n",size(root));
	printf("The maximum element in th tree is %d \n",max(root));
	printf("The preoreder transversal is \n");preorder(root);printf("\n");
	printf("The inoreder transversal is \n");inorder(root);printf("\n");
	printf("The postoreder transversal is \n");postorder(root);printf("\n");
	printf("The leaf nodes of the tree are \n");leaf(root);printf("\n");
}