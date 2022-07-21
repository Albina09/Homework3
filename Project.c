/* Телефонный справочник */
#include <stdio.h>
#include <locale.h> 
#include <string.h>

#define N 100
#define M 3

struct subsc {
    char Name[N], Surname[N], Number[N];
};
struct subsc data[M] = { '\0','\0','\0' };

int menu();
int add();
void concl();
void search();
void del();
void fil();

void fil() {
    int c;

    do {
        c = getchar();
    } while (c != EOF && c != '\n');
}

int add() {
    char p = 1, t = 1;
    int  l = 0;

    for (int i = 0; i < M; i++) {

        if (data[i].Name[0] == '\0') {
            t = 0;
            l = i + 1;
            printf("Введите имя\n");
            fgets(data[i].Name, N, stdin);

            printf("Введите фамилию\n");
            fgets(data[i].Surname, N, stdin);

            printf("Введите номер\n");
            fgets(data[i].Number, N, stdin);
            printf("Контакт добавлен\n");

            printf("Добавить ещё один контакт\n");
            printf("Да - 1\n");
            printf("Нет - 0\n");
            p = getchar();
            fil();

            if (p == '0') {
                menu();
                return 0;
            }
        }
        
    }
    if (t || l == M) {
        printf("Телефонный справочник полностью заполнен, желаете удалить старый контакт?\n");
        printf("Да - 1\n");
        printf("Нет - 0\n");
        p = getchar();

        fil();

        if (p != '0')
            del();
        else
            menu();
    }
    return 0;
}

void concl() {
	char p = 1;
    for (int i = 0; i < M; i++) {

        if (data[i].Name[0] != '\0'){ 
            printf(" Имя:%s Фамилия:%s Номер:%s\n", data[i].Name, data[i].Surname, data[i].Number);
            p = '0';
         }
    }
    if (p != '0')
            printf("Телефонный справочник пуст\n");
    menu();
}

void search() {
    char t = 1;
    char need[N] = { '\0' };

    printf("Для поиска контакта введите имя/фамилию/номер телефона\n");
    fgets(need, N, stdin);

    for (int i = 0; i < M; i++) {

        if (strcmp(data[i].Name, need) == 0 || strcmp(data[i].Surname, need) == 0 || strcmp(data[i].Number, need) == 0) {
            printf(" Имя:%s Фамилия:%s Номер:%s\n", data[i].Name, data[i].Surname, data[i].Number);
            t = 0;
        }
    }

    if (t)
        printf("Такого контакта нет в справочнике\n");
    
    menu();
}

void del() {
    char t = 1;
    char need[N] = { '\0' };

    printf("Для удаления контакта введите имя/фамилию/номер телефона\n");
    fgets(need, N, stdin);

    for (int i = 0; i < M; i++) {

        if (strcmp(data[i].Name, need) == 0 || strcmp(data[i].Surname, need) == 0 || strcmp(data[i].Number, need) == 0) {
            memset(&data[i], 0, sizeof(data[i]));
            printf("Контакт %s удалён\n",need);
            t = 0;
        }
    }

    if (t)
        printf("Такого контакта нет в справочнике\n");
    
    menu();
}

int menu() {
    char input = 0;
   
        printf("Добавить контакт - 1\n");
        printf("Вывести список контактов - 2\n");
        printf("Поиск контакта - 3\n");
        printf("Удалить контакт - 4\n");
        printf("Выйти - 5\n");

        int top = 0;
        input = getchar();
        fil();


        switch (input) {

        case '1': add();
            break;
        case '2': concl();
            break;
        case '3': search();
            break;
        case '4': del();
            break;
        case '5': top = 0;
            break;
        }
        
}

int main() {
    setlocale(LC_ALL,"Russian"); 
    
    menu();

    return 0;
}
