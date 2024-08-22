int f(int mid, vector<int> &board)
{
    int painter = 1;
    int hours = 0;
    for (int i = 0; i < board.size(); i++)
    {
        if (hours + board[i] <= mid)
        {
            hours += board[i];
        }
        else
        {
            painter++;
            hours = board[i];
        }
    }
    return painter;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (f(mid, boards) <= k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}