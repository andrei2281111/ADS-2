int cbinsearch(int* arr, int size, int value)
{
	int left = 0;
	int right = size - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] == value) {
			
			return mid;
		}

		else if (arr[mid] < value)
			left = mid + 1;
		else if (arr[mid] > value)
			right = mid - 1;
	}
	return -1;
}


int countPairs1(int* arr, int len, int value)
{
	int count = 0;
	for (int i = 0; i < len; i++) {
		for (int j = len - 1; j > 0; j--)
		{
			if ( (arr[i] + arr[j] == value) && (arr[i]!=arr[j]) && (i != j))
				count++;
		}
	}
	return count/2;
}
int countPairs2(int* arr, int len, int value)
{
	int k = 0;
 for (int i = 0; i < len-1; i++)
 {
   for (int j = len-1; j > i; j--)
   {
     if (arr[i] + arr[j] == value)
     {
       k++;

     }
   }
 }
 return k;
}
int countPairs3(int* arr, int len, int value)
{
	int key = 0, count = 0;
	for (int i = 0; i < len; i++) {
		key = value;
		key = key - arr[i];
		int x = cbinsearch(arr, len, key);
		if (x >= 0 && x > i)
			count++;
		if (x < 0)
			continue;
	}
	return count;
} 
