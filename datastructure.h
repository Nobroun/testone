#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int ElementType;
typedef struct Polynode
{	//coef为系数，expn为指数
	float coef;
	int expn;
	struct Polynode* next;
}Polynode, * Polylist;

//创建一个多项式
void CreatPoly(Polylist* hpp);

//多项式相加
Polylist PolyAdd(Polylist* hp1, Polylist* hp2);

//打印多项式
void PolyPrint(Polylist hp);

//找到对应的多项式进行去重
Polylist Polyfind(Polylist hp,int t);

//打印代码重复性太高
void Prints(float f, int i);
