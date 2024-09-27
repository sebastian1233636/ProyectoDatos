#include "pch.h"
#include "CppUnitTest.h"
#include"../ProyectoDatos/PaginaWeb.cpp"
#include"../ProyectoDatos/Pesta�a.cpp"
#include"../ProyectoDatos/AdminPesta�as.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestConstructor)
		{
			PaginaWeb pagina("www.steam.com", "steam");

			Assert::AreEqual(string("www.steam.com"), pagina.getURL());
			Assert::AreEqual(string("steam"), pagina.getTitulo());
		}


		TEST_METHOD(TestConstructorDefecto)
		{
			PaginaWeb pagina;

			Assert::AreEqual(string("Sin registro"), pagina.getURL());
			Assert::AreEqual(string("Sin registro"), pagina.getTitulo());
		}

		TEST_METHOD(TestURL)
		{
			PaginaWeb pagina;
			pagina.setUrl("www.algo.com");

			Assert::AreEqual(string("www.algo.com"), pagina.getURL());
		}

		TEST_METHOD(TestTitulo)
		{
			PaginaWeb pagina;
			 pagina.setTitulo("Titulo"); 

			Assert::AreEqual(string("Titulo"), pagina.getTitulo());
		}

		TEST_METHOD(TestMarcadorPersonal)
		{
			PaginaWeb pagina;
			pagina.setMarcadorPersonal("Marcador");

			Assert::AreEqual(string("Marcador"), pagina.getMarcadorPersonal());
		}

		TEST_METHOD(TestMarcador)
		{
			PaginaWeb pagina;

			pagina.PonerMarcador();
			Assert::IsTrue(pagina.getMarcador());

			pagina.QuitarMarcador();
			Assert::IsFalse(pagina.getMarcador());
		}

		TEST_METHOD(TestTiempo)
		{
			PaginaWeb pagina;
			time_t tiempoActual = time(0);

			pagina.setTiempo(tiempoActual);

			Assert::AreEqual(tiempoActual, pagina.getTiempo());
		}

		TEST_METHOD(TestArchivos)
		{
			
			PaginaWeb pagina("www:algo.com", "algo");
			pagina.setMarcadorPersonal("Marcador");
			pagina.PonerMarcador();
			time_t tiempoActual = time(0);
			pagina.setTiempo(tiempoActual);

			
			ofstream fileOut("testPaginaWeb.bin", ios::binary);
			pagina.guardarPaginaWeb(fileOut);
			fileOut.close();

			
			ifstream fileIn("testPaginaWeb.bin", ios::binary);
			PaginaWeb* paginaLeida = pagina.leerPaginaWeb(fileIn);
			fileIn.close();

			
			Assert::AreEqual(pagina.getURL(), paginaLeida->getURL());
			Assert::AreEqual(pagina.getTitulo(), paginaLeida->getTitulo());
			Assert::AreEqual(pagina.getMarcadorPersonal(), paginaLeida->getMarcadorPersonal());
			Assert::AreEqual(pagina.getMarcador(), paginaLeida->getMarcador());
			Assert::AreEqual(pagina.getTiempo(), paginaLeida->getTiempo());

			
			delete paginaLeida;
		}


	};



	TEST_CLASS(UnitTestPesta�a)
	{
	public:
		TEST_METHOD(TestConstructor)
		{
			Pesta�a pesta�a;
			Assert::AreEqual(pesta�a.getNombre(), std::string("Sin registro"));
			Assert::IsFalse(pesta�a.getIcognito());
			Assert::IsNull(pesta�a.getTail());
			Assert::IsNull(pesta�a.getHead());
		}

		TEST_METHOD(TestInsertar)
		{
			Pesta�a pesta�a;
			PaginaWeb pagina("www:algo.com", "Example");

			pesta�a.insertarPrimero(pagina);

			Assert::IsNotNull(pesta�a.getTail());
			Assert::IsNotNull(pesta�a.getHead());
			Assert::AreEqual(pesta�a.getTail()->paginaWeb->getURL(), std::string("www:algo.com"));
		}

		// Test activar/desactivar modo inc�gnito
		TEST_METHOD(TestIncognito)
		{
			Pesta�a pesta�a;
			pesta�a.activarModoIncognito();
			Assert::IsTrue(pesta�a.getIcognito());

			pesta�a.desactivarModoIncognito();
			Assert::IsFalse(pesta�a.getIcognito());
		}

		// Test guardar y leer pesta�a
		TEST_METHOD(TestArchivosPesta�a)
		{
			
			ofstream archivoGuardar("pesta�a.bin", ios::binary);
			Pesta�a pesta�a("TestPesta�a");
			pesta�a.guardarPesta�a(archivoGuardar);
			archivoGuardar.close();

			ifstream archivoLeer("pesta�a.bin", ios::binary);
			Pesta�a* pesta�aLeida = Pesta�a::leerPesta�a(archivoLeer);
			archivoLeer.close();

			Assert::AreEqual(pesta�aLeida->getNombre(), std::string("TestPesta�a"));
			delete pesta�aLeida;
		}
	};

	TEST_CLASS(UnitTestAdmin)
	{
	public:


	};


}
