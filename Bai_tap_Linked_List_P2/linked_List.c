/*
 * File: linked_List.c
 * Author: Thông Trương
 * Date: 02/01/2003
 * Description: Tạo 1 linked list với chức năng thêm, xóa, sửa
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Description: Tạo 1 struct và con trỏ struct để lưu và liên kết các giá trị của list
typedef struct node
{
    uint8_t data;
    struct node *next;
}node;

/*
 * Function: push_Back
 * Description: Thêm phần tử vào linked list bằng cách tạo thêm node
 * Input:
 *   *arr 
 *   data - giá trị của node cần thêm
 */
void push_Back(node *arr, uint8_t data) {
    node *newNode = (node *)malloc(sizeof(node));  // Khởi tạo 1 node mới
    newNode->data = data;
    newNode->next = NULL;

    if (arr->next == NULL) {                       // Tạo 1 node đâu tiên
        arr->next = newNode;
        return;
    }

    node *p = arr->next;
    while (p->next != NULL)
        p = p->next;
    p->next = newNode;                             // Liên kết với địa chỉ của node kế tiếp
}

/*
 * Function: assign
 * Description: Thay đổi giá trị tại 1 vị trí được chỉ định
 * Input:
 *   *arr 
 *   data - giá trị của node mới
 *   index - vị trí chỉ định
 */
void assign(node *arr, uint8_t index, uint8_t data) {
    printf("Thay the phan tu tai vi tri %d = %d:\n", index, data);
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (arr->next == NULL) {
        arr->next = newNode;
        return;
    }

    node *p = arr->next;
    uint8_t i = 0;          // Khởi tạo 1 biến đém để xát định vị trí index truyền vào
    while (p->next != NULL) {
        i++;
        if(i == index) {
            node *p2 = p->next;            // Khởi tạo địa chỉ của node cần thay đổi giá trị
            p->next = newNode;             // Liên kết node với địa chỉ của node mới 
            newNode->next = p2->next;      // Liên kết node mới với địa chỉ của node phía sau
            free(p2);                      // Xóa node cũ 
            return;
        }
        p = p->next;
    }
}

/*
 * Function: erase
 * Description: Xóa node chỉ định
 * Input:
 *   *arr 
 *   index - vị trí chỉ định
 */
void erase(node *arr, uint8_t index) {
    printf("Xoa phan tu tai vi tri %d:\n", index);
    node *p = arr->next;
    uint8_t i = 0;         
    while (p->next != NULL) {
        i++;
        if(i == index) {
            node *p2 = p->next;   // Khởi tạo địa chỉ của node cần xóa
            p->next = p2->next;   // Liên kết với node phía sau
            free(p2);             // Xóa node cần xóa
            return;
        }
        p = p->next;
    }
}

/*
 * Function: pop_Back
 * Description: Xóa node cuối cùng của list
 * Input:
 *   *arr
 */
void pop_Back(node *arr) {
    printf("Xoa phan tu cuoi cung:\n");
    node *p = arr->next;
    while (p->next != NULL) {
        if (p->next->next == NULL) {    // Xát định vị trí node cuối cùng
            free(p->next);              // xóa node cuối cùng
            p->next = NULL;             // Liên kết node thứ (n-1) với Null => trở thành node cuối cùng  
            return;
        }
        p = p->next;
    }
}

/*
 * Function: push_Back
 * Description: Xóa tất cả các node
 *   *arr 
 */
void clear(node *arr) {
    printf("Xoa tat ca phan tu ...\n");
    node *p = arr->next;
    while (p->next != NULL) {
        p = p->next;
        free(arr->next);            // Xóa node đầu tiên
        arr->next = p;              // Liên kết với node thứ 2 => node thứ 2 trở thành node đầu tiên
    }
    free(arr->next);                // Xóa node cuối cùng   
    arr->next = NULL;               
}

/*
 * Function: get_Data
 * Description: Tìm giá trị tại node được chỉ định
 * Input:
 *   *arr 
 *   index - vị trí chỉ định
 * Output:
 *   giá trị tại vị trí index
 *   0 : nếu nhập vị trí không hợp lệ
 */
uint8_t get_Data(node *arr, uint8_t index) {
    printf("Phan tu tai vi tri %d: ", index);
    node *p = arr->next;
    uint8_t temp = 0;                        // Khởi tạo biến đém để xát định vị trí index
    while (p->next != NULL) {
        if (index == temp) return p->data;   // Trả về kết quả tại vị trí index
        p = p->next;
        temp++;
    }
    printf("Nhap vi tri khong hop le: ");    
    return 0;                                // Với index nhập không hợp lệ trả về kết quả 0
}

/*
 * Function: prin
 * Description: In tất cả các giá trị có trong list
 * Input:
 *   *arr 
 */
void prin(node *arr) {
    for (node *p = arr->next; p != NULL; p = p->next) {
        printf("%d\n", p->data);
    }
}

/*
 * Function: main
 * Description: Thao tác chỉnh sửa với list
 */
int main()
{
    node arr = {0, NULL};
    printf("Cac gia tri trong mang:\n");
    push_Back(&arr, 2);
    push_Back(&arr, 17);
    push_Back(&arr, 9);
    push_Back(&arr, 8);
    prin(&arr);

    assign(&arr, 2, 12);
    prin(&arr);

    erase(&arr, 1);
    prin(&arr);

    pop_Back(&arr);
    prin(&arr);

    printf("%d\n", get_Data(&arr, 2));

    clear(&arr);
    prin(&arr);

    return(0);
}