#include"AdminPesta�as.h"

int main() {
	AdminPesta�as* Admin = new AdminPesta�as();
	Pesta�a* pes1 = new Pesta�a("Pestana 1");

	Admin->InsertarPrimero(pes1);
	Admin->ExplorarHistorialPesta�as();
	

	return 0;
}