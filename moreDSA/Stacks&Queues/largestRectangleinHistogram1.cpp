class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        int leftsmall[n];
        int rightsmall[n];
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                leftsmall[i] = 0;
            }
            else
                leftsmall[i] = st.top() + 1;
            st.push(i);
        }

        while (!st.empty())
        {
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                rightsmall[i] = n - 1;
            }
            else
                rightsmall[i] = st.top() - 1;
            st.push(i);
        }

        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
        }

        return maxi;
    }
};