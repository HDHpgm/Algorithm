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
int visited[N][M]; // 방문한곳은 못가게 하기위해 방문처리 할 배열
int fx = 2, fy = 3; // 목적지(음식위치)

// x,y 값을 가질 구조체
typedef struct _data {
	int x;
	int y;
	int dir; // 반시계방향 0 up / 1 left / 2 down / 3 right
}Data;


// 스택 정의
typedef struct _stack {
	Data arr[MAX_LEN];
	int top;
}Stack;


// 스택 초기화 함수
void StackInit(Stack* sp) {
	sp->top = -1;
}

// 스택 비었는지 확인하는 함수
int isEmpty(Stack* sp) {
	if (sp->top == -1) return TRUE;
	else return FALSE;
}

// 데이터 push 함수
void push(Stack* sp, Data data) {
	// 0~999 = 1000개 까진데 top이 1000이상이 된다면 꽉찬 것을 의미 
	if ((sp->top) + 1 >= MAX_LEN) return;
	sp->arr[++(sp->top)] = data;
}

// 데이터 pop 함수(삭제)
Data pop(Stack* sp) {
	Data data;
	// 스택이 비었을 때 리턴할 값 초기화
	data.x = -1;
	data.y = -1;
	data.dir = -1;

	if (isEmpty(sp)) return;

	// pop 할 것이 있다면
	return sp->arr[(sp->top)--];
}

// 스택 출력 함수
void printStack(Stack* sp) {
	printf("Stack: ");
	for (int i = 0; i < (sp->top) + 1; i++) {
		printf("(%d %d %d)", sp->arr[i].x, sp->arr[i].y, sp->arr[i].dir);
	}
	printf("\n");
}

int isReachable(int maze[N][M]) {
	int i = 0, j = 0; // 시작 위치

	// 스택 선언 및 초기화
	Stack stack;
	StackInit(&stack);

	Data temp;
	temp.x = i;
	temp.y = j;
	temp.dir = 0; //up

	push(&stack, temp);

	while (!isEmpty(&stack)) {
		temp = pop(&stack); // 스택에서 최근 값 꺼냄

		// x, y, dir 값 뽑아서 저장
		int d = temp.dir;
		i = temp.x; j = temp.y;
		temp.dir++; // 1,2,3,4 로 표현
		push(&stack, temp);

		if (i == fx && j == fy){
			printStack(&stack);
			return TRUE;
		}

		if (d == 0) { //UP
			// x가 0이상(벗어나지않고) && 벽이아닌 1이여야하고 && 방문하지 않은 1이여야 true
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
			// y가 0이상(벗어나지않고) && 벽이아닌 1이여야하고 && 방문하지 않은 1이여야 true
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
	memset(visited, TRUE, sizeof(visited)); // 모두 1로 초기화

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
