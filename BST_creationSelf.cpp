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
node *inserstBST(node *root,int val)
{
    if(root==NULL)
    {
        return new node(val);
    }
    if(val<root->data) {
        root->left = inserstBST(root->left,val);
    } 
    else {
        root->right = inserstBST(root->right,val);
    }
    return root;
}
void inodrder(node *root)
{
    if(root == NULL)
    {
        return;
    }
    inodrder(root->left);
    cout<< root->data << " " ; 
    inodrder(root->right);
}
int main()
{
    node *root = NULL;
    root = inserstBST(root,5);
    inserstBST(root,1);
    inserstBST(root,3);
    inserstBST(root,4);
    inserstBST(root,2);
    inserstBST(root,7); 
    // print inorder
    inodrder(root);
    cout << endl;
    return 0;
}