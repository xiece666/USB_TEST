class Solution {
    public:
        vector<int> specialSort(int n) {
            vector<int>res(n);
            for(int i=0;i<n;i++)res[i]=i+1;
            stable_sort(res.begin(),res.end(),compare);
            return res;
        }
};