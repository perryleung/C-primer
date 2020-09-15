#include "Tree.h"

TreeNode *CreateTreeNode(int value)
{
    TreeNode *pNode = new TreeNode();
    pNode->value = value;
    return pNode;
}

void ConnectTreeNodes(TreeNode *pParent, TreeNode *pChild)
{
    if (pParent != nullptr)
        pParent->child.push_back(pChild);
    else
        return;
}

void PrintTreeNode(const TreeNode *pNode);

void PrintTree(const TreeNode *pRoot);
void DestroyTree(TreeNode *pRoot);