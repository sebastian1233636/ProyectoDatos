#include "AdminPesta�as.h"

AdminPesta�as::AdminPesta�as(){
	tail = nullptr;
	head = nullptr;
	tam = 0;
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
	tam++;
}

void AdminPesta�as::BuscarFavorito(){
	NodoPest* nodoActual = tail;
	while (nodoActual != nullptr) {
		nodoActual->pesta�a->buscarFavorito();
		nodoActual = nodoActual->siguiente;
	}
}

void AdminPesta�as::ExplorarHistorialPesta�as() {
	bool bandera = true;
	NodoPest* nodoActual = tail;

	if (nodoActual == nullptr) {
		cout << "No hay historial todav�a" << endl;
		return;
	}

	while (bandera) {
		system("cls");
		menuAdminPesta�as(nodoActual);


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

int AdminPesta�as::contadorPesta�as()
{

	return tam;
}






void AdminPesta�as::menuAdminPesta�as(NodoPest* actual)
{
	int op = 0;
	int op2 = 0;
	bool incognito = false;
	bool control = true;
	bool control6 = true;
	while (control != false) {

		cout << actual->pesta�a->mostrarPesta�a() << endl;
		cout << "punto de control" << endl;
		actual->pesta�a->explorarHistorial();

		cout << "---------------------------------------" << endl;
		cout << "1.Ir al sitio web" << endl;
		cout << "2.Nueva pesta�a" << endl;
		cout << "3.Colocar Marcador" << endl;
		cout << "4.Modo incognito" << endl;
		cout << "5.Busquedas y filtros" << endl;
		cout << "6.Configuracion" << endl;
		cout << "7.Regresar" << endl;
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
				actual->pesta�a->insertarPrimero(PagNueva);
			}


			break;
		}
		case 2: {
			string nombrePesta�a = "Pesta�a " + to_string(tam + 1);
			Pesta�a* pes = new Pesta�a(nombrePesta�a);
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
				cout << "La opci�n de marcadores no est� disponible en modo inc�gnito." << endl;
			}


			break;
		}

		case 4: {

			if (incognito) {
				cout << "Modo inc�gnito activado." << endl;
				actual->pesta�a->activarModoIcognito();
				actual->pesta�a->explorarHistorialIcognito();

			}
			else {
				cout << "Modo inc�gnito desactivado." << endl;
				actual->pesta�a->desactivarModoIcognito();
			}


			break;
		}

		case 5:
			break;

		case 6:{
			//--------------------------------------------------------------------------------------
			//FUNCIONES A IMPLEMENTAR: 

			//FILTRAR POR TIEMPO

			//ELIMINAR CADA CIERTO TIEMPO

			//LIMITAR LA CANTIDAD DE ENTRADAS
				
			while (control6 != false) {

				cout << "---------------------------------------" << endl;
				cout << "1.Filtrar por tiempo" << endl;
				cout << "2.Limitar cantidad de entradas" << endl;
				cout << "3.Eliminar historial cada cierto tiempo" << endl;
				cout << "4.Regresar" << endl;
				cout << "---------------------------------------" << endl;
				cin >> op2;
				switch (op2) {
				case 1: {
					int min = 0;
					cout << "Digite el numero de minutos" << endl;
					cin >> min;
					actual->pesta�a->timeFilter(min);
					break;
				}


				case 2: {

					break;
				}

				case 3: {

					break;
				}

				case 4: {
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
			control = false;
			break;

		default:
			cout << "Opcion no valida" << endl;
			break;
		}
	}
}

PaginaWeb* AdminPesta�as::buscaPaginaWeb(string urlBuscado)
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
