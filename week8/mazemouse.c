#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000
#define TRUE 1
#define FALSE 0
#define N 4
#define M 5
int n = N, m = M; // 4 x 5
int visited[N][M]; // �湮�Ѱ��� ������ �ϱ����� �湮ó�� �� �迭
int fx = 2, fy = 3; // ������(������ġ)

// x,y ���� ���� ����ü
typedef struct _data {
	int x;
	int y;
	int dir; // �ݽð���� 0 up / 1 left / 2 down / 3 right
}Data;


// ���� ����
typedef struct _stack {
	Data arr[MAX_LEN];
	int top;
}Stack;


// ���� �ʱ�ȭ �Լ�
void StackInit(Stack* sp) {
	sp->top = -1;
}

// ���� ������� Ȯ���ϴ� �Լ�
int isEmpty(Stack* sp) {
	if (sp->top == -1) return TRUE;
	else return FALSE;
}

// ������ push �Լ�
void push(Stack* sp, Data data) {
	// 0~999 = 1000�� ������ top�� 1000�̻��� �ȴٸ� ���� ���� �ǹ� 
	if ((sp->top) + 1 >= MAX_LEN) return;
	sp->arr[++(sp->top)] = data;
}

// ������ pop �Լ�(����)
Data pop(Stack* sp) {
	Data data;
	// ������ ����� �� ������ �� �ʱ�ȭ
	data.x = -1;
	data.y = -1;
	data.dir = -1;

	if (isEmpty(sp)) return;

	// pop �� ���� �ִٸ�
	return sp->arr[(sp->top)--];
}

// ���� ��� �Լ�
void printStack(Stack* sp) {
	printf("Stack: ");
	for (int i = 0; i < (sp->top) + 1; i++) {
		printf("(%d %d %d)", sp->arr[i].x, sp->arr[i].y, sp->arr[i].dir);
	}
	printf("\n");
}

int isReachable(int maze[N][M]) {
	int i = 0, j = 0; // ���� ��ġ

	// ���� ���� �� �ʱ�ȭ
	Stack stack;
	StackInit(&stack);

	Data temp;
	temp.x = i;
	temp.y = j;
	temp.dir = 0; //up

	push(&stack, temp);

	while (!isEmpty(&stack)) {
		temp = pop(&stack); // ���ÿ��� �ֱ� �� ����

		// x, y, dir �� �̾Ƽ� ����
		int d = temp.dir;
		i = temp.x; j = temp.y;
		temp.dir++; // 1,2,3,4 �� ǥ��
		push(&stack, temp);

		if (i == fx && j == fy){
			printStack(&stack);
			return TRUE;
		}

		if (d == 0) { //UP
			// x�� 0�̻�(������ʰ�) && ���̾ƴ� 1�̿����ϰ� && �湮���� ���� 1�̿��� true
			if (i - 1 >= 0 && maze[i - 1][j] && visited[i - 1][j]) {
				Data temp1;
				temp1.x = i - 1;
				temp1.y = j;
				temp1.dir = 0;
				visited[i - 1][j] = FALSE;
				push(&stack, temp1);
			}
		}
		else if (d == 1) { // LEFT
			// y�� 0�̻�(������ʰ�) && ���̾ƴ� 1�̿����ϰ� && �湮���� ���� 1�̿��� true
			if (j - 1 >= 0 && maze[i][j - 1] && visited[i][j - 1]) {
				Data temp1;
				temp1.x = i;
				temp1.y = j - 1;
				temp1.dir = 0;
				visited[i][j - 1] = FALSE;
				push(&stack, temp1);
			}
		}
		else if (d == 2) { // DOWN
			if (i + 1 < n && maze[i + 1][j] && visited[i + 1][j]) {
				Data temp1;
				temp1.x = i + 1;
				temp1.y = j;
				temp1.dir = 0;
				visited[i + 1][j] = FALSE;
				push(&stack, temp1);
			}
		}
		else if (d == 3) { // RIGHT
			if (j + 1 < m && maze[i][j + 1] && visited[i][j + 1]) {
				Data temp1;
				temp1.x = i;
				temp1.y = j + 1;
				temp1.dir = 0;
				visited[i][j + 1] = FALSE;
				push(&stack, temp1);
			}
		}
		else {
			visited[temp.x][temp.y] = TRUE;
			temp = pop(&stack);
		}
	}
	return FALSE;
}

int main() {
	memset(visited, TRUE, sizeof(visited)); // ��� 1�� �ʱ�ȭ

	int maze[N][M] = {
		{1,0,1,1,0},
		{1,1,1,0,1},
		{0,1,0,1,1},
		{1,1,1,1,1}
	};

	if (isReachable(maze)) {
		printf("Path Found!\n");
	}
	else
		printf("Path Not Found!\n");

	
	return 0;
}
