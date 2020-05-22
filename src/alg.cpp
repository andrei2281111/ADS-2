int countPairs1(int* arr, int len, int value)
{
int f = 0;
for (int i = 0; i < len-1; i++)
{
for (int j = i + 1; j < len; j++)
{
if (arr[i] + arr[j] == value)
f++;
}
}

return f;
}
int countPairs2(int* arr, int len, int value)
{
int a = 0;
for (int i = 0; i < len - 1; i++)
{
for (int j = len - 1; j > i; j--)
{
if (arr[i] + arr[j] == value){
a++;}
}
}
return a;
}
int countPairs3(int* arr, int len, int value){
int c = 0;
for (int i = 0; i < len - 1; i++){
int left = i, right = len;
while (left < right-1){
int mid = (left + right) / 2;
if (arr[i] + arr[mid] == value){
c++;
int j = mid+1;
while (arr[i] + arr[j] == value && j <right){
c++;
j++;
}
j = mid - 1;
while (arr[i] + arr[j] == value && j>left){
c++;
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
return c;
}
