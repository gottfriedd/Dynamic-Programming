class Solution {
public:
    int isPresent(const string &temp, unordered_set<string>& wordDict )
    {
        if(wordDict.find(temp) != wordDict.end())
            return 1;
        else
            return 0;
    }
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int j,k,l,i,n = s.size();
        int **table;
        table = (int **)malloc(n*sizeof(int *));
        for(i=0;i<n;i++)
            table[i] = (int *)malloc(n*sizeof(int));
        for(i=0;i<n;i++){
           if(isPresent(s.substr(i,1), wordDict))
                table[i][i] = 1;
            else
                table[i][i] = 0;
        }
        for(l=2;l<=n;l++)
        {
            for(i=0,j=l+i-1;j<n;i++,j++)
            {
                for(k=i;k<=j;k++)
                {
                    if(k==j)
                        table[i][k] = isPresent(s.substr(i,l), wordDict);
                    else
                    {
                        if(table[i][k] && table[k+1][j]){
                            table[i][j] = 1;                
                            break;
                        }
                    }
                }
            }
        }
        return table[0][n-1];
    }
};
