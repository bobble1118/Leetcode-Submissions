
typedef struct {
    bool hash[1000001];
} MyHashSet;

MyHashSet* myHashSetCreate() {
    MyHashSet* obj = (MyHashSet*)calloc(1, sizeof(MyHashSet));
    return obj;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    return obj->hash[key];
}

void myHashSetAdd(MyHashSet* obj, int key) {
    obj->hash[key] = true;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    obj->hash[key] = false;
}

void myHashSetFree(MyHashSet* obj) {
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