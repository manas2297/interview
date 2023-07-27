// Maximum of all subarrays of size k --> Very important concept

vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        deque<int>q;
        vector<int> res;
        int i =0; // init the window
        int j=0;
        while(j<n) { 
            while(q.size()!=0 && q.back()<arr[j]) { // do calculation
                    q.pop_back();
            }
            q.push_back(arr[j]);
            
            if (j-i+1 < k) { // if window is not yet fixed
                j++;
            }
            else if(j-i+1 == k) { // when window fixed
                res.push_back(q.front()); 
                if(q.front() == arr[i]) {
                    q.pop_front();
                }
                j++;
                i++;
            }
        }
        return res;
    }