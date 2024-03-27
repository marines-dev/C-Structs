#include <iostream>
using namespace std;

class TreeNode 
{
public:
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BinaryTree 
{
private:
    TreeNode* rootNode = nullptr;

public:
    void insert(int key) 
    {
        rootNode = insertRecursive(rootNode, key);
    }

    void remove(int key) 
    {
        rootNode = removeRecursive(rootNode, key);
    }

    void inOrder() //중위 순회
    {
        inOrderTraversal(rootNode);
        cout << endl;
    }

private:
    TreeNode* insertRecursive(TreeNode* node, int key)
    {
        if (node == nullptr) //마지막 노드를 찾는다.
        {
            return new TreeNode(key);
        }

        if (key < node->key) //값이 작으면 왼쪽 노드로 이동
        {
            node->left = insertRecursive(node->left, key);
        }
        else if (key > node->key) //값이 크면 오른쪽 노드로 이동
        {
            node->right = insertRecursive(node->right, key);
        }

        return node;
    }

    TreeNode* removeRecursive(TreeNode* node, int key)
    {
        if (node == nullptr)
        {
            return node;
        }

        if (key < node->key) //값이 작으면 왼쪽 노드로 이동
        {
            node->left = removeRecursive(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = removeRecursive(node->right, key); //값이 크면 오른쪽 노드로 이동
        }
        else // 삭제할 노드를 찾으면
        {            
            if (node->left == nullptr)//왼쪽 노드가 없으면
            {
                TreeNode* tempNode = node->right;
                delete node;
                return tempNode;//오른쪽 노드가 루트 노드
            }
            else if (node->right == nullptr) //오른쪽 노드가 없으면
            {
                TreeNode* tempNoed = node->left;
                delete node;
                return tempNoed;//왼쪽 노드가 루트 노드
            }

            // 오른쪽 서브트리에서 최소값을 찾아 현재 노드로 이동하여 값을 교체하고 삭제
            TreeNode* tempNode = findMin(node->right);
            node->key = tempNode->key;
            node->right = removeRecursive(node->right, tempNode->key);
        }
        return node;
    }

    TreeNode* findMin(TreeNode* node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    void inOrderTraversal(TreeNode* node)
    {
        if (node != nullptr) 
        {
            inOrderTraversal(node->left);
            cout << node->key << " ";
            inOrderTraversal(node->right);
        }
    }
};

int main() 
{
    BinaryTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    bst.inOrder();


    bst.remove(20);
    bst.remove(70);
    bst.inOrder();

    return 0;
}
