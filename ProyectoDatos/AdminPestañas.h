#ifndef ADMINPESTAÑAS_H
#define ADMINPESTAÑAS_H

#include"Pestaña.h"
// Estructura para crear una lista doblemente enlazada que almacena pestañas.

struct NodoPest {
	Pestaña* pestaña;// Apuntador a una instancia de Pestaña.
	NodoPest* siguiente;// Apuntador al siguiente nodo en la lista.
	NodoPest* anterior;// Apuntador al nodo anterior en la lista.
};
// Clase que administra una lista doblemente enlazada de pestañas.
// Administra operaciones como la inserción de pestañas, exploración del historial, búsqueda de favoritas, entre otras.

class AdminPestañas {
private:
	NodoPest* tail;//Primero
	NodoPest* head;//Ultimo
	int tam; // Tamaño actual de la lista de pestañas (cantidad de pestañas).
public:
<<<<<<< HEAD
	//Construtor y Destructor
	AdminPestañas();
	~AdminPestañas();

	//Metodos de lista
	NodoPest* getTail();
	NodoPest* getHead();
=======
	// Constructores y destructor.
	AdminPestañas();
	~AdminPestañas();
	// GETTERS
	NodoPest* getTail();
	NodoPest* getHead();
	// Inserta una nueva pestaña al inicio de la lista (actualiza el tail).
>>>>>>> documentacion interna
	void InsertarPrimero(Pestaña*);
	// Recorre y muestra todas las pestañas en el historial desde la más reciente (tail) hasta la más antigua (head).
	void ExplorarHistorialPestañas();
	// Busca pestañas que están marcadas como favoritas y las muestra.
	void BuscarFavorito();
	// Devuelve el número total de pestañas actualmente almacenadas en la lista.
	int contadorPestañas();
	// Muestra un menú con opciones de administración de pestañas. 
	// Recibe un nodo actual para facilitar la navegación entre las pestañas.
	void menuAdminPestañas(NodoPest* actual);
	PaginaWeb* buscaPaginaWeb(string);

	//archivos
	void guardarPestañaBinario();
	void leerPestañaBinario();
	void guardarHistorialPestaña();
	void leerHistorialPestaña();
};
#endif
