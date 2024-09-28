#include "AdminPesta�as.h"

AdminPesta�as::AdminPesta�as() {
	tail = nullptr;
	head = nullptr;
	tam = 0;
}

AdminPesta�as::~AdminPesta�as() {
	NodoPest* aux = tail;
	while (aux != nullptr) {
		tail = tail->siguiente;
		delete aux;
		aux = tail;
	}
	tail = nullptr;
	head = nullptr;
}

NodoPest* AdminPesta�as::getTail() { return tail; }

NodoPest* AdminPesta�as::getHead() { return head; }


void AdminPesta�as::iniciarNavegador()
{
	//Metodo que se ejecuta cuando se inicia el programa
	cout << "---------------Bienvenido al navegador---------------" << endl;
	system("pause");
	if (tail == nullptr) {//La sesi�n inicia en blanco, se crea una pagina web nueva para comenzar el uso del programa 
		cout << "No hay pesta�as todavia, agregando una" << endl;
		string nombrePesta�a = "Pestana " + to_string(tam + 1);
		Pesta�a* pes = new Pesta�a(nombrePesta�a);
		InsertarPrimero(pes);
		ExplorarHistorialPesta�as();
	}
	else {//Si hay pesta�as inicia normalmente 
		ExplorarHistorialPesta�as();
	}
}

void AdminPesta�as::InsertarPrimero(Pesta�a* pes) {
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

void AdminPesta�as::BuscarFavorito() {
	NodoPest* nodoActual = tail;
	//Metodo que recorre la lista y llama al metodo "buscarFavorito" para obtener las paginas con marcador
	while (nodoActual != nullptr) {
		nodoActual->pesta�a->buscarFavorito();
		nodoActual = nodoActual->siguiente;
	}
}

void AdminPesta�as::ExplorarHistorialPesta�as() {
	bool bandera = true;  // Controla si el modo de exploraci�n sigue activo
	NodoPest* nodoActual = tail;  // Comienza desde la primera pesta�a (tail)

	if (nodoActual == nullptr) {
		// Si no hay historial de pesta�as, mostrar mensaje y salir
		cout << "No hay historial todavia" << endl;
		return;
	}

	while (bandera) {
		// Limpiar pantalla y mostrar el men� de administraci�n de pesta�as
		system("cls");
		menuAdminPesta�as(nodoActual);

		while (true) {
			// Moverse a la pesta�a anterior si se presiona flecha abajo
			if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
				if (nodoActual->anterior == nullptr) {
					cout << "NO SE PUEDE RETROCEDER MAS" << endl;
					system("pause");
				}
				else {
					nodoActual = nodoActual->anterior;
				}
				Sleep(200);  // Evitar detecci�n continua de la tecla
				break;
			}

			// Moverse a la pesta�a siguiente si se presiona flecha arriba
			if (GetAsyncKeyState(VK_UP) & 0x8000) {
				if (nodoActual->siguiente == nullptr) {
					cout << "NO SE PUEDE AVANZAR MAS" << endl;
					system("pause");
				}
				else {
					nodoActual = nodoActual->siguiente;
				}
				Sleep(200);  // Evitar detecci�n continua de la tecla
				break;
			}

			// Salir si se presiona ESC
			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
				bandera = false;  // Finalizar el bucle principal
				system("cls");  // Limpiar pantalla al salir
				break;
			}

			Sleep(100);  // Reducir la carga del sistema mientras se espera entrada
		}
	}
}

int AdminPesta�as::contadorPesta�as() { return tam; }

