#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
node *createBST(node *root,int val)
{
    if(root==NULL)
    {
        return new node(val);
    }
    if(val>root->data)
    {
        root->right = createBST(root->right,val);
    }
    else
    {
        root->left = createBST(root->left,val);
    }
    return root;
}
void traversal(node *root)
{
    if(root==NULL){
        return;        
    }
    traversal(root->left);
    cout << root->data << " ";
    traversal(root->right);
}
struct node *search (node *root,int key)
{
    if(root->data == key)
    {
        cout << "Your data found which is: "<< root->data;
        return root;
    }
    if(key>root->data)
    {
       root =  search(root->right,key);
    }
    else 
    {
        root = search(root->left,key);
    }
}
int main()
{
    node *root = NULL;
    root = createBST(root,3);
    createBST(root,4);
    createBST(root,10);
    createBST(root,23);
    createBST(root,1);
    createBST(root,2);
    cout << " Your Traversal is: " << endl;
    traversal(root);
    cout << endl;
    search(root,10);
    return 0;
}
