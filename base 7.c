char* convertToBase7(int num) {
    int sign = 0, i = 0;
    char* a = malloc(100 * sizeof(char));
    if (num < 0) {
        sign = 1;
        num *= -1;
    }
    while (num >= 7) {
        a[i] = num % 7 + '0';
        i++;
        num /= 7;
    }
    a[i] = num + '0';
    if (sign)
        a[++i] = '-';
    a[++i] = '\0';
    for (int j = 0; j < i / 2; j++) {
        int temp = a[j];
        a[j] = a[i - j - 1];
        a[i - j - 1] = temp;
    }
    return a;
}
