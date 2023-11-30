#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//typedef int Elementtype;
////单向循环链表
//typedef struct {
//    MyQueueNode* next;
//    Elementtype data;
//
//}MyQueueNode;
//
//typedef struct {//只需要用尾部节点进行维护（已知头节点作为尾部节点）
//    MyQueueNode* tail;
//} MyCircularQueue;
//
////队列初始化
//void InitMyCircularQueue(MyQueueNode* phead, MyCircularQueue* p) //第一个参数是头节点的地址，第二个参数是用于维护队列结构体
//{
//    assert(phead&&p);//都不能传进空指针
//
//    //初始化时只有头节点，其他元素都没有
//    phead->next = phead;
//    p->tail = phead;
// 
//}
//
////进入队列
////第一个参数是头节点，第二个参数是是为了告诉尾节点，第三个参数是数值
//void InMyCircularQueue(MyQueueNode* phead, MyCircularQueue* p, Elementtype x)
//{
//    assert(phead && p);
//
//    MyQueueNode* newnode = (MyQueueNode*)malloc(sizeof(MyQueueNode));
//    assert(newnode);//防止开辟失败
//    newnode->data = x;
//
//    p->tail->next = newnode;
//    newnode->next = phead;
//    p->tail = p->tail->next;
//}
//
////出队列
//void PopMyCircularQueue(MyQueueNode* phead, MyCircularQueue* p)
//{
//    assert(phead && p);
//    assert(phead != p);//二者不相等，也就是队列中存在节点的时候才能出队列
//
//    //分为队伍有一个元素和队伍有多个元素的情况
//    if (p->tail->next == phead)//只有一个元素
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




//用数组来模拟队列
typedef struct {
    int* queue;
    int front;
    int rear;
    int k;//k是队列最多可以存放空间数目
    int tag;//1 满；0不满
} MyCircularQueue;

//只有进入队列的时候才与可能满队列
//也只有出队列的时候才有可能出队列

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
    assert(!Qp->tag);//不满时刻才可以进队列

    Qp->queue[Qp->rear] = x;
    Qp->rear = (Qp->rear + 1) % Qp->k;//rear最大只能是k-1

    if (Qp->rear == Qp->front)
        Qp->tag = 1;
}

void PopMyCircularQueue(MyCircularQueue* Qp)
{
    assert(Qp);
    assert(Qp->tag == 0 && Qp->rear == Qp->front);//空队列不能再出队列了
    Qp->front = (Qp->front + 1) % Qp->k;//最大只能到k-1

    if (Qp->tag == 1)
        Qp->tag = 0;

}

