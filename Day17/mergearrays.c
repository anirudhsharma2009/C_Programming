#include <stdio.h>

int main(void)
{
    int n1, n2, i;

    printf("Enter size of first array: ");
    if (scanf("%d", &n1) != 1 || n1 < 0)
        return 0;

    int a[n1];
    printf("Enter %d elements: ", n1);
    for (i = 0; i < n1; i++)
        scanf("%d", &a[i]);

    printf("Enter size of second array: ");
    if (scanf("%d", &n2) != 1 || n2 < 0)
        return 0;

    int b[n2];
    printf("Enter %d elements: ", n2);
    for (i = 0; i < n2; i++)
        scanf("%d", &b[i]);

    int m = n1 + n2;
    int c[m];

    for (i = 0; i < n1; i++)
        c[i] = a[i];
    for (i = 0; i < n2; i++)
        c[n1 + i] = b[i];

    printf("Merged array: ");
    for (i = 0; i < m; i++)
        printf("%d ", c[i]);
    printf("\n");

    return 0;
}
