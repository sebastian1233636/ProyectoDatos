#include "Pesta�a.h"

Pesta�a::Pesta�a(){
	tail = nullptr;
	head = nullptr;
	modoIcognito = false;
}

Pesta�a::~Pesta�a(){
	NodoPag* aux = tail;
	while (aux != nullptr) {
		tail = tail->siguiente;
		delete aux;
		aux = tail;
	}
	tail = nullptr;
	head = nullptr;
}

NodoPag* Pesta�a::getTail() {return tail;}

NodoPag* Pesta�a::getHead() {return head;}

void Pesta�a::insertarPrimero(PaginaWeb* pag){
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

void Pesta�a::explorarHistorial(){
	bool bandera = true;
	NodoPag* nodoActual = tail;
	while (bandera == true) {
		if (modoIcognito) {
			cout << "No guardar historial ni marcadores" << endl;
		}
		else {
			if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
				if (nodoActual->anterior == nullptr) {
					nodoActual->paginaWeb->MostrarPaginaWeb();
					cout << "No se puede retroceder mas" << endl;
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
			if (GetAsyncKeyState('F') & 0x8000) {
				nodoActual->paginaWeb->PonerMarcador();
				cout << "Pagina marcada como favorita" << endl;
				Sleep(100);
			}
			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { bandera = false; }
		}
	}
}

void Pesta�a::activarModoIcognito()
{
	modoIcognito = true;
}

void Pesta�a::desactivarModoIcognito()
{
	modoIcognito = false;

}

