int countPairs1(int argc, char** argv)
{
    int s;
    cin >> s;
    const int n=10000;
    int A[n] = { 2,7,15,4,9,97,1,3,8,10 };
    for (int i = 0; i <n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (A[j + 1] < A[j])
            {
                int tmp;
                tmp = A[j + 1];
                A[j + 1] = A[j];
                A[j] = tmp;
            }
        }
    }
    int counter = 0;
    int lk = 0;
    int pk = 10;
    for (lk = 0, pk = 10; lk < 10 && pk>0; lk++, pk++)
        if (A[lk + pk] == s)
            counter++;
    {
        cout << counter;
    }
    system("pause");
    return 0;
}
