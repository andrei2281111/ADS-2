int countPairs1(int* arr, int len, int value) {
    int search = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if ((arr[i] + arr[j]) == value) {
                search = search + 1;
            }
        }
    }
    return search;
}
int countPairs2(int* arr, int len, int value) {
    int search = 0;
    int i = 0;
    int k;
    int j = len - 1;
    while (true) {
        if (i == j)
            return search;

        else if (arr[i] + arr[j] < value)
            i = i + 1;

        else if (arr[i] + arr[j] > value)
            j = j - 1;

        else  if (arr[i] + arr[j] == value) {
            search = search + 1;
            for (k = i + 1; k < j; k++) {
                if (arr[k] + arr[j] == value)
                    search = search + 1;

            }
            j = j - 1;
        }
    }
}
int countPairs3(int* arr, int len, int value) {
    int search = 0;
    cout << endl << "countPairs3 ";
    
    for (int i = 0; i < len-1; i++)
    {
        int first = i;
        int last = len ;
       
        while (first < last) {
            int mid = first + (last - first) / 2;
            if (arr[mid] + arr[i] == value && mid > i) {
                search = search + 1;
                cout << endl << search << " :mid: " << arr[mid] << " + " << arr[i];
                int k = 1;
                while ((arr[mid + k] + arr[i]) == value && ((mid + k)<last)) {
                    search = search + 1;
                    cout << endl << search << " :mid + k: " << arr[mid + k] << " + " << arr[i];
                    k++;
                }
                k = 1;
                while ((arr[mid - k] + arr[i]) == value && ((mid - k) >first)) {
                    search = search + 1;
                    cout << endl << search << " :mid - k: " << arr[mid - k] << " + " << arr[i];
                    k++;
                }
                break;
            }
            if (arr[mid] + arr[i] > value)
                last = mid ;
            else first = mid;
        }
    }
    return search;
}
