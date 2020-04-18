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

int countPairs3(int *arr, int len, int value) {

    int res = 0, num2, middle, low, high, step; 

    for (int i=0; i<len; i++) {

        num2 = value - arr[i];

        low = 0;
        high = len-1;

        while (low<=high) {

            middle = (low+high)/2;

            if (num2 == arr[middle]) {
                if (arr[i]!=num2)
               res++;

               step = middle;
               while (step>0) {
                   if (arr[step-1]!=num2) break;
                   else {
                       res++;
                       step--;
                   }
               }
               step=middle;
               while (step<len-1) { 
                   if (arr[step+1]!=num2) break;
                   else {
                       res++;
                       step++;
                   }
               }
               break; 
            }
           else if (num2<arr[middle])
           high = middle - 1;
           else 
           low = middle + 1;
        }
    }
    return res/2;
}
