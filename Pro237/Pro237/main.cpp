#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x){
		val=x;
		next=NULL;
	}
};

ListNode* head;
ListNode* pref;
ListNode* suff;
ListNode* temp;


void deleteNode(ListNode* node){
	/*temp=head;
	pref=head;
	while(temp!=NULL){
		suff=temp->next;
		if(temp==node && temp==head){
			head=head->next;
			return;
		}
		if(temp==node && temp!=head){
			pref->next=suff;
			return;
		}
		if(temp!=head){
			pref=pref->next;
		}
		temp=temp->next;
	}*/
	ListNode* ptr=node->next;
	node->val=ptr->val;
	node->next=ptr->next;
	free(ptr);
}

ListNode* reverseList(ListNode* head){
	ListNode* pref;
	ListNode* suff;
	ListNode* temp=head->next;
	pref=head;
	while(temp!=NULL){
		suff=temp->next;
		if(temp!=head){
			temp->next=pref;
			if(pref==head)
				pref->next=NULL;
		}
		pref=temp;
		temp=suff;
	}
	return pref;
}

ListNode* insertionSortList(ListNode* head){
	/*ListNode* temp=head;
	ListNode* prehead=new ListNode(0);
	prehead->next=head;
	ListNode* pre=prehead;
	ListNode* suf;
	while(temp){
		//如果出现逆序，向前寻找合适的插入位置
		if(temp->next && temp->val>temp->next->val){
			while(pre->next && pre->next->val<temp->next->val)
				pre=pre->next;
			//把temp->next插入pre之后
			suf=pre->next;
			pre->next=temp->next;
			//temp移到后一个位置
			temp->next=temp->next->next;
			pre->next->next=suf;
			pre=prehead;
		}else
			temp=temp->next;
	}
	suf=prehead->next;
	delete prehead;
	return suf;*/
	//faked head node 
        ListNode* res = new ListNode(-1);
        ListNode* cur = res;
        //head is the current node we are dealing with
        while (head) {
            ListNode *next = head->next;
            cur = res;//新建一个空链表，用来存放排好序的数组
            while (cur->next && cur->next->val <= head->val) {
                cur = cur->next;
            }
            //insert the head node into the list
            head->next = cur->next;
            cur->next = head;
            //move forward the head node
            head = next;
        }
        return res->next;
}

int main(){
	head=(ListNode*)malloc(sizeof(ListNode));
	temp=(ListNode*)malloc(sizeof(ListNode));
	head=temp;
	for(int i=0;i<5;i++){
		temp->val=5-i;
		printf("%d ",temp->val);
		if(i==4)
			temp->next=NULL;
		else{
		    temp->next=(ListNode*)malloc(sizeof(ListNode));
		    temp=temp->next;
		}
	}
	cout<<endl;
	//deleteNode(head);
	//temp=reverseList(head);
	temp=insertionSortList(head);
	for(int i=0;i<5;i++){
		printf("%d ",temp->val);
		temp=temp->next;
	}
	cout<<endl;
	system("pause");
	return 0;
}