class Solution {
public:
        int lcs(string s1,string s2) 
{
    int n = s1.size();
    int m = s2.size();
    int t[n+1][m+1];
    
    for(int i =0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0 || j==0)
                t[i][j] = 0;
        }
    }
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(s1[i-1]==s2[j-1])
                t[i][j] = t[i-1][j-1] + 1;
            else
                t[i][j] = max(t[i][j-1],t[i-1][j]);
        }
    }
    return t[n][m];
}

int minDistance(string word1, string word2) {
    
    int n = word1.size();  
    int m = word2.size(); 
    
    int ans = lcs(word1,word2);
    return (n+m) - (2*ans); 
    
}
};