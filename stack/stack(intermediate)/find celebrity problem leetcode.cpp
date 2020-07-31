int findCelebrity(int n)
{
    int candidate = 0;
    for (int i = 1; i < n; ++i)
    {
        if (knows(candidate, i))
        {
            candidate = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i != candidate && (knows(candidate, i) || !knows(i, candidate)))
        {
            return -1;
        }
    }
    return candidate;
}
// if data is given as a matrix
bool knows(int a, int b, int M[MAX][MAX])
{
    return M[a][b];
}
int getId(int M[MAX][MAX], int n)
{
    int candidate = 0;
    for (int i = 1; i < n; ++i)
    {
        if (knows(candidate, i, M))
        {
            candidate = i;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (i != candidate && (knows(candidate, i, M) || !knows(i, candidate, M)))
        {
            return -1;
        }
    }
    return candidate;
}