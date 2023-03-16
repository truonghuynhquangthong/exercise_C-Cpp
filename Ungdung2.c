#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

enum vehicles
{
  PLANE,
  HELICOPTER,
  BUS,
  CAR,
  MOTORBIKE,
  BICYCLE,
  BOAT,
  CARNO,
};
typedef enum vehicles vh;

union airline
{
  vh PLANE;
  vh HELICOPTER;
};
typedef union airline airline;

union road
{
  vh BUS;
  vh CAR;
  vh MOTORBIKE;
  vh BICYCLE;
};
typedef union road road;
union waterway
{
  vh BOAT;
  vh CARNO;
};
typedef union waterway waterWay;
union transpotationTraffic
{
  airline airlineTraffic;
  waterWay waterWayTraffic;
  road roadTraffic;
  vh vehicleType;
};
typedef union transpotationTraffic transpotationTraffic;
int select_transpotation_type(void);
void airlineFunc(transpotationTraffic *vehicles);
void roadFunc(transpotationTraffic *vehicles);
void waterWayFunc(transpotationTraffic *vehicles);
void handle_select_transpotation_type(vh);
void show_price(transpotationTraffic vh)
{
  switch (vh.vehicleType)
  {
  case PLANE:
    printf("You were selected plane for travelling");
    printf("Ticket price is 1.000.000 VND");
    break;
  default:
    break;
  }
}
int main(void)
{
  vh vh;
  select_transpotation_type(&vh);
  return 0;
}
int select_transpotation_type(void)
{
  int press;
  printf("Which do you want to select transpotation type ?");
  printf("Press 1: Airline");
  printf("Press 2: Road");
  printf("Press 3: Water way");
  printf("Press 0: Close console");
  scanf("%d", &press);
  return press;
}
void airlineFunc(transpotationTraffic *vehicles)
{
  int pressChildren;
  printf("The next =>");
  printf("Which do want to move by traffic vehicles ?");
  printf("Press 1: Plane");
  printf("Press 2: Helicopter");
  scanf("%d", &pressChildren);
  switch (pressChildren)
  {
  case 1:
    vehicles->airlineTraffic.PLANE = PLANE;
    break;
  case 2:
    vehicles->airlineTraffic.HELICOPTER = HELICOPTER;
  default:
    break;
  }
}
void roadFunc(transpotationTraffic *vehicles)
{
  int pressChildren;
  printf("The next =>");
  printf("Which do want to move by traffic vehicles ?");
  printf("Press 1: Motobike");
  printf("Press 2: Bus");
  printf("Press 3: Bycicle");
  printf("Press 4: Car");
  scanf("%d", &pressChildren);
  switch (pressChildren)
  {
  case 1:
    vehicles->roadTraffic.MOTORBIKE = MOTORBIKE;
    break;
  case 2:
    vehicles->roadTraffic.BUS = BUS;
  case 3:
    vehicles->roadTraffic.BICYCLE = BICYCLE;
  case 4:
    vehicles->roadTraffic.CAR = CAR;
  default:
    break;
  }
}
void waterWayFunc(transpotationTraffic *vehicles)
{
  int pressChildren;
  printf("The next =>");
  printf("Which do want to move by traffic vehicles ?");
  printf("Press 1: Carno");
  printf("Press 2: Boat");
  scanf("%d", &pressChildren);
  switch (pressChildren)
  {
  case 1:
    vehicles->waterWayTraffic.BOAT = BOAT;
  case 2:
    vehicles->waterWayTraffic.CARNO == CARNO;
  default:
    break;
  }
}
void handle_select_transpotation_type(transpotationTraffic *vh)
{
  switch (select_transpotation_type())
  {
  case 1:
    printf("Ok Your select transportation type is airline!");
    airline(vh);
    break;
  case 2:
    printf("Ok Your select transpotation type is road!");
    road(vh);
    break;
  case 3:
    printf("Ok Your select transpotation type is water way!");
    waterWay(vh);
  default:
    break;
  }
}