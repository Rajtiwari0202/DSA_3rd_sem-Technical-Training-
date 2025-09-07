#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force (O(n^4), O(1))
int fourSumBrute(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    int count = 0;
    int n = A.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                for(int l=0; l<n; l++){
                    if(A[i] + B[j] + C[k] + D[l] == 0){
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

// Approach 2: Hash Map (O(n^2), O(n^2))
int fourSumHash(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    unordered_map<int,int> sumAB;
    
    for(int a : A){
        for(int b : B){
            sumAB[a+b]++;
        }
    }
    
    int count = 0;
    for(int c : C){
        for(int d : D){
            int target = -(c+d);
            if(sumAB.count(target)){
                count += sumAB[target];
            }
        }
    }
    return count;
}

int main(){
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {-2,-1};
    vector<int> nums3 = {-1,2};
    vector<int> nums4 = {0,2};

    cout << "Brute Force: " << fourSumBrute(nums1, nums2, nums3, nums4) << endl;
    cout << "Hash Map: " << fourSumHash(nums1, nums2, nums3, nums4) << endl;

    return 0;
}
