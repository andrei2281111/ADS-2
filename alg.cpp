int countPairs1(int* arr, int len, int value) {
    int search = 0;
    for (int i = 0; i<len-1; i++) {
        for (int j = i+1; j<len; j++) {
            if (arr[i]+arr[j]==value) {
                search++;
            }
        }
    }
    return search;
}
int countPairs2(int* arr, int len, int value) {
    int search = 0;
    int i = 0;
    int k;
    int j = len-1;
    while (true) {
        if (i == j)
            return search;
        else if (arr[i]+arr[j] <value)
            i++;
        else if (arr[i]+arr[j] >value)
            j--;
        else  if (arr[i]+arr[j]==value) {
            search++;
            for (k = i+1; k<j; k++) {
                if (arr[k]+arr[j]==value)
                    search++;
            }
            j = j - 1;
        }
    }
}
int countPairs3(int* arr, int len, int value)
{int search = 0;
    for (int i = 0; i<len-1; i++)
    {
        int first = i;
        int last = len;
        while (first<last-1){
            int mid = (first+last)/2;
            if (arr[mid]+arr[i]==value)
            {
                search++;
                int k = mid+1;
                while (arr[k]+arr[i]==value && k<last)
                {
                    search++;
                    k++;
                }
                k = mid-1;
                while (arr[k]+arr[i]==value && k>first)
                {
                    search++;
                    k--;
                }
                break;
            }
            if (arr[mid]+arr[i]>value)
                last = mid;
            else first = mid;
        }
    }
    return search;
}
