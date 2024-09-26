#ifndef ADMINPESTAÑAS_H
#define ADMINPESTAÑAS_H

#include"Pestaña.h"

struct NodoPest {
	Pestaña* pestaña;
	NodoPest* siguiente;
	NodoPest* anterior;
};

class AdminPestañas {
private:
	NodoPest* tail;//Primero
	NodoPest* head;//Ultimo
	int tam;
public:
	AdminPestañas();
	~AdminPestañas();

	NodoPest* getTail();
	NodoPest* getHead();

	void InsertarPrimero(Pestaña*);
	void ExplorarHistorialPestañas();
	void BuscarFavorito();
	int contadorPestañas();
	void menuAdminPestañas(NodoPest* actual);
	PaginaWeb* buscaPaginaWeb(string);

	void guardarPestañaBinario();
	void leerPestañaBinario();
	void guardarHistorialPestaña();
	void leerHistorialPestaña();
};
#endif
