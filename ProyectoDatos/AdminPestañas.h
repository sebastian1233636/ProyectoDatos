#ifndef ADMINPESTA�AS_H
#define ADMINPESTA�AS_H

#include"Pesta�a.h"

struct NodoPest {
	Pesta�a* pesta�a;
	NodoPest* siguiente;
	NodoPest* anterior;
};

class AdminPesta�as{
private:
	NodoPest* tail;//Primero
	NodoPest* head;//Ultimo
public:
	AdminPesta�as();
	~AdminPesta�as();

	NodoPest* getTail();
	NodoPest* getHead();

	void InsertarPrimero(Pesta�a*);
	void ExplorarHistorialPesta�as();
};
#endif