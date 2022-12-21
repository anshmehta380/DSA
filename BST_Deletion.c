#include<stdio.h>
#include<malloc.h>
struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

void inOrder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}
struct node *CreateNode(int val)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}
// What is inOrderPredecessor?
// InorderPredecessor means the right most node in the left subtree of the root node.
// InOrderPredecessor is the value that comes before key Node in Inorder traversal
struct node *inOrderPredecessor(struct node *root)
{
    root = root->left;
    while(root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *delete(struct node *root,int value)
{
    struct node *iPre;

    if (root==NULL)
    {
        return NULL;
    }
    // If both the children's are NULL it means we have reached the leaf node Say "Hello MotherFucker"
    // And delete that node.
    if(root->left==NULL && root->right==NULL)
    {  
        free(root);
        return NULL;
    }
   if(value<root->data)
   {
        root->left= delete(root->left,value);
   }
   else if(value>root->data)
   {
        root->right = delete(root->right,value);
   }
   else
   {
        if(root)
        // Calling the inOrderPredecessor function
        iPre = inOrderPredecessor(root);
        // here we will store the value of the InOrderPredecessor at the node we want to delete
        // Now we will delete the node where our InOrderPredecessor exists.

        // Indirectly what we did is that we replace the value of the root with our inOrderPredecessor 
        // and deleted the leaf node

        //Suppose you want to delete 10 which have two childs 5 and 12
        // now we will replace 10 with 5
        // now 5 have two childs 5 and 12
        // now we will delete it's left child which is called it's InOrderPredecessor
        // now the 10 is deleted and it's InOrderPredecessor took it place
        root->data = iPre->data;
        root->left = delete(root->left,iPre->data);
   }
   return root;
}
int main()
{
    struct node *p = CreateNode(5);
    struct node *p1 = CreateNode(3);
    struct node *p2= CreateNode(6);
    struct node *p3 = CreateNode(1);
    struct node *p4 = CreateNode(4);
    struct node *p5 = CreateNode(8);
    
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;
    inOrder(p);
    delete(p,8);
    printf("\n");
    inOrder(p);
    return 0;
}