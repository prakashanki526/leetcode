class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // int l=0, r=arr.size()-1, ind;
        // while(l<=r){
        //     int m = l+(r-l)/2;
        //     ind = m;
        //     if(arr[m]==x){
        //         break;
        //     }
        //     if(arr[m]<x)
        //         l = m+1;
        //     else
        //         r = m-1;
        //     }
        // }
        // vector<int>v;
        // r = ind;
        // l = r-1;
        // if(r == 0){
        //     for(int i=0;i<k;i++)
        //         v.push_back(arr[i]);
        //     return v;
        // }
        // for(int i=0;i<k;i++){
        //    if(abs(arr[l]-x)<=abs(arr[r]-x)){
        //        v.push_back(arr[l]);
        //        if(l==0)
        //            arr[l]=INT_MAX;
        //        else
        //            l--;
        //    } 
        //     else{
        //         v.push_back(arr[r]);
        //         if(r == arr.size()-1)
        //             arr[r]=INT_MAX;
        //         else
        //             r++;
        //     }
        // }
        // sort(v.begin(),v.end());
        // return v;
        
        int left = 0;
int right = arr.size() - k;
while (left < right) {
int mid = ((right - left) >> 1) + left;
if (x - arr[mid] > arr[mid + k] - x)
left = mid + 1;
else
right = mid;
}
return vector(arr.begin() + left, arr.begin() + left + k);
    }
};