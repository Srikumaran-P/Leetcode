/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) 
{
    char** output = malloc(n * sizeof(char*));
    *returnSize = n;
    for (int i = 0; i < n; i++)
    {
        output[i] = malloc(9 * sizeof(char));
        if ((i + 1) % 3 == 0 && (i + 1) % 5 == 0)
        {
            output[i] = "FizzBuzz";
        }
        else if ((i + 1) % 3 == 0)
        {
            output[i] = "Fizz";
        }
        else if ((i + 1) % 5 == 0)
        {
            output[i] = "Buzz";
        }
        else
        {
            sprintf(output[i], "%d", i + 1);
        }
    }
    return output;

    for (int i = 0; i < returnSize; i++) 
    {
        free(output[i]);
    }
}
