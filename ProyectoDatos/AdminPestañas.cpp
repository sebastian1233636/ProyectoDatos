#include "AdminPesta�as.h"

AdminPesta�as::AdminPesta�as(){
	tail = nullptr;
	head = nullptr;
}

AdminPesta�as::~AdminPesta�as(){
	NodoPest* aux = tail;
	while (aux != nullptr) {
		tail = tail->siguiente;
		delete aux;
		aux = tail;
	}
	tail = nullptr;
	head = nullptr;
}

NodoPest* AdminPesta�as::getTail() {return tail;}

NodoPest* AdminPesta�as::getHead() {return head;}

void AdminPesta�as::InsertarPrimero(Pesta�a* pes){
	NodoPest* nuevo = new NodoPest();
	nuevo->pesta�a = pes;
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

void AdminPesta�as::ExplorarHistorialPesta�as(){
	bool bandera = true;
	NodoPest* nodoActual = tail;


	while (bandera == true) {
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			if (nodoActual->anterior == nullptr) {
				nodoActual->pesta�a->mostrarPesta�a();
				cout << "No se puede retroceder mas" << endl;
			}
			else {
				nodoActual->pesta�a->mostrarPesta�a();
				nodoActual = nodoActual->anterior;
			}
			Sleep(100);
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			if (nodoActual->siguiente == nullptr) {
				nodoActual->pesta�a->mostrarPesta�a();
				cout << "No se puede avanzar mas" << endl;
			}
			else {
				nodoActual->pesta�a->mostrarPesta�a();
				nodoActual = nodoActual->siguiente;
			}
			Sleep(100);
		}
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { bandera = false; }
	}
}