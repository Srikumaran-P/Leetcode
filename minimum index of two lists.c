/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize) {
    int k=0,sum=INT_MAX;
    int row=list1Size>list2Size?list2Size:list1Size;
    char** res = (char**)malloc(row * sizeof(char*));

    for (int i = 0; i < row; i++) {
        res[i] = (char*)malloc(32 * sizeof(char));
    }
    for(int i=0;i<list1Size;i++){
        int temp=-1;
        for(int j=0;j<list2Size;j++){
            if(strcmp(list1[i],list2[j])==0){
                temp=i+j;
                break;
            }
        }
        printf("%d %s ",sum,res[k]);
        if(sum>temp&&temp!=-1){
            k=0;
            strcpy(res[k],list1[i]);
            sum=temp;
        }else if(sum==temp){
            k++;
            strcpy(res[k],list1[i]);
        }
    }
    *returnSize=k+1;
    return res;
}
