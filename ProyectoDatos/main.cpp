#include"AdminPestañas.h"

int main() {
	AdminPestañas* Admin = new AdminPestañas();
	Pestaña* pes1 = new Pestaña("Pestana 1");

	PaginaWeb* pag1 = new PaginaWeb("www.steam.com", "steam");
	PaginaWeb* pag2 = new PaginaWeb("www.aulavirtual.com", "aula virtual");
	PaginaWeb* pag3 = new PaginaWeb("www.xbox.com", "xbox");
	PaginaWeb* pag4 = new PaginaWeb("www.armas.com", "armas");

	/*pes1->insertarPrimero(*pag1);
	pes1->insertarPrimero(*pag2);
	pes1->insertarPrimero(*pag3);
	pes1->insertarPrimero(*pag4);
	pes1->guardarHistorialBinario();*/

	pes1->leerHistorialBinario();
	pes1->explorarHistorial();
	
	
	
	

	return 0;
}