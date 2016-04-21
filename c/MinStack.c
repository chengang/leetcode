#include <stdio.h>
#include <stdlib.h>

typedef struct linkedListNode {
	int val;
	struct linkedListNode * next;
} linkedListNode;

typedef struct {
	linkedListNode * ptrData;
	linkedListNode * ptrMin;
} MinStack;

linkedListNode * linkedListPush (linkedListNode * node, int val) {
	linkedListNode *newNode = (linkedListNode *) calloc(1, sizeof(linkedListNode));
	newNode->val = val;
	newNode->next = node;

	node = newNode;

	return node;
}

linkedListNode * linkedListPop (linkedListNode * node) {
	linkedListNode *lastNode = node;
	node = node->next;
	free(lastNode);
	return node;
}

void linkedListFree (linkedListNode * node) {
	while(node->next != NULL) {
		node = linkedListPop(node);
	}
}

linkedListNode * minStackMinPush(linkedListNode *node, int element) {
	if(node == NULL || element <= node->val) {
		node = linkedListPush(node, element);
	}
	return node;
}

linkedListNode * minStackMinPop(linkedListNode *node) {
	return linkedListPop(node);
}

void minStackCreate(MinStack *stack, int maxSize) {
	stack->ptrData = NULL;
	stack->ptrMin = NULL;
}

void minStackPush(MinStack *stack, int element) {
	stack->ptrMin = minStackMinPush(stack->ptrMin, element);
	stack->ptrData = linkedListPush(stack->ptrData, element);
}

void minStackPop(MinStack *stack) {
	if(stack->ptrData->val <= stack->ptrMin->val) {
		stack->ptrMin = minStackMinPop(stack->ptrMin);
	}
	stack->ptrData = linkedListPop(stack->ptrData);
}

int minStackTop(MinStack *stack) {
	return stack->ptrData->val;
}

int minStackGetMin(MinStack *stack) {
	return stack->ptrMin->val;
}

void minStackDestroy(MinStack *stack) {
	linkedListFree(stack->ptrData);
	linkedListFree(stack->ptrMin);
}

int main() {
	MinStack stack;
	minStackCreate(&stack, 10);
	//int i;
	//for (i = 0; i < 5; i++) {
	//	minStackPush(&stack, i);
	//}

	//printf("top: %d\n", minStackTop(&stack));
	//printf("min: %d\n", minStackGetMin(&stack));

	//for (i = 1; i < 5; i++) {
	//	minStackPush(&stack, -i);
	//}

	//printf("top: %d\n", minStackTop(&stack));
	//printf("min: %d\n", minStackGetMin(&stack));

	minStackPush(&stack, 0);
	minStackPush(&stack, 1);
	minStackPush(&stack, 0);
	printf("min: %d\n", minStackGetMin(&stack));
	minStackPop(&stack);
	printf("min: %d\n", minStackGetMin(&stack));

	minStackDestroy(&stack);

	return 0;
}
