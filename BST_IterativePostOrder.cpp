#include<bits/stdc++.h>
using namespace std;
struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int val)
{
    struct node* node = new struct node;
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
void iterativePostOrder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    stack<node*> nodestack;
    nodestack.push(root);

    while(nodestack.empty()==false)
    {
        struct node* node = nodestack.top();
        printf("%d ",node->data);
        nodestack.pop();
        if(node->left)
        {
            nodestack.push(node->left);
        }
        if(node->right)
        {
            nodestack.push(node->right);
        }
    }
}
int main()
{
    struct node  *root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(2);
    iterativePostOrder(root);
    return 0;
}