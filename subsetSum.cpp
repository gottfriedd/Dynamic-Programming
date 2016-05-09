int subsetSum(int *arr, int sum, int l,int n)
{
  if(n==0)
    return 0;
  if(sum==0)
    return 1;
  int table[n+1][sum+1]
  
  int i,j;
  
  for(s=0;s<=sum;s++)
    table[0][s] = 0;
  for(i=0;i<=n;i++)
    table[i][0] = 1;
    
  for(i = 1; i<=n; i++ )
  {
    for(int s=1;s<=sum; s++)
    {
      if(arr[i-1]>s)
        table[i][s] = table[i-1][s];
      else
      {
        table[i][s] =  table[i-1][s] || table[i-1][j-arr[i-1]];
      }
    }
  }
  return table[n][sum];
        
    
