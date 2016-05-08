int knapsack( int *val, int *wt, int W, int n )
{
    if( W==0 || n==0 )
      return 0;
    int table[n+1][W+1];
    int i,w;
    for( i=0; i<=n;i++ )
    {
      for( w = 0; w<=W; w++ )
      {
        if(i==0 || w==0 )
          table[i][j] = 0;
        else
        {
          if(wt[i-1]>w)
            table[i][w] = table[i-1][w];
          else
          {
          table[i][j] = max( val[i-1] + table[i-1][j-wt[i-1]], table[i-1][j] );
          }
        }
      }
    }
    return table[n][W];
  }
