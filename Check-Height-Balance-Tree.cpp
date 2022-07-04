//8. Write a program to Check whether a given binary tree is a height balanced binary tree or not
#include <iostream>
using namespace std;

class BST
{
public:
    int data;
    BST *left;
    BST *right;
    BST(int key)
    {
        data = key;
        left = NULL;
        right = NULL;
    }

    BST *insert(BST *root, int x)
    {
        BST *temp = new BST(x);
        BST *parent;
        BST *ptr;
        if (root == NULL)
        {
            return temp;
        }
        else
        {
            parent = NULL;
            ptr = root;
            while (ptr != NULL)
            {
                parent = ptr;
                if (x < ptr->data)
                    ptr = ptr->left;
                else
                    ptr = ptr->right;
            }
            if (x < parent->data)
                parent->left = temp;
            else
                parent->right = temp;
            return root;
        }
    }
       
  
    int balancedTree(BST *root)
    {
        int l,r;
        if(root==NULL) return 0;
        l=balancedTree(root->left);
        if(l==-1) return -1;
        
        r=balancedTree(root->right);
        if(r==-1) return -1;
     if(abs(l-r)>1) return -1;
     else return (max(l,r)+1);
     
     
    }
};
int main()
{
        BST tree(0);
    BST *root;
    int ch, x ,l;
      cout << "ENTER THE NUMBER OF VALUE THAT YOU WANT TO INSERT\n";
            cin >> x;
            cout << "ENTER ELEMENTS==>\n";
            for (int i = 0; i < x; i++)
            {
                int temp;
                cin >> temp;
                root = tree.insert(root, temp);
            }
            cout << "BST HAS BEEN CREATED\n";
           
    
    if(tree.balancedTree(root)==-1)
    {
        cout<<"TREE IS NOT BALANCED";
    }
    else
    cout<<"TREE IS BALANCED";
    
};
