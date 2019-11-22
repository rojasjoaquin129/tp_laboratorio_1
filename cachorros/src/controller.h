/*
 * controller.h
 *
 *  Created on: 21 nov. 2019
 *      Author: alumno
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFromText(char* path, LinkedList* pArrayList);
int ll_removeLinkedlist(LinkedList* this );
int controller_List(LinkedList* pArrayList);
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee);
#endif /* CONTROLLER_H_ */
