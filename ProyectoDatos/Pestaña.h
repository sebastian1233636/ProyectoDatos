#pragma once
#include"PaginaWeb.h"
#include<Windows.h>
#include<conio.h>

struct NodoPag {
	PaginaWeb* paginaWeb;
	NodoPag* siguiente;
	NodoPag* anterior;

};



class Pesta�a
{
private:
	NodoPag* tail;//primero
	NodoPag* head;//ultimo
public:
	Pesta�a();
	~Pesta�a();
	void InsertarPrimero(PaginaWeb*);
	void ExplorarHistorial(NodoPag*);
	NodoPag* getTail();
	NodoPag* getHead();
	



};

