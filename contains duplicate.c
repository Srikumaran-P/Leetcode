#define TABLE_SIZE 10000

typedef struct HashNode{
    int key;
    struct HashNode* next;
} HashNode;

HashNode* hashTable[TABLE_SIZE];

unsigned int hash(int key) {
    return abs(key) % TABLE_SIZE;
}

bool insert(int key){
    unsigned int index = hash(key);
    HashNode* current = hashTable[index];
    
    while(current != NULL){
        if(current -> key == key){
            return true;
        }
        current = current -> next;
    }

    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode -> key = key;
    newNode -> next = hashTable[index];
    hashTable[index] = newNode;
    return false;
}



bool containsDuplicate(int* nums, int numsSize){
    for(int i = 0; i < TABLE_SIZE; i++){
        hashTable[i] = NULL;
    }
    
    for(int i = 0; i <= numsSize - 1; i++){
        if(insert(nums[i])){
            return true;
        }
    }
    return false;
}
