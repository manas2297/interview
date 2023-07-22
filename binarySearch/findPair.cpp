// Given an array Arr[] of size L and a number N, you need to write a program to find if there exists a pair of elements in the array whose difference is N.
bool findPair(int arr[], int size, int n){
    //code
    
    int l = 0;
    int h = size-1;
    int find_n;
    bool ans = false;
    sort(arr, arr+size);
    for(int i=size-1;i>=0;i--) {
        find_n = abs(n-arr[i]);
        l=0;
        h=i-1;
        
        
        while(h>=l){
            int mid = l + (h-l)/2; 
            if(arr[mid]==find_n){
                ans= true;
                break;
            }else if(arr[mid]>find_n)
                h = mid-1;
                else 
                l=mid+1;
        }
        if (ans) break;
        
    }
    return ans;
    
}