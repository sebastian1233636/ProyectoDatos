#ifndef PESTAÑA_H
#define PESTAÑA_H

#include"PaginaWeb.h"

struct NodoPag {
	PaginaWeb* paginaWeb;
	NodoPag* siguiente;
	NodoPag* anterior;
};

class Pestaña{
private:
	NodoPag* tail;//Primero
	NodoPag* head;//Ultimo
	bool modoIcognito;
public:
	Pestaña();
	~Pestaña();

	NodoPag* getTail();
	NodoPag* getHead();

	void insertarPrimero(PaginaWeb*);
	void explorarHistorial();
	void activarModoIcognito(); 
	void desactivarModoIcognito(); 

};
#endif