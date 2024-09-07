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

void AdminPestañas::BuscarFavorito(){
	NodoPest* nodoActual = tail;
	while (nodoActual != nullptr) {
		nodoActual->pestaña->buscarFavorito();
		nodoActual = nodoActual->siguiente;
	}
}

void AdminPestañas::ExplorarHistorialPestañas(){
	bool bandera = true;
	NodoPest* nodoActual = tail;
	if (nodoActual == nullptr) {
		cout << " no hay historial todavia" << endl;
	}
	else {
		while (bandera == true) {
			if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
				if (nodoActual->anterior == nullptr) {
					cout << nodoActual->pestaña->mostrarPestaña() << endl;
					nodoActual->pestaña->explorarHistorial();
					cout << "No se puede retroceder mas" << endl;
				}
				else {
					cout << nodoActual->pestaña->mostrarPestaña() << endl;
					nodoActual->pestaña->explorarHistorial();
					nodoActual = nodoActual->anterior;
				}
				Sleep(200);
			}

			if (GetAsyncKeyState(VK_UP) & 0x8000) {
				if (nodoActual->siguiente == nullptr) {
					cout << nodoActual->pestaña->mostrarPestaña() << endl;
					nodoActual->pestaña->explorarHistorial();
					cout << "No se puede retroceder mas" << endl;
				}
				else {
					cout << nodoActual->pestaña->mostrarPestaña() << endl;
					nodoActual->pestaña->explorarHistorial();
					nodoActual = nodoActual->siguiente;
				}
				Sleep(200);
			}
			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { bandera = false; }
		}
	}
}