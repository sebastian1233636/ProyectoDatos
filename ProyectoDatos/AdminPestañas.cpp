#include "AdminPestañas.h"

AdminPestañas::AdminPestañas(){
	tail = nullptr;
	head = nullptr;
	tam = 0;
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
	tam++;
}

void AdminPestañas::BuscarFavorito(){
	NodoPest* nodoActual = tail;
	while (nodoActual != nullptr) {
		nodoActual->pestaña->buscarFavorito();
		nodoActual = nodoActual->siguiente;
	}
}

void AdminPestañas::ExplorarHistorialPestañas() {
	bool bandera = true;
	NodoPest* nodoActual = tail;

	if (nodoActual == nullptr) {
		cout << "No hay historial todavía" << endl;
		return;
	}

	while (bandera) {
		system("cls");
		menuAdminPestañas(nodoActual);


		while (true) {
			if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
				if (nodoActual->anterior == nullptr) {
					cout << "NO SE PUEDE AVANZAR MAS" << endl;
					system("pause");
				}
				else {
					nodoActual = nodoActual->anterior;
				}
				Sleep(200);
				break;
			}

			if (GetAsyncKeyState(VK_UP) & 0x8000) {
				if (nodoActual->siguiente == nullptr) {
					cout << "NO SE PUEDE AVANZAR MAS" << endl;
					system("pause");
				}
				else {
					nodoActual = nodoActual->siguiente;
				}
				Sleep(200);
				break;
			}

			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
				bandera = false;
				break;
			}
			Sleep(100);
		}
	}


}

int AdminPestañas::contadorPestañas()
{

	return tam;
}






void AdminPestañas::menuAdminPestañas(NodoPest* actual)
{
	int op = 0;
	int op2 = 0;
	int op4 = 0;
	bool incognito = false;
	bool control = true;
	bool control6 = true;
	bool control4 = true;
	while (control != false) {

		
		if (actual->pestaña->getIcognito() == false) {
			cout << actual->pestaña->mostrarPestaña() << endl;
			actual->pestaña->explorarHistorial();
		}
		else {
			cout << "Modo incognito activado, no hay historial" << endl;
			cout << actual->pestaña->mostrarPestañaIncognito() << endl;
		}
		

		cout << "---------------------------------------" << endl;
		cout << "1.Ir al sitio web" << endl;
		cout << "2.Nueva pestaña" << endl;
		cout << "3.Colocar Marcador" << endl;
		cout << "4.Modo incognito" << endl;
		cout << "5.Busquedas y filtros" << endl;
		cout << "6.Configuracion" << endl;
		cout << "7.Importacion y exportacion" << endl;
		cout << "8.Regresar" << endl;
		cout << "---------------------------------------" << endl;
		cout << "Digite una opcion" << endl;
		cin >> op;
		switch (op) {
		case 1: {
			string url;
			cout << "Digite el URL de la pagina" << endl;
			cin >> url;
			PaginaWeb* PagNueva = buscaPaginaWeb(url);
			if (PagNueva == nullptr) {
				cout << "ERROR 404 NOT FOUND" << endl;
			}
			else {
				actual->pestaña->insertarPrimero(PagNueva);
			}


			break;
		}
		case 2: {
			string nombrePestaña = "Pestaña " + to_string(tam + 1);
			Pestaña* pes = new Pestaña(nombrePestaña);
			InsertarPrimero(pes);
			break;
		}

		
		case 3:{
			if (!incognito) {
				string marcador;
				cout << "Ingrese el nombre del marcador: ";
				cin >> marcador;
				NodoPag().paginaWeb->getMarcador();
				cout << "Marcador agregado: " << marcador << endl;
			}
			else {
				cout << "La opción de marcadores no está disponible en modo incógnito." << endl;
			}


			break;
		}

		case 4: {
			control4 = true;
			while (control4 != false) {

				cout << "1.Activar modo incognito" << endl;
				cout << "2.Desactivar modo incognito" << endl;
				cout << "3.regresar" << endl;
				cout << "Digite la opcion" << endl;
				cin >> op4;
				switch (op4) {
				case 1:
					actual->pestaña->activarModoIcognito();
					break;



				case 2:
					actual->pestaña->desactivarModoIcognito();
					break;


				case 3:
					control4 = false;
					break;

				}

		

			}


			break;
		}

		case 5:
			break;

		case 6:{
			//--------------------------------------------------------------------------------------
			control6 = true;
			while (control6 != false) {

				cout << "---------------------------------------" << endl;
				cout << "1.Limitar cantidad de entradas" << endl;
				cout << "2.Eliminar historial cada cierto tiempo" << endl;
				cout << "3.Regresar" << endl;
				cout << "---------------------------------------" << endl;
				cin >> op2;
				switch (op2) {
				case 1: {
					int min = 0;
					cout << "Digite el numero de minutos" << endl;
					cin >> min;
					actual->pestaña->timeFilter(min);
					break;
				}


				case 2: {
					int mins = 0;
					cout << "En este opcion se elminarán las paginas que superen los minutos ingresados" << endl;
					cout << "Digite los minutos deseados" << endl;
					cin >> mins;
					cout << "Eliminando paginas que superen los " << mins << " minutos" << endl;
					actual->pestaña->eliminarCadaTiempo(mins);
					break;
				}

				case 3: {
					control6 = false;
					break;
				
				}

				default:
					cout << "Opcion no valida" << endl;
					break;

				}


				}



			//--------------------------------------------------------------------------------------

			break;
		}

		case 7:
		
			break;

		case 8:
			control = false;
			break;

		default:
			cout << "Opcion no valida" << endl;
			break;
		}
	}
}

PaginaWeb* AdminPestañas::buscaPaginaWeb(string urlBuscado)
{
	string archivo("Prueba.csv");
	ifstream file(archivo);
	PaginaWeb* pagAr = new PaginaWeb();
	if (!file.is_open()) {
		cout << "El archivo no se abrio" << endl;

	}
	else {
		string linea;
		while (getline(file, linea)) {
			stringstream ss(linea);
			string url;
			string titulo;

			if (getline(ss, url, ',') && getline(ss, titulo)) {
				if (url == urlBuscado) {
					 pagAr = new PaginaWeb(url, titulo);
					 return pagAr;
				}
				else {
					pagAr = nullptr;
				}
				
			}
		}
		file.close();
	}

	return nullptr;
}
