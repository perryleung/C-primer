struct ListNode
{
	int value;
	ListNode* next;
};

__declspec(dllexport) ListNode *CreateListNode(int value);
__declspec(dllexport) void ConnectListNode(ListNode *pCurrent, ListNode *pNext);
__declspec(dllexport) void PrintListNode(const ListNode *pNode);
__declspec(dllexport) void PrintList(const ListNode *pHead);
__declspec(dllexport) void DestroyList(ListNode *pHead);
__declspec(dllexport) void AddToTail(ListNode **pHead, int value);
__declspec(dllexport) void RemoveNode(ListNode **pHead, int value);