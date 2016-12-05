#include <iostream>
using namespace std;

void InsertSort(int Array[],int n){
	int i,j;
	int curr;
	for(i=1;i<n;i++){
		curr=Array[i];
		//向前寻找插入位置
		j=i-1;
		while(j>=0){
			if(Array[j]>curr){
				Array[j+1]=Array[j];//大于当前值的元素后移
				j--;
			}else
				break;
		}
		Array[j+1]=curr;
	}
}

void SelectSort(int Array[],int n){
	int i,j;
	int Smallest;
	for(i=0;i<n-1;i++){
		//找到第i小的元素
		Smallest=i;
		for(j=i+1;j<n;j++){
			if(Array[j]<Array[Smallest])
				Smallest=j;
		}
		//交换i和j位置的元素
		int temp=Array[i];
		Array[i]=Array[Smallest];
		Array[Smallest]=temp;
	}
}

void BubbleSort(int Array[],int n){
	bool NoSwap;
	int i,j;
	for(i=0;i<n;i++){
		NoSwap=true;
		for(j=n-1;j>0;j--){
			if(Array[j]<Array[j-1]){
				int temp=Array[j];
				Array[j]=Array[j-1];
				Array[j-1]=temp;
				NoSwap=false;
			}
		}
		if(NoSwap)
			return;
	}
}

int main(){
	int A[5]={5,4,3,2,1};
	//InsertSort(A,5);
	//SelectSort(A,5);
	BubbleSort(A,5);
	for(int i=0;i<5;i++){
		cout<<A[i]<<" ";
	}
	system("pause");
	return 0;
}