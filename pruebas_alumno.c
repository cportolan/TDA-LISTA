#include "pa2m.h"
#include "src/lista.h"
#include "src/cola.h"
#include "src/pila.h"

// PRUEBAS LISTA 

void lista_recien_creada_e_insertando_quitando_elementos_final()
{
	lista_t* lista = lista_crear();

	// Lista recien creada:
	pa2m_afirmar(lista != NULL, "Una lista creada es diferente a NULL.");
	pa2m_afirmar(lista_tamanio(lista) == 0, "Una lista recien creada tiene cantidad igual a 0.");
	pa2m_afirmar(lista_vacia(lista), "Una lista recien esta vacia.");
	pa2m_afirmar(lista_primero(lista) == NULL, "El primer elemento de una lista recien creada es NULL.");
	pa2m_afirmar(lista_ultimo(lista) == NULL, "El ultimo elemento de una lista recien creada es NULL.");

	// Inserto elementos al final:
	void *elemento_1 = (void*)0x1234, *elemento_2 = (void*)0x12345;

	pa2m_afirmar(lista_insertar(lista, elemento_1) == lista, "Se inserta un primer elemento y devuelve la lista.");
	pa2m_afirmar(lista_tamanio(lista) == 1, "Se inserta un primer elemento en la lista y el tamaño ahora es UNO.");
	pa2m_afirmar(lista_vacia(lista) == false, "La lista no esta vacia.");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == elemento_1, "El elemento es el insertado.");

	pa2m_afirmar(lista_insertar(lista, elemento_2) == lista, "Se inserta un segundo elemento y devuelve la lista.");
	pa2m_afirmar(lista_tamanio(lista) == 2, "Se inserta un segundo elemento en la lista y el tamaño ahora es DOS.");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 1) == elemento_2, "El elemento es el insertado.");

	pa2m_afirmar(lista_insertar(lista, NULL) == lista, "Inserta elemento NULL sin problemas.");
	pa2m_afirmar(lista_tamanio(lista) == 3, "Al insertarse el elemento NULL, aumenta la cantidad a TRES.");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 2) == NULL, "El elemento es el insertado (NULL).");

	// Quito elementos al final:
	pa2m_afirmar(lista_quitar(lista) == NULL, "Puedo eliminar el ultimo elemento insertado (NULL).");
	pa2m_afirmar(lista_tamanio(lista) == 2, "Luego de eliminar, el la cantidad de elementos es DOS.");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 1) == elemento_2, "El elemento del final es el anteultimo insertado.");

	pa2m_afirmar(lista_quitar(lista) == elemento_2, "Puedo eliminar el ultimo elemento de la lista.");
	pa2m_afirmar(lista_tamanio(lista) == 1, "Luego de eliminar, el la cantidad de elementos es DOS.");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == elemento_1, "El elemento luego de eliminar es el correcto.");

	pa2m_afirmar(lista_quitar(lista) == elemento_1, "Puedo eliminar el ultimo elemento existente de la lista.");
	pa2m_afirmar(lista_tamanio(lista) == 0, "Luego de eliminar, el la cantidad de elementos es UNO.");
	pa2m_afirmar(lista_vacia(lista), "La lista quedo vacia.");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == NULL, "Si la lista queda sin elementos, al acceder a un elemento devuelve NULL.");

	lista_destruir(lista);
}

// INSERCION LISTA EN POSICION X

void lista_recien_creada_e_insertando_quitando_elementos_en_posicion()
{
	lista_t* lista = lista_crear();
	void *elemento_1 = (void*)0x1234, *elemento_2 = (void*)0x12345;

	pa2m_afirmar(lista_vacia(lista), "La lista recien creada esta vacia.");

	pa2m_afirmar(lista_quitar_de_posicion(lista, 50) == NULL, "Borrar en una lista vacia devuelve NULL.");

	pa2m_afirmar(lista_insertar_en_posicion(lista, elemento_2, 0) == lista, "Se inserta un elemento en la posicion 0 y devuelve la lista.");
	pa2m_afirmar(lista_tamanio(lista) == 1, "Se inserta un primer elemento en la lista y el tamaño ahora es UNO.");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == elemento_2, "El elemento en la posicion 0 es el insertado.");

	pa2m_afirmar(lista_insertar_en_posicion(lista, elemento_1, 50) == lista, "Se inserta un elemento en la posicion 50 (se inserta al final, pos 1) y devuelve la lista.");
	pa2m_afirmar(lista_tamanio(lista) == 2, "El tamaño ahora es DOS.");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 1) == elemento_1, "El elemento en la posicion 1 es el insertado.");

	pa2m_afirmar(lista_insertar_en_posicion(lista, elemento_1, 2) == lista, "Se inserta un elemento en la posicion 2 y devuelve la lista.");
	pa2m_afirmar(lista_tamanio(lista) == 3, "Aumenta el tamaño a 3.");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 2) == elemento_1, "El elemento en la posicion 2 es el correcto.");

	pa2m_afirmar(lista_insertar_en_posicion(lista, elemento_2, 2) == lista, "Se inserta nuevamente un elemento en la posicion 2 y devuelve la lista.");
	pa2m_afirmar(lista_tamanio(lista) == 4, "Aumenta el tamaño a 4.");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 2) == elemento_2, "El elemento en la posicion 2 es el correcto.");

	pa2m_afirmar(lista_quitar_de_posicion(lista, 50) == elemento_1, "Borrar en una posicion inexistente elimina el ultimo elemento.");
	pa2m_afirmar(lista_tamanio(lista) == 3, "Disminuye el tamaño a 3.");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 2) == elemento_2, "El elemento en la posicion 2 es el correcto.");

	pa2m_afirmar(lista_quitar_de_posicion(lista, 1) == elemento_1, "Se elimina el elemento de la posicion 1 y es el correcto.");
	pa2m_afirmar(lista_tamanio(lista) == 2, "Disminuye el tamaño a 2.");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 1) == elemento_2, "El nuevo elemento en la posicion 1 es el correcto.");

	pa2m_afirmar(lista_quitar_de_posicion(lista, 2) == elemento_2, "Se elimina nuevamente el elemento de la posicion 1 y es el correcto.");
	pa2m_afirmar(lista_tamanio(lista) == 1, "Disminuye el tamaño a 1.");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == elemento_2, "El nuevo elemento en la posicion 0 es el correcto.");

	pa2m_afirmar(lista_quitar_de_posicion(lista, 0) == elemento_2, "Se elimina el elemento de la posicion 0 y es el correcto.");
	pa2m_afirmar(lista_tamanio(lista) == 0, "Disminuye el tamaño a 0.");
	pa2m_afirmar(lista_vacia(lista), "La lista queda vacia.");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == NULL, "El ultimo elemento de una lista vacia es NULL.");

	lista_destruir(lista);
}

// PRUEBAS PILA 

void pruebas_pila()
{
	pila_t* pila = pila_crear();
	void *elemento_1 = (void*)0x1234, *elemento_2 = (void*)0x12345;

	pa2m_afirmar(pila_vacia(pila) == true, "Una pila recien creada esta vacia.");

	pa2m_afirmar(pila_apilar(pila, elemento_1) == pila, "Puedo apilar, se devuelve la pila.");
	pa2m_afirmar(pila_tamanio(pila) == 1, "La cantidad de elementos ahora es UNO.");
	pa2m_afirmar(pila_tope(pila) == elemento_1, "El tope (elemento) es el correcto.");
	pa2m_afirmar(pila_vacia(pila) == false, "Al apilar un elemento, ya no esta vacia.");

	pa2m_afirmar(pila_apilar(pila, elemento_2) == pila, "Apilo nuevamente, se devuelve la pila.");
	pa2m_afirmar(pila_tamanio(pila) == 2, "La cantidad de elementos ahora es DOS.");
	pa2m_afirmar(pila_tope(pila) == elemento_2, "El tope (elemento) es el correcto.");

	pa2m_afirmar(pila_desapilar(pila) == elemento_2, "Puedo desapilar, se devuelve el elemento correcto.");
	pa2m_afirmar(pila_tamanio(pila) == 1, "La cantidad de elementos ahora es UNO.");
	pa2m_afirmar(pila_tope(pila) == elemento_1, "El tope (elemento) es el correcto.");

	pa2m_afirmar(pila_desapilar(pila) == elemento_1, "Vuelvo a desapilar y devuelve el elemento correcto.");
	pa2m_afirmar(pila_vacia(pila) == true, "Ahora la pila esta vacia.");
	pa2m_afirmar(pila_tamanio(pila) == 0, "Cantidad de elementos es CERO.");
	pa2m_afirmar(pila_tope(pila) == NULL, "Al tener una pila vacia, el tope es NULL.");

	pila_destruir(pila);
}

// PRUEBAS COLA

void pruebas_cola()
{
	cola_t* cola = cola_crear();
	void *elemento_1 = (void*)0x1234, *elemento_2 = (void*)0x12345;

	pa2m_afirmar(cola_vacia(cola) == true, "Una cola recien creada esta vacia.");

	pa2m_afirmar(cola_encolar(cola, elemento_1) == cola, "Encolo un elemento y devuelve la lista.");
	pa2m_afirmar(cola_tamanio(cola) == 1, "La cantidad de elementos ahora es UNO.");
	pa2m_afirmar(cola_frente(cola) == elemento_1, "El frente es el elemento correcto.");
	pa2m_afirmar(cola_vacia(cola) == false, "Al encolar un elemento, ya no esta vacia.");

	pa2m_afirmar(cola_encolar(cola, elemento_2) == cola, "Encolo otro elemento y devuelve la lista.");
	pa2m_afirmar(cola_tamanio(cola) == 2, "La cantidad de elementos ahora es UNO.");
	pa2m_afirmar(cola_frente(cola) == elemento_1, "El frente es el elemento correcto.");

	pa2m_afirmar(cola_desencolar(cola) == elemento_1, "Desencolo y devuelve el elemento correcto.");
	pa2m_afirmar(cola_frente(cola) == elemento_2, "El frente es el elemento correcto.");
	pa2m_afirmar(cola_tamanio(cola) == 1, "La cantidad de elementos ahora es UNO.");

	pa2m_afirmar(cola_desencolar(cola) == elemento_2, "Desencolo nuevamente y el elemento es correcto.");
	pa2m_afirmar(cola_frente(cola) == NULL, "Ahora el frente es NULL.");
	pa2m_afirmar(cola_vacia(cola) == true, "La cola esta vacia.");
	pa2m_afirmar(cola_tamanio(cola) == 0, "La cantidad de elementos ahora es CERO.");

	cola_destruir(cola);
}

int main()
{
	pa2m_nuevo_grupo("PRUEBAS LISTA");

	pa2m_nuevo_grupo("Crear una lista, insertar al final y quitar al final:");
	lista_recien_creada_e_insertando_quitando_elementos_final();
	pa2m_nuevo_grupo("Crear una lista, y luego insertar y eliminar en posicion x.");
	lista_recien_creada_e_insertando_quitando_elementos_en_posicion();

	pa2m_nuevo_grupo("PRUEBAS PILA");
	pruebas_pila();

	pa2m_nuevo_grupo("PRUEBAS COLA");
	pruebas_cola();

	return pa2m_mostrar_reporte();
}
