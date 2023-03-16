#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef enum
{
  MAY_BAY_THUONG_MAI,
  MAY_BAY_TRUC_THANG,
  XE_KHACH,
  XE_MAY,
  XE_DAP,
  TAU_THUY,
  CA_NO,
} phuong_tien;

typedef union
{
  phuong_tien may_bay;
} hang_khong;

typedef union
{
  phuong_tien xe;
} bo;

typedef union
{
  phuong_tien duong_nuoc;
} thuy;

typedef union
{
  hang_khong duong_hang_khong;
  bo duong_bo;
  thuy duong_thuy;
  phuong_tien loai_phuong_tien;
} phuong_tien_giao_thong;

#define LOAI_HINH_GIAO_THONG(ten_duong, ...)          \
  void ten_duong(phuong_tien_giao_thong *phuong_tien) \
  {                                                   \
    printf("Ban da chon %s!!!!\n", #ten_duong);       \
    int dem = 0;                                      \
  again:                                              \
    printf("Vui long chon loai phuong tien\n");       \
    int lan = 0;                                      \
    int phim = -1;                                    \
    do                                                \
    {                                                 \
      __VA_ARGS__                                     \
      scanf("%d", &phim);                             \
      if (phim >= lan)                                \
        goto again;                                   \
    } while (1);                                      \
  }

#define KEY_VALUE(key, name, value)         \
  if (phim == -1)                           \
  {                                         \
    printf("Nhan %d: %s\n", key, name);     \
    lan++;                                  \
  }                                         \
  if (phim == key)                          \
  {                                         \
    printf("Ban chon: %s \n", name);        \
    if (phim == 0)                          \
    {                                       \
      if (dem == 0)                         \
      {                                     \
        printf("%s\n", value);              \
        dem++;                              \
        goto again;                         \
      }                                     \
      else if (dem == 1)                    \
      {                                     \
        printf("      Ban con lan cuoi\n"); \
        dem++;                              \
        goto again;                         \
      }                                     \
      else                                  \
      {                                     \
        printf("BYE !");                    \
        exit(0);                            \
      }                                     \
    }                                       \
    value;                                  \
    break;                                  \
  }

LOAI_HINH_GIAO_THONG(duong_hang_khong,
                     KEY_VALUE(1, "May bay thuong mai", phuong_tien->duong_hang_khong.may_bay = MAY_BAY_THUONG_MAI)
                         KEY_VALUE(2, "May bay truc thang", phuong_tien->duong_hang_khong.may_bay = MAY_BAY_TRUC_THANG)
                             KEY_VALUE(0, "Quay lai", "     Vui long suy nghi truoc kho chon :))")

)

LOAI_HINH_GIAO_THONG(duong_bo,
                     KEY_VALUE(1, "xe khach", phuong_tien->duong_bo.xe = XE_KHACH)
                         KEY_VALUE(2, "xe may", phuong_tien->duong_bo.xe = XE_MAY)
                             KEY_VALUE(3, "xe dap", phuong_tien->duong_bo.xe = XE_DAP)
                                 KEY_VALUE(0, "Quay lai", "Vui long suy nghi truoc kho chon :))"))

LOAI_HINH_GIAO_THONG(duong_thuy,
                     KEY_VALUE(1, "Tay thuy", phuong_tien->duong_thuy.duong_nuoc = TAU_THUY)
                         KEY_VALUE(2, "Ca no", phuong_tien->duong_thuy.duong_nuoc = CA_NO)
                             KEY_VALUE(0, "Quay lai", "Vui long suy nghi truoc kho chon :))"))

/////////////////////////////////////////////////////////////////////// chọn chương trình

void Chuong_Trinh_Chon_Duong(phuong_tien_giao_thong *phuong_tien)
{
  printf("Ban muon di chuyen bang duong nao?\n");
  printf("Nhan 1: Duong Hang Khong\n");
  printf("Nhan 2: Duong Bo\n");
  printf("Nhan 3: Duong Thuy\n");
  printf("Nhan 0: Thoat chuong trinh\n");
  int phim = 0;
  scanf("%d", &phim);

  switch (phim)
  {
  case 1:
    duong_hang_khong(phuong_tien);
    break;
  case 2:
    duong_bo(phuong_tien);
    break;
  case 3:
    duong_thuy(phuong_tien);
    break;
  case 0:
    exit(0);
  default:
    printf("Nhap phim khong hop le:");
    break;
  }
}

////////////////////////////////////////////////////////////////////// chương trình in giá tiền

void Hien_Thi_Gia(phuong_tien_giao_thong phuong_tien)
{

  switch (phuong_tien.loai_phuong_tien)
  {
  case MAY_BAY_THUONG_MAI:
    printf("Loai phuong tien: May bay thuong mai\n");
    printf("Gia ve: 799.000 vnd\n");
    break;
  case MAY_BAY_TRUC_THANG:
    printf("Loai phuong tien: May bay truc thang\n");
    printf("Gia ve: 999.000 vnd\n");
    break;
  case XE_KHACH:
    printf("Loai phuong tien: Xe khach\n");
    printf("Gia ve: 495.000 vnd\n");
    break;
  case XE_MAY:
    printf("Loai phuong tien: Xe may\n");
    printf("Gia ve: 95.000 vnd\n");
    break;
  case XE_DAP:
    printf("Loai phuong tien: Xe dap\n");
    printf("Gia ve: 15.000 vnd\n");
    break;
  case TAU_THUY:
    printf("Loai phuong tien: Tau thuy\n");
    printf("Gia ve: 599.000 vnd\n");
    break;
  case CA_NO:
    printf("Loai phuong tien: Ca no\n");
    printf("Gia ve: 799.000 vnd\n");
    break;
  default:
    printf("Nhap phim khong hop le !!!");
    break;
  }
}

int main(int argc, char const *argv[])
{

  phuong_tien_giao_thong phuong_tien;
  Chuong_Trinh_Chon_Duong(&phuong_tien);
  Hien_Thi_Gia(phuong_tien);

  return 0;
}
