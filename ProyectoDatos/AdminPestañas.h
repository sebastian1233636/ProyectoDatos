#ifndef ADMINPESTAÑAS_H
#define ADMINPESTAÑAS_H

#include"Pestaña.h"

struct NodoPest {
	Pestaña* pestaña;
	NodoPest* siguiente;
	NodoPest* anterior;
};

class AdminPestañas{
private:
	NodoPest* tail;//Primero
	NodoPest* head;//Ultimo
public:
	AdminPestañas();
	~AdminPestañas();

	NodoPest* getTail();
	NodoPest* getHead();

	void InsertarPrimero(Pestaña*);
	void ExplorarHistorialPestañas();
};
#endif