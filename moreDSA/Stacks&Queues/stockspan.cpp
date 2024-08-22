class StockSpanner
{
public:
    stack<pair<int, int>> st;
    vector<int> ans;
    int ind;

    StockSpanner()
    {
        ind = -1;
    }

    int next(int price)
    {

        ind++;
        if (ans.size() <= ind)
        {
            ans.push_back(0);
        }

        while (!st.empty() && st.top().first <= price)
            st.pop();

        ans[ind] = ind - (st.empty() ? -1 : (st.top().second));
        st.push({price, ind});
        return ans[ind];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */