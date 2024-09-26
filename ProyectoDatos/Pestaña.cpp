#include "Pesta�a.h"
#include <iostream>


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
bool Pesta�a::getIcognito()
{
	return modoIcognito;
}

NodoPag* Pesta�a::getTail() {return tail;}

NodoPag* Pesta�a::getHead() {return head;}

void Pesta�a::insertarPrimero(PaginaWeb& pag){
	NodoPag* nuevo = new NodoPag();
	nuevo->paginaWeb = &pag;
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
	string marcador;
	NodoPag* nodoActual = tail;

	if (nodoActual == nullptr) {cout << "El historial de paginas web esta vacio." << endl;}

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
                    cout << "Ingrese el nombre del marcador (dejar en blanco para no asignar nombre): ";
                    cin.ignore();
                    getline(cin, marcador);
                    if (!marcador.empty()) {
                        nodoActual->paginaWeb->getMarcadorPersonal(marcador);
                    }
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

void Pesta�a::activarModoIncognito(){modoIcognito = true;}

void Pesta�a::desactivarModoIncognito(){modoIcognito = false;}

string Pesta�a::mostrarPesta�a(){
    stringstream s;
	s << "|Si desea moverse entre pestanas, presione la opci�n 7 y las flechas de arriba y abajo." << endl;
	s << "|Si desea marcar una pagina web como favorita, presione la tecla F." << endl;
    s << "|-------------------------" << nombre << "---------------------------|" << endl;
    return s.str();
}

string Pesta�a::mostrarPesta�aIncognito() {
	return "-------------------------------\n"
		   "|       MODO INCOGNITO         |\n"
		   "|       _____________          |\n"
		   "|      |             |         |\n"
		   "|      |   PRIVADO   |         |\n"
		   "|      |_____________|         |\n"
		   "|       No se guarda           |\n"
		   "|     el historial aqui        |\n"
		   "-------------------------------\n";
}

PaginaWeb* Pesta�a::buscarPaginaWeb(string nomURL)
{
	NodoPag* actual = tail;
	while (actual != nullptr) {
		if (nomURL == actual->paginaWeb->getURL() || nomURL == actual->paginaWeb->getTitulo()) {
			return actual->paginaWeb;
		}
		else {
			actual = actual->siguiente;
		}
	}
	return nullptr;
}

void Pesta�a::buscarPorPalabraClave(string& palabraclave )
{
	NodoPag* actual = tail;
	bool bandera = false;

	while (actual != nullptr) {
		string url = actual->paginaWeb->getURL();
		string titulo = actual->paginaWeb->getTitulo();
		if (url.find(palabraclave) != string::npos || titulo.find(palabraclave) != string::npos) {
			actual->paginaWeb->MostrarPaginaWeb();
			bandera = true;
		}
		actual = actual->siguiente;
	}

	if (bandera == false) {
		cout << "No se encontraron paginas " << endl;
	}
}


void Pesta�a::timeFilter(int minutos){
	time_t tiempoActual = std::time(nullptr);
	NodoPag* actual = tail;

	while (actual != nullptr) {
		PaginaWeb* pagina = actual->paginaWeb;
		double segundosTranscurridos = difftime(tiempoActual, pagina->getTiempo());
		if (segundosTranscurridos <= minutos * 60) { pagina->MostrarPaginaWeb(); }
		actual = actual->siguiente;
	}
}

void Pesta�a::eliminarCadaTiempo(int minutos) {
	time_t tiempoActual = std::time(nullptr);
	NodoPag* aux = tail;

	while (aux != nullptr) {
		double segundosTranscurridos = difftime(tiempoActual, aux->paginaWeb->getTiempo());
		if (segundosTranscurridos > minutos * 60) {
			NodoPag* nodoAEliminar = aux;
			aux = aux->siguiente;

			if (nodoAEliminar == head && nodoAEliminar == tail) { head = tail = nullptr; }
			else if (nodoAEliminar == tail) {
				tail = tail->siguiente;
				if (tail != nullptr) {
					tail->anterior = nullptr;
				}
			}
			else if (nodoAEliminar == head) {
				head = head->anterior;
				if (head != nullptr) {
					head->siguiente = nullptr;
				}
			}
			else {
				NodoPag* prevNode = nodoAEliminar->anterior;
				NodoPag* nextNode = nodoAEliminar->siguiente;
				prevNode->siguiente = nextNode;
				nextNode->anterior = prevNode;
			}

			delete nodoAEliminar;
		}
		else {
			aux = aux->siguiente;
		}
	}
}

void Pesta�a::explorarHistorialIncognito(){
	bool bandera = true;
	NodoPag* nodoActual = tail;

	if (nodoActual == nullptr) {
		cout << "El historial de paginas web esta vacio." << endl;
		return;
	}

	cout << "Modo incognito activado. No se guardara historial ni marcadores." << endl;

	while (bandera) {
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			if (nodoActual->anterior == nullptr) { cout << "No se puede retroceder m�s." << endl; }
			else {
				nodoActual->paginaWeb->MostrarPaginaWeb();
				nodoActual = nodoActual->anterior;
			}
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			if (nodoActual->siguiente == nullptr) { cout << "No se puede avanzar m�s." << endl; }
			else {
				nodoActual->paginaWeb->MostrarPaginaWeb();
				nodoActual = nodoActual->siguiente;
			}
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { bandera = false; }
	}
}

void Pesta�a::cargarArchivoCSV(const string& archivoCVS){

}

void Pesta�a::guardarArchivoCSV(const string& archivoCSV){

}