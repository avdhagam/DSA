class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    struct data
    {
        int start;
        int end;
        int pos;
    };
    static bool comp(data var1, data var2)
    {
        return var1.end < var2.end;
    }
    int maxMeetings(int n, int start[], int end[])
    {
        // Your code here
        vector<data> arr(n);
        for (int i = 0; i < n; i++)
        {
            arr[i].start = start[i];
            arr[i].end = end[i];
            arr[i].pos = i + 1;
        }

        sort(arr.begin(), arr.end(), comp);

        int free = arr[0].end;
        vector<int> ans;
        ans.push_back(arr[0].pos);
        for (int i = 1; i < n; i++)
        {
            if (free < arr[i].start)
            {
                ans.push_back(arr[i].pos);
                free = arr[i].end;
            }
        }
        return ans.size();
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends