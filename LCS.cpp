int longestCommonSubsequence(char *str1, char *str2)
{
  int a = len(str1);
  int b = len(str2);
  
  int table[a+1][b+1];
  
  for(i=0;i<=b;i++)
    table[0][i] = 0;
  for(i=0;i<=a;i++)
    table[i][0] = 0;
    
  for(i=1;i<=a;i++)
  {
    for(j=1;j<=b;j++)
    {
        if(str1[i-1]==str[j-1])
          table[i][j] = table[i-1][j-1]+1;
        else
          table[i][j] = max(table[i-1][j],table[j][i-1]);
    }
  }
  return table[a][b];
  }
