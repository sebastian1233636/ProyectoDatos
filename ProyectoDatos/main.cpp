#include"AdminPesta�as.h"

int main() {
	AdminPesta�as* Admin = new AdminPesta�as();
	Pesta�a* pes = new Pesta�a("Pes1");
	PaginaWeb* pag1 = new PaginaWeb("www.aulavirtual.com", "aula1");
	PaginaWeb* pag2 = new PaginaWeb("www.aulavirtual2.com", "aula2");
	PaginaWeb* pag3 = new PaginaWeb("www.aulavirtual3.com", "aula3");
	PaginaWeb* pag4 = new PaginaWeb("www.steam.com", "steam");
	Admin->InsertarPrimero(pes);
	Admin->ExplorarHistorialPesta�as();

	return 0;
}
