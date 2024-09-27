#include"AdminPestañas.h"

int main() {
	AdminPestañas* Admin = new AdminPestañas();
	Admin->leerPestañaBinario();
	Admin->leerHistorialPestaña();

	Admin->ExplorarHistorialPestañas();

	return 0;
}
