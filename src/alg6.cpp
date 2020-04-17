int countPairs1(int *arr,int len,int value)
{
    int search=0;
	for (int i = 0; i < len; i++){
        	for (int j = 0; j < len; j++){
            		if (arr[i] + arr[j] == value){
            		search++;
            		}
    	}
    	}
	return search;
}
int countPairs2(int *arr,int len,int value)
{
	int search =0;
	while (*arr < len-1) {
		int s = arr[*arr] + arr[len-1];
		if (s == value) {
			search ++;
			*arr++;
			len--;
		} else {
			if (s < value)
			*arr++;
			else len--;
		}
	}
	return search;
}
int countPairs3(int *arr,int len,int value)
{
	int search =0;
	for (int i = 0; i < array.Length; i++){
		int mid = *arr + (len - *arr) / 2;
		if (array[i] + array[mid] == value){
		search =+1;
        	return countPairs3(mid + 1, len, value);
		}
		else if (array[mid] > value){
        	return countPairs3(*arr, mid, value);
		}
    		else{
       		return countPairs3(mid + 1, len, value);
		}
	}
	return search;
}
