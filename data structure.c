#include"datastructure.h"

//��������ʽ
void CreatPoly(Polylist* hpp) {
	printf("��ֱ��������ʽ��ϵ����ָ��(ע������Ҫ��0 0��ֹ���룩��\n");
	*hpp = (Polylist)malloc(sizeof(Polynode));
	assert(*hpp);

	
	Polylist cur = *hpp;
	Polylist tail = NULL;//ʼ����cur��ǰһ��
	scanf("%f %d", &cur->coef,&cur->expn);
	//��cur�ĳ�����Ϊ0������������������ѭ��
	while (cur->coef != 0)
	{
		tail = cur;
		cur->next = (Polylist)malloc(sizeof(Polynode));
		cur = cur->next;
		assert(cur);
		scanf("%f %d", &cur->coef, &cur->expn);
	}

	//���ѹ����û��Ԫ��
	if (cur == *hpp)
	{
		free(*hpp);
		*hpp = NULL;
		return;
	}

	//�����һ���ΪNULL
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
	while (cur)//��cur���ǿ�ָ���ʱ����д�ӡ
	{
		if (cur == hp)//��ӡ��һ��Ԫ��
		{
			if (cur->expn == 0)
				printf("%.2f", cur->coef);
			else if (cur->expn == 1)
				printf("%.2fx", cur->coef);
			else
				printf("%.2fx^%d", cur->coef, cur->expn);
		}
		else//���ǵ�һ��Ԫ�� 
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


//�ҵ���Ӧ�Ķ���ʽ
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




//����ʽ���
Polylist PolyAdd(Polylist hp1, Polylist hp2)
{
	//�пյ����
	if (hp1 == NULL && hp2 == NULL)
		return NULL;
	if (hp1 == NULL && hp2 != NULL)
		return hp2;
	if (hp2 == NULL && hp1 != NULL)
		return hp1;

	//���潫hp2����hp1��
	Polylist tail = hp1;
	while (tail->next != NULL)
		tail = tail->next;/*�ҵ���tail����β��*/
	while (hp2)
	{
		if (Polyfind(hp1, hp2->expn) == NULL)//û�ҵ���ֱ��β��
		{
			tail->next = hp2;
			hp2 = hp2->next;
			tail = tail->next;
			tail->next = NULL;
		}
		else//�ҵ��ˣ���Ҫ����ȥ������tail����
		{
			Polylist temp = Polyfind(hp1, hp2->expn);
			temp->coef = temp->coef + hp2->coef;
			temp= hp2;
			hp2 = hp2->next;
			free(temp);
		}
	}

	//���ڶ�hp1����ȥ��,ʹ��˫ָ��
	Polylist slow = hp1;
	Polylist fast = hp1->next;
	while (fast)
	{
		//��hp1�ڵ�֮ǰѰ�����л��غϵ�Ԫ��
		Polylist find = hp1;
		while (find != slow->next && find->expn == fast->expn)//�ڳ��˱���˳������ҵ���Ԫ�ص�����»��ѭ��
		{
				find = find->next;
		}

		if (find->expn != fast->expn)//û�ҵ�
		{
			slow->next = fast;
			slow = slow->next;
			fast = fast->next;
			slow->next = NULL;
		}
		else//�ҵ���,�ѱ��ҵ��ļӵ�ǰ��ȥ��ͬʱ�ͷ��ⲿ�ֿռ�
		{
			find->coef = find->coef + fast->coef;
			Polylist temp = fast;
			fast = fast->next;
			free(temp);
		}
	}
	slow->next = NULL;



		//���ڽ�����ܳ���0������
	if (hp1->coef == 0)//���׳���0
	{
		Polylist temp = hp1;
		hp1 = hp1->next;
		free(temp);
	}

	if (hp1 != NULL)
	{
		Polylist cur = hp1->next;
		tail = hp1;//tail��Ϊcur��ǰһ��ָ��
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
	//��������ʽ
	Polylist ha;
	Polylist hb;
	CreatPoly(&ha);
	CreatPoly(&hb);

	printf("ha����ʽ��");
	PolyPrint(ha);
	printf("\n");
	printf("hb����ʽ��");
	PolyPrint(hb);
	printf("\n");
	printf("��Ӻ�");
	Polylist hc = PolyAdd(ha, hb);
	printf("\n");

	PolyPrint(hc);

	return 0;

}


//��ֱ��������ʽ��ϵ����ָ����
//1 0
//2 4
//2 - 3
//3 2
//4 1
//0 4
//��ֱ��������ʽ��ϵ����ָ����
//- 2 3
//- 3 2
//- 1 0
//0 0
	//���ڽ�����ܳ���0������ 
	//if (hp1->coef == 0)//���׳���0 
	//{
	//	Polylist temp = hp1;
	//	hp1 = hp1->next;
	//	free(temp);
	//	tail = NULL; //���������0����tailҲӦ����ΪNULL
	//}
	//if (hp1 != NULL)
	//{
	//	Polylist cur = hp1->next;
	//	if (cur == NULL) //���curΪ�գ���tailӦ�ñ���Ϊhp1
	//	{
	//		tail = hp1;
	//	}
	//	else
	//	{
	//		tail = cur; //����tailӦ��ָ��cur��ǰһ���ڵ�
	//	}
	//	while (cur)
	//	{
	//		if (cur->coef == 0)
	//		{
	//			Polylist temp = cur;
	//			cur = cur->next;
	//			free(temp);
	//			//���cur��ǰһ���ڵ��Ѿ���ɾ������ôtailӦ��ǰ��һλ
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