void AdminPesta�as::menuAdminPesta�as(NodoPest* actual) {

	if (actual == nullptr) {
		cout << "No hay pesta�as todavia." << endl;
		return; 
	}

	//Variables de control para los diferentes bucles y menus
	int op = 0;
	int op2 = 0;
	int op3 = 0;
	int op4 = 0;
	int op6 = 0;
	string nom = "";
	string palabraclave = "";
	bool incognito = false;
	bool control = true;
	bool control3 = true;
	bool control4 = true;
	bool control5 = true;
	bool control6 = true;
	while (control != false) {
		system("cls");
		//Menu principal del programa
		cout << "----------------" << actual->pesta�a->getNombre() << "----------------" << endl;
		cout << "---------------------------------------" << endl;
		cout << "1.Ver historial" << endl;
		cout << "2.Ir al sitio web" << endl;
		cout << "3.Nueva pesta�a" << endl;
		cout << "4.Modo incognito" << endl;
		cout << "5.Busquedas y filtros" << endl;
		cout << "6.Configuracion" << endl;
		cout << "7.Importacion y exportacion" << endl;
		cout << "8.Regresar" << endl;
		cout << "---------------------------------------" << endl;
		cout << "Digite una opcion:";
		cin >> op;
		cout << endl;
		switch (op) {

		case 1: {//Permite meterse al historial de cada pesta�a, a menos que sea incognito
			if (actual->pesta�a->getIcognito() == false) {

				cout << actual->pesta�a->mostrarPesta�a() << endl;
				actual->pesta�a->explorarHistorial();
			}
			else { cout << actual->pesta�a->mostrarPesta�aIncognito() << endl; }
			break;
			
		}

		case 2: {
			//Se le pide al usuario que ingrese el URL para buscarlo en el archivo CSV
			string url;
			cout << "Digite el URL de la pagina:";
			cin >> url;
			cout << endl;
			PaginaWeb* PagNueva = buscaPaginaWeb(url);
			if (PagNueva == nullptr) { cout << "ERROR 404 NOT FOUND" << endl; } //Devuelve el respectivo error si no se encuentra la pagina
			else { actual->pesta�a->insertarPrimero(*PagNueva); }// se inserta si se encuentra
			system("pause");
			break;
		}
		case 3: {
			//Opcion para crear una nueva pesta�a
			string nombrePesta�a = "Pestana " + to_string(tam + 1);//se crea un nombre junto al tama�o del container, ejemplo si no hay elementos la primera pesta�a se llamar� "Pesta�a 1"
			Pesta�a* pes = new Pesta�a(nombrePesta�a);
			InsertarPrimero(pes);
			cout << "Se ha creado una nueva pesta�a. Siga las instrucciones anteriores para navegar a ella." << endl;
			system("pause");
			break;
		}
		case 4: {
			//Menu para el modo incognito
			control3 = true;
			while (control3 != false) {
				system("cls");
				cout << "1.Activar modo incognito" << endl;
				cout << "2.Desactivar modo incognito" << endl;
				cout << "3.Regresar" << endl;
				cout << "Digite la opcion" << endl;
				cin >> op3;
				switch (op3) {
				case 1:
					//Activa el modo incognito de la pesta�a
					actual->pesta�a->activarModoIncognito();
					if (actual->pesta�a->getIcognito() == true) {
						cout << "Modo incognito activado" << endl;
					}
					system("pause");
					break;
				case 2:
					//Desactiva el modo incognito de la pesta�a
					actual->pesta�a->desactivarModoIncognito();
					if (actual->pesta�a->getIcognito() == false) {
						cout << "Modo incognito desactivado" << endl;
					}
					system("pause");
					break;
				case 3: {
					control3 = false;
					break;
				}

				default:
					cout << "Opcion no valida" << endl;
					break;
				}

			}
			break;
		}
		case 5: {
			control4 = true;
			while (control4 != false) {
				system("cls");
				//Menu para manejar las busquedas y filtros
				cout << "---------------------------------------" << endl;
				cout << "1.Mostrar solo favoritos" << endl;
				cout << "2.Busqueda por palabra clave" << endl;
				cout << "3.Buscar una pagina especifica" << endl;
				cout << "4.regresar" << endl;
				cout << "---------------------------------------" << endl;
				cin >> op4;
				switch (op4) {

				case 1: {
					system("cls");
					actual->pesta�a->buscarFavorito();
					system("pause");
					break;
				}

				case 2: {
					cout << "Digite la palabra clave para filtrar paginas" << endl;
					cin >> palabraclave;
					system("cls");
					actual->pesta�a->buscarPorPalabraClave(palabraclave);
				

					break;
				}

				case 3: {
					PaginaWeb* pag;
					cout << "Digite el URL o el titulo de la pagina web" << endl;
					cin >> nom;
					pag = actual->pesta�a->buscarPaginaWeb(nom);
					if (pag == nullptr) {
						cout << "La pagina que busca no se encuentra" << endl;
					}
					else {
						pag->MostrarPaginaWeb();
						system("pause");
					}
					break;
				}
				case 4: {
					control4 = false;
					break;
				}

				default:
					cout << "Opcion no valida" << endl;
					break;


				}
			}
			break;
		}
		case 6: {
			//--------------------------------------------------------------------------------------
			control5 = true;
			while (control5 != false) {
				system("cls");
				//Menu para manejar las politicas del historial
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
					actual->pesta�a->timeFilter(min);
					system("pause");
					break;
				}
				case 2: {
					int mins = 0;
					cout << "En esta opcion se elminar�n las paginas que superen los minutos ingresados" << endl;
					cout << "Digite los minutos deseados" << endl;
					cin >> mins;
					cout << "Eliminando paginas que superen los " << mins << " minutos" << endl;
					actual->pesta�a->eliminarCadaTiempo(mins);
					system("pause");
					break;
				}

				case 3: {
					control5 = false;
					break;
				}
				default:
					cout << "Opcion no valida" << endl;
					break;
				}
			}
			break;
		}
		case 7: {
			//archivos
			guardarPesta�aBinario();
			guardarHistorialPesta�a();
			cout << "Historial guardado" << endl;
			system("pause");
			break;
		}
		case 8:
			control = false;
			break;
		default:
			cout << "Opcion no valida" << endl;
			break;
		}
	}
}

