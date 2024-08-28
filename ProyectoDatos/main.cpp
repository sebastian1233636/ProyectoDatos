#include<iostream>
#include"AdminPestañas.h"
using namespace std;

int main() {
	
	Pestaña* pes = new Pestaña();
	PaginaWeb* pag1 = new PaginaWeb("aaaaa", "Steam");
	PaginaWeb* pag2 = new PaginaWeb("bbbbb", "OnlyFans");
	PaginaWeb* pag3 = new PaginaWeb("ccccc", "PlayStation");
	pes->AgregarAlHistorial(pag1);
	pes->AgregarAlHistorial(pag2);
	pes->AgregarAlHistorial(pag3);

	pes->mostrarHistorial();


	
	return 0;
}
