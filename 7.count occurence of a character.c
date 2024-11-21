#include <stdio.h>

int countCharOccurrences(const char *str, char target) {
    int count = 0;

    // Traverse the string and count occurrences of the target character
    while (*str != '\0') {
        if (*str == target) {
            count++;
        }
        str++;
    }

    return count;
}

int main() {
    char str[100], target;

    // Ask the user to input a string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove the trailing newline character if fgets is used
    str[strcspn(str, "\n")] = '\0';

    // Ask the user to input the character to count
    printf("Enter the character to count: ");
    scanf("%c", &target);

    // Call the function to count the occurrences
    int count = countCharOccurrences(str, target);

    // Print the result
    printf("The character '%c' appears %d times in the string.\n", target, count);

    return 0;
}
