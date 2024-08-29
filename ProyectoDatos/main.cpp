#include<iostream>
#include"AdminPestañas.h"
using namespace std;

int main() {
	
	Pestaña* pes = new Pestaña();
	PaginaWeb* pag1 = new PaginaWeb("aaaaa", "Steam");
	PaginaWeb* pag2 = new PaginaWeb("bbbbb", "OnlyFans");
	PaginaWeb* pag3 = new PaginaWeb("ccccc", "PlayStation");
	pes->InsertarPrimero(pag1);
	pes->InsertarPrimero(pag2);
	pes->InsertarPrimero(pag3);
	pes->ExplorarHistorial(pes->getTail());

	
	return 0;
}
