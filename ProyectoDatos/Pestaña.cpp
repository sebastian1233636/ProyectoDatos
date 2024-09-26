#include "Pestaña.h"
#include <iostream>


Pestaña::Pestaña(string nom){
	tail = nullptr;
	head = nullptr;
	nombre = nom;
	modoIcognito = false;
}

Pestaña::Pestaña() {
	nombre = "Sin registro";
	modoIcognito = false;
	tail = nullptr;
	head = nullptr;
}

Pestaña::~Pestaña(){
	NodoPag* aux = tail;
	while (aux != nullptr) {
		tail = tail->siguiente;
		delete aux;
		aux = tail;
	}
	tail = nullptr;
	head = nullptr;
}

bool Pestaña::getIcognito() { return modoIcognito; }

string Pestaña::getNombre() { return nombre; }

NodoPag* Pestaña::getTail() {return tail;}

NodoPag* Pestaña::getHead() {return head;}

void Pestaña::setNombre(string nom) { nombre = nom; }

void Pestaña::insertarPrimero(PaginaWeb& pag){
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

void Pestaña::explorarHistorial(){
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
                        nodoActual->paginaWeb->setMarcadorPersonal(marcador);
                    }
                    cout << "Pagina marcada como favorita" << endl;
                    Sleep(300);
                }
				if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { bandera = false; }
			}
		}
	}
}

void Pestaña::buscarFavorito(){
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

void Pestaña::activarModoIncognito(){modoIcognito = true;}

void Pestaña::desactivarModoIncognito(){modoIcognito = false;}

string Pestaña::mostrarPestaña(){
    stringstream s;
	s << "|Si desea moverse entre pestanas, presione la opción 7 y las flechas de arriba y abajo." << endl;
	s << "|Si desea marcar una pagina web como favorita, presione la tecla F." << endl;
    s << "|-------------------------" << nombre << "---------------------------|" << endl;
    return s.str();
}

string Pestaña::mostrarPestañaIncognito() {
	return "|-------------------------" + nombre + "---------------------------|\n"
		   "-------------------------------\n"
		   "|       MODO INCOGNITO         |\n"
		   "|       _____________          |\n"
		   "|      |             |         |\n"
		   "|      |   PRIVADO   |         |\n"
		   "|      |_____________|         |\n"
		   "|       No se guarda           |\n"
		   "|     el historial aqui        |\n"
		   "-------------------------------\n";
}

PaginaWeb* Pestaña::buscarPaginaWeb(string nomURL)
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

void Pestaña::buscarPorPalabraClave(string& palabraclave )
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


void Pestaña::timeFilter(int minutos){
	time_t tiempoActual = std::time(nullptr);
	NodoPag* actual = tail;

	while (actual != nullptr) {
		PaginaWeb* pagina = actual->paginaWeb;
		double segundosTranscurridos = difftime(tiempoActual, pagina->getTiempo());
		if (segundosTranscurridos <= minutos * 60) { pagina->MostrarPaginaWeb(); }
		actual = actual->siguiente;
	}
}

void Pestaña::eliminarCadaTiempo(int minutos) {
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

void Pestaña::guardarPestaña(ofstream& file){
	string name = getNombre();
	bool incognito = getIcognito();
	size_t longitudname = name.size();
	file.write(reinterpret_cast<const char*>(&longitudname), sizeof(longitudname));
	file.write(name.c_str(), longitudname);
	file.write(reinterpret_cast<char*>(&incognito), sizeof(incognito));
}

Pestaña* Pestaña::leerPestaña(ifstream& file) {
	string name;
	bool incognito;
	size_t Lname= 0;
	file.read(reinterpret_cast<char*>(&Lname), sizeof(Lname));
	name.resize(Lname);
	file.read(&name[0], Lname);
	file.read(reinterpret_cast<char*>(&incognito), sizeof(incognito));
	Pestaña* pestaña = new Pestaña(name);
	if (incognito) { pestaña->activarModoIncognito(); }
	return pestaña;
}

void Pestaña::guardarHistorialBinario(ofstream& file){
	NodoPag* actual = tail;
	file.open("Historial.bin", ios::binary);
	if (!file.is_open()) {
		cout << "El archivito no se abrio" << endl;
	}
	else {
		while (actual != nullptr) {
			actual->paginaWeb->guardarPaginaWeb(file);
			actual = actual->siguiente;
		}
	}
	file.close();
}

void Pestaña::leerHistorialBinario(ifstream& file) {
	if (!file.is_open()) {
		cout << "El archivo no se pudo abrir" << endl;
		return;
	}

	file.seekg(0, ios::end);
	std::streampos fileSize = file.tellg();
	file.seekg(0, ios::beg); 

	while (file.tellg() < fileSize) {
		PaginaWeb* pagLeida = new PaginaWeb();
		PaginaWeb* pag = pagLeida->leerPaginaWeb(file);

		if (pag != nullptr) { insertarPrimero(*pag); }
		else {
			cout << "Error al leer una página web del archivo." << endl;
			break; 
		}
	}
	file.close();
	cout << "Lectura del historial completada." << endl;
}


void Pestaña::explorarHistorialIncognito(){
	bool bandera = true;
	NodoPag* nodoActual = tail;

	if (nodoActual == nullptr) {
		cout << "El historial de paginas web esta vacio." << endl;
		return;
	}

	cout << "Modo incognito activado. No se guardara historial ni marcadores." << endl;

	while (bandera) {
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			if (nodoActual->anterior == nullptr) { cout << "No se puede retroceder más." << endl; }
			else {
				nodoActual->paginaWeb->MostrarPaginaWeb();
				nodoActual = nodoActual->anterior;
			}
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			if (nodoActual->siguiente == nullptr) { cout << "No se puede avanzar más." << endl; }
			else {
				nodoActual->paginaWeb->MostrarPaginaWeb();
				nodoActual = nodoActual->siguiente;
			}
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { bandera = false; }
	}
}
