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
node *createBst(node *root,int val){
    if(root == NULL){
        return new node(val);
    }
    if(val<root->data)
    {
        root->left = createBst(root->left,val);
    }
    else
    {
        root->right = createBst(root->right,val);
    }
    return root;
}
// PreOrder - <Root><Left><Right>
void preorder(node *root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root -> data << " ";
    preorder(root->left);
    preorder(root->right);
}

// InOrder - <Left><Root><Right>
void inorder(node *root)
{
    if(root == NULL)
    {
        return;
    }
    preorder(root->left);
    cout << root->data << " ";
    preorder(root->right);
}

// PostOrder - <Left><Right><Root>
void postorder(node *root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int main()
{
    struct node *root = NULL;
    root = createBst(root,10);
    createBst(root,4);
    createBst(root,23);
    createBst(root,2);
    createBst(root,6);
    createBst(root,8);
    createBst(root,4);
    createBst(root,20);
    createBst(root,19);
    cout << "Preorder: " << endl;
    preorder(root);
    cout << endl;
    cout << "Inorder: " << endl;
    inorder(root);
    cout << endl;
    cout << "Postorder: " << endl;
    postorder(root);
    return 0;
}