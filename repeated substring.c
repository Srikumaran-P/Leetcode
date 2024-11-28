
bool repeatedSubstringPattern(char* s) {
    int len = strlen(s);
    int check[256] = {0};
    bool ret = false;
    int idx = 0;

    int* arr = malloc(sizeof(int) * 26);

    for (int i = 0; i < len; i++) {
        check[s[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (check[i] != 0) {
            arr[idx++] = check[i];
        }
    }

    int maxrepeat = (len/idx);

    if (maxrepeat <= 1) return false;

    for (int k = 2; k <= maxrepeat; k++) {
        bool hit = true;
        for (int x = 0; x < idx; x++) {
            if (arr[x] % k) {
                hit = false;
                break;
            }
        }
        if (hit) {
            ret = true;
            for (int i = 0; i < (len - (len/k)); i++) {
                if (s[i] != s[i + (len/k)]) {ret = false; break;}
            }
            if(ret) break;
        }
    }
    if (arr) free(arr);
    return ret;
}
