[ 1, 2, 3, 7, 9 ], target sum = 11

                              [1, 1, 3, 7, 9],
                          return [ 1, 9 ] or [ 3, 7 ] map->

                                             for (auto i : arr)
{
    target - i
    {
    }
}
1 1, 3, 7, 9, 11, 12, 13 targ = 10

                      l,
                         r mid

                             mid = l + r / 2

                                           if (arr[i] <= mid)
{
    ans = mid
        r = mid - 1;
}
if (arr[i] > mid)
{
    l = mid + 1;
}
vector < pair < int, int >>

                         1,
    3, 7, 9, 11, 13 target = 21

                     [9, 11][7, 13]

                 for ()

                     i = 0 targ = 21 - arr[i] = 21 - 1 = 20 i = 1 tar = 21 - 3 = 18 i = 2 tar = 21 - 7 = 14 i = 3 tar = 21 - 9 = 12 i = 4 tar = 21 - 11 = 10 O(n) 20,
                    16, 20, 20 21 tbs(3, 7, 9, 11, 13) 20 [13, arr[i]] = tbs(1)(7, 9, 11, 13) 18 13, 3 tbs(1, 3) tbs(9, 11, 13) 13, 7 tbs(1, 3, 7) tbs(11, 13) 11, 9(1, 3, 7, 9)tbs(13) O(logn)

                                                                                                                                                                       if (arr[i] <= mid)
{
    ans = mid
        r = mid - 1;
}
if (arr[i] > mid)
{
    l = mid + 1;
}
