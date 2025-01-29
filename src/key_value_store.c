#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "key_value_store.h"

#define MAX_KEY_LEN 100
#define MAX_VAL_LEN 256

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VAL_LEN];
} KeyValuePair;

KeyValuePair kv_store[100];
int kv_count = 0;

int set_key_value(char *key, char *value) {
    if (kv_count >= 100) return -1;
    
    strcpy(kv_store[kv_count].key, key);
    strcpy(kv_store[kv_count].value, value);
    kv_count++;
    return 0;
}

char* get_value(char *key) {
    for (int i = 0; i < kv_count; i++) {
        if (strcmp(kv_store[i].key, key) == 0) {
            return kv_store[i].value;
        }
    }
    return NULL;
}

int delete_key(char *key) {
    for (int i = 0; i < kv_count; i++) {
        if (strcmp(kv_store[i].key, key) == 0) {
            for (int j = i; j < kv_count - 1; j++) {
                kv_store[j] = kv_store[j + 1];
            }
            kv_count--;
            return 0;
        }
    }
    return -1;
}
