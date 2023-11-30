#include"bt.h"
//typedef char BTDataType;
//
//typedef struct BinaryTreeNode
//{
//	BTDataType _data;
//	struct BinaryTreeNode* _left;
//	struct BinaryTreeNode* _right;
//}BTNode;

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
//BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
//{
//
//}
// ����������
void BinaryTreeDestory(BTNode** root) {
	BTNode* temp = *root;
	if (*root == NULL)
		return;
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free(temp);

}
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root->_left == NULL && root->_right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	//��������
	if (root->_data == x)
		return root;
	if (root == NULL)
		return NULL;

	//�ݹ��ϵ
	BTNode* p = BinaryTreeFind(root->_left, x);

	return p==NULL?BinaryTreeFind(root->_right, x):p;//����һ�����ǿյ�ָ��
}
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	//�� ������ ������
	printf("%d", root->_data);

	//�ݹ��ϵ
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);

}
// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return ;
	
	BinaryTreeInOrder(root->_left);

	printf("%d", root->_data);
	BinaryTreeInOrder(root->_right);

}
// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;

	
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);

	printf("%d", root->_data);
	
}
// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	

}
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);