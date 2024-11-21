#include <stdio.h>
#include <ctype.h>  // For tolower() function

// Function to check if the string is a palindrome
int isPalindrome(char *str) {
    int left = 0, right = 0;

    // First, find the length of the string (ignoring spaces)
    while (str[right] != '\0') {
        right++;
    }
    right--; // Adjust right to point to the last valid character

    // Compare characters from both ends, ignoring spaces and case differences
    while (left < right) {
        // Skip spaces from the left side
        if (isspace(str[left])) {
            left++;
            continue;
        }
        // Skip spaces from the right side
        if (isspace(str[right])) {
            right--;
            continue;
        }

        // Check if characters match, ignoring case
        if (tolower(str[left]) != tolower(str[right])) {
            return 0;  // Not a palindrome
        }

        // Move towards the center
        left++;
        right--;
    }

    return 1;  // It's a palindrome
}

int main() {
    char str[100];

    // Ask the user to input a string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove the trailing newline character if fgets is used
    str[strcspn(str, "\n")] = '\0';

    // Call the function to check if it's a palindrome
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
