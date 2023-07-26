long long int mergeSort(long long arr[], long long temp[], int left, int right) {
        long long int count = 0;
        int mid;
        
        if(left <right){
            mid = (right + left)/2;
            count += mergeSort(arr, temp, left, mid);
            count += mergeSort(arr, temp, mid+1, right);
            
            count += merge(arr, temp, left, mid+1, right);
        }
        return count;
    }
    
    long long int merge(long long arr[], long long temp[], int left, int mid,int right) {
        long long int count = 0;
        int i = left;
        int j = mid;
        int k = left;
        
        while((i<= (mid-1)) && j <= right) {
            if(arr[i]<= arr[j]) {
                temp[k++] = arr[i++];
            }else {
                temp[k++] = arr[j++];
                
                count += (mid-i);
            }
        }
        
        while(i<= mid-1)
        temp[k++] = arr[i++];
        while(j<=right)
        temp[k++]= arr[j++];
        
        for(int i = left; i<=right; i++) {
            arr[i]=temp[i];
        }
        return count;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int temp[N];
        return mergeSort(arr, temp, 0, N-1);
        
    }
