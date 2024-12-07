typedef struct
{
    int val;
    int rank;
}PAIR;

int cmpPair(const void * a, const void* b) {
    PAIR* pairA = (PAIR*) a;
    PAIR* pairB = (PAIR*) b;
    return pairB->val - pairA->val;
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    char** ret;
    PAIR pairs[10000];
    ret = (char**) malloc(scoreSize * sizeof(char*));
    for (int i = 0; i < scoreSize; i++) {
        ret[i] = (char*) malloc(100 * sizeof(char));
        pairs[i].val = score[i];
        pairs[i].rank = i;
    }
    qsort(pairs, scoreSize, sizeof(PAIR), cmpPair);
    * returnSize = scoreSize;
    for (int i = 0; i < scoreSize; i++) {
        int idx = pairs[i].rank;
        switch (i) {
            case 0:
                ret[idx] = "Gold Medal";
                break;
            case 1:
                ret[idx] = "Silver Medal";
                break;
            case 2:
                ret[idx] = "Bronze Medal";
                break;
            default:
                sprintf(ret[idx], "%d", i + 1);
                break;
        }
    }
    return ret;
}
