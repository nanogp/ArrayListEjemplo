/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
#define EMPTY 1
#define OCCUPY 0
#define TRUE "true"
#define FALSE "false"

#define EMPLOYEE_SHOW_MASK "\n%d \t %s \t %s \t %d"

struct
{
    int id;
    char name[51];
    char lastName[51];
    int isEmpty;

}typedef Employee;


int employee_compare(void* pEmployeeA,void* pEmployeeB);
void employee_print(Employee* this);
Employee* employee_new(void);
Employee* employee_newParam(int id, char* name, char* lastName, int isEmpty);
void employee_delete(Employee* this);
int employee_getId(Employee* this);
int employee_getIsEmpty(Employee* this);
char* employee_getName(Employee* this);
char* employee_getLastName(Employee* this);
int employee_setId(Employee* this, int id);
int employee_setIsEmpty(Employee* this, int isEmpty);
int employee_setName(Employee* this, char* name);
int employee_setLastName(Employee* this, char* lastName);
#endif // _EMPLOYEE_H



