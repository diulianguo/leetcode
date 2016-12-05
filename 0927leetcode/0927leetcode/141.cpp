#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    while (fast && fast->next){
        fast = fast->next->next;
        if (fast == NULL)
            return false;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
}

ListNode *detectCycle(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    while (fast && fast->next){
        fast = fast->next->next;
        if (fast == NULL)
            return NULL;
        slow = slow->next;
        if (fast == slow){
            slow = head;
            while (slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
}

//int main()
//{
//    ListNode p1(1), p2(2), p3(3), p4(4);
//    p1.next = &p2;
//    p2.next = &p3;
//    p3.next = &p4;
//    p4.next = &p2;
//    ListNode* p = detectCycle(&p1);
//    cout << hasCycle(&p1) << endl;
//    return 0;
//}