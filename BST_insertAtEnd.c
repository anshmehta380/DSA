// #include<stdio.h>
// #include<malloc.h>

// struct node{
//     int data;
//     struct node* left;
//     struct node* right;
// };

// struct node* createNode(int data){
//     struct node *n; // creating a node pointer
//     n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
//     n->data = data; // Setting the data
//     n->left = NULL; // Setting the left and right children to NULL
//     n->right = NULL; // Setting the left and right children to NULL
//     return n; // Finally returning the created node
// }

// void insert(struct node *root, int key){
//    struct node *prev = NULL;
//    while(root!=NULL){
//        prev = root;
//        if(key==root->data){
//            printf("Cannot insert %d, already in BST", key);
//            return;
//        }
//        else if(key<root->data){
//            root = root->left;
//        }
//        else{
//            root = root->right;
//        }
//    }
//    struct node* new = createNode(key);
//    if(key<prev->data){
//        prev->left = new;
//    }
//    else{
//        prev->right = new;
//    }

// }

// int main(){
     
//     struct node *p = createNode(5);
//     struct node *p1 = createNode(3);
//     struct node *p2 = createNode(6);
//     struct node *p3 = createNode(1);
//     struct node *p4 = createNode(4);

//     p->left = p1;
//     p->right = p2;
//     p1->left = p3;
//     p1->right = p4;

//     insert(p, 16);
//     printf("%d", p->right->right->data);
//     return 0;
// }



// My Code
#include<stdio.h>
#include<malloc.h>
struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *CreateNode(int val)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void insert(struct node *root,int key)
{   
    struct node *prev = NULL;
    //Finding the node after which you want to insert
    //here root != NULL means unless you find the place where you want to insert keep searching for that place
    while(root!= NULL)
    {
        prev = root; 
        //Find the node after which you want to insert
        if(key<root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }        
    }
    // When root will be null previous will be pointing at it's previous root
    // Now create a new node and check whethere you have to insert at left or right 
    struct node *new = CreateNode(key);
    if(key<prev->data)
    {
        prev->left=new;
    }
    else {
        prev->right= new;
    }
}
int main()
{
    struct node *p = CreateNode(5);
    struct node *p1 = CreateNode(6);
    struct node *p2= CreateNode(3);
    struct node *p3 = CreateNode(1);
    struct node *p4 = CreateNode(4);
    
    p->left = p1;
    p->right = p2;
    p1->right = p3;
    p1->right = p4;

    insert(p,7);
    printf("%d",p->right->right->data);
    return 0;
}