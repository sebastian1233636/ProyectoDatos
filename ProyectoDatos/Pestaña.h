#pragma once

#include<list>
#include"PaginaWeb.h"
#include<Windows.h>
class Pesta�a
{
private:
	list<PaginaWeb> Historial;
public:
	void AgregarAlHistorial(PaginaWeb*);
	PaginaWeb Avanzar(list<PaginaWeb>::iterator);
	PaginaWeb Retroceder(list<PaginaWeb>::iterator);
	void mostrarHistorial();
	



};

