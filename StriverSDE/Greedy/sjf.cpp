long long solve(vector<int> &bt)
{
    // code here
    sort(bt.begin(), bt.end());
    long long wtime = 0;
    long long t = 0;
    long long n = bt.size();
    for (auto i : bt)
    {
        wtime += t;
        t += i;
    }
    return wtime / n;
}
}
;