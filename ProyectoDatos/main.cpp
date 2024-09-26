#include"AdminPestañas.h"

int main() {
	AdminPestañas* Admin = new AdminPestañas();
	Pestaña* pes1 = new Pestaña("Pestana1");
	Pestaña* pes2 = new Pestaña("Pestana");
	Pestaña* pes3 = new Pestaña("Pestana");
	Pestaña* pes4 = new Pestaña("Pestana");
	//pes2->activarModoIncognito();
	//pes4->activarModoIncognito();


	//Admin->InsertarPrimero(pes1);
	//Admin->InsertarPrimero(pes2);
	//Admin->InsertarPrimero(pes3);
	//Admin->InsertarPrimero(pes4);

	//Admin->guardarPestañaBinario();
	//Admin->leerPestañaBinario();
	//Admin->ExplorarHistorialPestañas();
	PaginaWeb* pag1 = new PaginaWeb("www.steam.com", "steam");
	PaginaWeb* pag2 = new PaginaWeb("www.aulavirtual.com", "aula virtual");
	PaginaWeb* pag3 = new PaginaWeb("www.xbox.com", "xbox");
	PaginaWeb* pag4 = new PaginaWeb("www.armas.com", "armas");

	pes1->insertarPrimero(*pag1);
	pes1->insertarPrimero(*pag2);
	pes1->insertarPrimero(*pag3);
	pes1->insertarPrimero(*pag4);
	Admin->guardarHistorialPestaña();

	//pes1->leerHistorialBinario();
	//pes1->explorarHistorial();
	
	return 0;
}
