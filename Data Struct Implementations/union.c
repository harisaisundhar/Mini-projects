void insert(struct node** head_ref, int new_value);
  
/* A utility function to check if given value is present in a list */
  
bool isPresent (struct node *head, int value)
{
    struct node *t = head;
    while (t != NULL)
    {
        if (t->value == value)
            return 1;
        t = t->next;
    }
    return 0;
}
  
/* Function to get union of two linked lists head1 and head2 */
struct node *getUnion(struct node *head1, struct node *head2)
{
    struct node *result = NULL;
    struct node *t1 = head1, *t2 = head2;
  
    // Insert all elements of list1 to the result list
    while (t1 != NULL)
    {
        insert(&result, t1->value);
        t1 = t1->next;
    }
  
    // Insert those elements of list2 which are not
    // present in result list
    while (t2 != NULL)
    {
        if (!isPresent(result, t2->value))
            insert(&result, t2->value);
        t2 = t2->next;
    }
  
    return result;
}
  
/* Function to get intersection of two linked lists
  head1 and head2 */
struct node *getIntersection(struct node *head1,
                              struct node *head2)
{
    struct node *result = NULL;
    struct node *t1 = head1;
  
    // Traverse list1 and search each element of it in
    // list2. If the element is present in list 2, then
    // insert the element to result
    while (t1 != NULL)
    {
        if (isPresent(head2, t1->value))
            insert (&result, t1->value);
        t1 = t1->next;
    }
  
    return result;
}
  
/* A utility function to insert a node at the begining of a linked list*/
void insert (struct node** head_ref, int new_value)
{
    /* allocate node */
    struct node* new_node =
        (struct node ) malloc(sizeof(struct node));
  
    /* put in the value */
    new_node->value = new_value;
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);
  
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}