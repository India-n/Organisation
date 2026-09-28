#include <stdio.h>
#include <string.h>

int linear(char a[][20], int n, char key[])
{
    int i, c = 0;

    for(i = 0; i < n; i++)
    {
        c++;

        if(strcmp(a[i], key) == 0)
            return c;
    }

    return c;
}

int binary(char a[][20], int n, char key[])
{
    int low = 0, high = n - 1;
    int mid, c = 0;

    while(low <= high)
    {
        mid = (low + high) / 2;
        c++;

        if(strcmp(a[mid], key) == 0)
            return c;

        if(strcmp(key, a[mid]) < 0)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return c;
}

int main()
{
    char a[8][20] = {
        "Backend",
        "CEO",
        "Development",
        "Finance",
        "Frontend",
        "HR",
        "IT",
        "Testing"
    };

    char key[20];

    printf("Enter department: ");
    scanf("%s", key);

    printf("Linear Search Comparisons = %d\n",
           linear(a, 8, key));

    printf("Binary Search Comparisons = %d\n",
           binary(a, 8, key));

    return 0;
}
