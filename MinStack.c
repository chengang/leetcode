#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int * ptrData;
	int szData;
	int * ptrMin;
	int szMin;
	int stackSize;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
	stack->ptrData = calloc(1, maxSize + 100000); 
	stack->szData = 0;
	stack->ptrMin = calloc(1, maxSize + 100000); 
	stack->szMin = 0;
	stack->stackSize = maxSize;
}

void minStackPushMin(MinStack *stack, int element) {
	if(stack->szMin >= stack->szData)
		return;

	if(element <= stack->ptrMin[stack->szMin] || stack->szMin == 0) {
		stack->szMin++;
		stack->ptrMin[stack->szMin] = element;
	}
}

void minStackPopMin(MinStack *stack, int element) {
	if(element <= stack->ptrMin[stack->szMin]) {
		stack->szMin--;
	}
}

void minStackPush(MinStack *stack, int element) {
	if(stack->szData >= stack->stackSize)
		return;

	stack->szData++;
	stack->ptrData[stack->szData] = element;

	minStackPushMin(stack, element);
}

void minStackPop(MinStack *stack) {
	minStackPopMin(stack, stack->ptrData[stack->szData]);
	stack->szData--;
}

int minStackTop(MinStack *stack) {
	return stack->ptrData[stack->szData];
}

int minStackGetMin(MinStack *stack) {
	return stack->ptrMin[stack->szMin];
}

void minStackDestroy(MinStack *stack) {
	free(stack->ptrData);
	free(stack->ptrMin);
}

int main()
{
	MinStack ms;
	minStackCreate(&ms, 100000);

	minStackPush(&ms, -10);
	minStackPush(&ms, -9);
	minStackPush(&ms, -8);
	minStackPush(&ms, -7);
	minStackPush(&ms, -6);
	minStackPush(&ms, -5);
	minStackPush(&ms, -4);
	minStackPush(&ms, -3);
	minStackPush(&ms, -2);
	minStackPush(&ms, -1);
	minStackPush(&ms, 0);
	minStackPush(&ms, 1);
	minStackPush(&ms, 2);
	minStackPush(&ms, 3);
	minStackPush(&ms, 4);
	minStackPush(&ms, 5);
	minStackPush(&ms, 6);
	minStackPush(&ms, 7);
	minStackPush(&ms, 8);
	minStackPush(&ms, 9);
	minStackPush(&ms, 10);
	minStackPush(&ms, 11);
	minStackPush(&ms, 12);
	minStackPush(&ms, 13);
	minStackPush(&ms, 14);
	minStackPush(&ms, 15);
	minStackPush(&ms, 16);
	minStackPush(&ms, 17);
	minStackPush(&ms, 18);
	minStackPush(&ms, 19);
	minStackPush(&ms, 20);
	minStackPush(&ms, 21);

	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));
	minStackPop(&ms);
	printf("%d\n", minStackGetMin(&ms));

	minStackDestroy(&ms);
	return 0;
}
