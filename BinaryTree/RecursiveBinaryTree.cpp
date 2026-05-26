#include<iostream>
using namespace std;

struct node
{
    int element;
    node* left;
    node* right;
};

class BinaryTree
{
private:
    node* root;
    int counter;

    // private recursive insert
    node* insert(node* current, int element)
    {
        if(current == NULL)
        {
            node* newNode = new node;
            newNode->element = element;
            newNode->left = NULL;
            newNode->right = NULL;
            counter++;
            return newNode;
        }
        if(element < current->element)
            current->left = insert(current->left, element);
        else if(element > current->element)
            current->right = insert(current->right, element);
        // if equal, duplicate, do nothing
        return current;
    }

    // private recursive search
    bool search(node* current, int value)
    {
        if(current == NULL)
            return false;
        if(current->element == value)
            return true;
        if(value < current->element)
            return search(current->left, value);
        else
            return search(current->right, value);
    }

    // private recursive inorder
    void inorder(node* current)
    {
        if(current == NULL)
            return;
        inorder(current->left);
        cout << current->element << endl;
        inorder(current->right);
    }

public:
    BinaryTree()
    {
        root = NULL;
        counter = 0;
    }

    // public insert
    void insert(int element)
    {
        root = insert(root, element);
    }

    // public search
    bool search(int value)
    {
        return search(root, value);
    }

    // public inorder
    void inorder()
    {
        inorder(root);
    }

    int size()
    {
        return counter;
    }

    bool isEmpty()
    {
        return counter == 0;
    }
};

int main()
{
    BinaryTree tree;

    tree.insert(8);
    tree.insert(3);
    tree.insert(10);
    tree.insert(1);
    tree.insert(6);
    tree.insert(14);
    tree.insert(4);
    tree.insert(7);
    tree.insert(13);
    tree.insert(3); // duplicate

    cout << "Inorder traversal:" << endl;
    tree.inorder();

    cout << "Size: " << tree.size() << endl;

    if(tree.search(30))
        cout << "30 found" << endl;
    else
        cout << "30 not found" << endl;

    if(tree.search(14))
        cout << "14 found" << endl;
    else
        cout << "14 not found" << endl;

    return 0;
}