#include"AdminPesta�as.h"

int main() {
	AdminPesta�as* Admin = new AdminPesta�as();
	Pesta�a* pes1 = new Pesta�a("Pesta�a 1");
	Pesta�a* pes2 = new Pesta�a("Pesta�a 2");
	Pesta�a* pes3 = new Pesta�a("Pesta�a 3");
	PaginaWeb* pag1 = new PaginaWeb("https://store.steampowered.com", "Steam");
	PaginaWeb* pag2 = new PaginaWeb("https://onlyfans.com", "OnlyFans");
	PaginaWeb* pag3 = new PaginaWeb("https://www.playstation.com", "PlayStation");	
	PaginaWeb* pag4 = new PaginaWeb("https://www.aulavirtual.com", "Aula Virtual");

	Admin->InsertarPrimero(pes1);
	Admin->InsertarPrimero(pes2);
	Admin->InsertarPrimero(pes3);
	Admin->ExplorarHistorialPesta�as();
	return 0;
}