class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())return 0;
        bool f[256];
        memset(f,0,sizeof(f));
        queue<char> Q;
        unsigned int ans = 0;
        for(int i=0;i<s.size();++i){
            if(Q.empty()){Q.push(s[i]);f[s[i]] = 1;}
            else if(!f[s[i]]){
                f[s[i]] = 1;
                Q.push(s[i]);
            }else{
                ans = max(ans,Q.size());
                while(Q.front()!=s[i]){
                    f[Q.front()] = 0;
                   Q.pop();
                }
                Q.pop();
                Q.push(s[i]);
            }
        }
        return max(ans,Q.size());
    }

};
