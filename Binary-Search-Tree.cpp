/*Write a program to construct a binary search tree (BST) having functions for the following
operations:
Insert an element (no duplicates are allowed),
 Traverse the BST (in-order, pre-order, and post-order),
 Count the number of leaf nodes,
 Count the number of non-leaf (internal) nodes,
 Count the number of nodes
 Calculate the height of the tree
 Calculate the number of full nodes
 Determine the successor of any node
 Delete an existing element, */

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

    void inOrder(BST *root)
    {
        if (root != NULL)
        {
            inOrder(root->left);
            cout << (root->data) << " ";
            inOrder(root->right);
        }
    }

    void preOrder(BST *root)
    {
        if (root != NULL)
        {
            cout << (root->data) << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void postOrder(BST *root)
    {
        if (root != NULL)
        {
            postOrder(root->left);
            postOrder(root->right);
            cout << (root->data) << " ";
        }
    }

    int countLeaf(BST *root)
    {
        if (root == NULL)
            return 0;
        else if ((root->left == NULL) && (root->right == NULL))
            return 1;
        else
            return (countLeaf(root->left) + countLeaf(root->right));
    }

    int countNLeaf(BST *root)
    {
        if ((root == NULL) || ((root->left == NULL) && (root->right == NULL)))
            return 0;
        else
            return (countNLeaf(root->left) + countNLeaf(root->right) + 1);
    }

    int count(BST *root)
    {
        if (root == NULL)
            return 0;
        else
            return (count(root->left) + count(root->right) + 1);
    }

    int countFull(BST *root) 
    {
        if (root == NULL)
        {
            return 0;
        }
        if(root->left==NULL && root->right==NULL)
        {
            return 0;
        }
        int l=countFull(root->left);
        int r=countFull(root->right);
        if(root->left==NULL && root->right==NULL)
        {
            return (l+r);
        }
            return (1+l+r);
    }

    int height(BST *root)
    {
        if (root == NULL)
            return -1;
        else
            return (1 + max(height(root->left), height(root->right)));
    }

    BST *search(BST *root, int item)
    {
        while (root != NULL)
        {
            if (root->data == item)
            {
                return root;
            }
            else if (root->data < item)
            {
                root = root->right;
            }
            else
                root = root->left;
        }
        return NULL;
    }

    BST *succ(BST *curr)
    {

        curr = curr->right;
        while (curr != NULL && curr->left != NULL)
        {
            curr = curr->left;
        }
        return curr;
    }

    BST *deletenode(BST *root, int k)
    {
        if (root == NULL)
        {
            cout << "TREE IS EMPTY\n";
            return root;
        }
        if (root->data > k)
            root->left = deletenode(root->left, k);
        else if (root->data < k)
        {
            root->right = deletenode(root->right, k);
        }
        else if (root->left == NULL)
        {
            BST *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            BST *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            BST *SuccG = succ(root);
            root->data = SuccG->data;
            root->right = deletenode(root->right, SuccG->data);
        }
        return root;
    }
};

int main(void)
{
    BST tree(0);
    BST *root, *ptr, *ptr2;
    int ch, x, arr[100], del, l;
    do
    {
        cout << "*************MENU****************" << endl;
        cout << "| PRESS 0: TO INSERT            |\n| PRESS 1: TO INORDER           |\n| PRESS 2: TO PREORDER          |\n| PRESS 3: TO POSTORDER         |\n| PRESS 4: TO DELETE            |\n| PRESS 5: TO COUNT             |\n| PRESS 6: TO COUNT LEAF        |\n| PRESS 7: TO COUNT NON LEAF    |\n| PRESS 8: TO COUNT FULL NODES  |\n| PRESS 9: TO HEIGHT            |\n| PRESS 10: TO SUCCESSOR        |\n| PRESS 11: TO EXIT             |\n";
        cout << "*********************************" << endl;
        cout << "Enter: ";
        cin >> ch;
        switch (ch)
        {
        case 0:
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
            break;
        case 1:
            cout << "YOUR INORDER TRAVERSAL IS:\n";
            tree.inOrder(root);
            cout << endl;
            break;
        case 2:
            cout << "YOUR PREORDER TRAVERSAL IS:\n";
            tree.preOrder(root);
            cout << endl;
            break;
        case 3:
            cout << "YOUR POSTODER TRAVERSAL IS:\n";
            tree.postOrder(root);
            cout << endl;
            break;
        case 4:
            cout << "ENTER THE ELEMENT THAT YOU WANT TO DELETE\n";
            cin >> del;
            tree.deletenode(root, del);
            break;
        case 5:
            cout << "TOTAL NUMBER OF NODES IN YOUR BST IS==>" << tree.count(root) << "\n";
            break;
        case 6:
            cout << "TOTAL NUMBER OF LEAF NODES IN YOUR BST IS==>" << tree.countLeaf(root) << "\n";
            break;
        case 7:
            cout << "TOTAL NUMBER OF NONLEAF NODES IN YOUR BST IS==>" << tree.countNLeaf(root) << "\n";
            break;
        case 8:
            cout << "TOTAL NUMBER OF FULL NODES IN YOUR BST IS==>" << tree.countFull(root) << "\n";
            break;
        case 9:
            cout << "HEIGHT OF YOUR BST IS==>" << tree.height(root) << "\n";
            break;
        case 10:
            cout << "ENTER THE VALUE OF ELEMENT\n";
            cin >> l;
            ptr = tree.search(root, l);
            if (ptr != NULL)
            {
                ptr2 = tree.succ(ptr);
                cout << "SUCCESOR OF " << l << " IS " << ptr2->data << endl;
            }
            else
                cout << "DATA IS NOT PRESENT IN THE BST\n";
        }
    } while (ch != 11);
}
