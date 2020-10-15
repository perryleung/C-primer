int AddFrom1ToN_Recursive(int n)
{
    return n <= 0 ? 0 : n + AddFrom1ToN_Recursion(n - 1);
}

int AddFrom1ToN_Iterative(int n)
{
    int result = 0;
    for (int i = 0; i <= n; i++){
        result += i;
    }
    return result;
}