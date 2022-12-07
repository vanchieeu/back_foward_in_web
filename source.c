#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

int count = 0;
int length = 0;

typedef struct WebURL {
    int ID;

    struct WebURL *next;
    struct WebURL *prev;
} webURL;
webURL *root = NULL;

webURL *makeURL(int ID) {
    webURL *ptr = (webURL *)malloc(sizeof(webURL));

    ptr->ID = ID;
    ptr->next = NULL;
    ptr->prev = NULL;

    return ptr;
}

void addNextURL(int ID) {
    if (root == NULL) {
        root = makeURL(ID);
        return;
    }

    webURL *ptr = (webURL *)malloc(sizeof(webURL));
    ptr = root;

    if (count != 0) {
        for (int i = 1; i < length-count; i++)
            ptr = ptr->next;      
    } else {
        while (ptr->next != NULL) 
            ptr = ptr->next;
    }

    ptr->next = makeURL(ID);
    ptr->next->prev = ptr;
}

void coutList() {
    webURL *ptr = (webURL *)malloc(sizeof(webURL));
    ptr = root;

    int i = 1;
    bool check = true;
    while (ptr != NULL) {
        if (i > length-count && check) {
            printf("[ ");
            check = false;
        }
        printf("%d -> ", ptr->ID);
        ptr = ptr->next;
        i++;
    }    
    printf("NULL\n");
}

void backURL() {
    count++;
}

void nextURL() {
    count--;
}

void Menu() {
    AGAIN:
    system("cls");
    printf("Chuỗi URL hiện tại: \n      ");
    coutList();
    printf("1. Di chuyển đến URL tiếp theo.\n");
    printf("2. Lùi lại 1 URL.\n");
    printf("3. Tiến lên 1 URL.\n");
    printf("0. Thoát Menu.");
    printf("Chọn chức năng: ");
    int n;
    int ID;
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        printf("Nhập ID URL: ");
        scanf("%d", &ID);
        addNextURL(ID);
        length++;
        goto AGAIN;
    case 2:
        backURL();
        goto AGAIN;
    case 3:
        nextURL();
        goto AGAIN;
    case 0:
        exit(0);
    default:
        goto AGAIN;
    }
}


int main() {
    Menu();
    return 0;
}