PaginaWeb* AdminPesta�as::buscaPaginaWeb(string urlBuscado) {
	string archivo("Prueba.csv");
	ifstream file(archivo);
	PaginaWeb* pagAr = new PaginaWeb();

	// Verificar si el archivo se abri� correctamente
	if (!file.is_open()) {
		cout << "El archivo no se abrio" << endl;
	}
	else {
		string linea;

		// Leer cada l�nea del archivo CSV
		while (getline(file, linea)) {
			stringstream ss(linea);
			string url;
			string titulo;

			// Separar URL y t�tulo usando coma como delimitador
			if (getline(ss, url, ',') && getline(ss, titulo)) {
				// Comparar la URL de la l�nea actual con la URL buscada
				if (url == urlBuscado) {
					// Si coincide, crear un nuevo objeto PaginaWeb y retornarlo
					pagAr = new PaginaWeb(url, titulo);
					return pagAr;
				}
				else {
					// Si no coincide, devolver nullptr
					pagAr = nullptr;
				}
			}
		}

		// Cerrar el archivo despu�s de la lectura
		file.close();
	}

	// Retornar nullptr si no se encontr� la p�gina con la URL buscada
	return nullptr;
}

void AdminPesta�as::guardarPesta�aBinario() {
	ofstream file("Pesta�as.bin", ios::binary);
	if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }
	else {
		NodoPest* actual = tail;
		while (actual != nullptr) {
			actual->pesta�a->guardarPesta�a(file);
			actual = actual->siguiente;
		}
	}
	file.close();
}

void AdminPesta�as::leerPesta�aBinario() {
	ifstream file("Pesta�as.bin", ios::binary);
	if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }
	else {
		file.seekg(0, ios::end);
		std::streampos fileSize = file.tellg();
		file.seekg(0, ios::beg);
		while (file.tellg() < fileSize) {
			Pesta�a* pesta�a = new Pesta�a();
			Pesta�a* pes = pesta�a->leerPesta�a(file);
			if (pes != nullptr) { InsertarPrimero(pes); }
			else {
				cout << "Error al leer una pesta�a del archivo." << endl;
				break;
			}
		}
	}
	file.close();
}

void AdminPesta�as::guardarHistorialPesta�a() {
	NodoPest* actual = tail;
	ofstream file;
	string nombre;
	//Se recorre la lista y guarda el historia de cada pesta�a con un nombre diferente para mayor facilidad de lectura
	while (actual != nullptr) {
		nombre = "Historial" + actual->pesta�a->getNombre() + ".bin";//toma el nombre de cada pesta�a y lo convierte en el nombre del archivo 
		file.open(nombre, ios::binary);
		if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }
		actual->pesta�a->guardarHistorialBinario(file);
		actual = actual->siguiente;
		file.close();
	}
}

void AdminPesta�as::leerHistorialPesta�a(){
	NodoPest* actual = tail;
	ifstream file;
	string nombre;
	//Abre los archivos segun se guardaron para lectura
	while (actual != nullptr) {
		nombre = "Historial" + actual->pesta�a->getNombre() + ".bin";
		file.open(nombre, ios::binary);
		if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }
		actual->pesta�a->leerHistorialBinario(file);
		actual = actual->siguiente;
		file.close();
	}
}
