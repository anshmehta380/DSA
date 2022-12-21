#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left,*right;
    node(int val)
    {
    data = val;
    left = NULL;
    right = NULL;        
    }
};
node *createbst(node *root,int val)
{
    if(root==NULL)
    {
        return new node(val);
    }
    if(val<root->data)
    {
        root->left = createbst(root->left,val);
    }
    else 
    {
        root->right = createbst(root->right,val);
    }
    return root;
}

void postorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int main()
{
    node *root = NULL;
    root = createbst(root,10);
    createbst(root,1);
    createbst(root,2);
    createbst(root,3);
    createbst(root,4);
    createbst(root,5);
    createbst(root,6);
    createbst(root,7);
    createbst(root,8);
    createbst(root,9);
    postorder(root);
    return 0;
}