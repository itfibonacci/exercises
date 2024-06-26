#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "linkedlist.h"

void printlinkedlist(struct ListNode *head) {
	struct ListNode *current = head;

	while (current != NULL) {
		if (current->next == NULL) {
			printf("%d ", current->val);
		}
		else {
			printf("%d -> ", current->val);
		}
		current = current->next;
	}
	printf("\n");
}

struct ListNode *createlinkedlistfromarray(int arr[], int size) {
	if (size == 0) {
		return NULL;
	}
	
	struct ListNode *head = malloc(sizeof(*head));
	struct ListNode *node = head;

	for (int i = 0; i < size; i++) {
		node->val = arr[i];
		if (i == size - 1) {
			node->next = NULL;
		}
		else {
			node->next = malloc(sizeof(*node));
		}
		node = node->next;
	}

	return head;
}

struct ListNode *appendlists(struct ListNode *head1, struct ListNode *head2) {
	if (head1 == NULL && head2 == NULL) {
		return NULL;
	}

	if (head2 == NULL) {
		return head1;
	}

	if (head1 == NULL) {
		return head2;
	}

	struct ListNode *current = head1;

	while (current->next != NULL) {
		current = current->next;
	}

	current->next = head2;

	return head1;
}

size_t get_ll_length(struct ListNode *head) {
	size_t i = 0;

	while (head != NULL) {
		head = head->next;
		i++;
	}

	return i;
}

struct ListNode *reversell_recursive(struct ListNode *head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	struct ListNode* rest = reversell_recursive(head->next);
	head->next->next = head;
	head->next = NULL;
	return rest;
}

struct ListNode *reversell_iterative(struct ListNode *head) {
	struct ListNode *prev = NULL;
	struct ListNode *curr = head;
	struct ListNode *next = NULL;

	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}

bool is_equal(struct ListNode *list1, struct ListNode *list2) {
	while (list1 != NULL && list2 != NULL) {
		if (list1->val != list2->val) {
			return false;
		}
	}

	if (list1 != NULL || list2 != NULL) {
		return false;
	}

	return true;
}
