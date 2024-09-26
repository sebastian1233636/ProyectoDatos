#include"AdminPestañas.h"

int main() {
	AdminPestañas* Admin = new AdminPestañas();
	
	Pestaña* pes1 = new Pestaña("Pestala 1");
	Admin->InsertarPrimero(pes1);
	Admin->ExplorarHistorialPestañas();

	return 0;
}
