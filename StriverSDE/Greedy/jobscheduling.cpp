class Solution
{
public:
    static bool comp(Job var1, Job var2)
    {
        return var1.profit > var2.profit;
    }
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        vector<Job> jobs(arr, arr + n);
        sort(jobs.begin(), jobs.end(), comp);
        int cnt = 0;
        int maxdeadline = -1;
        int maxprof = 0;
        for (int i = 0; i < n; i++)
        {
            maxdeadline = max(maxdeadline, jobs[i].dead);
        }

        vector<int> hash(maxdeadline + 1, -1);

        for (int i = 0; i < n; i++)
        {
            for (int j = jobs[i].dead; j >= 1; j--)
            {
                if (hash[j] == -1)
                {
                    hash[j] = jobs[i].id;
                    cnt++;
                    maxprof += jobs[i].profit;
                    break;
                }
            }
        }
        return {cnt, maxprof};
    }
};

//{ Driver Code Starts.
// Driver program to test methods
int main()
{
    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;
        Job arr[n];

        // adding id, deadline, profit
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        // function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends