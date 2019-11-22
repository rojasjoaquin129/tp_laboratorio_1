#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = malloc(sizeof(LinkedList));
    this->pFirstNode=NULL;
    this->size=0;

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNodo=NULL;
	int saltos;
	if(this != NULL && nodeIndex >= 0 && nodeIndex < this->size)
	{
		pNodo = this->pFirstNode;
		for(saltos=0;saltos<nodeIndex;saltos++)
		{
			pNodo = pNodo->pNextNode;
		}
	}
    return pNodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNodo;
    Node* pNodoAnterior;
	if(this != NULL && nodeIndex >= 0 && nodeIndex <= this->size)
	{
		pNodo = malloc(sizeof(pNodo));
		if(pNodo == NULL) return -1;

		returnAux = 0;
		this->size++;
		pNodo->pElement = pElement;
		if(nodeIndex == 0)
		{
			pNodo->pNextNode = this->pFirstNode;
			this->pFirstNode = pNodo;
		}
		else
		{
			pNodoAnterior = getNode(this,nodeIndex-1);
			pNodo->pNextNode = pNodoAnterior->pNextNode;
			pNodoAnterior->pNextNode = pNodo;
		}
	}
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
	int returnAux = -1;
	if(this!=NULL ){
		if(addNode(this,this->size,pElement)!=-1){
			returnAux=0;
		}

	}



    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node*pAux=NULL;
    if(this != NULL && index >= 0 && index < this->size){
    	pAux=getNode(this,index);
    	if(pAux!=NULL){
    		returnAux=(Node*)pAux->pElement;
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node*pAux=NULL;
    if(this != NULL && index >= 0 && index < this->size){
       	pAux=getNode(this,index);
       	if(pAux!=NULL){
       	pAux->pElement=pElement;
       	returnAux=0;
       	}
       }


    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNodo;
    Node* pNodoAnterior;
	if(this != NULL && index >= 0 && index <= this->size)
	{

		pNodo = getNode(this,index);
		if(pNodo == NULL) return -1;

		returnAux = 0;
		this->size--;

		if(index == 0)
		{
			this->pFirstNode=pNodo->pNextNode;

		}
		else
		{
			pNodoAnterior = getNode(this,index-1);
			pNodoAnterior->pNextNode=pNodo->pNextNode;


		}
		free(pNodo);
	}
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
	int returnAux = -1;
	int i=0;
	int len=0;
	if(this!=NULL){
		len=this->size;
		returnAux=0;
		for(i=len;i>0;i--){
			ll_remove(this,0);
		}

	}
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL){
    	ll_clear(this);
    	free(this);
    	returnAux=0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    void*elemento;
    int i=0;
    int len=0;
    if(this!=NULL){
    	len=ll_len(this);
    	for(i=0;i<len;i++){
    		elemento=ll_get(this,i);
    		if(elemento==pElement){
    			returnAux=i;
    			break;
    		}

    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL){
    	if(this->size==0){
    		returnAux=1;
    	}else{
    		returnAux=0;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
	int returnAux = -1;
	if(this != NULL && index >= 0 && index <= this->size){
		if(addNode(this,index,pElement)!=-1){
			returnAux=0;
		}

	}



    return returnAux;
}



/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL && index >= 0 && index <= this->size){
    	returnAux=ll_get(this,index);
    	ll_remove(this,index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL){
    	returnAux=0;
    if(ll_indexOf(this,pElement)!=-1){
    	returnAux=1;
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int len =0;
    int i=0;
    int cont=0;
    void*element;
    if(this!=NULL && this2!=NULL) {
    	len=ll_len(this2);
    	returnAux=0;
    	for(i=0;i<len;i++){
    		element=ll_get(this2,i);
    		if(ll_contains(this,element)==1){
    			cont++;
    		}
    	}
    	if(cont==len){
    		returnAux=1;
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int tamThis = ll_len(this);
    void* pElement = NULL;

    if(this != NULL && tamThis > -1 && (from >= 0 && from < tamThis) && (to > from  && to <= tamThis) )
    {
        cloneArray = ll_newLinkedList();

        if(cloneArray != NULL)
        {
            for(int i=from; i<to; i++)
            {
                pElement = ll_get(this, i);
                if(pElement != NULL)
                {
                    ll_add(cloneArray, pElement);
                }
            }
        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
        cloneArray = ll_subList(this, 0, ll_len(this));
    }

    return cloneArray;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
	int i;
	int j;
	int flagOrdeno;
	void* swap;
	void* swapAnterior;
	int len =ll_len(this);
if (this!=NULL && pFunc !=NULL && (order==1 || order==0) ){
	for(i=1; i<len; i++){
		j=i;
		flagOrdeno = 1;
		while(flagOrdeno != 0 && j!=0){
			flagOrdeno = 0;

			if(pFunc(ll_get(this,j),ll_get(this,j-1))>0 && order==0 ){
				swapAnterior = ll_get(this,j-1);
				swap=ll_get(this,j);
				ll_set(this,j-1,swap);
				//array[j-1] = array[j];
				ll_set(this,j,swapAnterior);
				//array[j] = swap;
				flagOrdeno = 1;
			}
			if(pFunc(ll_get(this,j),ll_get(this,j-1))<0 && order!=0 ){
							swapAnterior = ll_get(this,j-1);
							swap=ll_get(this,j);
							ll_set(this,j-1,swap);
							//array[j-1] = array[j];
							ll_set(this,j,swapAnterior);
							//array[j] = swap;
							flagOrdeno = 1;
						}
			j--;
		}
		returnAux=0;
	}
}

    return returnAux;

}

int ll_map(LinkedList* this, int (*pFunc)(void*)){
	int retorno =-1;
	int i=0;
	int len=0;
	if(this!=NULL && pFunc!=NULL){
		len=ll_len(this);
		for(i=0;i<len;i++){

			pFunc(ll_get(this,i));

		}
	}
	return retorno;
}

LinkedList* filter (LinkedList* this,int(* pFunc)(void*))
{
    LinkedList* cloneArray = NULL;
    void* pElement = NULL;
    int len =0;
    int i=0;
    if(this != NULL && pFunc !=NULL )
    {
        cloneArray = ll_newLinkedList();
        len=ll_len(this);
        if(cloneArray != NULL)
        {
            for(i=0; i<len; i++)
            {
            	pElement=ll_get(this,i);
                if(pFunc(pElement)==1)
                {
                    ll_add(cloneArray, pElement);

                }

            }
        }
    }

    return cloneArray;
}
