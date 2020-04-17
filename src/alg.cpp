int countPairs1(int *arr,int len,int value)
{
int n = 0;
int a = 0;
  for (int i = 0; i < len-1; i++)
  {
  a = arr[i];
    for (int j = 1; j < len; j++)
    {
    if (a + arr[j] == value)
    n++;
    }
  }
return n;
}



int countPairs2(int *arr,int len,int value)
{
int n = 0;
  for (int i = 0; i < len - 1; i++)
  {
    for (int j = len - 1; j > i; j--)
    {
      if (arr[i] + arr[j] == value)
      {
      n++;
      }
    }
  }
return n;
}



int countPairs3(int *arr,int len,int value)
{
int a = 0;
 for (int i = 0; i < len; i++)
 {
 a = value-arr[i];
 int q=0, i=0, left = 0;
 int right = size-1;
  
  while (left <= right)
  {
    int mid = (left + right) / 2;
    if (a == arr[mid])
    {
      q++;
      i=mid;
    }
    if (arr[mid] < a) {left = mid + 1;}
    else {right = mid - 1;}
  } 
  
  if (q>0)
  {
    int q_same=0;
    while(arr[i]==a)
    {
      q_same++;
      i++;
    }
  }
  
} 
a = 0;
a = q+q_same-1;
return a;
}
