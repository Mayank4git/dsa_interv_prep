/*

You are given a 0-indexed integer array piles, where piles[i] represents the number of stones in the ith pile, and an integer k. You should apply the following operation exactly
k times:
Choose any piles[i] and remove floor(piles[i] / 2) stones from it.
Notice that you can apply the operation on the same pile more than once.
Return the minimum possible total number of stones remaining after applying the k operations.
floor(x) is the greatest integer that is smaller than or equal to x (i.e., rounds x down).

*/

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {

        priority_queue<int> maxHeap;

        for(int i=0;i<piles.size();i++){
            maxHeap.push(piles[i]);
        }

        while(k--){
            int maxEle = maxHeap.top();
            maxHeap.pop();
            maxEle = maxEle - floor(maxEle/2);
            maxHeap.push(maxEle);
        }

        int sum = 0;
        while(!maxHeap.empty()){
            int temp = maxHeap.top();
            maxHeap.pop();
            sum = sum + temp;
        }
        return sum;
        
    }
};