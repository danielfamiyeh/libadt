#include <stdlib.h>
#include <stdio.h>

struct HMap //opaque hash map type definition
{
	int capacity;
	int* array;
};

struct HMap* h_map_init(int size)
{
	struct HMap* hashMap = (struct HMap*)malloc(sizeof(struct HMap));
	hashMap->capacity = size;
	hashMap->array = (int*)malloc(sizeof(int) * size);

	return hashMap;
};

void hmap_dest(struct HMap* hmap)
{
	free(hmap->array);
	free(hmap);
};

int hash_func(struct HMap* hmap, char* key)
{
	return (key[0] + 2 * key[1]) % hmap->capacity;
};

int hmap_insert(struct HMap* hmap, char* key, int value)
{
	int index = hash_func(hmap, key);
	hmap->array[index] = value;
};

int hmap_search(struct HMap* hmap, char* key)
{

};

int hmap_remove(struct HMap* hmap, char* key)
{

};

void hmap_print(struct HMap* hmap)
{
	printf("[");
	for(int i=0; i<hmap->capacity; i++)
	{
		printf(" %d ", hmap->array[i]);
	}
	printf("]\n");
}
