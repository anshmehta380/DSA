#include<stdio.h>
#include<malloc.h>
struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *CreateNode(int val)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void insert(struct node *root,int key)
{
    struct node *prev=NULL;
    while(root!=NULL){
        prev = root;
        if(key<root->data)
        {
            // root = root->left but why? because we used while loop in order to go to next statement
            // you will need new root 
            // root will keep pointing to it's next pointer unless it finds the value after which it can insert
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *ansh = CreateNode(key);
    if(key<prev->data)
        prev->left = ansh;
            prev->right = ansh;

}
int main()
{
    struct node *p = CreateNode(5);
    struct node *p1 = CreateNode(6);
    struct node *p2= CreateNode(3);
    struct node *p3 = CreateNode(1);
    struct node *p4 = CreateNode(4);
    
    p->left = p1;
    p->right = p2;
    p1->right = p3;
    p1->right = p4;

    insert(p,17);
    printf("%d",p->right->right->data);
    return 0;
}