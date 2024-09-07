#include "AdminPestañas.h"

AdminPestañas::AdminPestañas(){
	tail = nullptr;
	head = nullptr;
}

AdminPestañas::~AdminPestañas(){
	NodoPest* aux = tail;
	while (aux != nullptr) {
		tail = tail->siguiente;
		delete aux;
		aux = tail;
	}
	tail = nullptr;
	head = nullptr;
}

NodoPest* AdminPestañas::getTail() {return tail;}

NodoPest* AdminPestañas::getHead() {return head;}

void AdminPestañas::InsertarPrimero(Pestaña* pes){
	NodoPest* nuevo = new NodoPest();
	nuevo->pestaña = pes;
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

void AdminPestañas::ExplorarHistorialPestañas(){
	bool bandera = true;
	NodoPest* nodoActual = tail;


	while (bandera == true) {
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			if (nodoActual->anterior == nullptr) {
				nodoActual->pestaña->mostrarPestaña();
				cout << "No se puede retroceder mas" << endl;
			}
			else {
				nodoActual->pestaña->mostrarPestaña();
				nodoActual = nodoActual->anterior;
			}
			Sleep(100);
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			if (nodoActual->siguiente == nullptr) {
				nodoActual->pestaña->mostrarPestaña();
				cout << "No se puede avanzar mas" << endl;
			}
			else {
				nodoActual->pestaña->mostrarPestaña();
				nodoActual = nodoActual->siguiente;
			}
			Sleep(100);
		}
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { bandera = false; }
	}
}