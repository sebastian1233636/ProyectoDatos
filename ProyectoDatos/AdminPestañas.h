#ifndef ADMINPESTA�AS_H
#define ADMINPESTA�AS_H

#include"Pesta�a.h"
// Estructura para crear una lista doblemente enlazada que almacena pesta�as.

struct NodoPest {
	Pesta�a* pesta�a;// Apuntador a una instancia de Pesta�a.
	NodoPest* siguiente;// Apuntador al siguiente nodo en la lista.
	NodoPest* anterior;// Apuntador al nodo anterior en la lista.
};
// Clase que administra una lista doblemente enlazada de pesta�as.
// Administra operaciones como la inserci�n de pesta�as, exploraci�n del historial, b�squeda de favoritas, entre otras.

class AdminPesta�as {
private:
	NodoPest* tail;//Primero
	NodoPest* head;//Ultimo
	int tam; // Tama�o actual de la lista de pesta�as (cantidad de pesta�as).
public:
<<<<<<< HEAD
	//Construtor y Destructor
	AdminPesta�as();
	~AdminPesta�as();

	//Metodos de lista
	NodoPest* getTail();
	NodoPest* getHead();
=======
	// Constructores y destructor.
	AdminPesta�as();
	~AdminPesta�as();
	// GETTERS
	NodoPest* getTail();
	NodoPest* getHead();
	// Inserta una nueva pesta�a al inicio de la lista (actualiza el tail).
>>>>>>> documentacion interna
	void InsertarPrimero(Pesta�a*);
	// Recorre y muestra todas las pesta�as en el historial desde la m�s reciente (tail) hasta la m�s antigua (head).
	void ExplorarHistorialPesta�as();
	// Busca pesta�as que est�n marcadas como favoritas y las muestra.
	void BuscarFavorito();
	// Devuelve el n�mero total de pesta�as actualmente almacenadas en la lista.
	int contadorPesta�as();
	// Muestra un men� con opciones de administraci�n de pesta�as. 
	// Recibe un nodo actual para facilitar la navegaci�n entre las pesta�as.
	void menuAdminPesta�as(NodoPest* actual);
	PaginaWeb* buscaPaginaWeb(string);

	//archivos
	void guardarPesta�aBinario();
	void leerPesta�aBinario();
	void guardarHistorialPesta�a();
	void leerHistorialPesta�a();
};
#endif
