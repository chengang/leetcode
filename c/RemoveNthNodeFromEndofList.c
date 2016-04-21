#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode * addNode (struct ListNode * ln, int val) {
  struct ListNode * lnNew = malloc(sizeof(struct ListNode));
  lnNew->val = val;
  lnNew->next = ln;
  return lnNew;
}

void print_r(struct ListNode * ln) {
  struct ListNode * tmpNode = ln;
	printf("[");
	while(tmpNode != NULL) {
    printf("%d ", tmpNode->val);
		tmpNode = tmpNode->next;
  }
	printf("]\n");
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	if(head->next == NULL && n == 1) {
		free(head);
		return NULL;
	}

	int i = 0;
	struct ListNode *wantToRemove = head;
	struct ListNode *ori = head;
	while(head != NULL) {
		if(i>n)
			wantToRemove = wantToRemove->next;
		head = head->next;
		i++;
	}
	if(i==n) {
		struct ListNode *tmp = ori->next;
		free(ori);
		return tmp;
	}

	if(wantToRemove->next == NULL) {
		free(wantToRemove);
		wantToRemove = NULL;
	} else {
		struct ListNode *tmp = wantToRemove->next->next;
		free(wantToRemove->next);
		wantToRemove->next = tmp;
	}

	return ori;
}

int main() {
  struct ListNode * llPtrB = NULL;
  //llPtrB = addNode(llPtrB, 5);
  //llPtrB = addNode(llPtrB, 3);
  //llPtrB = addNode(llPtrB, 1);
  //llPtrB = addNode(llPtrB, 3);
  llPtrB = addNode(llPtrB, 6);
  llPtrB = addNode(llPtrB, 90);

  print_r(llPtrB);
	llPtrB = removeNthFromEnd(llPtrB, 2);
  print_r(llPtrB);

	return 0;
}
