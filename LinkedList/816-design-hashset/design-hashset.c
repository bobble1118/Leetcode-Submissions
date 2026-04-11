struct Node {
    int key;
    struct Node* next;
};

#define BASE 769 
typedef struct {
    struct Node* buckets[BASE];
} MyHashSet;

int hash(int key) {
    return key % BASE;
}

MyHashSet* myHashSetCreate() {
    MyHashSet* obj = (MyHashSet*)malloc(sizeof(MyHashSet));
    for (int i = 0; i < BASE; i++) {
        obj->buckets[i] = NULL;
    }
    return obj;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    int h = hash(key);
    struct Node* curr = obj->buckets[h];
    while (curr) {
        if (curr->key == key) return true;
        curr = curr->next;
    }
    return false;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    if (myHashSetContains(obj, key)) return;

    int h = hash(key);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = obj->buckets[h];
    obj->buckets[h] = newNode;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int h = hash(key);
    struct Node* curr = obj->buckets[h];
    struct Node* prev = NULL;

    while (curr) {
        if (curr->key == key) {
            if (prev == NULL) {
                obj->buckets[h] = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr); 
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void myHashSetFree(MyHashSet* obj) {
    for (int i = 0; i < BASE; i++) {
        struct Node* curr = obj->buckets[i];
        while (curr) {
            struct Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(obj);
}
/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/