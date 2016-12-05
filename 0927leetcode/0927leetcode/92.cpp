#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n)
{
    if (head == NULL || m >= n)
        return head;

    int i = 1;
    ListNode* p = head;
    ListNode* pre = NULL;
    ListNode* shead = NULL;
    ListNode* send = NULL;
    ListNode* nxt = NULL;
    ListNode* p1 = NULL;
    ListNode* ptmp = NULL;
    while (p){
        if (i < m){
            pre = p;
            p = p->next;
            i++;
        }
        if (i == m){
            shead = p;
            p1 = shead->next;
            shead->next = NULL;
        }
        while (i >= m && i < n){
            ptmp = p1->next;
            p1->next = p;
            p = p1;
            p1 = ptmp;
            i++;
        }
        if (i == n){
            send = p;
            nxt = ptmp;
            break;
        }
    }
    if (pre){
        pre->next = send;
    } else
        head = send;
    shead->next = nxt; 

    return head;
}

//int main()
//{
//    ListNode p1(1), p2(2), p3(3), p4(4), p5(5);
//    p1.next = &p2;
//    p2.next = &p3;
//    p3.next = &p4;
//    p4.next = &p5;
//    ListNode* head = reverseBetween(&p1, 3, 5);
//    return 0;
//}