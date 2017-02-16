#include <iostream>
using namespace std;

//the augmented interval tree is created by using the 
//functionality of BST 
// Structure to represent an interval
struct Interval
{
    int low, high;
};

// Structure to represent a node in Interval Search Tree
struct ITNode
{
    Interval *i;  // 'i' could also be a normal variable
    int max;
    ITNode *left, *right;
};
 
// A utility function to create a new Interval Search Tree Node
ITNode * newNode(Interval i)
{
    ITNode *temp = new ITNode;
    temp->i = new Interval(i);
    temp->max = i.high;
    temp->left = temp->right = NULL;
    return temp;
};
 
//A utility function to find the min value node 
ITNode *minValueNode(ITNode *root)
{
    ITNode *temp=root;
    //loop down to find the leftmost leaf
    while(temp->left!=NULL)
        temp=temp->left;
    return temp;
} 
// A utility function to insert a new Interval Search Tree Node
// This is similar to BST Insert. 
ITNode *insert(ITNode *root, Interval i)
{
    // Base case: Tree is empty, new node becomes root
    if (root == NULL)
        return newNode(i);
 
    // Get low value of interval at root
    int l = root->i->low;
 
    // If root's low value is smaller, then new interval goes to
    // left subtree
    if (i.low < l)
        root->left = insert(root->left, i);
 
    // Else, new node goes to right subtree.
    else
        root->right = insert(root->right, i);
 
    // Update the max value of this ancestor if needed
    if (root->max < i.high)
        root->max = i.high;
 
    return root;
}
 
// A utility function to check if given two intervals overlap
bool doOVerlap(Interval i1, Interval i2)
{
    if (i1.low <= i2.high && i2.low <= i1.high)
        return true;
    return false;
}
 
// The main function that searches a given interval i in a given
// Interval Tree.
void overlapSearch(ITNode *root, Interval i)
{
    // Base Case, tree is empty
    if (root == NULL) return ;
 
    // If given interval overlaps with root
    if (doOVerlap(*(root->i), i))
    {
        cout << "Overlaps with [" << root->i->low << ", " << root->i->high << "]\n";
    }
 
    // If left child of root is present and max of left child is
    // greater than or equal to given interval, then i may
    // overlap with an interval is left subtree
    if (root->left != NULL && root->left->max >= i.low)
        return overlapSearch(root->left, i);
 
    // Else interval can only overlap with right subtree
    return overlapSearch(root->right, i);
}

//A function to find the maximum of three numbers 
int maximum(int a,int b,int c)
{
    if(a>=b&&a>=c)
        return a;
    if(b>=a&&b>=c)
        return b;
    return c;
}

//A function to find the maximum of two numbers
int maximum(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

//A function for updating all the max because after deletion
//they need to be updated 
void updateMax(ITNode*root)
{
    //if its null
    if(root==NULL)
        return ;
    updateMax(root->left);
    updateMax(root->right);
    //if its a extreme leaf
    if(root->left==NULL&&root->right==NULL)
        root->max=root->i->high;
    //if it has no left child 
    else if(root->left==NULL)
    {
        root->max=maximum(root->i->high,root->right->max);
    }
    //if it has no right child 
    else if(root->right==NULL)
    {
        root->max=maximum(root->i->high,root->left->max);
    }
    //if it has two childs
    else
    root->max=maximum(root->i->high,root->right->max,root->left->max);
}

//A function to delete the interval
//using the same method as in BST
ITNode *deleteNode(ITNode *root,Interval x)
{
    //if its null
    if(root==NULL)
        return root;
    //if required interval is in left subtree
    if(x.low<root->i->low)
        root->left=deleteNode(root->left,x);
    //if required interval is in right subtree
    else if(x.low<root->i->low)
        root->right=deleteNode(root->right,x);
    //if key is same as root's key
    else
    {
        if(root->left==NULL)
        {
            ITNode *temp=root->right;
            delete(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            ITNode *temp=root->left;
            delete(root);
            return temp;
        }
        //node with two children
        ITNode *temp=minValueNode(root->right);
        root->i=temp->i;
        //creating an interval similar to temp->i
        //as it is a pointer variable 
        Interval k={temp->i->low,temp->i->high};
        root->right=deleteNode(root->right,k);
    }
    return root;
} 
 
//A function to print the nodes in inorder fashion  
void inorder(ITNode *root)
{
    if (root == NULL) return;
 
    inorder(root->left);
 
    cout << "[" << root->i->low << ", " << root->i->high << "]"
         << " max = " << root->max << endl;
 
    inorder(root->right);
}
 
//A function for deleting an interval and updating
void delete_Interval(ITNode *root,Interval y)
{
    root=deleteNode(root,y);
    updateMax(root);
}

// Main function to execute 
int main()
{
    //no.of nodes to be inserted
    int n;
    cin>>n;
    Interval a[n]; 
    for(int i=0;i<n;i++)
    {
        Interval x;
        cin>>x.low>>x.high;
        a[i]=x;
    }
    ITNode *root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, a[i]);
    cout << "Inorder traversal of constructed Interval Tree is\n";
    inorder(root);
    //queries for seraching
    int q;
    cin>>q;
    while(q--)
    {
        Interval x;
        cin>>x.low>>x.high;
        cout << "\nSearching for interval [" << x.low << "," << x.high << "]\n";
        overlapSearch(root, x);
    }  
    //no.of deletions
    int d;
    cin>>d;
    while(d--)
    {
        Interval y;
        cin>>y.low>>y.high;
        delete_Interval(root,y);
        cout<<"\nInorder traversal after deleting ["<<y.low<<","<<y.high<<"] is\n";
        inorder(root);
    }
    return 0;
}
