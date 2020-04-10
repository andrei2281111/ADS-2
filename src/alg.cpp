int countPairs1(int *arr,int len,int value)
{
    int counter = 0;
    for (int i = 0; i < len - 1; i++)
        for(int j = i+1; j < len; j++)
            if (arr[i] + arr[j] == value)
                counter++;
    return counter;
}

int countPairs2(int* arr, int len, int value)
{
	int counter = 0;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = len - 1; j > i; j--)
		{
			if (arr[i] + arr[j] == value)
			{
				counter++;

			}
            //if (arr[i] + arr[j] < value)
            //    break;
		}
	}
	return counter;
}

int countPairs3(int *arr, int len, int value)
{
	int counter = 0;
	for (int i = 0; i < len - 1; i++)
	{
		int leftBorder = i;
		int rightBorder = len;
		while (leftBorder < rightBorder -1)
		{
			int mid = (first + rightBorder) / 2;
			if (arr[i] + arr[mid] == value)
			{
				pairs++;
				int j = mid+1;
				while (arr[i] + arr[j] == value && j < rightBorder)
				{
					pairs++;
					j++;
				}
				j = mid - 1;
				while (arr[i] + arr[j] == value && j> first)
				{
					pairs++;
					j--;
				}
				break;
			}
			if (arr[i] + arr[mid] > value)
				last = mid;
			else
				first = mid;
		}
	}
	return pairs;
}
