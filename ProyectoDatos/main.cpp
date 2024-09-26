#include"AdminPestañas.h"

int main() {
	AdminPestañas* Admin = new AdminPestañas();
	Admin->leerPestañaBinario();
	Admin->leerHistorialPestaña();
	//Admin->InsertarPrimero(new Pestaña("Pestaña 1"));
	Admin->ExplorarHistorialPestañas();

	return 0;
}
