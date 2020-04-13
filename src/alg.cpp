#include <iostream>
using namespace std;

int cbinsearch(int *arr, int size, int value)
{
   int index=-1;
    int left = 0;
    int right = size-1;
    while (left <= right)
      {
            int mid = (left + right) / 2;
            if (value == arr[mid])
                  return mid;
            else if (arr[mid] < value)
                left = mid + 1;
            else  right = mid - 1;
      }

return index;
}

int countPairs1(int *arr,int len,int value)
{
    int n=0;
    for (int i = 0; i < len-1; i++)
    {
        for (int j = i + 1; j < len; j++)
		{
			if (arr[i] + arr[j] == value)
				n++;
		}
	}
return n;
}

int countPairs2(int *arr,int len,int value)
{
	int n = 0;
	 for (int i = 0; i < len-1; i++)
	 	for (int j = len-1; j > i; j--)
			if (arr[i] + arr[j] == value)
		 		n++;
	 return n;
}

int countPairs3(int *arr,int len,int value)
{
    int n = 0;
    for (int i = 0; i < len-1; i++)
    {
    int first = arr[i];
    int second = value - first;
    int index = cbinsearch(arr,len,second);
   if (index >= 0 && index > i)
			n++;
		if (index < 0)
			continue;
	}
    return n;
}
