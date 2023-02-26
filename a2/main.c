

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct payment{
    char* date;         //  MM/DD/YY as text
    float amount;
    struct payment* next;
}PAYMENT;

typedef struct employee{
    int id;
    char* name;
    PAYMENT* payments;
    struct employee* next;
}EMPLOYEE;

void printEmployee(EMPLOYEE e);
void printEmployees();
void addEmployee(int e_id,char* e_name);
int addPayment(int e_id, char* p_date, float p_amount);
int deleteEmployee(int e_id, char* e_name);

EMPLOYEE* list_of_employees=NULL;


int main(){
    //-----------------------------------------------------
    //testCase -1
    
    // EMPLOYEE e;
    // e.name="james";
    // e.id=123456;
    // e.next=NULL;
    // e.payments=NULL;
    // printEmployee(e);
    
    //-----------------------------------------------------
    //testCase -2
    
    // PAYMENT p1;
    // p1.date="01/01/2010";
    // p1.amount=150;
    // p1.next=NULL;
    // PAYMENT p2;
    // p2.date="01/05/2010";
    // p2.amount=200;
    // p2.next=&p1;
    // EMPLOYEE e;
    // e.name="sarah";
    // e.id=123456;
    // e.payments=&p2;
    // e.next=NULL;
    // printEmployee(e);
    
    //-----------------------------------------------------
    //testCase -3
    
    // addEmployee(123,"alma");
    // addEmployee(456,"mike");
    // printEmployees();
    
    //-----------------------------------------------------
    //testCase -4
    
    // addEmployee(123,"alma");
    // addPayment(123,"01/02/2020",3000);
    // addPayment(123,"10/07/2021",5000);
    // printEmployees();
    
    //-----------------------------------------------------
    //testCase -5
    
    // addEmployee(123,"alma");
    // addPayment(123,"01/02/2020",3000);
    // addPayment(123,"10/07/2021",5000);
    // addEmployee(456,"mike");
    // addPayment(456,"06/03/2020",700);
    // addPayment(456,"07/02/2020",200);
    // addPayment(456,"06/04/2021",600);
    // printEmployees();
    
    //-----------------------------------------------------
    //testCase -6
    
    // addEmployee(123,"alma");
    // addPayment(123,"01/02/2020",3000);
    // addPayment(123,"10/07/2021",5000);
    // addEmployee(456,"mike");
    // addPayment(456,"06/03/2020",700);
    // addPayment(456,"07/02/2020",200);
    // addPayment(456,"06/04/2021",600);
    // deleteEmployee(123,"alma");
    // printEmployees();
    
    //-----------------------------------------------------
    //testCase -7
    
    addEmployee(123,"alma");
    addPayment(123,"01/02/2020",3000);
    addPayment(123,"10/07/2021",5000);
    addEmployee(456,"mike");
    addPayment(456,"06/03/2020",700);
    addPayment(456,"07/02/2020",200);
    addPayment(456,"06/04/2021",600);
    deleteEmployee(456,"mike");
    deleteEmployee(123,"alma");
    printEmployees();
    
}


void printEmployee(EMPLOYEE e){
    // Your code here
    printf("NAME: %s, ID: %d\n", e.name, e.id);
    printf("---------------------\n");
    if(e.payments == NULL)
        printf("No Payments..\n");
    else
    {
        printf("Date\t\t\tAmount\n");
        printf("----\t\t\t------\n");
        PAYMENT * p = e.payments;
        while(p != NULL)
        {
            printf("%s\t\t%.6f\n", p->date, p->amount);
            p = p->next;
        }
    }
}

void addEmployee(int e_id, char* e_name){
    // Your code here
    EMPLOYEE *e;
    e = (EMPLOYEE *)malloc(sizeof(EMPLOYEE));
    e->id = e_id;
    e->name = e_name;
    e->next = NULL;
    e->payments = NULL;
    // if(list_of_employees == NULL)
    // {
    //     list_of_employees = e;
    // }
    // else
    // {
    //     e->next = list_of_employees;
    //     list_of_employees = e;
    // }
    e->next = list_of_employees;
    list_of_employees = e;
}

void printEmployees(){
    // Your code here
    EMPLOYEE * e = list_of_employees;
    if(e == NULL)
        printf("The list is empty..\n");
    while(e != NULL)
    {
        printEmployee(*e);
        printf("===================================\n");
        e = e->next;
    }
}

int addPayment(int e_id, char* p_date, float p_amount){
    // Your code here
    EMPLOYEE *e = list_of_employees;
    while(e != NULL && e->id != e_id)
        e = e->next;
    if(e == NULL)
        return 0;
    PAYMENT *p;
    p = (PAYMENT *)malloc(sizeof(PAYMENT));
    p->date = p_date;
    p->amount = p_amount;
    p->next = e->payments;
    e->payments = p;
    return 1;
}

int deleteEmployee(int e_id, char* e_name){
    // Your code here
    EMPLOYEE *e = list_of_employees;
    if (e == NULL)
        return 0;
    // first node
    if(e->id == e_id)
    {
        list_of_employees = e->next;
        free(e);
        return 1;
    }
    // general situation
    while(e->next != NULL && e->next->id != e_id)
        e = e->next;
    if(e == NULL)
        return 0;
    EMPLOYEE *d = e->next;
    e->next = d->next;
    free(d);
    return 1;
}