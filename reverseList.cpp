#include <iostream>

//反转一个链表

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

//解体思路1：可以使用迭代的方式，使用3个指针，一个指针指向当前节点，一个指针指向前一个节点，一个指针指向后一个节点
ListNode* reverse_list(ListNode* head)
{
    ListNode* curr = head;
    ListNode* prev = NULL;
    
    while (curr) {
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

//解体思路2： 使用递归的方法。比如1->2->3->4->5->NULL, 递归返回的条件是递归到最后一个节点，并且如果想要当前节点反转，必须要将当前节点的下一个节点指向自己，即p->next->next = p
//并且需要注意当当前节点为head的时候，需要将其指针指向NULL。
ListNode* reverse_list_2(ListNode* node)
{
    if (node->next == NULL || node == NULL)
        return node;

    ListNode* p = reverse_list_2(node->next);
    node->next->next = node;
    node->next = NULL;

    return p;
}
