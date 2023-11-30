#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//typedef int Elementtype;
////����ѭ������
//typedef struct {
//    MyQueueNode* next;
//    Elementtype data;
//
//}MyQueueNode;
//
//typedef struct {//ֻ��Ҫ��β���ڵ����ά������֪ͷ�ڵ���Ϊβ���ڵ㣩
//    MyQueueNode* tail;
//} MyCircularQueue;
//
////���г�ʼ��
//void InitMyCircularQueue(MyQueueNode* phead, MyCircularQueue* p) //��һ��������ͷ�ڵ�ĵ�ַ���ڶ�������������ά�����нṹ��
//{
//    assert(phead&&p);//�����ܴ�����ָ��
//
//    //��ʼ��ʱֻ��ͷ�ڵ㣬����Ԫ�ض�û��
//    phead->next = phead;
//    p->tail = phead;
// 
//}
//
////�������
////��һ��������ͷ�ڵ㣬�ڶ�����������Ϊ�˸���β�ڵ㣬��������������ֵ
//void InMyCircularQueue(MyQueueNode* phead, MyCircularQueue* p, Elementtype x)
//{
//    assert(phead && p);
//
//    MyQueueNode* newnode = (MyQueueNode*)malloc(sizeof(MyQueueNode));
//    assert(newnode);//��ֹ����ʧ��
//    newnode->data = x;
//
//    p->tail->next = newnode;
//    newnode->next = phead;
//    p->tail = p->tail->next;
//}
//
////������
//void PopMyCircularQueue(MyQueueNode* phead, MyCircularQueue* p)
//{
//    assert(phead && p);
//    assert(phead != p);//���߲���ȣ�Ҳ���Ƕ����д��ڽڵ��ʱ����ܳ�����
//
//    //��Ϊ������һ��Ԫ�غͶ����ж��Ԫ�ص����
//    if (p->tail->next == phead)//ֻ��һ��Ԫ��
//    {
//        p->tail = phead;
//        free(phead->next);
//        phead->next = phead;
//    }
//    else
//    {
//        MyQueueNode* temp = (MyQueueNode*)malloc(sizeof(MyQueueNode));
//        temp = phead->next;
//        phead->next = phead->next->next;
//        free(temp);
//    }
//}




//��������ģ�����
typedef struct {
    int* queue;
    int front;
    int rear;
    int k;//k�Ƕ��������Դ�ſռ���Ŀ
    int tag;//1 ����0����
} MyCircularQueue;

//ֻ�н�����е�ʱ��������������
//Ҳֻ�г����е�ʱ����п��ܳ�����

void InitMyCircularQueue(MyCircularQueue* Qp)
{
    assert(Qp);
    Qp->queue = (int*)malloc(sizeof(int) * Qp->k);

    Qp->front = Qp->rear = 0;
    Qp->tag = 0;
}

void PushMyCircularQueue(MyCircularQueue* Qp,int x)
{
    assert(Qp);
    assert(!Qp->tag);//����ʱ�̲ſ��Խ�����

    Qp->queue[Qp->rear] = x;
    Qp->rear = (Qp->rear + 1) % Qp->k;//rear���ֻ����k-1

    if (Qp->rear == Qp->front)
        Qp->tag = 1;
}

void PopMyCircularQueue(MyCircularQueue* Qp)
{
    assert(Qp);
    assert(Qp->tag == 0 && Qp->rear == Qp->front);//�ն��в����ٳ�������
    Qp->front = (Qp->front + 1) % Qp->k;//���ֻ�ܵ�k-1

    if (Qp->tag == 1)
        Qp->tag = 0;

}

