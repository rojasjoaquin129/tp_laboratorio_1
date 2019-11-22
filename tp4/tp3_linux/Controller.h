#ifndef controller_H_INCLUDED
#define controller_H_INCLUDED

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int ll_getIdMax(LinkedList*pArrayListEmployee);
int controller_listModific (LinkedList*pArrayListEmployee,void*auxEmpleado);
int ll_getIndexById(LinkedList* this,int idIn,int*posicion );
int comparaEmpleados(void* pEmpleadoA,void* pEmpleadoB);
int ll_removeLinkedlist(LinkedList* this );
#endif // controller_H_INCLUDED
