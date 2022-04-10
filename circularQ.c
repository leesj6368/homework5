#include<stdio.h>
#include<stdlib.h>
#define cQ_SIZE  100
 
typedef int element;            // 큐 원소(element)의 자료형을 char로 정의
typedef struct {
    element queue[cQ_SIZE]; // 1차원 배열 큐 선언
    int front, rear;
    int count;
} QueueType;
 
QueueType *createQueue() {//creatQueue 함수 
    QueueType *cQ;
    cQ = (QueueType *)malloc(sizeof(QueueType));//동적 메모리 할당
    cQ->front = 0;       // front 초깃값 설정
    cQ->rear = 0;        // rear 초깃값 설정
    cQ->count = 0;       //count 초깃값 설정
    return cQ;
}// 원형 큐가 공백 상태인지 검사하는 연산
int isEmpty(QueueType *cQ) {
    if (cQ->front == cQ->rear) { //front==rear이면 원형큐는 empty 상태
        printf(" Circular Queue is empty! ");
        return 1;
    }
    else return 0;
}
 
// 원형 큐가 포화 상태인지 검사하는 연산
int isFull(QueueType *cQ) {
    if (((cQ->rear + 1) % cQ_SIZE) == cQ->front) { //원형큐 포화상태
        printf("  Circular Queue is full! ");
        return 1;
    }
    else return 0;
}
 
// 원형 큐의 rear에 원소를 삽입하는 연산
void enQueue(QueueType *cQ, element item1) {
    if (isFull(cQ)) return;
    else {
        cQ->rear = (cQ->rear + 1) % cQ_SIZE;
        cQ->queue[cQ->rear] = item1;
 
        (cQ->count) += 1;
    }
}
 
// 원형 큐의 front에서 원소를 삭제하고 반환하는 연산
element deQueue(QueueType *cQ) {
    if (isEmpty(cQ)) exit(1);
    else {
        cQ->front = (cQ->front + 1) % cQ_SIZE;
 
        (cQ->count) -= 1;
        return cQ->queue[cQ->front];
    }
}
// 원형 큐의 가장 앞에 있는 원소를 검색하는 연산
element peek(QueueType *cQ) {
    if (isEmpty(cQ)) exit(1); //empty이면 탈출
    else return cQ->queue[(cQ->front + 1) % cQ_SIZE];
}
 
// 원형 큐의 원소를 출력하는 연산
void printQ(QueueType *cQ) {
    int i, first, last;
    first = (cQ->front + 1) % cQ_SIZE; //first에 값 대입
    last = (cQ->rear + 1) % cQ_SIZE; //last에 값 대입
    printf("[");
    i = first;
    while (i != last) {//i가 last가 아니면, 원소출력
        printf(" %d ", cQ->queue[i]);
        i = (i + 1) % cQ_SIZE;
    }
    printf("]");
}
 
 
 
 
void main(void){
    printf("[----- [LeeSeonJue] [2021041042] -----]");
    QueueType *cQ = createQueue();  // 큐 생성
    element data, i, num1, num2;
     
     
    printf("\n ***** 원형 큐 연산 ***** \n");
     
    while (1)
    {
        if (cQ->count != 10)//값 입력받고 rear에 원소삽입
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
        else//원소가 다 차면 원소 삭제
            printf("\n10개가 들어있기 때문에 전부 dequeue\n");
            for (i = 0; i < 10; i++)
                printf("dequeue : %d\n", deQueue(cQ));
        }
 printQ(cQ);
}
