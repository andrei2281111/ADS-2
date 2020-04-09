int countPairs1(int *arr,int len,int value)
{
int k = 0;
 for (int i = 0; i < len; i++)
 {
   for (int j = 1; j < len; j++)
   {
     if (arr[i] + arr[j] == value)
     k++;
   }
 }
 return k;
}


int countPairs2(int *arr,int len,int value)
{
int k = 0;
 for (int i = 0; i < len; i++)
 {
   for (int j = len; j > i; j--)
   {
     if (arr[i] + arr[j] == value)
     {
       k++;
       len=j;
     }
   }
 }
 return k;
}


int countPairs3(int *arr,int len,int value)
{
int k = 0;
 for (int i = 0; i < len; i++)
 {
    int l = i;
    int mi=(l+r)/2;
    int j;
    int r = len-1;
    int mid=arr[mi];
    
    while ((mid+arr[i]!=value)&&(l<(len-1))&&(r>0))
    {
      if (mid+arr[i]>value)
        {
        r=mi-1;
        mi=(l+r)/2;
        mid=arr[mi];
        }
        else
        if (mid+arr[i]<value)
          {
          l=mi+1;
          mi=(l+r)/2;
          mid=arr[mi];
          }
     }    
          
          
     if (mid+arr[i]==value)
      {
          k++;
          j=mi;
          while (arr[j+1]==mid)
            {
              j++;
              k++;
            }
           j=mi;
          while (arr[j-1]==mid)
            {
              j--;
              k++;
            }
      }       
 }
 return k;
}
