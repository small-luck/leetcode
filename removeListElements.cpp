#include <iostream>

/* 删除链表中值为val的节点 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

//方法1：当头节点的值为val时，先循环删除头节点，然后再迭代删除其余节点
ListNode* removeElement_1(ListNode* head, int val)
{
    while ((head != NULL) && (head->val == val))
        head = head->next;

    if (head == NULL || head->next == NULL)
        return head;

    //迭代
    ListNode* prev = head;
    while (prev->next != NULL) {
        //如果当前节点的值为val，那么其前节点所指向的next应该为当前节点所指向的next，否则的话，后移节点
        if (prev->next->val == val)
            prev->next = prev->next->next;
        else
            prev = prev->next;
    }

    return head;
}

//方法2：构建一个虚拟节点，使其next指向head，迭代删除
ListNode* removeElement_2(ListNode* head, int val)
{   
    //构建一个节点，放在head前面
    ListNode* p = new ListNode(0);
    p->next = head;

    //使用prev去迭代
    ListNode* prev = p;
    while (prev->next != NULL) {
        if (prev->next->val == val)
            prev->next = prev->next->next;
        else
            prev = prev->next;
    }

    return p->next;
}

//方法3：递归删除。其实是一种反序遍历
ListNode* removeElement_3(ListNode* head, int val)
{
    //递归的返回是如果该节点为NULL，则返回。
    if (head == NULL)
        return head;

    head->next = removeElement_3(head->next, val);

    if (head->val == val)
        return head->next;
    else
        return head;
}
