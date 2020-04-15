int countPairs1(int* arr, int len, int value)
{
int n = 0;
for (int i = 0; i < len-1; i++)
{
for (int j = i + 1; j < len; j++)
{
if (arr[i] + arr[j] == value)
n++;
}
}

return n;
}
int countPairs2(int* arr, int len, int value)
{
int n = 0;
for (int i = 0; i < len - 1; i++)
{
for (int j = len - 1; j > i; j--)
{
if (arr[i] + arr[j] == value){
n++;}
}
}
return n;
}
int countPairs3(int* arr, int len, int value){
int n = 0;
for (int i = 0; i < len - 1; i++){
int left = i, right = len;
while (left < right-1){
int mid = (left + right) / 2;
if (arr[i] + arr[mid] == value){
n++;
int j = mid+1;
while (arr[i] + arr[j] == value && j <right){
n++;
j++;
}
j = mid - 1;
while (arr[i] + arr[j] == value && j>left){
n++;
j--;
}
break;
}
if (arr[i] + arr[mid] > value)
right = mid;
else
left = mid;
}
}
return n;
}
