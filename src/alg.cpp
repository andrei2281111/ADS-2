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
	int k = 0;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = len - 1; j > i; j--)
		{
			if (arr[i] + arr[j] == value)
			{
				k++;
			}
      if (arr[i] + arr[j] < value)
        break;
		}
	}
	return k;
}

int findRightBoundIndexInBounds(int *arr, int n, int element, int leftBound, int rightBound)
{
    if (rightBound == leftBound + 1) return rightBound;
    int middle = (leftBound + rightBound)/2;
    if (arr[middle] <= element)
        return findRightBoundIndexInBounds(arr, n, element, middle, rightBound);
    else 
        return findRightBoundIndexInBounds(arr, n, element, leftBound, middle);
}

int findLeftBoundIndexInBounds(int *arr, int len, int element, int leftBound, int rightBound)
{
    if (rightBound == leftBound + 1)
        return leftBound;
    int midIndex = (leftBound + rightBound) / 2;
    if (arr[midIndex] < element)
        leftBound = midIndex;
    else
        rightBound = midIndex;
    return findLeftBoundIndexInBounds(arr, len, element, leftBound, rightBound);
}

int countPairs3(int *arr,int len,int value)
{
    int counter = 0;
    int leftBound = 0;
    int rightBound = 0;
    int elementForPair = 0;
    for (int i = 0; i < len - 1; i++)
    {
        elementForPair = value - arr[i];
        if (elementForPair < arr[i])
            return counter;
        leftBound = findLeftBoundIndexInBounds(arr, len, elementForPair, i, len);
        rightBound = findRightBoundIndexInBounds(arr, len, elementForPair, i, len);
        counter += rightBound - leftBound - 1;
    }
    return counter;
}
