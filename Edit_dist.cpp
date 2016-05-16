
int minEditDist(char *str1, char *str2, int n, int m)
{
    if(n==0)
      return m;
    if(m==0)
      return n;
    
    if(str1[n-1]==str2[m-1])
      return minEditDist(str1,str2,n-1,m-1);
    
    return 1+ min(minEditDist(str1,str2,n-1,m-1),//replace
                    minEditDist(str1,str2,n,m-1),//insert
                    minEditDist(str1,str2,n-1,m));//remove
                    
  
}

DP soln

int minEditDist(char *str1, char *str2, int n, int m)
{
  int table[n+1][m+1],i,j,k;
  
  for(i=0;i<=n;i++)
    table[i][0] = i;
    
  for(i=0;i<=m;i++)
    table[0][i] = i;
  
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=m;j++)
    {
      if(str1[i] == str2[j])
          table[i][j] = table[i-1][j-1];
      else
        table[i][j] = min( table[i-1][j-1],min(table[i][j-1],table[i][j-1]));
    }
  }
}
