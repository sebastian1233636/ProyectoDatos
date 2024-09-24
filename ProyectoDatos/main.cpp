#include"AdminPestañas.h"

int main() {
	AdminPestañas* Admin = new AdminPestañas();
	Pestaña* pes1 = new Pestaña("Pestaña 1");
	Pestaña* pes2 = new Pestaña("Pestaña 2");
	Pestaña* pes3 = new Pestaña("Pestaña 3");
	PaginaWeb* pag1 = new PaginaWeb("https://store.steampowered.com", "Steam");
	PaginaWeb* pag2 = new PaginaWeb("https://onlyfans.com", "OnlyFans");
	PaginaWeb* pag3 = new PaginaWeb("https://www.playstation.com", "PlayStation");	
	PaginaWeb* pag4 = new PaginaWeb("https://www.aulavirtual.com", "Aula Virtual");
	pes3->insertarPrimero(pag1);
	pes3->insertarPrimero(pag2);
	pes3->insertarPrimero(pag3);

	Admin->InsertarPrimero(pes1);
	Admin->InsertarPrimero(pes2);
	Admin->InsertarPrimero(pes3);

	Admin->ExplorarHistorialPestañas();
	//cout << pag1->getTiempo() << endl;

	return 0;
}