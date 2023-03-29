
#include<iostream>
#include<conio.h>
#include <stdlib.h>
#include<fstream>
#include<string>
#include<stdio.h>
using namespace std;

//Variables_Datos Personales
string CodUsuario;
string Nombre, Apellido;
string Direccion;
string Email;		
string Password;
int Telefono;
string Continuar;
string TMPcodigo;

//Variables_Datos Financieros
string CodFinanciero;
string Banco;
int NumCuenta;
string TipoCuenta;
int NumTarjeta;
string TipoTarjeta;

//Variables_Cuentas Virtuales
	string codigoDI;
	string CodCuentaVirtual;
	string UsuarioCuentaVirtual;
	string PasswordCuentaVirtual;



void CuentasVirtuales(){
	/*string codigoDI;
	string CodCuentaVirtual;
	string UsuarioCuentaVirtual;
	string PasswordCuentaVirtual;*/
	int res=0;
	system("cls");
	ifstream DatosPersonales("Datos Personales.txt");
	ofstream CuentasVirtuales("Cuentas Virtuales.txt", ios::app);
	
	cout<<"Ingrese un Codigo de Usuario ya Existente"<<endl;
	cin>>codigoDI;
	
	while (DatosPersonales!=NULL){
	DatosPersonales>>CodUsuario>>Nombre>>Apellido>>Direccion>>Email>>Password>>Telefono;
	if (codigoDI==CodUsuario && TMPcodigo!=codigoDI){
	codigoDI == CodUsuario;
	/*cout<<"Desea agregar una nueva cuenta?"<<endl;
	cout<<"1. Si"<<endl;
	cout<<"2. No"<<endl;
	cin>>NuevaC;
	if */
	cout<<"Ingrese Codigo de Cuenta Virtual: "<<endl;
	cin>>CodCuentaVirtual;
	cout<<"Ingrese Usuario de Cuenta Virtual:\t";
	cin>>UsuarioCuentaVirtual;
	cout<<"Ingrese una Contraseña de Usuario:\t";
	cin>>PasswordCuentaVirtual;
	res=1;
	system("pause");
	
	CuentasVirtuales<<CodUsuario<<"\t"<<CodCuentaVirtual<<"\t"<<UsuarioCuentaVirtual<<"\t"<<PasswordCuentaVirtual<<endl;
	}
	if (codigoDI!= CodUsuario){
		cout<<"Codigo no encontrado, ingrese codigo ya registrado..." <<endl;
	}
	TMPcodigo=codigoDI;
	}
	DatosPersonales.close();
	CuentasVirtuales.close();
	
	system("pause");
	
} 

void DatosFinancieros(){
	string TMPcodigo;
	string codigoID;
	int res=0;
	system("cls");
	ifstream DatosPersonales("Datos Personales.txt");
	ofstream DatosFinancieros("Datos Financieros.txt", ios::app);
	
	cout<<"Ingrese un Codigo de Usuario ya Existente"<<endl;
	cin>>codigoID;
	
	while (DatosPersonales!=NULL){
		DatosPersonales>>CodUsuario>>Nombre>>Apellido>>Direccion>>Email>>Password>>Telefono;
		if (codigoID==CodUsuario && TMPcodigo!=CodUsuario){
			cout <<"DATOS REGISTRADOS"<<endl;
					cout <<"	Codigo de Usuario: "<<CodUsuario <<endl;
					cout <<"	Nombre: "<<Nombre<<" "<<Apellido<<endl;
					cout <<"	Direccion: "<<Direccion <<endl;
					cout <<"	Correo Electronico: "<<Email <<endl;
					cout <<"	Contrasenia: "<<Password<<endl;
					cout <<"	Telefono: "<<Telefono <<endl<<endl;
					res=1;
					system("pause");
					
					cout<<"\t Ingrese Codigo Financiero:\t"<<endl;
					cin>>CodFinanciero;
					cout<<"Ingrese el nombre del Banco:\t";
					cin>>Banco;
					cout<<"Ingrese numero de Cuenta:\t";
					cin>>NumCuenta;
					cout<<"Ingrese tipo de Cuenta:\t";
					cin>>TipoCuenta;
					cout<<"Ingrese el Numero de Tarjeta:\t";
					cin>>NumTarjeta;
					cout<<"Ingrese el Tipo de Tarjeta:\t";
					cin>>TipoTarjeta;
					
					DatosFinancieros<<CodUsuario<<"\t"<<CodFinanciero<<"\t"<<Banco<<"\t"<<NumCuenta<<"\t"<<TipoCuenta<<"\t"<<NumTarjeta<<"\t"<<TipoTarjeta<<endl;
					}
				TMPcodigo = CodUsuario;
				}
				if (res==0){
					cout<<"Usuario no Encontrado"<<endl;
					system("pause");
				}
		DatosPersonales.close();
		DatosFinancieros.close();
	}


	
