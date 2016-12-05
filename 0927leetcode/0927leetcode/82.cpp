#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head)
{
    ListNode* pre = NULL;
    ListNode* node1 = head;
    ListNode* node2 = head;

    while (node2){
        while (node2 && node2->val == node1->val){
            node2 = node2->next;
        }

        while (node1!=node2 && node1->next != node2){
            if (pre && pre!=node1){
                pre->next = node2;
                node1 = pre;
            } else{
                head = node2;
                node1 = head;
                node2 = head;
            }
        }

        if (node2){
            pre = node1;
            node1 = node2;
            node2 = node2->next;
        }
    }
    return head;
}

//int main()
//{
//    ListNode p1(1), p2(1), p3(2), p33(2), p4(4), p44(4), p5(5);
//    p1.next = &p2;
//    p2.next = &p3;
//    p3.next = &p33;
//    /*p33.next = &p4;
//    p4.next = &p44;
//    p44.next = &p5;*/
//    ListNode* head = deleteDuplicates(&p1);
//    return 0;
//}