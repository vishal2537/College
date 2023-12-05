#include<stdio.h>
#include<stdlib.h>
#define bool int 

struct tree
{
    int key;
    struct tree *left, *right;
};

struct Node
{
    int data;
    int top;
    struct Node *next;
} * head=NULL, *tail = NULL;

void push(int data){
   if (head==NULL && tail==NULL)
   {
       struct Node *t = malloc(sizeof(struct Node));
       t->data = data;
       t->next = NULL;
       head = t;
       tail = t;

   }
   else
   {
       struct Node *t = malloc(sizeof(struct Node));
       t->data = data;
       t->next = head;
       head = t;
   }
}
struct tree* pop(struct Node** top_ref){
    struct tree *res;
    struct Node *top;


        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;

}

int isempty(struct Node* t){
    if (t==NULL)
    {
        return 1;
    }
    return 0;
}

void inorder(struct tree* root){

    struct tree *current = root;
    bool done = 0;
    while (!done)
    {
        if (current)
        {
            
            push(current->key);
            current = current->left;
        }
        else
        {
            if (isempty(head)==0)
            {
                current = pop(&head);
                printf("%d ", current->key);
                current = current->right;
            }
            else
            {
                done = 1;
            }
        }
    }
}
struct tree *newnode(int data){
    struct tree *node = malloc(sizeof(struct tree));
    node->key = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

 int main()
{
    struct tree *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);

    inorder(root);
    return 0;
}