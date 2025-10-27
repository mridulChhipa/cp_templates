#include <iostream>
#include <utility> // Include for std::swap

struct Node
{
    int value;
    Node *left;
    Node *right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

Node *merge(Node *node1, Node *node2)
{
    if (node1 == nullptr)
    {
        return node2;
    }
    if (node2 == nullptr)
    {
        return node1;
    }

    if (node1->value > node2->value)
    {
        std::swap(node1, node2);
    }

    node1->right = merge(node1->right, node2);

    return node1;
}

void printPreorder(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    std::cout << node->value << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void printInorder(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    printInorder(node->left);
    std::cout << node->value << " ";
    printInorder(node->right);
}

int main()
{
    Node *t1 = new Node(10);
    t1->left = new Node(20);
    t1->right = new Node(30);
    t1->left->left = new Node(40);

    std::cout << "Tree 1 (Preorder): ";
    printPreorder(t1);
    std::cout << std::endl;

    Node *t2 = new Node(15);
    t2->left = new Node(25);
    t2->right = new Node(35);

    std::cout << "Tree 2 (Preorder): ";
    printPreorder(t2);
    std::cout << std::endl;

    Node *mergedTree = merge(t1, t2);

    std::cout << "--------------------" << std::endl;
    std::cout << "Merged Tree (Preorder): ";
    printPreorder(mergedTree);
    std::cout << std::endl;

    std::cout << "Merged Tree (Inorder):  ";
    printInorder(mergedTree);
    std::cout << std::endl;

    return 0;
}
