#include"AdminPestañas.h"

int main() {
	AdminPestañas* Admin = new AdminPestañas();
	Pestaña* pes = new Pestaña("Pes1");
	PaginaWeb* pag1 = new PaginaWeb("www.aulavirtual.com", "aula1");
	PaginaWeb* pag2 = new PaginaWeb("www.aulavirtual2.com", "aula2");
	PaginaWeb* pag3 = new PaginaWeb("www.aulavirtual3.com", "aula3");
	PaginaWeb* pag4 = new PaginaWeb("www.steam.com", "steam");
	Admin->InsertarPrimero(pes);
	pes->insertarPrimero(*pag1);
	pes->insertarPrimero(*pag2);
	pes->insertarPrimero(*pag3);
	Admin->ExplorarHistorialPestañas();

	return 0;
}
