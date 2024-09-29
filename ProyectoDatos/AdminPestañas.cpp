#include "AdminPestañas.h"
#include<limits>
#include<ios>

AdminPestañas::AdminPestañas() {
	tail = nullptr;
	head = nullptr;
	tam = 0;
}

AdminPestañas::~AdminPestañas() {
	NodoPest* aux = tail;
	while (aux != nullptr) {
		tail = tail->siguiente;
		delete aux;
		aux = tail;
	}
	tail = nullptr;
	head = nullptr;
}

NodoPest* AdminPestañas::getTail() { return tail; }

NodoPest* AdminPestañas::getHead() { return head; }


void AdminPestañas::iniciarNavegador()
{
	//Metodo que se ejecuta cuando se inicia el programa
	cout << "---------------Bienvenido al navegador---------------" << endl;
	if (tail == nullptr) {//La sesión inicia en blanco, se crea una pagina web nueva para comenzar el uso del programa 
		cout << "No hay pestañas todavia, agregando una" << endl;
		string nombrePestaña = "Pestana " + to_string(tam + 1);
		Pestaña* pes = new Pestaña(nombrePestaña);
		system("pause");
		InsertarPrimero(pes);
		ExplorarHistorialPestañas();
	}
	else {//Si hay pestañas inicia normalmente 
		ExplorarHistorialPestañas();
	}
}

