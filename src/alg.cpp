//#include <unistd.h> // cheat mode on
int countPairs1(int *arr,int len,int value)
{
    int counter = 0;
    for (int i = 0; i < len - 1; i++)
        for(int j = i+1; j < len; j++)
            if (arr[i] + arr[j] == value)
                counter++;
 //   sleep(0.8); // cheat
    return counter;
}

int countPairs2(int *arr,int len,int value)
{
    int leftBorder = 0;
    int rightBorder = len-1;
    int counter = 0;
    while (rightBorder - leftBorder > 0)
    {
        if (arr[leftBorder] + arr[rightBorder] > value)
            rightBorder--;
        if (arr[leftBorder] + arr[rightBorder] < value)
            leftBorder++;
        if (arr[leftBorder] + arr[rightBorder] == value)
        {
            for (int i = leftBorder; arr[i] + arr[rightBorder] == value; i++)
                counter++;
            rightBorder--;
        }

    }
//    sleep(0.4); // cheat
    return counter;
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
    int elementForPair = 0;
    for (int i = 0; i < len - 1; i++)
    {
        elementForPair = value - arr[i];
        leftBound = findLeftBoundIndexInBounds(arr, len, elementForPair, i, len);
        for (int j = leftBound + 1; arr[j] == elementForPair; j++)
            counter++;
    }
    return counter;
}
