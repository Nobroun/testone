#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int ElementType;
typedef struct Polynode
{	//coefΪϵ����expnΪָ��
	float coef;
	int expn;
	struct Polynode* next;
}Polynode, * Polylist;

//����һ������ʽ
void CreatPoly(Polylist* hpp);

//����ʽ���
Polylist PolyAdd(Polylist* hp1, Polylist* hp2);

//��ӡ����ʽ
void PolyPrint(Polylist hp);

//�ҵ���Ӧ�Ķ���ʽ����ȥ��
Polylist Polyfind(Polylist hp,int t);

//��ӡ�����ظ���̫��
void Prints(float f, int i);
