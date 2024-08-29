#pragma once
#include"PaginaWeb.h"
#include<Windows.h>
#include<conio.h>

struct NodoPag {
	PaginaWeb* paginaWeb;
	NodoPag* siguiente;
	NodoPag* anterior;

};



class Pestaña
{
private:
	NodoPag* tail;//primero
	NodoPag* head;//ultimo
public:
	Pestaña();
	~Pestaña();
	void InsertarPrimero(PaginaWeb*);
	void ExplorarHistorial(NodoPag*);
	NodoPag* getTail();
	NodoPag* getHead();
	



};

