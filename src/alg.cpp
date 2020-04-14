int countPairs1(int* arr, int len, int value)
{
    int c{ 0 };
    for (int i = 0; i < len; ++i)
    {
        int dif = value - arr[i];
        for (int j = 0; j < len && (i != j); ++j)
            if (arr[j] == dif)
            {
                ++c;
            }
    }
    return c;
}

int countPairs2(int* arr, int len, int value) 
{
    int c{ 0 };
    for (int i = 0; i < len;++i)
    {
        int def = value - arr[i];
        for (int j = i + 1; j < len && arr[j] <= def; ++j)
            if (def == arr[j])
            {
                ++c;;
            }
        for (int j = i - 1; j >= 0 && arr[j] >= def; --j)
            if (def == arr[j])
            {
                ++c;
            }
    }
    return c/2;
}

int countPairs3(int* arr, int len, int value)
{
    int c{ 0 };
    for (int i = 0; i < len; ++i)
    {
        int def = value - arr[i];
        c += cbinsearch(arr, len, def);
        if (def == arr[i])
            --count;
    }
    return c/2;
}
