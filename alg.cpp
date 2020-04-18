int countPairs1(int *arr, int len, int value)
{
    int result = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++) 
        {
            if (arr[i] + arr[j] == value) 
            {
                result++;
            }
        }
    }
    return result; 
}

int countPairs2(int *arr, int len, int value)
{
    int result = 0;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = len - 1; i < j; j--) 
        {
            if (arr[i] + arr[j] == value) 
            {
                result++;
            }
        }
    }
    return result;
}

int countPairs3(int* arr, int len, int value)
{
	int count = 0;
	int l;
	int r;
	int mid;

	for (int i = 0; i < len; i++)
	{
		l = i + 1;
		r = len - 1;
		mid = (r - l) / 2;
		while (l<=r)
		{
			mid = (r + l) / 2;
			if (arr[i] + arr[mid] == value)
			{
				count++;
				int k = mid + 1, k_1 = mid - 1;
				while (arr[i] + arr[k]==value&&k<=r)
				{
					count++;
					k++;
				}
				while (arr[i] + arr[k_1]==value&&k_1>i)
				{
					count++;
					k_1--;
				}
				break;
			}
			else if (arr[i] + arr[mid] < value)
			{
				l = mid+1;
			}
			else
			{
				r = mid-1;
			}
		}
	}
	return count;
}
