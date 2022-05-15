#include <stdlib.h>
#include <string.h>

typedef struct
{
    void *data;
    int item;
} map_find_t;
map_find_t __mf_out__;

typedef struct
{
    int size;
    char **keys;
    void **values;
    int current_item;
} map_t;

#define _quick_type_ int
#define _quick_name_ 0

#define map_set(map_name, key, type, value) ({\
    type __t__ = value;\
    map_find_t __res__ = __map_find__(map_name, key);\
    if(__res__.item == -1) {\
        map_name.keys[map_name.current_item] = key;\
        map_name.values[map_name.current_item++] = &__t__;\
    } else {\
        map_name.values[__res__.item] = &__t__;\
    }\
})

map_find_t __map_find__(map_t map_name, char *value)
{
    int i = 0;
    map_find_t ret;
    while (i < map_name.current_item)
    {
        if (!strcmp(map_name.keys[i], value))
        {
            ret.data = map_name.values[i];
            ret.item = i;
            return ret;
        }
        i++;
    }
    ret.item = -1;
    return ret;
}

#define map_find_safe(map_name, type, value) ({                 \
    __mf_out__ = __map_find__(map_name, value);                 \
    (__mf_out__.item > -1) ? (*((type *)__mf_out__.data)) : -1; \
})

#define map_find(map_name, type, value) ({             \
    *((type *)((__map_find__(map_name, value)).data)); \
})

map_t init_map(int size)
{
    map_t _map;
    _map.size = size;
    _map.keys = malloc(sizeof(char *) * size);
    _map.values = malloc(sizeof(void *) * size);
    _map.current_item = 0;
    return _map;
}