void DatosPersonales(){//Procedimiento para el registro de una nueva Cuenta de usuario
	system("cls");
	ofstream DatosPersonales("Datos Personales.txt", ios::app);
	cout<<"Ingrese un Nuevo Codigo de Persona: "<<endl;
	cin>>CodUsuario;
	cout<<"Ingrese el Primer nombre:\t";
	cin>>Nombre;
	cout<<"Ingrese el Primer apellido:\t";
	cin>>Apellido;
	cout<<"\nDireccion \n(Separe las palabras con guion bajo( _ ):\t";
	cin>>Direccion;
	cout<<"Ingrese un Correo Electronico:\t";
	cin>>Email;
	cout<<"Ingrese una Contraseña de Ingreso:\t";
	cin>>Password;
	cout<<"Ingrese su No. de Telefono:\t";
	cin>>Telefono;
	
	DatosPersonales<<CodUsuario<<"\t"<<Nombre<<" "<<Apellido<<"\t"<<Direccion<<"\t"<<Email<<"\t"<<Password<<"\t"<<Telefono<<endl;
	DatosPersonales.close();
	
	do{
	cout<<"Desea Agregar Datos Financieros? [s/n]";
	cin>>Continuar;
		if (Continuar == "s"){
		DatosFinancieros();
		}
	}	while (Continuar== "s");
	system("pause");
}



void RegistrarUsuario(){//Menu REGISTRO DE DATOS DE USUARIO
	int regDatos;
	cout<<"REGISTRAR INFORMACION DE USUARIO"<<endl;
	cout<<"1.Registrar Datos Personales"<<endl;
	cout<<"2.Registrar Datos Financieros"<<endl;
	cout<<"3.Registrar Cuenta Virtual"<<endl;
	cin>>regDatos;
	switch (regDatos){
		case 1:
			DatosPersonales();
			break;
		case 2:
			DatosFinancieros();
			break;
		case 3:
			CuentasVirtuales();
			break;
	}
}

void VerPersonales(){
	char cadena[100];
	ifstream DatosPersonales("Datos Personales.txt");//Abrir archivo de texto
		system("cls");
            
	            if (DatosPersonales.fail ()) 
		            { 	 
						cerr<<"El archivo no existe"<<endl;  
					} 
	            	else  
	            	{    while (DatosPersonales.getline(cadena,100) != NULL)
	            		{ 	
						cout << cadena<<endl; 
						}
	                }      
            
			cout<<endl<<endl<<endl;
			DatosPersonales.close();
			system("pause");
}

void VerFinancieros(){
	char cadena[100];
	ifstream VerFinancieros("Datos Financieros.txt");//Abrir archivo de texto
		system("cls");
            
	            if (VerFinancieros.fail ()) 
		            { 	 
						cerr<<"El archivo no existe"<<endl;  
					} 
	            	else  
	            	{    while (VerFinancieros.getline(cadena,100) != NULL)
	            		{ 	
						cout << cadena<<endl; 
						}
	                }      
            
			cout<<endl<<endl<<endl;
			VerFinancieros.close();
			system("pause");
}

