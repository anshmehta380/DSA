#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
struct node *createBST(node *root,int val)
{
    if(root == NULL)
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
};
void traversal(node *root)
{
    if(root==NULL)
    {
        return;
    }
    traversal(root->left);
    cout << root->data << " ";
    traversal(root->right);
}
struct node *insert(node *root,int val)
{
    struct node *prev = NULL;
    struct node *p = new node(val);
    while(root!= NULL)
    {
        prev = root;
        if(root->data==val)
        {
            printf("You data already exists in the tree");
            return root;
        }
        else if(val<root->data)
        {
            root = root->left;
        }
        else 
        {
            root = root->right;
        }
    }
    if(val<prev->data)
    {
        prev ->left = p;
    }
    else
    {
        prev->right = p;
    }
    return root;
}
int main()
{
    struct node *root = NULL;
    root = createBST(root,10);
    createBST(root,5);
    createBST(root,8);
    createBST(root,12);
    createBST(root,3);
    createBST(root,9);
    cout << "Your Traversal is: " << endl;
    insert(root,13);
    traversal(root);

    return 0;
}