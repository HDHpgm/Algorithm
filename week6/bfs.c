#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 20
 
bool visited[9];

int graph[9][3] = { {NULL}, {2,3,8}, {1,7}, {1,4,5}, {3,5}, {3,4}, {7}, {2,6,8}, {1,7} };

// 큐 구조체 선언
typedef struct { // 선형 큐 타입
	int front;
	int rear;
	int data[MAX_QUEUE_SIZE];
} QueueType;

// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 큐 초기화 함수
void init_queue(QueueType* q)
{
	q->rear = -1;
	q->front = -1;
}

// 큐가 포화상태인가
int is_full(QueueType* q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}

//큐 공백 확인
bool is_empty(QueueType* q)
{
	if (q->front == q->rear)
		return true;
	else
		return false;
}


// 데이터 삽입 함수
void enqueue(QueueType* q, int item)
{
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	q->data[++(q->rear)] = item;
}

// 큐에서 데이터 제거
int dequeue(QueueType* q)
{
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		return -1;
	}
	int item = q->data[++(q->front)];
	return item;
}

void bfs(int start) {
	// queue 선언
	QueueType queue;
	init_queue(&queue);

	// 시작 값 추가
	enqueue(&queue, start);

	// 현재 노드 방문처리
	visited[start] = true;

	// 큐가 빌 때까지
	while (!is_empty(&queue)) {
		int v = dequeue(&queue); // 가장 먼저 나갈 값 저장

		// 방문 노드 하나씩 출력
		printf("%d ", v);

		for (int i = 0; i < 3 && graph[v][i] != 0; i++) {
			if (!visited[graph[v][i]]) {
				enqueue(&queue, graph[v][i]);
				visited[graph[v][i]] = true;
			}
		}
	}
}

void main() {
	bfs(1);
}