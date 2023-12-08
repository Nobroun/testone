#include"datastructure.h"

//创建多项式
void CreatPoly(Polylist* hpp) {
	printf("请分别输入多项式的系数和指数(注意你需要以0 0终止输入）：\n");
	*hpp = (Polylist)malloc(sizeof(Polynode));
	assert(*hpp);

	
	Polylist cur = *hpp;
	Polylist tail = NULL;//始终是cur的前一项
	scanf("%f %d", &cur->coef,&cur->expn);
	//当cur的常数项为0，不满足条件，结束循环
	while (cur->coef != 0)
	{
		tail = cur;
		cur->next = (Polylist)malloc(sizeof(Polynode));
		cur = cur->next;
		assert(cur);
		scanf("%f %d", &cur->coef, &cur->expn);
	}

	//如果压根就没有元素
	if (cur == *hpp)
	{
		free(*hpp);
		*hpp = NULL;
		return;
	}

	//把最后一项变为NULL
	free(cur);
	tail->next = NULL;

}

void PolyPrint(Polylist hp)
{
	if (hp == NULL)
	{
		printf("0");
		return;
	}
	Polylist cur = hp;
	while (cur)//当cur不是空指针的时候进行打印
	{
		if (cur == hp)//打印第一个元素
		{
			if (cur->expn == 0)
				printf("%.2f", cur->coef);
			else if (cur->expn == 1)
				printf("%.2fx", cur->coef);
			else
				printf("%.2fx^%d", cur->coef, cur->expn);
		}
		else//不是第一个元素 
		{
			Prints(cur->coef, cur->expn);
		}
		cur = cur->next;
	}
}

void Prints(float f, int i)
{
	if (fabs(f)<0.0001)//f==0
		printf("+0");
	else if (f > 0)
	{
		if (i == 0)
			printf("%.2f", f);
		else if (i == 1)
			printf("+%.2fx", f);
		else
			printf("+%.2fx^%d", f, i);
	}
	else 
	{
		if (i == 0)
			printf("%.2f", f);
		else if (i == 1)
			printf("%.2fx", f);
		else
			printf("%.2fx^%d", f, i);
	}
}


//找到对应的多项式
Polylist Polyfind(Polylist hp, int t)
{
	
	while (hp) 
	{
		if (hp->expn == t)
			break;
		hp = hp->next;
	}
	return hp;
}




//多项式相加
Polylist PolyAdd(Polylist hp1, Polylist hp2)
{
	//有空的情况
	if (hp1 == NULL && hp2 == NULL)
		return NULL;
	if (hp1 == NULL && hp2 != NULL)
		return hp2;
	if (hp2 == NULL && hp1 != NULL)
		return hp1;

	//下面将hp2加在hp1上
	Polylist tail = hp1;
	while (tail->next != NULL)
		tail = tail->next;/*找到的tail用于尾插*/
	while (hp2)
	{
		if (Polyfind(hp1, hp2->expn) == NULL)//没找到，直接尾插
		{
			tail->next = hp2;
			hp2 = hp2->next;
			tail = tail->next;
			tail->next = NULL;
		}
		else//找到了，就要加上去，但是tail不变
		{
			Polylist temp = Polyfind(hp1, hp2->expn);
			temp->coef = temp->coef + hp2->coef;
			temp= hp2;
			hp2 = hp2->next;
			free(temp);
		}
	}

	//现在对hp1进行去重,使用双指针
	Polylist slow = hp1;
	Polylist fast = hp1->next;
	while (fast)
	{
		//在hp1节点之前寻找是有会重合的元素
		Polylist find = hp1;
		while (find != slow->next && find->expn == fast->expn)//在出了遍历顺序或者找到了元素的情况下会出循环
		{
				find = find->next;
		}

		if (find->expn != fast->expn)//没找到
		{
			slow->next = fast;
			slow = slow->next;
			fast = fast->next;
			slow->next = NULL;
		}
		else//找到了,把被找到的加到前面去，同时释放这部分空间
		{
			find->coef = find->coef + fast->coef;
			Polylist temp = fast;
			fast = fast->next;
			free(temp);
		}
	}
	slow->next = NULL;



		//现在解决可能出现0的问题
	if (hp1->coef == 0)//队首出现0
	{
		Polylist temp = hp1;
		hp1 = hp1->next;
		free(temp);
	}

	if (hp1 != NULL)
	{
		Polylist cur = hp1->next;
		tail = hp1;//tail作为cur的前一个指针
		while (cur)
		{
			if (cur->coef == 0)
			{
				Polylist temp = cur;
				cur = cur->next;
				tail->next = cur;
				free(temp);
			}
			else
			{
				cur = cur->next;
				tail = tail->next;
			}
		}
	}


	return hp1;
}


int main()
{
	//创建多项式
	Polylist ha;
	Polylist hb;
	CreatPoly(&ha);
	CreatPoly(&hb);

	printf("ha多项式：");
	PolyPrint(ha);
	printf("\n");
	printf("hb多项式：");
	PolyPrint(hb);
	printf("\n");
	printf("相加后：");
	Polylist hc = PolyAdd(ha, hb);
	printf("\n");

	PolyPrint(hc);

	return 0;

}


//请分别输入多项式的系数和指数：
//1 0
//2 4
//2 - 3
//3 2
//4 1
//0 4
//请分别输入多项式的系数和指数：
//- 2 3
//- 3 2
//- 1 0
//0 0
	//现在解决可能出现0的问题 
	//if (hp1->coef == 0)//队首出现0 
	//{
	//	Polylist temp = hp1;
	//	hp1 = hp1->next;
	//	free(temp);
	//	tail = NULL; //如果队首是0，则tail也应该置为NULL
	//}
	//if (hp1 != NULL)
	//{
	//	Polylist cur = hp1->next;
	//	if (cur == NULL) //如果cur为空，则tail应该保持为hp1
	//	{
	//		tail = hp1;
	//	}
	//	else
	//	{
	//		tail = cur; //否则，tail应该指向cur的前一个节点
	//	}
	//	while (cur)
	//	{
	//		if (cur->coef == 0)
	//		{
	//			Polylist temp = cur;
	//			cur = cur->next;
	//			free(temp);
	//			//如果cur的前一个节点已经被删除，那么tail应该前进一位
	//			if (tail->next == cur)
	//			{
	//				tail = tail->next;
	//			}
	//		}
	//		else
	//		{
	//			cur = cur->next;
	//			tail = tail->next;
	//		}
	//	}
	//}
