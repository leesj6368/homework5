#include<stdio.h>
#include<stdlib.h>
#define cQ_SIZE  100
 
typedef int element;            // ť ����(element)�� �ڷ����� char�� ����
typedef struct {
    element queue[cQ_SIZE]; // 1���� �迭 ť ����
    int front, rear;
    int count;
} QueueType;
 
QueueType *createQueue() {//creatQueue �Լ� 
    QueueType *cQ;
    cQ = (QueueType *)malloc(sizeof(QueueType));//���� �޸� �Ҵ�
    cQ->front = 0;       // front �ʱ갪 ����
    cQ->rear = 0;        // rear �ʱ갪 ����
    cQ->count = 0;       //count �ʱ갪 ����
    return cQ;
}// ���� ť�� ���� �������� �˻��ϴ� ����
int isEmpty(QueueType *cQ) {
    if (cQ->front == cQ->rear) { //front==rear�̸� ����ť�� empty ����
        printf(" Circular Queue is empty! ");
        return 1;
    }
    else return 0;
}
 
// ���� ť�� ��ȭ �������� �˻��ϴ� ����
int isFull(QueueType *cQ) {
    if (((cQ->rear + 1) % cQ_SIZE) == cQ->front) { //����ť ��ȭ����
        printf("  Circular Queue is full! ");
        return 1;
    }
    else return 0;
}
 
// ���� ť�� rear�� ���Ҹ� �����ϴ� ����
void enQueue(QueueType *cQ, element item1) {
    if (isFull(cQ)) return;
    else {
        cQ->rear = (cQ->rear + 1) % cQ_SIZE;
        cQ->queue[cQ->rear] = item1;
 
        (cQ->count) += 1;
    }
}
 
// ���� ť�� front���� ���Ҹ� �����ϰ� ��ȯ�ϴ� ����
element deQueue(QueueType *cQ) {
    if (isEmpty(cQ)) exit(1);
    else {
        cQ->front = (cQ->front + 1) % cQ_SIZE;
 
        (cQ->count) -= 1;
        return cQ->queue[cQ->front];
    }
}
// ���� ť�� ���� �տ� �ִ� ���Ҹ� �˻��ϴ� ����
element peek(QueueType *cQ) {
    if (isEmpty(cQ)) exit(1); //empty�̸� Ż��
    else return cQ->queue[(cQ->front + 1) % cQ_SIZE];
}
 
// ���� ť�� ���Ҹ� ����ϴ� ����
void printQ(QueueType *cQ) {
    int i, first, last;
    first = (cQ->front + 1) % cQ_SIZE; //first�� �� ����
    last = (cQ->rear + 1) % cQ_SIZE; //last�� �� ����
    printf("[");
    i = first;
    while (i != last) {//i�� last�� �ƴϸ�, �������
        printf(" %d ", cQ->queue[i]);
        i = (i + 1) % cQ_SIZE;
    }
    printf("]");
}
 
 
 
 
void main(void){
    printf("[----- [LeeSeonJue] [2021041042] -----]");
    QueueType *cQ = createQueue();  // ť ����
    element data, i, num1, num2;
     
     
    printf("\n ***** ���� ť ���� ***** \n");
     
    while (1)
    {
        if (cQ->count != 10)//�� �Է¹ް� rear�� ���һ���
        {
            scanf("%d", &num1);
            scanf("%d", &num2);
            enQueue(cQ, num1);
            enQueue(cQ, num2);
            printf("dequeue : %d\n", deQueue(cQ));
            printf("Current Circular Queue : ");
            printQ(cQ);
            printf(" , Queue size : %d\n\n", cQ->count);
        }
        else//���Ұ� �� ���� ���� ����
            printf("\n10���� ����ֱ� ������ ���� dequeue\n");
            for (i = 0; i < 10; i++)
                printf("dequeue : %d\n", deQueue(cQ));
        }
 printQ(cQ);
}
