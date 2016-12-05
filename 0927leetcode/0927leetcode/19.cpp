#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* pre = NULL;
    ListNode* node1 = head;
    ListNode* node2 = head;
    int delta = n;

    while (delta){
        node2 = node2->next;
        delta--;
    }

    while (node2->next){
        node1 = node1->next;
        node2 = node2->next;
    }

    if (pre == NULL){
        head = node1->next;
    }else
        pre->next = node1->next;

    return head;
}

//int main()
//{
//    ListNode p1(1), p2(2), p3(3);
//    //p1.next = &p2;
//    //p2.next = &p3;
//    ListNode* head = removeNthFromEnd(&p1, 1);
//    return 0;
//}