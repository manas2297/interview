//Moore Algo

int majorityElement(int a[], int size)
    {
        
        // your code here
        int count = 0; 
        int ele= 0;
        for(int i=0;i<size;i++){
            if(count == 0)ele = a[i];
            if(a[i]==ele)count++;
            else count--;
        }
        count=0;
        for(int i = 0; i<size;i++) {
            if(ele == a[i])count++;
        }
        
        if(count>(size/2)) return ele;
        return -1;
    }