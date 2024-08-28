#include "PaginaWeb.h"



PaginaWeb::PaginaWeb(string U, string tit) {
	URL = U;
	Titulo = tit;
	marcador = false;
}



PaginaWeb::PaginaWeb() {
	URL = "Sin registro";
	Titulo = "sin registro";
	marcador = false;

}

PaginaWeb::PaginaWeb(PaginaWeb& copia) {
	this->URL = copia.URL;
	this->Titulo = copia.Titulo;
	this->marcador = copia.marcador;
	
}

string PaginaWeb::getURL()
{
	return URL;
}

string PaginaWeb::getTitulo()
{
	return Titulo;
}

void PaginaWeb::MostrarPaginaWeb()
{
	cout << "------------------------------------" << getURL() << "----------------------------------------" << endl;
	
	if (marcador = true) {
		cout << "FAVORITO" << endl;
	}




}

void PaginaWeb::PonerMarcador()
{
	marcador = true;
}
