#include"AdminPesta�as.h"

int main() {
	AdminPesta�as* Admin = new AdminPesta�as();
	Pesta�a* pes1 = new Pesta�a("Pestana1");
	Pesta�a* pes2 = new Pesta�a("Pestana");
	Pesta�a* pes3 = new Pesta�a("Pestana");
	Pesta�a* pes4 = new Pesta�a("Pestana");
	//pes2->activarModoIncognito();
	//pes4->activarModoIncognito();


	//Admin->InsertarPrimero(pes1);
	//Admin->InsertarPrimero(pes2);
	//Admin->InsertarPrimero(pes3);
	//Admin->InsertarPrimero(pes4);

	//Admin->guardarPesta�aBinario();
	//Admin->leerPesta�aBinario();
	//Admin->ExplorarHistorialPesta�as();
	PaginaWeb* pag1 = new PaginaWeb("www.steam.com", "steam");
	PaginaWeb* pag2 = new PaginaWeb("www.aulavirtual.com", "aula virtual");
	PaginaWeb* pag3 = new PaginaWeb("www.xbox.com", "xbox");
	PaginaWeb* pag4 = new PaginaWeb("www.armas.com", "armas");

	Admin->InsertarPrimero(pes1);
	Admin->buscaPaginaWeb("www.steam.com");
	pes1->insertarPrimero(*pag1);
	pes1->insertarPrimero(*pag2);
	pes1->insertarPrimero(*pag3);
	pes1->insertarPrimero(*pag4);
	Admin->guardarHistorialPesta�a();

	//pes1->leerHistorialBinario();
	//pes1->explorarHistorial();

	return 0;
}
