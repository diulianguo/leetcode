#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverse(ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode* p1 = head;
    ListNode* p2 = head->next;
    ListNode* ptmp = NULL;
    p1->next = NULL;
    while (p2){
        ptmp = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = ptmp;
    }
    return p1;
}

bool isSame(ListNode* n1, ListNode* n2)
{
    while (n2){
        if (n1->val == n2->val){
            n1 = n1->next;
            n2 = n2->next;
        } else
            return false;
    }
    return true;
}

bool isPalindrome(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast){//奇数个节点
        slow->next = reverse(slow->next);
        slow = slow->next;
    } else{
        slow = reverse(slow);
    }

    return isSame(head, slow);
}

//int main()
//{
//    ListNode p1(1), p2(1), p3(2), p33(2), p4(1), p44(1), p5(5);
//    p1.next = &p2;
//    p2.next = &p3;
//    p3.next = &p33;
//    p33.next = &p4;
//    p4.next = &p44;
//    //p44.next = &p5;
//    cout << isPalindrome(&p1) << endl;
//    return 0;
//}
