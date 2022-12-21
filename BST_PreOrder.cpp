#include<iostream>
using namespace std;
// Creating a tree node;
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
// PreOrder = <root><Left><Right>
void preorder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
// InOrder = <Left><Root><Right>
void inorder(struct node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder (root->right);  
}
// PostOrder = <Left><Right><Root>
void postorder(struct node *root)
{
    if(root == NULL)
        return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
}
/*               1
               /   \
              2     3
             / \   / \
            4   5 6   7
*/  

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout << "PreOrder function: " << endl; 
    preorder(root);
    cout << endl;
    cout << "InOrder function: " << endl;
    inorder(root);
    cout << endl;
    cout << "PostOrder function: " << endl;
    postorder(root);
    return 0;
}