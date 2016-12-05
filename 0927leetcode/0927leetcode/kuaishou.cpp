#include<iostream>
using namespace std;

void ThePivotElements(int data[], int len)
{
    int* rightmin = new int[len];
    int r_min = data[len - 1];
    for (int i = len - 1; i >= 0; i--)
    {
        if (data[i]<r_min)
            r_min = data[i];
        rightmin[i] = r_min;
    }
    int l_max = data[0];
    for (int i = 0; i<len; i++)
    {
        if (data[i]>l_max)
            l_max = data[i];
        if (l_max == rightmin[i])
            cout << data[i] << endl;
    }
}

//维护一个candidate的数组， 该数组的元素满足： 
//到目前为止，这些元素都大于等于它前面的元素，而小于等于到目前为止扫描到的它右边的所有元素。
int findNum(int *arr, int n)
{
    if (arr == NULL) return 0;
    int *cand = new int[n];
    int idx = 0; //记录当前cand数组中的元素个数。
    cand[idx++] = arr[0];
    int max = arr[0], i;
    for (i = 1; i<n; i++) {
        if (arr[i] >= max) {
            cand[idx++] = arr[i];
            max = arr[i];
        } else {
            //arr[i]是当前candidate数组中所有元素的右边元素
            while (idx > 0 && cand[idx - 1] > arr[i]) idx--;
        }
    }
    printf(" num: ");
    for (i = 0; i<idx; i++) printf("%d ", cand[i]);
    printf("\n");
    return idx;
}

//int main()
//{
//    int nums[6] = { 1, 3, 2, 4, 6, 5 };
//    cout << nums[findNum(nums, 6)] << endl;
//    system("pause");
//    return 0;
//}