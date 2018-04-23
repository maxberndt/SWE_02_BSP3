#include <stdio.h>
#include "list.h"

int main() {
    int a[] = { 1, 2, 3 };
    int i;
    
    SLIST_HEADER *root = CreateSlist();
    if ( root == NULL ) return 0;
    
    for ( i=0; i< sizeof(a)/sizeof(int); i++)
        InsertFirst( root, a[i] );
    
    return 0;
}
