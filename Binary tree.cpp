#include"bt.h"
//typedef char BTDataType;
//
//typedef struct BinaryTreeNode
//{
//	BTDataType _data;
//	struct BinaryTreeNode* _left;
//	struct BinaryTreeNode* _right;
//}BTNode;

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
//BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
//{
//
//}
// 二叉树销毁
void BinaryTreeDestory(BTNode** root) {
	BTNode* temp = *root;
	if (*root == NULL)
		return;
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free(temp);

}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root->_left == NULL && root->_right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	//结束条件
	if (root->_data == x)
		return root;
	if (root == NULL)
		return NULL;

	//递归关系
	BTNode* p = BinaryTreeFind(root->_left, x);

	return p==NULL?BinaryTreeFind(root->_right, x):p;//返回一个不是空的指针
}
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	//根 左子树 右子树
	printf("%d", root->_data);

	//递归关系
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);

}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return ;
	
	BinaryTreeInOrder(root->_left);

	printf("%d", root->_data);
	BinaryTreeInOrder(root->_right);

}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;

	
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);

	printf("%d", root->_data);
	
}
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	

}
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);