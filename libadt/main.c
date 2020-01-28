#include <stdio.h>
#include <stdlib.h>

#include "AssocArr/HMap.h"

int main()
{
    struct HMap* hmap = h_map_init(5);
    hmap_print(hmap);

    hmap_insert(hmap, "fs", 3);
    hmap_print(hmap);

    hmap_insert(hmap, "fs", 5);
    hmap_print(hmap);

    hmap_insert(hmap, "value one", 12);
    hmap_print(hmap);

    hmap_insert(hmap, "aa", 5);
    hmap_print(hmap);

    hmap_dest(hmap);
    return 0;
}