class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &a, vector<int> &b)
    {
        unordered_map<int, int> mp;
        stack<int> st;
        vector<int> ans;

        for (int i = b.size() - 1; i >= 0; --i)
        {
            while (!st.empty() && st.top() <= b[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                mp[b[i]] = -1;
            }
            else if (!st.empty())
            {
                mp[b[i]] = st.top();
            }
            st.push(b[i]);
        }

        for (int i = 0; i < a.size(); i++)
        {
            ans.push_back(mp[a[i]]);
        }
        return ans;
    }
};