int rec_sum_c(int *a, int len)
{
    if (len == 0) {
        return 0;
    } else {
        return a[0] + rec_sum_c(a + 1, len - 1);
    }
}
