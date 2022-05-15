# C-maps
Simple C library for handling maps of multiple/any types

## Creating a Map
`map_t mymap = init_map(size)`
- Initiates a new map with the maximum size `size`
<br>

`map_set(map name, key, value type, value)`
- Creates or redefines a key in a map
- A map can have multiple types in it
- Structures are also permitted
  - See `demo2` in `main.c`
<br>

`map_find(map name, value type, key)`
- Gets the value of a given key
- Note that you must know the type of the value at a key
