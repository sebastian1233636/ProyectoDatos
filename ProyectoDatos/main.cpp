#include"AdminPesta�as.h"

int main() {
	AdminPesta�as* Admin = new AdminPesta�as();
	Admin->leerPesta�aBinario();
	Admin->leerHistorialPesta�a();
	//Admin->InsertarPrimero(new Pesta�a("Pesta�a 1"));
	Admin->ExplorarHistorialPesta�as();

	return 0;
}
