  int totalFruits(vector<int> &arr) {
    int maxlen=0;
    int l=0;
    int r=0;
    map<int,int> mp;
    while(r<arr.size()){
        mp[arr[r]]++;
        while(mp.size()>2){
            mp[arr[l]]--;
            if(mp[arr[l]]==0){
                mp.erase(arr[l]);
            }
            l++;
        }
        if(mp.size()<=2){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
    }