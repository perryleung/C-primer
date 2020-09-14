#include "ListNode.h"
#include <stdio.h>
#include <stdlib.h>

ListNode* CreateListNode(int value)
{
	ListNode* pNode = new ListNode();
	pNode->value = value;
	pNode->next = nullptr;
	return pNode;
}

void ConnectListNode(ListNode* pCurrent, ListNode* pNext)
{
	if (pCurrent == nullptr){
		return;
	}
	pCurrent->next = pNext;
}

void PrintListNode(ListNode* pNode)
{
	if (pNode == nullptr)
		return;
	else
		printf("The value in this node is %d. \n", pNode->value);
}

void PrintList(ListNode* pHead)
{
	if (pHead == nullptr)
		return;
	else
	{
		ListNode *pNode = pHead;
		while(pNode->next != NULL){
			PrintListNode(pNode);
			pNode = pNode->next;
		}
	}	
}

void DestroyList(ListNode* pHead)
{
	if (pHead == nullptr)
		return;
	else{
		ListNode *pNode = pHead;
		while (pNode != nullptr){
			pHead = pHead->next;
			delete pNode;
			pNode = pHead;
		}
	}
}

void AddToTail(ListNode** pHead, int value)
{
	ListNode *pNew = new ListNode();
	pNew->value = value;
	pNew->next = nullptr;

	if (*pHead == nullptr)
		*pHead = pNew;
	else{
		ListNode *pNode = *pHead;
		while (pNode->next != nullptr){
			pNode = pNode->next;
		}
		pNode->next = pNew;
	}
}

void RemoveNode(ListNode** pHead, int value)
{
	if (*pHead == nullptr || pHead == nullptr)
		return;

	ListNode* ToBeDeleted = nullptr;

	if ((*pHead)->value == value){
		ToBeDeleted = *pHead;
		*pHead = (*pHead)->next;
	}else{
		ListNode *pNode = *pHead;
		while (pNode->next->value != value && pNode->next != nullptr)
			pNode = pNode->next;

		if (pNode->next->value == value && pNode->next != nullptr){
			ToBeDeleted = pNode->next;
			pNode->next = pNode->next->next;
		}
	}

	if (ToBeDeleted != nullptr){
		delete ToBeDeleted;
		ToBeDeleted = nullptr;
	}
}