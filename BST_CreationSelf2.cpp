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
// Creating a Binary Tree
node *CreateBST(node *root,int val)
{
    if(root == NULL)
    {
        return new node(val);
    }
    if(val<root->data)
    {
        root->left = CreateBST(root->left,val);
    }
    else 
    {
        root->right = CreateBST(root->right,val);
    }
    return root;
}
void inorder(node *root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root ->data << " ";
    inorder(root->right);
}
int main()
{
    node *root = NULL;
    root = CreateBST(root,10);
    CreateBST(root,8);
    CreateBST(root,2);
    CreateBST(root,3);
    CreateBST(root,5);
    CreateBST(root,2);
    inorder(root);
    return 0;
}