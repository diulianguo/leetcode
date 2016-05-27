#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        int i, j, k,l;
        vector<int> C;
        //output intersection without repetition
        /*for (i = 0; i < nums1.size(); i++){
            for (j = 0; j < nums2.size(); j++){
                if (nums1[i] == nums2[j])
                {
                    if (C.size()>0){
                        for (k = 0; k < C.size(); k++){
                            if (C[k] == nums1[i])
                                break;
                        }
                        if (k == C.size()){
                            C.push_back(nums1[i]);
                        }
                    } else
                        C.push_back(nums1[i]);
                }
            }
        }
        return C;*/
        //output intersection with repetition
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto it1 = nums1.begin(), it2 = nums2.begin();
        while (it1 != nums1.end() && it2 != nums2.end()){
            if (*it1 < *it2)
                it1++;
            else if (*it1>*it2)
                it2++;
            else{
                C.push_back(*it1);
                it1++;
                it2++;
            }
        }
            return C;
        /*int length = C.size();
        vector<int> D(length);
        for (i=j = 1; i < length; i++){
            for (k = 0; k < j; k++){
                if (C[k] == C[j])
                    break;
            }
            if (k>j)
                C[j++] = C[]
            
        }*/
        
    }
};

int main()
{
    vector<int> A;
    vector<int> B;
    cout<<"please input array A:"<<endl;
    int temp;
    while (cin >> temp && temp != -1){
        A.push_back(temp);
    }
    cout<<"please input array B:"<<endl;
    while (cin >> temp && temp != -1){
        B.push_back(temp);
    }
    cout << endl;
    Solution AB;
    for (int i = 0; i < AB.intersect(A, B).size(); i++){
        cout << AB.intersect(A, B)[i] << " ";
    }
    system("pause");
    return 0;
}