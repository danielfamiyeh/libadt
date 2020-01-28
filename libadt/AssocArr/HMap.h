struct HMap; //opaque hash map type definition

struct HMap* h_map_init();

void hmap_dest();

int hmap_insert(struct HMap* hmap, char* key, int entity);

int hmap_search(struct HMap* hmap, int key);

int hmap_remove(struct HMap* hmap, int key);

void hmap_print(struct HMap* hmap);
