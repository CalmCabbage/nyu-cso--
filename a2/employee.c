#include "employee.h"
EMPLOYEE* list_of_employees=NULL;

void printEmployee(EMPLOYEE e){
    // Your code here
    printf("NAME: %s, ID:%d\n", e.name, e.id);
    printf("---------------------\n");
    if(e.payments == NULL)
        printf("No Payments.\n");
    else
    {
        PAYMENT * p = e.payments;
        while(p != NULL)
        {
            printf("Date\t\t\t\t\tAmount\n");
            printf("----\t\t\t\t\t------\n");
            printf("%s\t\t\t\t\t%.6f\n");
            p = p->next;
        }
    }
}

void addEmployee(int e_id, char* e_name){
    // Your code here
}

void printEmployees(){
    // Your code here

}

int addPayment(int e_id, char* p_date, float p_amount){
    // Your code here
}

int deleteEmployee(int e_id, char* e_name){
    // Your code here
}