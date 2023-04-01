#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


#define print(item, itemText) \
  case item:                  \
    printf(itemText);         \
    break
#define if_case(CART, item)  \
  if (CART & (bitmask << i)) \
    printf(item);            \
  break;
uint8_t bitmask = 1;
uint8_t CART;
typedef enum
{
  SHIRT = 1 << 0,
  TROUSERS = 1 << 1,
  RING = 1 << 2,
  SHOES = 1 << 3,
  GLASSES = 1 << 4,
  BRACELET = 1 << 5,
  BAG = 1 << 6,
  DRESS = 1 << 7,
} PERSONAL_BELONGINGS;
void insert_item(uint8_t *CART, PERSONAL_BELONGINGS item)
{
  *CART |= item;
}
void deleted_item(uint8_t *CART, PERSONAL_BELONGINGS item)
{
  *CART ^= item;
  printf("\nThe car was deleted item");
}
void show_item(uint8_t *CART)
{
  printf("\nShow the cart: ");
  for (int i = 0; i < 8; i++)
  {
    uint8_t temp = (*CART) & (bitmask << i);
    switch (temp)
    {
      print(RING, "ring ");
      print(TROUSERS, "trousers ");
      print(DRESS, "dress ");
      print(GLASSES, "glasses ");
      print(BRACELET, "bracelet ");
      print(BAG, "bag ");
      print(SHOES, "shoes ");
      print(SHIRT, "shirt ");
    }
  }
}
void check_many_item(uint8_t *CART, PERSONAL_BELONGINGS item)
{
  *CART |= item;
  printf("\nCheck the cart has: ");
  for (int i = 0; i < 8; i++)
  {
    if (item & (bitmask << i))
      switch (i)
      {
      case 0:
        if_case(*CART, "shirt ");
      case 1:
        if_case(*CART, "trousers ");
      case 2:
        if_case(*CART, "ring ");
      case 3:
        if_case(*CART, "shoes ");
      case 4:
        if_case(*CART, "glasses ");
      case 5:
        if_case(*CART, "bracelet ");
      case 6:
        if_case(*CART, "bag ");
      case 7:
        if_case(*CART, "dress ");
      }
  }
}
int main(void)
{
  insert_item(&CART, RING | BAG | SHIRT | BRACELET);
  show_item(&CART);
  check_many_item(&CART, BAG | SHIRT);
  deleted_item(&CART, RING | BRACELET);
  show_item(&CART);
  return 0;
}
