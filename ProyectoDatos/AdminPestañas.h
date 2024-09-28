#ifndef ADMINPESTA�AS_H
#define ADMINPESTA�AS_H

#include"Pesta�a.h"

struct NodoPest {
	Pesta�a* pesta�a;
	NodoPest* siguiente;
	NodoPest* anterior;
};

class AdminPesta�as {
private:
	NodoPest* tail;//Primero
	NodoPest* head;//Ultimo
	int tam;
public:
	//Construtor y Destructor
	AdminPesta�as();
	~AdminPesta�as();

	//Metodos de lista
	NodoPest* getTail();
	NodoPest* getHead();
	void iniciarNavegador();
	void InsertarPrimero(Pesta�a*);
	void ExplorarHistorialPesta�as();
	void BuscarFavorito();
	int contadorPesta�as();
	void menuAdminPesta�as(NodoPest* actual);
	PaginaWeb* buscaPaginaWeb(string);

	//archivos
	void guardarPesta�aBinario();
	void leerPesta�aBinario();
	void guardarHistorialPesta�a();
	void leerHistorialPesta�a();
};
#endif