void VerCuentas(){
	char cadena[100];
	ifstream VerCuentas("Cuentas Virtuales.txt");//Abrir archivo de texto
		system("cls");
            
	            if (VerCuentas.fail ()) 
		            { 	 
						cerr<<"El archivo no existe"<<endl;  
					} 
	            	else  
	            	{    while (VerCuentas.getline(cadena,100) != NULL)
	            		{ 	
						cout << cadena <<endl; 
						}
	                }      
            
			cout<<endl<<endl<<endl;
			VerCuentas.close();
			system("pause");
}


void VerInfoUsuario()
{
	
	int ver;
	system("cls");
	cout<<"1. Ver Datos Personales"<<endl;
	cout<<"2. Ver Datos Financieros"<<endl;
	cout<<"3. Ver Cuentas Virtuales"<<endl;
	cout<<"4. Ver Todos los Datos"<<endl;
	cin>>ver;
	
	switch (ver){
		case 1:
			VerPersonales();
			break;
			
		case 2:
			VerFinancieros();
			break;
			
		case 3:
			VerCuentas();
			break;
			
		case 4:
			VerPersonales();
			VerFinancieros();
			VerCuentas();
			break;
	}
	

				
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void BuscarUsuario(){
	system("cls");
	string TMPcodigo;
	//TMPcodigo = CodUsuario;
	string buscarcodigo;
	int res = 0;

	ifstream DatosPersonales("Datos Personales.txt");
	cout<<"Ingrese Codigo Personal"<<endl;
	cin>>buscarcodigo;
	
	while (DatosPersonales != NULL)	
				{
				DatosPersonales>>CodUsuario>>Nombre>>Apellido>>Direccion>>Email>>Password>>Telefono;
		
					if (buscarcodigo==CodUsuario&&CodUsuario!= TMPcodigo){
						
					cout <<"Coincidencias de busqueda: "<<endl;
					cout <<"	Codigo de Usuario: "<<CodUsuario <<endl;
					cout <<"	Nombre: "<<Nombre<<" "<<Apellido<<endl;
					cout <<"	Direccion: "<<Direccion <<endl;
					cout <<"	Correo Electronico: "<<Email <<endl;
					cout <<"	Contrasenia: "<<Password<<endl;
					cout <<"	Telefono: "<<Telefono <<endl<<endl;
					res=1;
					}
				TMPcodigo = CodUsuario;
				}
				if (res==0){
					cout<<"Usuario no Encontrado"<<endl;
				}
			DatosPersonales.close();
			system("pause");
			//return;
}

void BuscarFinancieros()
{ system("cls");
	string TMPcodigo;
	//TMPcodigo = CodUsuario;
	string buscarCodigo;
	int res = 0;

	ifstream DatosFinancieros("Datos Financieros.txt");
	cout<<"Ingrese Codigo Personal de los datos Financieros:"<<endl;
	cin>>buscarCodigo;
	while (DatosFinancieros != NULL)	
				{
				DatosFinancieros>>CodUsuario>>CodFinanciero>>Banco>>NumCuenta>>TipoCuenta>>NumTarjeta>>TipoTarjeta;
		
					if (buscarCodigo==CodUsuario && CodUsuario!= TMPcodigo){
						
					cout <<"Coincidencias de busqueda: "<<endl;
					cout <<"Codigo de Usuario: "<<CodUsuario<<endl;
					cout <<"	Codigo Financiero: "<<CodFinanciero <<endl;
					cout <<"	Banco: "<<Banco<<endl;
					cout <<"	Numero de Cuenta: "<<NumCuenta <<endl;
					cout <<"	Tipo de Cuenta: "<<TipoCuenta <<endl;
					cout <<"	Numero de Tarjeta: "<<NumTarjeta<<endl;
					cout <<"	Tipo de Tarjeta: "<<TipoTarjeta<<endl<<endl;
					res=1;
					}
				TMPcodigo = CodUsuario;
				}
				if (res==0){
					cout<<"Usuario no Encontrado"<<endl;
				}
			DatosFinancieros.close();
			system("pause");
			//return;
}

void BuscarCuentas(){
	system("cls");
	string TMPcodigo;
	//TMPcodigo = CodUsuario;
	string buscarCodigo;
	int res = 0;

	ifstream CuentasVirtuales("Cuentas Virtuales.txt");
	cout<<"Ingrese Codigo Personal de la Cuenta Virtual"<<endl;
	cin>>buscarCodigo;
	while (CuentasVirtuales != NULL)	
				{
				CuentasVirtuales>>CodUsuario>>CodCuentaVirtual>>UsuarioCuentaVirtual>>PasswordCuentaVirtual;
		
					if (buscarCodigo==CodUsuario && CodUsuario!= TMPcodigo){
						
					cout <<"Coincidencias de busqueda: "<<endl;
					cout <<"Codigo de Usuario: "<<CodUsuario<<endl;
					cout <<"	Codigo de Cuenta Virtual: "<<CodCuentaVirtual <<endl;
					cout <<"	Usuario de Cuenta Virtual: "<<UsuarioCuentaVirtual<<endl;
					cout <<"	Contrasenia de cuenta virtual: "<<PasswordCuentaVirtual<<endl;
					res=1;
					}
			
		TMPcodigo = CodUsuario;
				}
				if (res==0){
					cout<<"Usuario no Encontrado"<<endl;
				}
			CuentasVirtuales.close();
			system("pause");
			//return;
}

void BuscarDatos(){
	int buscar;
	system("cls");
	cout<<"1. Buscar Datos Personales"<<endl;
	cout<<"2. Buscar Datos Financieros"<<endl;
	cout<<"3. Buscar Cuentas Virtuales"<<endl;
	cout<<"4. Buscar Todos los Datos"<<endl;
	cin>>buscar;
	
	switch (buscar){
		
		
		case 1:
			BuscarUsuario();
			break;
			
		case 2:
			BuscarFinancieros();
			break;
			
		case 3:
			BuscarCuentas();
			break;
			
		case 4:
			BuscarUsuario();
			BuscarFinancieros();
			BuscarCuentas();
			break;
	}
	
	
}

 void Modificardatos()
{//inicio del void modificar 
	string busqueda;
	
	string CodNuevo;
	string NomNuevo, ApeNuevo;
	string DirNuevo;
	string EmailNuevo;		
	string PassNuevo;
	int TelNuevo;

	ifstream Modificardatos("Datos Personales.txt");
	
	//temporal documento para no perder datos
	ofstream GuardarTemporal("temporal.txt");
	cout<<"ingrese el codigo de la persona que desea modificar"<<endl;
	cin>>busqueda;
	while (Modificardatos != NULL)
	{			
//principo del codigo
	Modificardatos>>CodUsuario>>Nombre>>Apellido>>Direccion>>Email>>Password>>Telefono;
	if (busqueda==CodUsuario && CodUsuario!= TMPcodigo)
	{	
					cout <<"Coincidencias de busqueda: "<<endl;
					cout <<"	Codigo de Usuario: "<<CodUsuario <<endl <<endl;
					cout <<"	Nombre: "<<Nombre<<" "<<Apellido <<endl<<endl;
					cout <<"	Direccion: "<<Direccion <<endl;
					cout <<"	Correo Electronico: "<<Email <<endl<<endl;
					cout <<"	Contrasenia: "<<Password<<endl<<endl;
					cout <<"	Telefono: "<<Telefono <<endl<<endl;
					
					cout <<"ingrese nuevo codigo de usuario"<<endl;
					cin>>CodNuevo;
					
					cout <<"ingrese nuevo Nombre"<<endl;
					cin>>NomNuevo;
					
					cout <<"ingrese nuevo  Apellido"<<endl;
					cin>>ApeNuevo;

					cout <<"ingrese nuevo Direccion"<<endl;
					cin>>DirNuevo;
					
					cout <<"ingrese nuevo Correo Electronico"<<endl;
					cin>>EmailNuevo;
					
					cout <<"ingrese nuevo Contrasenia"<<endl;
					cin>>PassNuevo;
					
					cout <<"ingrese nuevo Telefono"<<endl;
					cin>>TelNuevo;
		GuardarTemporal<<CodNuevo<<" "<<NomNuevo<<" "<<ApeNuevo<<" "<<DirNuevo<<" "<<EmailNuevo<<" "<<PassNuevo<<" "<<TelNuevo<<endl;
	}
	else
		{
		if(CodUsuario!= TMPcodigo)
		{
			//cout<<"Codigo no registrado... "<<endl;
			GuardarTemporal<<CodUsuario<<" "<<Nombre<<" "<<Apellido<<" "<<Direccion<<" "<<Email<<" "<<Password<<" "<<Telefono<<endl;
					}									
		}
	TMPcodigo = CodUsuario;
										
	}	
	Modificardatos.close();
	GuardarTemporal.close();
	remove("Datos Personales.txt");
    rename("temporal.txt","Datos Personales.txt");	
    system("pause");
    
}


void ModificarFinancieros()
{//inicio del void modificar 
	string busqueda;
	string CodNuevo;
	string CodFinanciero2;
	string Banco2;
	int NumCuenta2;
	string TipoCuenta2;
	int NumTarjeta2;
	string TipoTarjeta2;


	ifstream ModificarFinancieros("Datos Financieros.txt");
	
	//temporal documento para no perder datos
	ofstream GuardarTemporal("temporal.txt");
	cout<<"ingrese el codigo de la persona que desea modificar"<<endl;
	cin>>busqueda;
	while (ModificarFinancieros != NULL)
	{			
//principo del codigo
	ModificarFinancieros>>CodUsuario>>CodFinanciero>>Banco>>NumCuenta>>TipoCuenta>>NumTarjeta>>TipoTarjeta;
	if (busqueda==CodUsuario && CodUsuario!= TMPcodigo)
	{	
					cout <<"Coincidencias de busqueda: "<<endl;
					cout <<"Codigo de Usuario: "<<CodUsuario<<endl;
					cout <<"	Codigo Financiero: "<<CodFinanciero <<endl;
					cout <<"	Banco: "<<Banco<<endl;
					cout <<"	Numero de Cuenta: "<<NumCuenta <<endl;
					cout <<"	Tipo de Cuenta: "<<TipoCuenta <<endl;
					cout <<"	Numero de Tarjeta: "<<NumTarjeta<<endl;
					cout <<"	Tipo de Tarjeta: "<<TipoTarjeta<<endl<<endl;
					
					cout <<"ingrese nuevo codigo de usuario"<<endl;
					cin>>CodNuevo;
					
					cout <<"ingrese nuevo codigo financiero: "<<endl;
					cin>>CodFinanciero2;
					
					cout <<"ingrese nuevo  banco"<<endl;
					cin>>Banco2;

					cout <<"ingrese nuevo Numero de Cuenta"<<endl;
					cin>>NumCuenta2;
					
					cout <<"ingrese nuevo Tipo de Cuenta"<<endl;
					cin>>TipoCuenta2;
					
					cout <<"ingrese nuevo Numero de Tarjeta"<<endl;
					cin>>NumTarjeta2;
					
					cout <<"ingrese nuevo Tipo de Tarjeta"<<endl;
					cin>>TipoTarjeta2;
		GuardarTemporal<<CodNuevo<<" "<<CodFinanciero2<<" "<<Banco2<<" "<<NumCuenta2<<" "<<TipoCuenta2<<" "<<NumTarjeta2<<" "<<TipoTarjeta2<<endl;
	}
	else
		{
		if(CodUsuario!= TMPcodigo)
		{
			//cout<<"Codigo no registrado... "<<endl;
			GuardarTemporal<<CodUsuario<<" "<<CodFinanciero<<" "<<Banco<<" "<<NumCuenta<<" "<<TipoCuenta<<" "<<NumTarjeta<<" "<<TipoTarjeta<<endl;
					}									
		}
	TMPcodigo = CodUsuario;
										
	}	
	ModificarFinancieros.close();
	GuardarTemporal.close();
	remove("Datos Financieros.txt");
    rename("temporal.txt","Datos Financieros.txt");	
    system("pause");
    
}


void ModificarVirtuales()
{//inicio del void modificar 
	string busqueda;
	string CodNuevo;
	string codigoDI2;
	string CodCuentaVirtual2;
	string UsuarioCuentaVirtual2;
	string PasswordCuentaVirtual2;

	ifstream ModificarVirtuales("Cuentas Virtuales.txt");
	
	//temporal documento para no perder datos
	ofstream GuardarTemporal("temporal.txt");
	cout<<"ingrese el codigo de la persona que desea modificar"<<endl;
	cin>>busqueda;
	while (ModificarVirtuales != NULL)
	{			
//principo del codigo
	ModificarVirtuales>>CodUsuario>>CodCuentaVirtual>>UsuarioCuentaVirtual>>PasswordCuentaVirtual;
	if (busqueda==CodUsuario && CodUsuario!= TMPcodigo)
	{	
					cout <<"Coincidencias de busqueda: "<<endl;
					cout <<"Codigo de Usuario: "<<CodUsuario<<endl;
					cout <<"	Codigo de Cuenta Virtual: "<<CodCuentaVirtual <<endl;
					cout <<"	Usuario de Cuenta Virtual: "<<UsuarioCuentaVirtual<<endl;
					cout <<"	Contrasenia de cuenta virtual: "<<PasswordCuentaVirtual<<endl;
					
					cout <<"ingrese nuevo codigo de usuario"<<endl;
					cin>>CodNuevo;
					
					cout <<"ingrese nuevo Codigo de Cuenta Virtual: "<<endl;
					cin>>CodCuentaVirtual2;
					
					cout <<"ingrese nuevo  Usuario de Cuenta Virtual:"<<endl;
					cin>>UsuarioCuentaVirtual2;

					cout <<"ingrese nueva Contrasenia de cuenta Virtual:"<<endl;
					cin>>PasswordCuentaVirtual2;
					
		GuardarTemporal<<CodNuevo<<" "<<CodCuentaVirtual2<<" "<<UsuarioCuentaVirtual2<<" "<<PasswordCuentaVirtual2<<endl;
	}
	else
		{
		if(CodUsuario!= TMPcodigo)
		{
			//cout<<"Codigo no registrado... "<<endl;
			GuardarTemporal<<CodUsuario<<" "<<CodCuentaVirtual<<" "<<UsuarioCuentaVirtual<<" "<<PasswordCuentaVirtual<<endl;
					}									
		}
	TMPcodigo = CodUsuario;
										
	}	
	ModificarVirtuales.close();
	GuardarTemporal.close();
	remove("Cuentas Virtuales.txt");
    rename("temporal.txt","Cuentas Virtuales.txt");	
    system("pause");
    
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void modificargeneral()
{
	string modificar;
					cout<<"1. Datos personales"<<endl;
					cout<<"2. Datos Financieros"<<endl;
					cout<<"3. Cuentas Virtuales"<<endl;
					cin>>modificar;
					
					if (modificar=="1") {
						Modificardatos();
						}
					if (modificar=="2") {	
						ModificarFinancieros();
						}
					if (modificar=="3") {	
						ModificarVirtuales();
					}
}






int main(){//**********Menu Principal**********
	int bienvenido;
	do{
		system("cls");
		cout<<"\t\t\t BIENVENIDO"<<endl;
	    cout<<"\t Seleccione la Opcion a la que Desea Ingresar"<<endl;
	    cout<<" "<<endl;
	    cout<<"1.Registrar Usuario"<<endl;
	    cout<<"2.Visualizar Informacion de Usuario"<<endl;
	    cout<<"3.Buscar Informacion de Usuario"<<endl;
	    cout<<"4.Modificar informacion de Usuario"<<endl;
	    cout<<"5.    Salir        "<<endl;
		cin>>bienvenido;
		
		switch(bienvenido){
			case 1:
				RegistrarUsuario();
				break;
				
			case 2:
				VerInfoUsuario();
				break;
				
			case 3:
				BuscarDatos();
				break;
				
			case 4:
				modificargeneral();
				break;
				
			case 5:
				cout<<"Programa Finalizado";
				break;
			}   
		}while(bienvenido != 5);
		return 0;
	}	
