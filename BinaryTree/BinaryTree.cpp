#include<iostream>
#include<stack>
using  namespace std;

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

public:
    BinaryTree()
    {
        root = NULL;
        counter = 0;
    }

    void insert(int element)
    {
        //create a new node
        node* newNode = new node;
        newNode->element = element;
        newNode->left = NULL;
        newNode->right = NULL;
        
        //check if tree is empty then newNode will be the root
        if(root == NULL)
        {
            root = newNode;
            counter++;
            return;
        }

        node* current = root;
        node* parent = NULL;
        while(current != NULL)
        {
            parent = current;
            if(element<current->element)
            {
                current=current->left;
            }
            else if(element>current->element)
            {
                current=current->right;
            }
            else//means duplicated so remove it
            {
                delete newNode;
                return;
            }
        }
        //after we got the place of the root node we can now insert the newnode
        if(element<parent->element)
        {
            parent->left = newNode;
        }
        else
        {
            parent->right = newNode;
        }
        counter++;
    }

    bool search(int value)
    {
        node* current = root;
        while(current != NULL)
        {
            if(current->element == value)
            {
                return true;
            }
            if(value<current->element)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        //value was not found
        return false;
    }

    //prints all tree Values in ascending order
    void inorder() 
    {
        stack<node*> nodes;
        node* current = root;

        while(current != NULL || !nodes.empty())
        {
            while(current != NULL)
            {
                nodes.push(current);
                current = current->left;
            }

            current = nodes.top();
            nodes.pop();
            cout<<current->element<<endl;
            current = current->right;
        }
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
    tree.insert(3);//try to insert duplicated value

    cout << "Inorder traversal:" << endl;
    tree.inorder();

    cout << "Size: " << tree.size() << endl;

    if(tree.search(30))
    {
        cout << "30 found" << endl;
    }
    else {
        cout << "30 not found" << endl;
    }

    if(tree.search(14))
    {
        cout << "14 found" << endl;
    }
    else {
        cout << "14 not found" << endl;
    }

    return 0;
}
