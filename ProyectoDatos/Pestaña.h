#ifndef PESTA�A_H
#define PESTA�A_H

#include"PaginaWeb.h"

struct NodoPag {
	PaginaWeb* paginaWeb;
	NodoPag* siguiente;
	NodoPag* anterior;
};

class Pesta�a{
private:
	NodoPag* tail;//Primero
	NodoPag* head;//Ultimo
	bool modoIcognito;
	string nombre;
public:
	Pesta�a(string);
	~Pesta�a();

	NodoPag* getTail();
	NodoPag* getHead();

	void insertarPrimero(PaginaWeb*);
	void explorarHistorial();
	void activarModoIcognito(); 
	void desactivarModoIcognito(); 
	string mostrarPesta�a();

};
#endif