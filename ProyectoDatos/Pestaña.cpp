#include "Pesta�a.h"

Pesta�a::Pesta�a()
{
	tail = nullptr;
	head = nullptr;
}

Pesta�a::~Pesta�a()
{
	NodoPag* aux = tail;
	while (aux != nullptr) {
		tail = tail->siguiente;
		delete aux;
		aux = tail;
	}
	tail = nullptr;
	head = nullptr;
}

void Pesta�a::InsertarPrimero(PaginaWeb* pag)
{
	NodoPag* nuevo = new NodoPag();
	nuevo->paginaWeb = pag;
	if (tail == nullptr) {
		tail = head = nuevo;
		nuevo->siguiente;
		nuevo->anterior;
	}
	else {
		nuevo->siguiente = tail;
		tail->anterior = nuevo;
		tail = nuevo;
	}
}

void Pesta�a::ExplorarHistorial(NodoPag* nodoActual)
{
	bool bandera = true;
	nodoActual = tail;
	while (bandera == true) {

		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			if (nodoActual->anterior == nullptr) {
				nodoActual->paginaWeb->MostrarPaginaWeb();
				cout << "no se puede retroceder mas" << endl;
			}
			else {
				nodoActual->paginaWeb->MostrarPaginaWeb();
				nodoActual = nodoActual->anterior;
			}
			Sleep(100);
		}


		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			if (nodoActual->siguiente == nullptr) {
				nodoActual->paginaWeb->MostrarPaginaWeb();
				cout << "No se puede avanzar mas" << endl;
			}
			else {
				nodoActual->paginaWeb->MostrarPaginaWeb();
				nodoActual = nodoActual->siguiente;
			}
			Sleep(100);
		}



		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			bandera = false;
		}


	}

}

NodoPag* Pesta�a::getTail()
{
	return tail;
}

NodoPag* Pesta�a::getHead()
{
    return head;
}
