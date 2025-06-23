/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peakIndexInMountainArray(MountainArray &mountainArr) {
        int n = mountainArr.length();
        
        if(mountainArr.get(0) > mountainArr.get(1)) return 0;
        if(mountainArr.get(n-1) > mountainArr.get(n-2)) return n-1;
        int low = 1, high = n-2;
        while(low <= high){
            int mid = low + (high - low)/2;
            int midEl = mountainArr.get(mid);
            int midAfter = mountainArr.get(mid+1);
            int midPrev = mountainArr.get(mid-1);
            if(midEl > midPrev && midEl > midAfter){
                return mid;
            }
            else if(midEl > midPrev){
                low = mid + 1;
            } else{
                high = mid - 1;
            }
        }
        return -1;
    }
    
    int binarySearch(MountainArray &mountainArr, int l, int r, int target) {
        
        int mid;
        while(l <= r) {
            mid = l + (r-l)/2;
            
            if(mountainArr.get(mid) == target) {
                return mid;
            } else if(mountainArr.get(mid) > target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return -1;
        
    }

    int reverseBinarySearch(MountainArray &mountainArr, int l, int r, int target) {
        int mid;
        while(l <= r) {
            mid = l + (r-l)/2;
            
            if(mountainArr.get(mid) == target) {
                return mid;
            } else if(mountainArr.get(mid) > target) { 
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        
        int peakIndex = peakIndexInMountainArray(mountainArr);
        
        int idx = binarySearch(mountainArr, 0, peakIndex, target);
        
        if(idx == -1) {
            return reverseBinarySearch(mountainArr, peakIndex, n-1, target);
        }
        
        return idx;
        
    }
};