void AdminPestañas::InsertarPrimero(Pestaña* pes) {
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

void AdminPestañas::BuscarFavorito() {
	NodoPest* nodoActual = tail;
	//Metodo que recorre la lista y llama al metodo "buscarFavorito" para obtener las paginas con marcador
	while (nodoActual != nullptr) {
		nodoActual->pestaña->buscarFavorito();
		nodoActual = nodoActual->siguiente;
	}
}

void AdminPestañas::ExplorarHistorialPestañas() {
	bool bandera = true;  // Controla si el modo de exploración sigue activo
	NodoPest* nodoActual = tail;  // Comienza desde la primera pestaña (tail)

	if (nodoActual == nullptr) {
		// Si no hay historial de pestañas, mostrar mensaje y salir
		cout << "No hay historial todavia" << endl;
		return;
	}

	while (bandera) {
		// Limpiar pantalla y mostrar el menú de administración de pestañas
		system("cls");
		menuAdminPestañas(nodoActual);

		while (true) {
			// Moverse a la pestaña anterior si se presiona flecha abajo
			if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
				if (nodoActual->anterior == nullptr) {
					cout << "NO SE PUEDE RETROCEDER MAS" << endl;
					system("pause");
				}
				else {
					nodoActual = nodoActual->anterior;
				}
				Sleep(200);  // Evitar detección continua de la tecla
				break;
			}

			// Moverse a la pestaña siguiente si se presiona flecha arriba
			if (GetAsyncKeyState(VK_UP) & 0x8000) {
				if (nodoActual->siguiente == nullptr) {
					cout << "NO SE PUEDE AVANZAR MAS" << endl;
					system("pause");
				}
				else {
					nodoActual = nodoActual->siguiente;
				}
				Sleep(200);  // Evitar detección continua de la tecla
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

int AdminPestañas::contadorPestañas() { return tam; }

void AdminPestañas::menuAdminPestañas(NodoPest* actual) {

	if (actual == nullptr) {
		cout << "No hay pestañas todavia." << endl;
		return; 
	}

	//Variables de control para los diferentes bucles y menus
	string nom = "";
	string palabraclave = "";
	bool incognito = false;
	bool control = true;
	bool control3 = true;
	bool control4 = true;
	bool control5 = true;
	bool control6 = true;
	bool controlAr = true;
	while (control != false) {
		system("cls");
		//Menu principal del programa
		if (actual->pestaña->getIcognito() == false) {
			cout << "----------------" << actual->pestaña->getNombre() << "----------------" << endl;
		}
		else {
			cout << actual->pestaña->mostrarPestañaIncognito() << endl;
		}

		cout << "---------------------------------------" << endl;
		cout << "1.Ver historial" << endl;
		cout << "2.Ir al sitio web" << endl;
		cout << "3.Nueva pestaña" << endl;
		cout << "4.Modo incognito" << endl;
		cout << "5.Busquedas y filtros" << endl;
		cout << "6.Configuracion" << endl;
		cout << "7.Importacion y exportacion" << endl;
		cout << "8.Regresar" << endl;
		cout << "---------------------------------------" << endl;
		int op = obtenerOpcion();
		cout << endl;
		switch (op) {

		case 1: {//Permite meterse al historial de cada pestaña, a menos que sea incognito
			if (actual->pestaña->getIcognito() == false) {

				cout << actual->pestaña->mostrarPestaña() << endl;
				actual->pestaña->explorarHistorial();
			}
			else { 
				cout << "No hay historial en este modo" << endl;
				system("pause");
			}
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
			else {
				actual->pestaña->insertarPrimero(*PagNueva);
				actual->pestaña->getTail()->paginaWeb->MostrarPaginaWeb();
			}// se inserta si se encuentra
			system("pause");
			break;
		}
		case 3: {
			//Opcion para crear una nueva pestaña
			string nombrePestaña = "Pestana " + to_string(tam + 1);//se crea un nombre junto al tamaño del container, ejemplo si no hay elementos la primera pestaña se llamará "Pestaña 1"
			Pestaña* pes = new Pestaña(nombrePestaña);
			InsertarPrimero(pes);
			cout << "Se ha creado una nueva pestaña. Presione 8 para salir del menu y luego flecha de arriba o abajo para navegar." << endl;
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
				int op3 = obtenerOpcion();
				switch (op3) {
				case 1:
					//Activa el modo incognito de la pestaña
					actual->pestaña->activarModoIncognito();
					if (actual->pestaña->getIcognito() == true) {
						cout << "Modo incognito activado" << endl;
					}
					system("pause");
					break;
				case 2:
					//Desactiva el modo incognito de la pestaña
					actual->pestaña->desactivarModoIncognito();
					if (actual->pestaña->getIcognito() == false) {
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
				cout << "4.Desactivar filtro" << endl;
				cout << "5.regresar" << endl;
				cout << "---------------------------------------" << endl;
				int op4 = obtenerOpcion();
				switch (op4) {

				case 1: {
					system("cls");
					actual->pestaña->buscarFavorito();
					system("pause");
					break;
				}

				case 2: {
					cout << "Digite la palabra clave para filtrar paginas" << endl;
					cout << "Se enseñaran solo las paginas que tenga la palabra que usted digite ya sea en el titulo o en la URL" << endl;
					cin >> palabraclave;
					system("cls");
					actual->pestaña->buscarPorPalabraClave(palabraclave);
				

					break;
				}

				case 3: {
					PaginaWeb* pag;
					cout << "Digite el URL o el titulo de la pagina web" << endl;
					cin >> nom;
					pag = actual->pestaña->buscarPaginaWeb(nom);
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
					actual->pestaña->desactivarFiltros();
					cout << "Filtro por palabra clave desactivado" << endl;
					system("pause");
					break;
				}

				case 5: {
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
				cout << "3.Desactivar Filtro" << endl;
				cout << "4.Regresar" << endl;
				cout << "---------------------------------------" << endl;
				int op2 = obtenerOpcion();
				switch (op2) {
				case 1: {
					int min = 0;
					cout << "Esta funcion mostrara las entradas las cuales hayan sido ingresadas antes del minuto especificado" << endl;
					cout << "Digite el numero de minutos" << endl;
					cin >> min;
					actual->pestaña->timeFilter(min);
					cout << "Filtro aplicado" << endl;
					system("pause");
					break;
				}
				case 2: {
					int mins = 0;
					cout << "En esta opcion se elminarán las paginas que superen los minutos ingresados" << endl;
					cout << "Digite los minutos deseados" << endl;
					cin >> mins;
					cout << "Eliminando paginas que superen los " << mins << " minutos" << endl;
					actual->pestaña->eliminarCadaTiempo(mins);
					system("pause");
					break;
				}

				case 3: {
					actual->pestaña->desactivarFiltroTiempo();
					cout << "Filtro por tiempo desactivado" << endl;
					system("pause");
					break;
				}

				case 4: {
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
			controlAr = true;
			while (controlAr != false) {
				system("cls");
				cout << "------------M E N U - A R C H I V O S---------------" << endl;
				cout << "1.Guardar sesion" << endl;
				cout << "2.Cargar sesión" << endl;
				cout << "3.Regresar" << endl;
				int opAr = obtenerOpcion();
				switch (opAr) {


					case 1: {
						guardarPestañaBinario();
						guardarHistorialPestaña();
						cout << "Historial guardado" << endl;
						system("pause");
						break;
					}

					case 2: {
						leerPestañaBinario();
						leerHistorialPestaña();
						cout << "Sesion cargada" << endl;
						system("pause");
						break;
					}

					case 3: {
						controlAr = false;
						break;
					}
				}
			}

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

PaginaWeb* AdminPestañas::buscaPaginaWeb(string urlBuscado) {
	string archivo("Prueba.csv");
	ifstream file(archivo);
	PaginaWeb* pagAr = new PaginaWeb();

	// Verificar si el archivo se abrió correctamente
	if (!file.is_open()) {
		cout << "El archivo no se abrio" << endl;
	}
	else {
		string linea;

		// Leer cada línea del archivo CSV
		while (getline(file, linea)) {
			stringstream ss(linea);
			string url;
			string titulo;

			// Separar URL y título usando coma como delimitador
			if (getline(ss, url, ',') && getline(ss, titulo)) {
				// Comparar la URL de la línea actual con la URL buscada
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

		// Cerrar el archivo después de la lectura
		file.close();
	}

	// Retornar nullptr si no se encontró la página con la URL buscada
	return nullptr;
}

int AdminPestañas::obtenerOpcion()
{
	int op;
	cout << "Ingrese una opcion: ";
	cin >> op;

	// Si la entrada no es un número entero
	while (cin.fail()) {
		cin.clear();  // Limpia el estado de error de cin
		cin.ignore(1000, '\n');  // Ignora hasta 1000 caracteres o hasta un salto de línea
		cout << "Entrada invalida. Por favor, ingrese un numero: ";
		cin >> op;
	}

	return op;  // Retorna la opción válida
}

void AdminPestañas::guardarPestañaBinario() {
	ofstream file("Pestañas.bin", ios::binary);
	if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }
	else {
		NodoPest* actual = tail;
		while (actual != nullptr) {
			actual->pestaña->guardarPestaña(file);
			actual = actual->siguiente;
		}
	}
	file.close();
}

void AdminPestañas::leerPestañaBinario() {
	ifstream file("Pestañas.bin", ios::binary);
	if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }
	else {
		file.seekg(0, ios::end);
		std::streampos fileSize = file.tellg();
		file.seekg(0, ios::beg);
		while (file.tellg() < fileSize) {
			Pestaña* pestaña = new Pestaña();
			Pestaña* pes = pestaña->leerPestaña(file);
			if (pes != nullptr) { InsertarPrimero(pes); }
			else {
				cout << "Error al leer una pestaña del archivo." << endl;
				break;
			}
		}
	}
	file.close();
}

void AdminPestañas::guardarHistorialPestaña() {
	NodoPest* actual = tail;
	ofstream file;
	string nombre;
	//Se recorre la lista y guarda el historia de cada pestaña con un nombre diferente para mayor facilidad de lectura
	while (actual != nullptr) {
		nombre = "Historial" + actual->pestaña->getNombre() + ".bin";//toma el nombre de cada pestaña y lo convierte en el nombre del archivo 
		file.open(nombre, ios::binary);
		if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }
		actual->pestaña->guardarHistorialBinario(file);
		actual = actual->siguiente;
		file.close();
	}
}

void AdminPestañas::leerHistorialPestaña(){
	NodoPest* actual = tail;
	ifstream file;
	string nombre;
	//Abre los archivos segun se guardaron para lectura
	while (actual != nullptr) {
		nombre = "Historial" + actual->pestaña->getNombre() + ".bin";
		file.open(nombre, ios::binary);
		if (!file.is_open()) { cout << "El archivo no se abrio" << endl; }
		actual->pestaña->leerHistorialBinario(file);
		actual = actual->siguiente;
		file.close();
	}
}
