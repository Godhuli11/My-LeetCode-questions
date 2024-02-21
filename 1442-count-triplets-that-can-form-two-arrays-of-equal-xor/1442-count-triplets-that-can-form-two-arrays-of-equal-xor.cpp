class Solution {
public:
    int countTriplets(vector<int>& a) {
        int n = a.size();
        int res =0;
        for(int i=0;i<n;i++)
        {
            int t = a[i];
            for(int k=i+1;k<n;k++)
            {
                t = t^a[k];
                if(t==0)
                    res+=(k-i);
            }
        }
        
        return res;
        
    }
};
