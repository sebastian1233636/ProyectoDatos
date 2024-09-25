#include "Pestaña.h"
#include <iostream>


Pestaña::Pestaña(string nom){
	tail = nullptr;
	head = nullptr;
	nombre = nom;
	modoIcognito = false;
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
bool Pestaña::getIcognito()
{
	return modoIcognito;
}

NodoPag* Pestaña::getTail() {return tail;}

NodoPag* Pestaña::getHead() {return head;}

void Pestaña::insertarPrimero(PaginaWeb* pag){
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

void Pestaña::explorarHistorial(){
	bool bandera = true;
	NodoPag* nodoActual = tail;

	if (nodoActual == nullptr) {cout << "El historial de páginas web está vacío." << endl;}

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

void Pestaña::activarModoIcognito(){modoIcognito = true;}

void Pestaña::desactivarModoIcognito(){modoIcognito = false;}

string Pestaña::mostrarPestaña()
{
	stringstream s;
	s << "-------------------------" << nombre << "---------------------------" << endl;
	return s.str();
}

string Pestaña::mostrarPestañaIncognito() {
	return "-------------------------------\n"
		"|       MODO INCOGNITO         |\n"
		"|       _____________          |\n"
		"|      |             |         |\n"
		"|      |   PRIVADO    |         |\n"
		"|      |_____________|         |\n"
		"|       No se guarda           |\n"
		"|     el historial aqui        |\n"
		"-------------------------------\n";
}


void Pestaña::timeFilter(int minutos)
{
	time_t tiempoActual = std::time(nullptr); // Obtiene el tiempo actual
	NodoPag* actual = tail; // Comienza desde el inicio de la lista

	// Iterar sobre la lista de nodos
	while (actual != nullptr) {
		PaginaWeb* pagina = actual->paginaWeb;
		double segundosTranscurridos = difftime(tiempoActual, pagina->getTiempo());

		// Compara si la página fue agregada dentro de los últimos "minutos"
		if (segundosTranscurridos <= minutos * 60) {
			pagina->MostrarPaginaWeb(); // Muestra la página si cumple con la condición
		}

		actual = actual->siguiente; // Avanza al siguiente nodo
	}
}

void Pestaña::eliminarCadaTiempo(int minutos) {
	time_t tiempoActual = std::time(nullptr);
	NodoPag* aux = tail; // Comienza desde el primer nodo (tail)

	while (aux != nullptr) {
		double segundosTranscurridos = difftime(tiempoActual, aux->paginaWeb->getTiempo());

		if (segundosTranscurridos > minutos * 60) {
			NodoPag* nodoAEliminar = aux;
			aux = aux->siguiente; // Avanzar al siguiente antes de eliminar el actual

			// Si el nodo a eliminar es el único en la lista
			if (nodoAEliminar == head && nodoAEliminar == tail) {
				head = tail = nullptr;
			}
			// Si es el primer nodo (tail)
			else if (nodoAEliminar == tail) {
				tail = tail->siguiente;
				if (tail != nullptr) {
					tail->anterior = nullptr;
				}
			}
			// Si es el último nodo (head)
			else if (nodoAEliminar == head) {
				head = head->anterior;
				if (head != nullptr) {
					head->siguiente = nullptr;
				}
			}
			// Si está en medio de la lista
			else {
				NodoPag* prevNode = nodoAEliminar->anterior;
				NodoPag* nextNode = nodoAEliminar->siguiente;
				prevNode->siguiente = nextNode;
				nextNode->anterior = prevNode;
			}

			delete nodoAEliminar; // Eliminar el nodo
		}
		else {
			aux = aux->siguiente; // Si no se elimina, avanza al siguiente nodo
		}
	}
}



void Pestaña::explorarHistorialIcognito()
{

	bool bandera = true;
	NodoPag* nodoActual = tail;


	if (nodoActual == nullptr) {
		cout << "El historial de páginas web está vacío." << endl;
		return;
	}

	cout << "Modo incógnito activado. No se guardará historial ni marcadores." << endl;

	while (bandera) {
		// Solo se permite la navegación en modo incógnito sin guardar nada
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			if (nodoActual->anterior == nullptr) {
				cout << "No se puede retroceder más." << endl;
			}
			else {
				nodoActual->paginaWeb->MostrarPaginaWeb();
				nodoActual = nodoActual->anterior;
			}
			Sleep(300);
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			if (nodoActual->siguiente == nullptr) {
				cout << "No se puede avanzar más." << endl;
			}
			else {
				nodoActual->paginaWeb->MostrarPaginaWeb();
				nodoActual = nodoActual->siguiente;
			}
			Sleep(300);
		}

		// Salir del modo de exploración
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			bandera = false;
		}
	}

}

void Pestaña::cargarArchivoCSV(const string& archivoCVS)
{
	ifstream archivo(archivoCVS, ios::binary);
	if (!archivo) {
		cout << "No se pudo cargar el archivo binario" << endl;

	}
	int canPestanas = 0;
	archivo.read(reinterpret_cast<char*>(&canPestanas), sizeof(canPestanas));
	for (int i = 0; i < canPestanas; i++) {
		bool incogito;
		archivo.read(reinterpret_cast<char*>(&incogito), sizeof(canPestanas));
		Pestaña nuevaPestana("nombre");
		int canSitio = 0;
		archivo.read(reinterpret_cast<char*>(&canSitio), sizeof(canSitio));
		for (int j = 0; j < canSitio; j++) {
			string titulo;
			string url;
			bool marcadores;
			size_t LTitulo = 0;
			archivo.read(reinterpret_cast<char*>(&LTitulo), sizeof(LTitulo));
			titulo.resize(LTitulo);
			archivo.read(&titulo[0], LTitulo);
			size_t LUrl = 0;
			archivo.read(reinterpret_cast<char*>(&LUrl), sizeof(LUrl));
			archivo.read(&url[0], LUrl);
			archivo.read(reinterpret_cast<char*>(&marcadores), sizeof(marcadores));
			PaginaWeb* paginaWeb = new PaginaWeb(titulo, url);
			nuevaPestana.explorarHistorial();

		}
	}
	archivo.close();
	cout << "Cargando archovo CSV Binario" << endl;

}

/*void Pestaña::guardarArchivoCSV(const string& archivoCSV)
{

	ofstream archivo(archivoCSV, ios::binary);
	if (!archivo) {
		cout << "No se pudo abrir el archivo CSV Bianrio" << endl;
	}
	int cantPestanas = 0;
	archivo.write(reinterpret_cast<char*>(&cantPestanas), sizeof(cantPestanas));
	int listaP = AdminPestañas.contadorPestañas();


	for (int i = 0; i <= listaP; i++) {
		bool icognito = getIcognito();
		archivo.write(reinterpret_cast<char*>(&icognito), sizeof(icognito));
		int cantPagWeb = 0;
		archivo.write(reinterpret_cast<char*>(&cantPagWeb), sizeof(cantPagWeb));
		for (NodoPag().paginaWeb->MostrarPaginaWeb()) {
			string titulo = NodoPag().paginaWeb->getTitulo();
			string url = NodoPag().paginaWeb->getURL();
			bool marcadores = NodoPag().paginaWeb->getMarcador();
			size_t LonT = titulo.size();
			archivo.write(reinterpret_cast<char*>(&LonT), sizeof(LonT));
			archivo.write(titulo.c_str(), LonT);
			size_t LonUrl = url.size();
			archivo.write(reinterpret_cast<char*>(&LonUrl), sizeof(LonUrl));
			archivo.write(reinterpret_cast<char*>(&marcadores), sizeof(marcadores));




		}

	}
	archivo.close();
	cout << "Se guardo el archivo CSV Binario" << endl;
}*/
