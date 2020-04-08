int countPairs1(int* arr, int len, int value)
{
	del(arr, len);
	sort(arr, len);
	int k = 0;
	for (int i = 0; i < len; i++)
	{
		int j = 0;
		while ((j < len) && (arr[i] + arr[j] != value))
			j++;
		if ((arr[i]!=-1)&&(arr[j]!=-1)&&(arr[i] + arr[j] == value))
			k++;
	}
	return k;
}
int countPairs2(int* arr, int len, int value)
{
	del(arr, len);
	sort(arr, len);
	int i = 0, n = 0, k = 0;
	while ((i < len) && (arr[i] == -1))
	{
		i++;
		n++;
	}
	for (int i = n; i < len; i++) 
	{
		for (int j = len; j >= n; j--)
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
	del(arr, len);
	sort(arr, len);
	int i = 0, n = 0, k = 0;
	while ((i < len) && (arr[i] == -1))
	{
		i++;
		n++;
	}
	for (int i = n; i < len; i++)
		if (cbinsearch(arr, len, value - arr[i]))
			k++;
	return k;
}
void del(int* arr, int len)
{
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
			if ((i!=j)&&(arr[i] == arr[j])) arr[j] = -1;
}

void sort(int* arr, int len)
{
	int swap;
	int j = 0;
	while (j<len) {
		int minind = j;
		int cur = minind + 1;
		while (cur<len) {
			if (arr[cur] < arr[minind]) minind = cur;
			cur++;
		}
		swap = arr[j];
		arr[j] = arr[minind];
		arr[minind] = swap;
		j++;
	}
}

int cbinsearch(int* arr, int size, int value)
{
	int k = 0;
	int left = 0, right = size, mid = (left + size) / 2;
	while (left <= right)
	{
		if (arr[mid] == value)
		{
			k += 1;
			break;
		}
		if (arr[mid] < value)
		{
			left = mid + 1;
			mid = (left + right) / 2;
		}
		if (arr[mid] > value)
		{
			right = mid - 1;
			mid = (left + right) / 2;
		}
	}
	k = arr[mid];
	if (k == value) return k;
	else return 0;
}
