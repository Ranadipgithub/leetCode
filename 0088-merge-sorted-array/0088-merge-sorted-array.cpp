class Solution {
private:
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            } else{
                nums1[k--] = nums2[j--];
            }
        }
        while(j>=0){
            nums1[k--] = nums2[j--];
        }
        // int i = 0, j = 0;
        // vector<int> res;
        // while(i<m && j < n){
        //     if(nums1[i] <= nums2[j]){
        //         res.push_back(nums1[i]);
        //         i++;
        //     } else{
        //         res.push_back(nums2[j]);
        //         j++;
        //     } 
        // }
        // while(i < m){
        //     res.push_back(nums1[i]);
        //     i++;
        // }
        // while(j < n){
        //     res.push_back(nums2[j]);
        //     j++;
        // }

        // for(int i = 0;i<m+n;i++){
        //     nums1[i] = res[i];
        // }
        // int left = m-1;
        // int right = 0;
        // while(left >= 0 && right < n){
        //     if(nums1[left] >= nums2[right]){
        //         swap(nums1[left], nums2[right]);
        //         left--;
        //         right++;
        //     }
        //     else{
        //         break;
        //     }
        // }
        // sort(nums1.begin(),nums1.begin()+m);
        // sort(nums2.begin(),nums2.begin()+n);
        // for(int i = 0;i<n;i++){
        //     nums1[m++] = nums2[i];
        // }
        
    }
};