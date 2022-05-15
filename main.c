#include "maps.h"
#include <stdio.h>

void demo1();
void demo2();

int main()
{
    demo1();
    printf("*******\n");
    demo2();
    return 0;
}

void demo1() {
    map_t prices = init_map(100);

    // QOL macros
    #define set_quick(key,type, value) map_set(prices, key, type, value)
    #define find_quick(type, key) map_find(prices, type, key)

    // set the key "chicken" to hold the value 10
    set_quick("chicken", int, 10);
    set_quick("pork", int, 12);
    // set "apples" to hold a string
    set_quick("apples", char *, "$1 per pound");

    printf("%i\n",find_quick(int, "chicken"));
    printf("%i\n",find_quick(int, "pork"));
    // recall as a string
    printf("%s\n",find_quick(char *, "apples"));
    
    // redefininition can be done with the same function
    map_set(prices, "apples", int, 1);
    printf("%i\n",find_quick(int, "apples"));
}



void demo2() {
    map_t grocery_list = init_map(100);

    // QOL macros
    #undef set_quick
    #undef find_quick
    #define set_quick(key, value) map_set(grocery_list, key, struct Item, value)
    #define find_quick(key) map_find(grocery_list, struct Item, key)
    
    // Create a temporary structure
    struct Item{int amount;int price;} grocery_item = (struct Item){
        .amount = 5, 
        .price = 3
    };

    // expands like "map_set(grocery_list, "chicken", struct Item, grocery_item)"
    set_quick("chicken", grocery_item);

    // read the properties
    printf("I need %i pieces of chicken\n",find_quick("chicken").amount);
    printf("And they each cost $%i\n",find_quick("chicken").price);
}
