#include "pch.h"
#include "CppUnitTest.h"
#include"../ProyectoDatos/PaginaWeb.cpp"
#include"../ProyectoDatos/Pestaña.cpp"
#include"../ProyectoDatos/AdminPestañas.cpp"
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



	TEST_CLASS(UnitTestPestaña)
	{
	public:
		TEST_METHOD(TestConstructor)
		{
			Pestaña pestaña;
			Assert::AreEqual(pestaña.getNombre(), std::string("Sin registro"));
			Assert::IsFalse(pestaña.getIcognito());
			Assert::IsNull(pestaña.getTail());
			Assert::IsNull(pestaña.getHead());
		}

		TEST_METHOD(TestInsertar)
		{
			Pestaña pestaña;
			PaginaWeb pagina("www:algo.com", "Example");

			pestaña.insertarPrimero(pagina);

			Assert::IsNotNull(pestaña.getTail());
			Assert::IsNotNull(pestaña.getHead());
			Assert::AreEqual(pestaña.getTail()->paginaWeb->getURL(), std::string("www:algo.com"));
		}

		// Test activar/desactivar modo incógnito
		TEST_METHOD(TestIncognito)
		{
			Pestaña pestaña;
			pestaña.activarModoIncognito();
			Assert::IsTrue(pestaña.getIcognito());

			pestaña.desactivarModoIncognito();
			Assert::IsFalse(pestaña.getIcognito());
		}

		// Test guardar y leer pestaña
		TEST_METHOD(TestArchivosPestaña)
		{
			
			ofstream archivoGuardar("pestaña.bin", ios::binary);
			Pestaña pestaña("TestPestaña");
			pestaña.guardarPestaña(archivoGuardar);
			archivoGuardar.close();

			ifstream archivoLeer("pestaña.bin", ios::binary);
			Pestaña* pestañaLeida = Pestaña::leerPestaña(archivoLeer);
			archivoLeer.close();

			Assert::AreEqual(pestañaLeida->getNombre(), std::string("TestPestaña"));
			delete pestañaLeida;
		}
	};

	TEST_CLASS(UnitTestAdmin)
	{
	public:


	};


}
