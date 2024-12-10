#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
} *newnode, *ptr, *parent;

class binaryst
{
public:
    node *root, *ptr;
    binaryst()
    {
        root = NULL;
    }

    void createbst(int);

    void inorder(node *);
    void preorder(node *);
    void postorder(node *);

    void deletenode(int);
    void casea(node *, node *);
    void caseb();

    void search(int);
    int depth(node *);
    void leafnode(node *);
    void mirror(node *);
};

void binaryst::createbst(int val)
{
    newnode = new node;
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;

    if (root == NULL)
    {
        root = newnode;
    }
    else
    {
        ptr = root;
        while (ptr != nullptr)
        {
            parent = ptr;
            if (val > ptr->data)
            {
                ptr = ptr->right;
            }
            else
            {
                ptr = ptr->left;
            }
        }
        if (val > parent->data)
        {
            parent->right = newnode;
        }
        else
        {
            parent->left = newnode;
        }
    }
}

void binaryst ::inorder(node *ptr)
{
    if (ptr != nullptr)
    {
        inorder(ptr->left);
        cout << ptr->data << " ";
        inorder(ptr->right);
    }
}
void binaryst ::preorder(node *ptr)
{
    if (ptr != nullptr)
    {

        cout << ptr->data << " ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
void binaryst ::postorder(node *ptr)
{
    if (ptr != nullptr)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->data << " ";
    }
}

// casea function

void binaryst::casea(node *loc, node *parent)
{
    node *child;
    if (loc->left == nullptr && loc->right == nullptr)
    {
        child = nullptr;
    }
    else if (loc->left != nullptr)
    {
        child = loc->left;
    }
    else
    {
        child = loc->right;
    }
    if (parent != nullptr)
    {
        if (loc == parent->left)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
        }
    }
    else
    {
        root = child;
    }
}

// caseb function to delete the node with two child

void binaryst::caseb()
{
    node *suc, *parsuc, *ptr, *save, *loc, *parent;
    ptr = loc->right;
    save = loc;
    while (ptr->left != nullptr)
    {
        save = ptr;
        ptr = ptr->left;
    }
    suc = ptr;
    parsuc = save;
    casea(suc, parsuc);
    if (parent != nullptr)
    {
        if (loc == parent->left)
        {
            parent->left = suc;
        }
        else
        {
            parent->right = suc;
        }
    }
    else
    {
        root = suc;
    }
    suc->left = loc->left;
    suc->right = loc->right;
}

// main function og delete

void binaryst::deletenode(int x)
{
    node *loc, *parent;
    loc = root;
    while (loc != nullptr && x != loc->data)
    {
        parent = loc;
        if (x < parent->data)
        {
            loc = loc->left;
        }
        else
        {
            loc = loc->right;
        }
    }
    if (loc == nullptr)
    {
        cout << "\n"
             << x << "not found ";
    }
    if (loc->right != nullptr && loc->left != nullptr)
    {
        caseb();
    }
    else
    {
        casea(loc, parent);
    }
}

// function to search in tree

void binaryst::search(int x)
{
    ptr = root;
    if (ptr == nullptr)
    {
        cout << " element not found : ";
    }
    while (ptr != nullptr)
    {
        if (ptr->data == x)
        {
            cout << x << " is found ";
            break;
        }
        else if (x < ptr->data)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }
    if (ptr == nullptr)
    {
        cout << x << " not found ";
    }
}

//  find the depth of the tree

int binaryst::depth(node *ptr)
{
    if (ptr == nullptr)
    {
        return 0;
    }
    int lh = depth(ptr->left);
    int rh = depth(ptr->right);
    return (max(lh, rh) + 1);
}

// find the leafnode of the tree
void binaryst::leafnode(node *ptr)
{
    if (ptr == nullptr)
    {
        return;
    }
    if (ptr->left == nullptr && ptr->right == nullptr)
    {
        cout << ptr->data<<" ";
        return;
    }
    if (ptr->left)
    {
        leafnode(ptr->left);
    }
    if (ptr->right)
    {
        leafnode(ptr->right);
    }
}

// find then mirror image of the tree

void binaryst::mirror(node *ptr)
{
    node *temp;
    if (ptr != nullptr)
    {
        temp = ptr->left;
        ptr->left = ptr->right;
        ptr->right = temp;

        mirror(ptr->left);
        mirror(ptr->right);
    }
    else
    {
        return;
    }
}

int main()
{
    int ch, x, h;
    binaryst b;

    do
    {
        cout << "\n----------operations----------";
        cout << "\n 1.Insertion in binart tree";
        cout << "\n 2.Traversals in binary tree";
        cout << "\n 3.Delete in binary tree";
        cout << "\n 4.Search in binary tree";
        cout << "\n 5.Depth of binary tree";
        cout << "\n 6.Leafnodes in  in binartytree";
        cout << "\n 7.Mirror image of binary tree";
        cout << "\n 8.Exit";
        cout << "\n Enter your choice :\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nEnter data to insert\n";
            cin >> x;
            b.createbst(x);
            break;

        case 2:
            cout << "\nInorder :";
            b.inorder(b.root);
            cout << "\nPreorder :";
            b.preorder(b.root);
            cout << "\nPostorder :";
            b.postorder(b.root);
            break;

        case 3:
            cout << "\n Enter element to delete\n";
            cin >> x;
            b.deletenode(x);
            break;
        case 4:
            cout << "\n Enter element to search\n";
            cin >> x;
            b.search(x);
            break;

        case 5:
            x = b.depth(b.root);
            cout << "Depth od tree is :" << x;
            break;

        case 6:

            b.leafnode(b.root);
            cout<<" ";
            break;
        case 7:
            b.mirror(b.root);
            cout << "Inorder display of mirror tree : ";
            b.inorder(b.root);
            break;
        case 8:
            break;
        }
    } while (ch != 8);

    return 0;
}
