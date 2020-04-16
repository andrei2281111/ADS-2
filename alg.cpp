void SortMass(int *arr) {
    int size=9;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int number = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = number;
            }
        }
    }
    
}

int Pairs1(int* arr, int len, int value) {
    int search = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if ((arr[i] + arr[j]) == value) {
                search = search+1;
            }
        }
    }
    return  search;
}
int Pairs2(int* arr, int len, int value) {
    int search = 0;
    int i = 0;
    int k;
    len = 9;
    int j = len - 1;
    while (true) {
    if (i == j)
        return search;
    
    else if (arr[i] + arr[j] < value)
            i = i + 1;

        else if (arr[i] + arr[j] > value)
            j = j - 1;

        else  if (arr[i] + arr[j] == value){
        search = search + 1;
            for (k = i + 1; k < j; k++) {
                if (arr[k] + arr[j] == value)
                    search = search + 1;

            }
            j = j - 1;
        }
    }
}

int Pairs3(int* arr, int len, int value) {
    int search = 0;
    for (int i = 0; i < len; i++)
    {
        int first = 0;
        int last = len - 1;
        
        while (first <= last) {
            int mid = first + (last - first) / 2;
            if (arr[mid]+arr[i] == value&&arr[mid]>i) {
                search = search + 1;
                int k = 1;
                while ((arr[mid + k] + arr[i]) == value&&((mid + k)<=last)){
                    search = search + 1;
                    k++;
                }
                k = 1;
                while ((arr[mid - k] + arr[i]) == value&&((mid - k)>i)) {
                    search = search + 1;
                    k++;
                    
                }
                break;
                
            }

            if (arr[mid]+arr[i] < value)
                first = mid + 1;
            else last = mid - 1;
        }

        
    }
    return search;
}
