#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
}; 
node *insertBST(node *root,int val)
{
    if(root==NULL)
    {
        return new node(val);
    }
    // if the value of the current root is smaller than loop will execute
    //in the loop the value is smaller so now we will point to the root's left node and call the
    // function again but now will make the "Pointed node" our root
    // Now it will again check the values if small then left and great than right until it reach the end
    // the end will be where any pointer becomes NULL;
    if(val<root->data)
    {
        root->left = insertBST(root->left,val);
    }
    else if(val>root->data)
    {
        root->right = insertBST(root->right,val);
    }
    return root;
}
void inorder(node *root)
{
    if (root==NULL)
    {
        return;
    }
    inorder(root->left); 
    cout << root->data << " ";
    inorder(root->right);
    cout << root->data << " ";
}
int main()
{
    // Creating a very first node root
    node *root = NULL;
    // Depending on the first node all the other nodes will be constructed
    // the function will return a root 
    // in the function root == NULL hence the condition
    root = insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);
    return 0;
}