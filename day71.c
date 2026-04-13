#include <stdio.h>
#include <string.h>

#define EMPTY -1
#define MAX 1000

int table[MAX];
int m;

// Hash function
int hash(int key) {
    return key % m;
}

// INSERT operation
void insert(int key) {
    int h = hash(key);
    int i = 0;
    
    while(i < m) {
        int idx = (h + i*i) % m;
        
        if(table[idx] == EMPTY) {
            table[idx] = key;
            return;
        }
        i++;
    }
}

// SEARCH operation
int search(int key) {
    int h = hash(key);
    int i = 0;

    while(i < m) {
        int idx = (h + i*i) % m;

        if(table[idx] == EMPTY)
            return 0;  // not found
        
        if(table[idx] == key)
            return 1;  // found
        
        i++;
    }
    return 0;
}

int main() {
    int q;
    scanf("%d", &m);
    scanf("%d", &q);

    // initialize table
    for(int i = 0; i < m; i++)
        table[i] = EMPTY;

    char op[10];
    int x;

    while(q--) {
        scanf("%s %d", op, &x);

        if(strcmp(op, "INSERT") == 0)
            insert(x);
        else if(strcmp(op, "SEARCH") == 0) {
            if(search(x))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }
    return 0;
}
