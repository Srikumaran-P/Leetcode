#include <stdio.h>
#include <ctype.h>  // For the tolower() and toupper() functions

void toggleCase(char *str) {
    int i = 0;
    
    // Iterate through each character in the string
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            // Convert lowercase to uppercase
            str[i] = str[i] - 'a' + 'A';
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            // Convert uppercase to lowercase
            str[i] = str[i] - 'A' + 'a';
        }
        i++;
    }
}

int main() {
    char str[100];
    
    // Ask the user to input a string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove the trailing newline character if fgets is used
    str[strcspn(str, "\n")] = '\0';

    // Call the function to toggle case
    toggleCase(str);

    // Print the modified string
    printf("Modified string: %s\n", str);

    return 0;
}
