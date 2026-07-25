

typedef struct {
    int key;
    int index;
    UT_hash_handle hh;
} HashNode;

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    HashNode *map = NULL, *entry, *tmp;

    for (int i = 0; i < numsSize; i++) {

        HASH_FIND_INT(map, &nums[i], entry);

        if (entry != NULL) {
            if (i - entry->index <= k) {

                // Free memory before returning
                HASH_ITER(hh, map, entry, tmp) {
                    HASH_DEL(map, entry);
                    free(entry);
                }

                return true;
            }

            entry->index = i;
        }
        else {
            entry = (HashNode*)malloc(sizeof(HashNode));
            entry->key = nums[i];
            entry->index = i;
            HASH_ADD_INT(map, key, entry);
        }
    }

    // Free hash table
    HASH_ITER(hh, map, entry, tmp) {
        HASH_DEL(map, entry);
        free(entry);
    }

    return false;
}