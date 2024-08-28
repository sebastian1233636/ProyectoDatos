#include "Pestaña.h"




void Pestaña::AgregarAlHistorial(PaginaWeb* pag)
{
	Historial.push_front(*pag);
}

PaginaWeb Pestaña::Avanzar(list<PaginaWeb>::iterator iter)
{
	if (iter == Historial.end()) {
		cout << "No hay mas paginas para mostrar" << endl;
		return PaginaWeb("ULTIMO PAGINA","");
	}
	else {

		PaginaWeb pagina = *iter;
		std::cout << "Mostrando página: " << endl;

		iter->MostrarPaginaWeb();
		return Avanzar(++iter);
		
	}

}

PaginaWeb Pestaña::Retroceder(list<PaginaWeb>::iterator iter)
{
	if (iter == Historial.begin()) {
		cout << "No hay mas paginas para mostrar" << endl;
		return PaginaWeb("PRIMERA PAGINA", "");
	}
	else {
		PaginaWeb pagina = *iter;
		std::cout << "Mostrando página: " << endl;

		iter->MostrarPaginaWeb();
		
		return Retroceder(--iter);
	}
}

void Pestaña::mostrarHistorial()
{
	list<PaginaWeb>::iterator iter;
	iter = Historial.begin();
	bool bandera = true;
	system("cls");
	cout << "Oprima las felchas de arriba o abajo para avanzar y retroceder" << endl;
	while (bandera) {

		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			//Avanzar(iter).MostrarPaginaWeb();
			cout << "---------" << endl;
			Sleep(100);
		}// Espera un poco para evitar detección múltiple rápida

		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			Retroceder(iter).MostrarPaginaWeb();
			
			Sleep(100);
		}// Espera un poco para evitar detección múltiple rápida
		
		
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			bandera = false;
		}
	}

}





