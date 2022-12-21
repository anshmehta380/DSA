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
// Create a binary tree as follow
/*
            10
           /  \
          7     18
        /  \   /  \
       6   8  12   22
*/
void preOrder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
struct node *search(node *root,int key)
{
    bool flag = false;
    if(root->data == key)
    {
        flag = true;
    }
    if(root->data < key)
    {
        return search(root->right,key);
    }
    if(root->data > key)
    {
        return search(root->left,key);
    }
    if(flag==true)
    {   
        cout << "Data found!" << endl;
    } else
    {
        cout << "Data is invalid!!" << endl;
    }
}

int main()
{
    struct node *root = new struct node(10);
    
    root->left = new struct node(7);
    root->right = new struct node(18);
    root->left->left = new struct node(6);
    root->left->right = new struct node(8);
    root->right->left = new struct node(12);
    root->right->right = new struct node(22);
    preOrder(root);
    cout << endl;  
    search(root,56);
    return 0;
}