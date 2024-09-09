class Solution
{
public:
    static bool comp(Item val1, Item val2)
    {
        return (double(val1.value) / double(val1.weight)) >= (double(val2.value) / double(val2.weight));
    }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr + n, comp);
        double val = 0.0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].weight <= w)
            {
                val += arr[i].value;
                w = w - arr[i].weight;
            }
            else
            {
                val += (double(arr[i].value) / double(arr[i].weight)) * w;
                break;
            }
        }
        return val;
    }
};
