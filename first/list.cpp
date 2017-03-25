#include <stdio.h>
#include <stdlib.h>
int global;
typedef struct node
{
    int data;
    char str[50];
    struct node *next;
} ITEM;

ITEM* add_node(ITEM* head, int new_data, char string[50])
{
    ITEM *new_item, *prev;
    new_item=(ITEM *)malloc(sizeof(ITEM));
    if(new_item==NULL)
    {
        puts("Ошибка выделения памяти");
        return head;
    }
    new_item->data=new_data;
    for (int i = 0; i < 50; i++)
    {
        new_item->str[i] = string[i];
    }

    if(head==NULL)
    {
        puts("Список создан");
        new_item->next=NULL;
        puts("Для продолжения введите любое число");
        scanf("%d",&global);
        return new_item;
    }

    if(head->data<new_data)
    {
        printf("Элемент %d вставлен в начало списка\n",new_data);
        new_item->next=head;
        puts("Для продолжения введите любое число");
        scanf("%d",&global);
        return new_item;
    }
    prev=head;
    while(prev->next!=NULL)
    {
        if(prev->next->data<new_data)
        {
            /*вставка*/
            printf("Элемент %d вставлен в середину списка\n",new_data);
            new_item->next=prev->next;
            prev->next=new_item;
            puts("Для продолжения введите любое число");
            scanf("%d",&global);
            return head;
        }
        else
        {
            prev=prev->next;
        }
    }
    printf("Элемент %d вставлен в конец списка\n ",new_data);
    prev->next=new_item;
    new_item->next=NULL;
    puts("Для продолжения введите любое число");
    scanf("%d",&global);
    return head;
}


ITEM* delete_node(ITEM* head, int n1, int n2)
{
    ITEM *cur, *prev;
    prev=NULL;
    cur=head;
    int sum = 0;
    while (cur != NULL) {
        sum++;
        cur = cur->next;
    }
    if (sum < n2 || sum < n1){
        printf("Вы хотите удалить слишком много элементов\n ");
        puts("Для продолжения введите любое число");
        scanf("%d",&global);
        return head;
    }

    int del = n2 - n1 + 1;
    printf("Удаление c элемента №%d по этемент №%d\n ",n1,n2);

    prev = NULL;
    cur = head;

    for (int i = 1; i < n1; i++)
    {
        prev = cur;
        cur = cur->next;
    }
    for (int i = 1; i <= del; i++)
    {
        if (prev == NULL)
        {
            head = head->next;
        }
        else
        {
            prev->next = cur->next;
            free(cur);
            cur = prev->next;
        }
    }
    puts("Для продолжения введите любое число");
    scanf("%d",&global);
    return head;
}


ITEM* find_node(ITEM* head, int find_data)
{
    ITEM *cur;
    cur=head;
    while(cur!=NULL && cur->data>=find_data)
    {
        if(cur->data==find_data)
        {
            printf("Элемент %d найден и он содержит строку: ",find_data);
            for (int i = 0; i<50; i++){
                printf("%c",cur->str[i]);
            }
            printf("\n");
            puts("Для продолжения введите любое число");
            scanf("%d",&global);
            return cur;
        }
        cur=cur->next;
    }
    printf("Элемент %d НЕ найден \n",find_data);
    puts("Для продолжения введите любое число");
    scanf("%d",&global);
    return NULL;
}

ITEM* Show_node(ITEM* head)
{
    ITEM *cur;
    cur = head;
    while (cur != NULL){
        printf("\nid: %d строка: ", cur->data);
        for (int i = 0; i < 50; i++){
            printf("%c",cur->str[i]);
        }
        cur = cur->next;
    }
    printf("\n");
    puts("Для продолжения введите любое число");
    scanf("%d",&global);
    return NULL;
}


void recurs(ITEM* head)
{
    if (head != NULL) {
        recurs(head->next);
        printf("id: %d строка: ", head->data);
        for (int i = 0; i < 50; i++){
            printf("%c",head->str[i]);
        }
        printf("\n");
    }
}


int list_main()
{
    ITEM *Head = NULL;
    char key,str[50] = {0};
    int n1,n2,search,id;
    while(1)
    {
        //system("clear");

        puts("1 - добавить элемент");
        puts("2 - удалить элемент");
        puts("3 - найти элемент");
        puts("4 - вывести список");
        puts("5 - рекурсивная функция");
        puts("6 - выйти");
        scanf("%c",&key);

        switch(key)
        {
            case '1':
                puts("Введите число");
                scanf("%d",&id);
                puts("Введите строку");
                for (int i = 0; i < 50; i++)
                {
                    str[i] = ' ';
                }

                for (int i = 0; i<50; i++){
                    scanf("%c",&str[i]);
                    if (str[i] == ' ') break;
                }
                Head=add_node(Head,id,str);
                break;
            case '2':
                puts("Введите c какого по какой элемент удалить");
                scanf("%d",&n1);
                scanf("%d",&n2);
                Head=delete_node(Head,n1,n2);
                break;
            case '3':
                puts("Введите число");
                scanf("%d",&search);
                find_node(Head,search);
                break;
            case '4':
                Show_node(Head);
                break;
            case '5':
                recurs(Head);
                break;
            case '6':
                puts("Выход");
                return 0;
        }
    }
}

