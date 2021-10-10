#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 20
 
bool visited[9];

int graph[9][3] = { {NULL}, {2,3,8}, {1,7}, {1,4,5}, {3,5}, {3,4}, {7}, {2,6,8}, {1,7} };

// ť ����ü ����
typedef struct { // ���� ť Ÿ��
	int front;
	int rear;
	int data[MAX_QUEUE_SIZE];
} QueueType;

// ���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ť �ʱ�ȭ �Լ�
void init_queue(QueueType* q)
{
	q->rear = -1;
	q->front = -1;
}

// ť�� ��ȭ�����ΰ�
int is_full(QueueType* q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}

//ť ���� Ȯ��
bool is_empty(QueueType* q)
{
	if (q->front == q->rear)
		return true;
	else
		return false;
}


// ������ ���� �Լ�
void enqueue(QueueType* q, int item)
{
	if (is_full(q)) {
		error("ť�� ��ȭ�����Դϴ�.");
		return;
	}
	q->data[++(q->rear)] = item;
}

// ť���� ������ ����
int dequeue(QueueType* q)
{
	if (is_empty(q)) {
		error("ť�� ��������Դϴ�.");
		return -1;
	}
	int item = q->data[++(q->front)];
	return item;
}

void bfs(int start) {
	// queue ����
	QueueType queue;
	init_queue(&queue);

	// ���� �� �߰�
	enqueue(&queue, start);

	// ���� ��� �湮ó��
	visited[start] = true;

	// ť�� �� ������
	while (!is_empty(&queue)) {
		int v = dequeue(&queue); // ���� ���� ���� �� ����

		// �湮 ��� �ϳ��� ���
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