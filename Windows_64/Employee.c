#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include <string.h>


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    int returnAux = 0;
    Employee* a;
    Employee* b;

    a = (Employee*) pEmployeeA;
    b = (Employee*) pEmployeeB;

    returnAux = strcmp(a->name, b->name);

    if(returnAux == 0)
    {
        returnAux = strcmp(a->lastName, b->lastName);
    }

    return returnAux;
}


void employee_print(Employee* this)
{
    printf(EMPLOYEE_SHOW_MASK,this->id, this->name, this->lastName, this->isEmpty);
}


Employee* employee_new(void)
{
    Employee* returnAux = NULL;

    returnAux = (Employee*)malloc(sizeof(Employee));

    return returnAux;
}

Employee* employee_newParam(int id, char* name, char* lastName, int isEmpty)
{
    Employee* returnAux;

    returnAux = employee_new();

    employee_setId(returnAux,id);
    employee_setIsEmpty(returnAux,isEmpty);
    employee_setName(returnAux,name);
    employee_setLastName(returnAux,lastName);

    return returnAux;
}

void employee_delete(Employee* this)
{
    employee_setIsEmpty(this, EMPTY);
}

int employee_getId(Employee* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = this->id;
    }
    return returnAux;
}

int employee_getIsEmpty(Employee* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = this->isEmpty;
    }
    return returnAux;
}

char* employee_getName(Employee* this)
{
    char* returnAux = NULL;
    if(this != NULL)
    {
        returnAux = this->name;
    }
    return returnAux;
}

char* employee_getLastName(Employee* this)
{
    char* returnAux = NULL;
    if(this != NULL)
    {
        returnAux = this->lastName;
    }
    return returnAux;
}

int employee_setId(Employee* this, int id)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = 0;
        this->id = id;
    }
    return returnAux;
}

int employee_setIsEmpty(Employee* this, int isEmpty)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = 0;
        this->isEmpty = isEmpty;
    }
    return returnAux;
}

int employee_setName(Employee* this, char* name)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = 0;
        strcpy(this->name, name);
    }
    return returnAux;
}

int employee_setLastName(Employee* this, char* lastName)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = 0;
        strcpy(this->lastName, lastName);
    }
    return returnAux;
}
