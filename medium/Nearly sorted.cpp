
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        int n = arr.size();
    	int index = 0;
    	priority_queue<int,vector<int>, greater<int>> pq;
        for(int i=0;i<=k && i<n;i++){
        	pq.push(arr[i]);
        }
        for(int i=k+1;i<n;i++){
        	arr[index++] = pq.top();
        	pq.pop();
        	pq.push(arr[i]);
        }
        while(!pq.empty()){
        	arr[index++] = pq.top();
        	pq.pop();
        }

    }
};
