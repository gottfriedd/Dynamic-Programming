void wordWrap(vector<strings> &s1, int width)
{
  int s = s1.size();
  int table[s][s],i,j;
    
  for(i=0;i<s;i++)
  {
    int len = 0;
    for(j=i;j<s;j++)
    {
      len+=(s1[j].length());
      table[i][j] = len<=10?(10-len)*(10-len):120;
    }
  }
  int travel[s],cost[s] = {10000};
  
  for(i=s-1;i>=0;i--)
  {
    if(table[i][s-1]<100)
    {
      cost[i] = table[i][s-1];
      travel[i] = s;
    }
    else{
      for(j=s-1;j<i;j--)
      {
          if(table[i][j-1]<100){
            if( cost[i] > table[i][j-1]+table[j][s-1] )
            {
              travel[i] = j;
              cost[i] = table[i][j-1]+table[j][s-1];
            }
          }
        }
    }
  }
  i=0;
  while(i<s)
  {
    j=i;
    while(j<travel[i]){
      cout<<s1[j]<<" "
      j++;
      }
    i = travel[i];
  }
    
    
    
    
