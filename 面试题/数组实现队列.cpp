#include <iostream>
using namespace std;

#define MAXLINE 20

//用数组实现队列
struct Queue1
{
    int front1;
    int rear1;
    int icount;
    int maxsize;
    int data[MAXLINE];
};
void QueueCreate(Queue1 *que)
{
    que->front1 = 0;
    que->rear1 = 0;
    que->icount = 0;
    que->maxsize = MAXLINE-1;
    for(int i=0;i <= que->maxsize;i++)
        que->data[i] = 0;
}
bool isempty(Queue1 que)
{
    if(que.front1 == que.rear1)
        return true;
    else
        return false;
}
bool isfull(Queue1 que)
{
    if((que.rear1 + 1)%MAXLINE == que.front1)
        return true;
    else
        return false;
}
void inQueue(Queue1 *que,int data)
{
    if(isfull(*que))
        return;
    que->data[que->rear1] = data;
    que->rear1 = (que->rear1 + 1) % MAXLINE;
}
void outQueue(Queue1 *que,int *data1)
{
    if(isempty(*que))
        return;
    *data1 = que->data[que->front1];
    que->front1 = (que->front1 +1) % MAXLINE;
}

int main()
{
    int *data2;
    *data2 = 0;
    Queue1 aa;
    QueueCreate(&aa);
    inQueue(&aa,3);
    inQueue(&aa,4);
    inQueue(&aa,5);
    inQueue(&aa,6);
    outQueue(&aa,data2);
    cout<<*data2<<endl;
    for(int i=0;i<MAXLINE;i++)
        cout<<aa.data[i]<<endl;
    cout<<aa.front1<<endl;
    cout<<aa.rear1<<endl;
    return 0;
}
