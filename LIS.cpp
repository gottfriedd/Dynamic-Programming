int findCeil(int *arr, int *tail, int n, int key)
{
  int l = 0, r = n;
  while(l<r)
  {
    int mid = (l+r)>>1;
    if(key==arr[tailIndices[mid]])
        return mid;
    else if(key>arr[tailIndices[mid]])
      l = mid+1;
    else
      r = mid;
  }
  return r;
}
int LIS(int *arr, int n)
{
  int tailIndices[n], prevIndices[n], len =1,j,k;
  tailIndices[0] = 0; 
  prevIndices[0] = -1;
  
  for(i=1;i<n;i++)
  {
    if(arr[i] < arr[tailIndices[0]])
    {
      tailIndices[0] = i;
      prevIndices[i] = -1;
    }
    else if(arr[i] > arr[tailIndices[len-1]])
    {
      prevIndices[i] = tailIndices[len-1]; 
      tailIndices[len++] = i;
    }
    else
    {
      pos = findCeil(arr, tailIndices, len-1,arr[i]);
      tailIndices[pos] = i;
      prevIndices[pos] = tailIndices[pos-1];
    }
  }
  
  //Printing
  
  for(i=tailIndices[len-1];i>=0;i = preIndices[i])
    cout<<arr[i]<<" ";
  
