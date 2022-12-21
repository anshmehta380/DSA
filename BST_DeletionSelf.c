#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createBST(int val)
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    n->right = NULL;
    n->left = NULL;
    return n;
}
void inOrder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}
struct node *inOrderPredecessor(struct node *root)
{
    root = root->left;
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *deleteNode(struct node *root,int val)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->left==NULL && root-> right ==NULL)
    {
        free(root);
        return NULL;
    }
    struct node *iPri;
    if(val<root->data)
    {
        root->left = deleteNode(root->left,val);
    }
    else if(val>root->data)
    {
        root->right = deleteNode(root->right,val);
    }
    else
    {
        iPri = inOrderPredecessor(root);
        root->data = iPri->data;
        root->left = deleteNode(root->left,iPri->data);
    }
}
int main()
{
    struct node *p = createBST(5);
    struct node *p1 = createBST(3);
    struct node *p2 = createBST(6);
    struct node *p3 = createBST(1);
    struct node *p4 = createBST(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    inOrder(p);
    deleteNode(p,3);
    printf("\n");
    inOrder(p);
    return 0;
}