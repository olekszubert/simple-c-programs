#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
Create a tree like this:
            4
    2               6
1       3       5       7


Print the tree like this:
1, 2, 3, 4, 5, 6, 7
*/

typedef struct Node
{
    uint32_t value;
    struct Node* left;
    struct Node* right;
}BinaryTree_t;

static BinaryTree_t* newNode(uint32_t val) 
{
    BinaryTree_t* tmp = (BinaryTree_t*)malloc(sizeof(BinaryTree_t));
    if (!tmp) return NULL;

    tmp->value = val;
    tmp->left = tmp->right = NULL;
    return tmp;
}

BinaryTree_t* binaryTreeInsert(BinaryTree_t* node, uint32_t val)
{
    //If the node is empty, return a new node
    if (node == NULL) return newNode(val);

    //Compare for same values, give error message on duplicates
    if (val == node->value) {
        printf("Error: Invalid value: Binary tree must have unique values: Insert skipped\n");
        return node;
    }

    //Lesser - go left, greater - go right
    if (val < node->value)
        node->left = binaryTreeInsert(node->left, val);
    else
        node->right = binaryTreeInsert(node->right, val);

    return node;
}

#define printTreeWithDecorator(x) do{ printf("\nBinary Tree: ");printTree(x);printf("\n"); }while(0)
void printTree(BinaryTree_t* node)
{
    //Return if empty node reached
    if (node != NULL)
    {
        //Go left recursively
        printTree(node->left);

        //Print value
        printf("%d, ", node->value);

        //Go right recursively
        printTree(node->right);
    }
}

#define printTreeReversedWithDecorator(x) do{ printf("\nBinary Tree Reversed: ");printTreeReversed(x);printf("\n"); }while(0)
void printTreeReversed(BinaryTree_t* node)
{
    //Return if empty node reached
    if (node != NULL)
    {
        //Go right recursively
        printTreeReversed(node->right);

        //Print value
        printf("%d, ", node->value);

        //Go left recursively
        printTreeReversed(node->left);
    }
}


//Find the left-most value of a binary tree (minimum value)
static BinaryTree_t* leftMostNode(BinaryTree_t* node) {
    BinaryTree_t* currNode = node;

    //Find the left-most node
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;

    return currNode;
}

//Deleting a single node
BinaryTree_t* deleteNode(BinaryTree_t* node, uint32_t val)
{
    //If the node is empty, return
    if (node == NULL) return node;

    //Find the node to be deleted
    if (val < node->value)
        node->left = deleteNode(node->left, val);
    else if (val > node->value)
        node->right = deleteNode(node->right, val);

    //Node found
    else {
        //If the node has 1 or 0 subnodes
        if (node->left == NULL) {
            BinaryTree_t* tmp = node->right;
            free(node);
            return tmp;
        }
        else if (node->right == NULL) {
            BinaryTree_t* tmp = node->left;
            free(node);
            return tmp;
        }

        //If the node has 2 subnodes
        //Find the node closest in value to current node 
        //(could be either right-most of node->left or left-most of node->right
        BinaryTree_t* tmp = leftMostNode(node->right);

        //Place the found value in the position of the node to be deleted
        node->value = tmp->value;

        //Delete the value we just used to replace the deleted value
        //If it is the only value in that node, returns NULL
        node->right = deleteNode(node->right, tmp->value);
    }
    return node;
}

//Delete tree, free memory
void deleteTree(BinaryTree_t* node)
{
    if (node != NULL)
    {
        deleteTree(node->left);
        deleteTree(node->right);

        free(node);
        node = NULL;
    }
}

BinaryTree_t* createExampleTree()
{
    BinaryTree_t* node = NULL;
    node = binaryTreeInsert(node, 4); //first value according to the task
    node = binaryTreeInsert(node, 6);
    node = binaryTreeInsert(node, 5);
    node = binaryTreeInsert(node, 1);
    node = binaryTreeInsert(node, 3);
    node = binaryTreeInsert(node, 2);
    node = binaryTreeInsert(node, 7);

    //Two invalid cases
    node = binaryTreeInsert(node, 4);
    node = binaryTreeInsert(node, 2);
    return node;
}

int main(void)
{
    BinaryTree_t* myTree = createExampleTree();
    printTreeWithDecorator(myTree);

    deleteNode(myTree, 4);
    printTreeWithDecorator(myTree);

    deleteNode(myTree, 2);
    printTreeWithDecorator(myTree);

    deleteNode(myTree, 9);
    printTreeWithDecorator(myTree);
    printTreeReversedWithDecorator(myTree);

    deleteTree(myTree);
    myTree = NULL;

    return 0;
}
