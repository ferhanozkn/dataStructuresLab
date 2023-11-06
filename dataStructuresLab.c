#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Bağlı liste düğüm yapısı
/*struct Node {
    int data;
    struct Node* next;
};

// Yeni bir düğüm oluşturur
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Liste başına yeni bir düğüm ekler
void addToFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Liste sonuna yeni bir düğüm ekler
void addToEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Bağlı listeyi yazdırır
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int num;

    while (1) {
        printf("Bir Sayi Giriniz. Eger (-1) Girerseniz Programdan Cikis Yapilir : ");
        scanf("%d", &num);

        if (num == -1) {
            break;
        }

        if (num % 2 == 0) {
            addToEnd(&head, num);  // Çift sayıları listenin sonuna ekler
        } else {
            addToFront(&head, num);  // Tek sayıları listenin başına ekler
        }
    }

    printf("\nDuzenlenmis Bagli Liste:\n");
    printList(head);

    // Belleği temizle
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}*/

// Bağlı liste düğüm yapısı
/*struct Node {
    int data;
    struct Node* next;
};

// Yeni bir düğüm oluşturan fonksiyon
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Bağlı listeye yeni bir düğüm ekleyen fonksiyon
void insert(struct Node** head, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head;
    *head = new_node;
}

// Bağlı listeyi büyükten küçüğe sıralayan fonksiyon
void sortList(struct Node** head) {
    struct Node* sortedList = NULL;
    struct Node* current = *head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;

        // Sıralı listeyi dolaşarak doğru konumu bul
        if (sortedList == NULL || sortedList->data >= current->data) {
            current->next = sortedList;
            sortedList = current;
        } else {
            struct Node* temp = sortedList;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    *head = sortedList;
}

// Bağlı listeyi yazdıran fonksiyon
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d-> ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Rastgele 100 sayıyı bağlı listeye ekle
    for (int i = 0; i < 100; i++) {
        int randomNum = rand() % 1000; // 0 ile 999 arasında rastgele bir sayı üret
        insert(&head, randomNum);
    }

    printf("Eklendikleri Sirayla Bagli Liste :\n");
    printList(head);

    // Bağlı listeyi büyükten küçüğe sırala
    sortList(&head);

    printf("\nBuyukten Kucuge Sirali Bagli Liste :\n");
    printList(head);

    return 0;
}*/

// Öğrenci yapısı
struct Student {
    int student_number;
    char name[50];
    int age;
};

// Bağlı liste düğüm yapısı
struct Node {
    struct Student student;
    struct Node* next;
};

// Bağlı liste başlangıç düğümü
struct Node* head = NULL;

// Öğrenci bilgilerini ekrana yazan ve sayan fonksiyon
void printAndCountStudents() {
    struct Node* current = head;
    int count = 0;

    while (current != NULL) {
        printf("%d- %s %d %d\n", current->student.student_number, current->student.name, current->student.age, current->student.student_number);
        current = current->next;
        count++;
    }

    printf("Toplam %d ogrenci bulunmaktadir.\n", count);
}

// Öğrenci ekleyen fonksiyon
void addStudent(int student_number, char name[50], int age) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->student.student_number = student_number;
    strcpy(new_node->student.name, name);
    new_node->student.age = age;
    new_node->next = head;
    head = new_node;
}

// İsimle öğrenci arama fonksiyonu
void searchStudentByName(char name[50]) {
    struct Node* current = head;

    while (current != NULL) {
        if (strcmp(current->student.name, name) == 0) {
            printf("Aranan ogrenci bulundu: %d- %s %d %d\n", current->student.student_number, current->student.name, current->student.age, current->student.student_number);
            return;
        }
        current = current->next;
    }

    printf("Aranan ogrenci bulunamadi.\n");
}

// İsimle öğrenci silme fonksiyonu
void deleteStudentByName(char name[50]) {
    struct Node* current = head;
    struct Node* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->student.name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("%s isimli ogrenci silindi.\n", name);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Aranan ogrenci bulunamadi.\n");
}

// En uzun ismi bulan fonksiyon
void findLongestName() {
    struct Node* current = head;
    char longest_name[50] = "";

    while (current != NULL) {
        if (strlen(current->student.name) > strlen(longest_name)) {
            strcpy(longest_name, current->student.name);
        }
        current = current->next;
    }

    if (strlen(longest_name) > 0) {
        printf("En uzun isimli ogrenci: %s\n", longest_name);
    } else {
        printf("Ogrenci bulunamadi.\n");
    }
}

int main() {
    // Öğrenci eklemek için örnek veriler
    addStudent(201, "Ferhan", 21);
    addStudent(202, "Ozkan", 22);
    addStudent(203, "Ali", 23);

    // İşlemleri gerçekleştirme
    printAndCountStudents();
    searchStudentByName("Ferhan");
    deleteStudentByName("Ferhan");
    findLongestName();

    return 0;
}