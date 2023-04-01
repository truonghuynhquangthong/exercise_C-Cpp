#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
uint8_t CART;

#define show(ITEM, item, TempVar) \
  if ((*CART &= ITEM) == ITEM)    \
  {                               \
    printf(item);                 \
  }                               \
  *CART = TempVar;
#define check(ITEM, item)      \
  if ((*CART &= ITEM) == ITEM) \
  {                            \
    printf(item);              \
  }

#define if_case(item, text) \
  {                         \
  case item:                \
    printf(text);           \
    break;                  \
  }

typedef enum
{
  SHIRT = 1 << 0,    // 0b00000001
  TROUSERS = 1 << 1, // 0b00000010
  DRESS = 1 << 2,    // 0b00000100
  GLASSES = 1 << 3,  // 0b00001000
  RING = 1 << 4,     // 0b00010000
  BRACELET = 1 << 5, // 0b00100000
  SHOES = 1 << 6,    // 0b01000000
  BAG = 1 << 7,      // 0b10000000
} PERSONAL_BELONGINGS;

void conver_enum_to_text(PERSONAL_BELONGINGS item_name)
{
  switch (item_name)
  {
    if_case(SHIRT, "shirt");
    if_case(DRESS, "dress");
    if_case(BAG, "bag");
    if_case(RING, "ring");
    if_case(BRACELET, "bracelet");
    if_case(SHOES, "shoes");
    if_case(GLASSES, "glasses");
  }
}
void insert_item_for_cart(uint8_t *CART, PERSONAL_BELONGINGS item_name)
{
  *CART |= item_name;
}
void show_item(uint8_t *CART)
{
  uint8_t Temp = *CART;
  printf(">>> The Cart include: ");
  show(SHIRT, "shirt ", Temp);
  show(TROUSERS, "trousers ", Temp);
  show(DRESS, "dress ", Temp);
  show(BAG, "bag ", Temp);
  show(BRACELET, "bracelet ", Temp);
  show(SHOES, "shoes ", Temp);
  show(GLASSES, "glasses ", Temp);
  show(RING, "ring ", Temp);
}
void delete_item(uint8_t *CART, PERSONAL_BELONGINGS item_name)
{
  printf(">>> You want to delete ");
  conver_enum_to_text(item_name);
  printf("-> it was deleted!", item_name);
  uint8_t Temp = *CART;
  *CART = *CART ^ item_name;
}
void insert_item(uint8_t *CART, PERSONAL_BELONGINGS item_name)
{
  printf(">>> You want to insert ");
  conver_enum_to_text(item_name);
  printf("-> it was inserted!", item_name);
  uint8_t Temp = *CART;
  *CART = *CART | item_name;
}
void check_item_for_cart(uint8_t *CART, PERSONAL_BELONGINGS item_name)
{
  uint8_t Temp = *CART;
  uint8_t test = *CART & item_name;
  printf(">>> Check the ");
  conver_enum_to_text(item_name);
  check(SHIRT, "-> The cart has shirt ");
  check(TROUSERS, "-> The cart has trousers ");
  check(DRESS, "-> The cart has dress ");
  check(BAG, "-> The cart has bag ");
  check(BRACELET, "-> The cart has brecelet ");
  check(SHOES, "-> The cart has shoes ");
  check(GLASSES, "-> The cart has glasses ");
  check(RING, "-> The cart has ring ");
  *CART = Temp;
}
int main(void)
{
  insert_item_for_cart(&CART, RING | SHIRT | SHOES | DRESS | BAG);
  show_item(&CART);
  printf("\n");
  delete_item(&CART, BAG);
  printf("\n");
  insert_item(&CART, RING);
  printf("\n");
  show_item(&CART);
  printf("\n");
  check_item_for_cart(&CART, SHIRT);
  return 0;
}