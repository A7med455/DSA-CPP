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

    string searchMessage(int value)
    {
        node* current = root;
        string message;
        while(current != NULL)
        {
            if(current->element == value)
            {
                message = "Value " + to_string(value) + " found";
                return message;
            }
            if(value < current->element)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        message = "Value " + to_string(value) + " not found";
        return message;
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

    cout << tree.searchMessage(30) << endl;
    cout << tree.searchMessage(14) << endl;
    
    cout<<tree.search(9)<<endl; //True(1) or False(0)
   

    return 0;
}
