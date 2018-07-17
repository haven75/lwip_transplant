#include "FIFOQUEUE.h"
#include "bsp.h"
/*Queue Init*/
void
QueueInit (struct FifoQueue *Queue)
{
    Queue->front = Queue->rear;
    Queue->count = 0;
}

/* Queue In */
uint8_t
QueueIn (struct FifoQueue *Queue, ElemType sdat)
{
    CPU_SR cpu_sr = 0;          /*disable interrupt during queue input */
    OS_ENTER_CRITICAL ();
    if ((Queue->front == Queue->rear) && (Queue->count == QueueSize))
    {
        OS_EXIT_CRITICAL ();
        return QueueFull;
    }
    else
    {
        Queue->dat[Queue->rear] = sdat;
        Queue->rear = (Queue->rear + 1) % QueueSize;
        Queue->count = Queue->count + 1;
        OS_EXIT_CRITICAL ();
        return QueueOperateOk;
    }
}

/* Queue Out*/
uint8_t
QueueOut (struct FifoQueue * Queue, ElemType * sdat)
{
    CPU_SR cpu_sr = 0;          /*disable interrupt during queue input */
    OS_ENTER_CRITICAL ();
    if ((Queue->front == Queue->rear) && (Queue->count == 0))
    {
        OS_EXIT_CRITICAL ();
        return QueueEmpty;
    }
    else
    {
        *sdat = Queue->dat[Queue->front];
        Queue->front = (Queue->front + 1) % QueueSize;
        Queue->count = Queue->count - 1;
        OS_EXIT_CRITICAL ();
        return QueueOperateOk;
    }
}
