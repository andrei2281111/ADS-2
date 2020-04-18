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

int countPairs3(int *arr, int len, int value)
{
    int result = 0;
    for (int i = 0; i < len; i++)
    {
        int search = value - arr[i];
        int middle = ((len - i)/2) + i;
        for (int start = i, end = len; middle != start || middle != end; middle = ((end - start) / 2) + start)
        {
            if (arr[middle] == search)
            {
                for (; arr[middle] == search; middle--) { }
                for (; arr[++middle] == search; result++) { }
                break;
            }
            if (arr[middle] < search)
            {
                start = middle;
            }
            else
            {
                end = middle;
            }
        }
    }
    return result;
}
