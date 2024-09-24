#include "Pesta�a.h"

Pesta�a::Pesta�a(string nom){
	tail = nullptr;
	head = nullptr;
	nombre = nom;
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

	if (nodoActual == nullptr) {cout << "El historial de p�ginas web est� vac�o." << endl;}

	else {
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
					Sleep(300);
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
					Sleep(300);
				}
				if (GetAsyncKeyState('F') & 0x8000) {
					nodoActual->paginaWeb->PonerMarcador();
					cout << "Pagina marcada como favorita" << endl;
					Sleep(300);
				}
				if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { bandera = false; }
			}
		}
	}

}

void Pesta�a::buscarFavorito(){
	NodoPag* nodoActual = tail;
	while (nodoActual != nullptr) {
		if (nodoActual->paginaWeb->getMarcador() == true && nodoActual->paginaWeb->yaMostrada() == false) {
			nodoActual->paginaWeb->marcarComoMostrada();
			nodoActual->paginaWeb->MostrarPaginaWeb();
			nodoActual = nodoActual->siguiente;
		}
		else(nodoActual = nodoActual->siguiente);
	}
}

void Pesta�a::activarModoIcognito(){modoIcognito = true;}

void Pesta�a::desactivarModoIcognito(){modoIcognito = false;}

string Pesta�a::mostrarPesta�a()
{
	stringstream s;
	s << "-------------------------" << nombre << "---------------------------" << endl;
	return s.str();
}

void Pesta�a::timeFilter(int minutos)
{
	time_t tiempoActual = std::time(nullptr); // Obtiene el tiempo actual
	NodoPag* actual = head; // Comienza desde el inicio de la lista

	// Iterar sobre la lista de nodos
	while (actual != nullptr) {
		PaginaWeb* pagina = actual->paginaWeb;
		double segundosTranscurridos = difftime(tiempoActual, pagina->getTiempo());

		// Compara si la p�gina fue agregada dentro de los �ltimos "minutos"
		if (segundosTranscurridos <= minutos * 60) {
			pagina->MostrarPaginaWeb(); // Muestra la p�gina si cumple con la condici�n
		}

		actual = actual->siguiente; // Avanza al siguiente nodo
	}
}

