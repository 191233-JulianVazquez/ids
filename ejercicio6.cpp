#include<iostream>
#include<stdlib.h> 
using namespace std;
//mis funciones
void menu();
int pizza_tradicional();
int pizza_especial();
int pizza_ligera();
int productos_adicionales(int Cpizza, int Tpizza);
float preciopizzas(int Tpizza, int Cpizza);
float precio_producto(int producto1, int producto2, int Cproducto, int vuelta);

//mis variables
/* //cantidad de pizzas = Cpizzas //tipo de pizza = Tpizza
*/
//_________________________________________________________________________________
int main ()
{
setlocale(LC_CTYPE,"Spanish");
system ("color 0B");
system ("cls");
	menu();
}
// mis funciones
void menu ()
{
	string detalle;
	int Tpizza, Cpizza, desicion1, desicion2, vuelta=0, tipo_de_pago ; 
	float cantidad, cantidad_alterna, descuento=0.10;
	float descuento_de_precio, precio_con_descuento, precio_total;
	cout<<"               Bienvenido a pizzas up"<<endl;
		cout<<"Por favor seleccione su tipo de pizza del siguiente menú"<<endl;
		cout<<endl;
		cout<<"(1) Pizza Tradicional"<<endl;
		cout<<"(2) Pizza Especial"<<endl;
		cout<<"(3) Pizza Ligera"<<endl;
		cin>>Tpizza;
		if(Tpizza<1 ||  Tpizza>3)
		{
		do
		{
			cout<<"Error, tipo de pizza no encontrado "<<endl;
			cin>>Tpizza;
		}
		while(Tpizza<1 || Tpizza>3);
		}
		do
		{
			cout<<"Ingrese la cantidad de pizzas que desea"<<endl;
			cin>>Cpizza;
		}
		while(Cpizza<1 || Cpizza>3);
		switch (Tpizza)
		{
			case 1: 
				pizza_tradicional();
				detalle="tradicional";
				break;
			case 2:
				detalle="especial";
				pizza_especial();
				break;
			case 3: 
			detalle="ligera";
				pizza_ligera();
				break;
			default:
				cout<<"tipo de pizza no encontrado";
		}
	if (Cpizza<3)
	{
	cout<<"¿Desea productos adicionales?"<<endl;
	cout<<"(1)SI (2)NO"<<endl;
	do
	{
		cin>>desicion2;
	}
	while(desicion2!=1 && desicion2!=2);
	//si decea mas productos
	if(desicion2==1)
	{
		cantidad_alterna=productos_adicionales(Cpizza, Tpizza);
		cantidad=preciopizzas(Tpizza, Cpizza);
		precio_total=cantidad_alterna+cantidad;
		if(Cpizza==2)
		{
			
			descuento_de_precio=precio_total*descuento;
			precio_con_descuento=precio_total-descuento_de_precio;
			cout<<"Su compra fue de 2 pizzas "<<detalle<<" con producto adicional"<<endl;
			cout<<"Su precio a pagar es: "<<precio_con_descuento<<endl;
			cout<<"¿Pagará con tarjeta de credito?"<<endl;
			cout<<" (1) SI (2) NO"<<endl;
			cin>>tipo_de_pago;
			if(tipo_de_pago==1)
			{
				cout<<"Ingrese datos"<<endl;
				cout<<endl;
				cout<<"cargando..."<<endl;
				cout<<"Gracias por su compra, vuelva pronto..."<<endl;
			}
			else
			{
				cout<<"Se le cobrara en su domicilio"<<endl;
			}
		}
		else
		{
			cout<<"Su compra fue de 1 pizza "<<detalle<<" con producto adicional"<<endl;
			cout<<"Su precio a pagar es: "<<precio_total<<endl;
			cout<<"¿Pagará con tarjeta de credito?"<<endl;
			cout<<" (1) SI (2) NO"<<endl;
			cin>>tipo_de_pago;
			if(tipo_de_pago==1)
			{
				cout<<"Ingrese datos"<<endl;
				cout<<endl;
				cout<<"cargando..."<<endl;
				cout<<"Gracias por su compra, vuelva pronto..."<<endl;
			}
			else
			{
				cout<<"Se le cobrara en su domicilio"<<endl;
			}
			
		}
	}
	else
	{
		if(Cpizza==2)
		{
			cantidad=preciopizzas(Tpizza, Cpizza);
			descuento_de_precio=cantidad*descuento;
			precio_con_descuento=cantidad-descuento_de_precio;
			cout<<"Su compra fue de 2 pizzas "<<detalle<<endl;
			cout<<"Su precio a pagar es: "<<precio_con_descuento<<endl;
			cout<<"¿Pagará con tarjeta de credito?"<<endl;
			cout<<" (1) SI (2) NO"<<endl;
			cin>>tipo_de_pago;
			if(tipo_de_pago==1)
			{
				cout<<"Ingrese datos"<<endl;
				cout<<endl;
				cout<<"Cargando..."<<endl;
				cout<<"Gracias por su compra, vuelva pronto..."<<endl;
			}
			else
			{
				cout<<"Se le cobrara en su domicilio"<<endl;
			}
		}
		else
		{
			cantidad=preciopizzas(Tpizza, Cpizza);
			cout<<"Su compra fue de 1 pizza "<<detalle<<endl;
			cout<<"Su precio a pagar es: "<<cantidad<<endl;
			cout<<"Pagara con tarjeta de credito"<<endl;
			cout<<" (1) SI (2) NO"<<endl;
			cin>>tipo_de_pago;
			if(tipo_de_pago==1)
			{
				cout<<"Ingrese datos"<<endl;
				cout<<endl;
				cout<<"Cargando..."<<endl;
				cout<<"Gracias por su compra, vuelva pronto..."<<endl;
			}
			else
			{
				cout<<"Se le cobrara en su domicilio"<<endl;
			}
		}
	}
	}
	else
	{
		cantidad=preciopizzas(Tpizza, Cpizza);
		descuento_de_precio=cantidad*descuento;
		precio_con_descuento=cantidad-descuento_de_precio;
		cout<<"Su compra fue de 3 pizzas "<<detalle<<endl;
		cout<<"Su precio a pagar es: "<<precio_con_descuento<<endl;
		cout<<"Pagara con tarjeta de credito"<<endl;
		cout<<" (1) SI (2) NO"<<endl;
		cin>>tipo_de_pago;
		if(tipo_de_pago==1)
		{
			cout<<"Ingrese datos"<<endl;
			cout<<endl;
			cout<<"Cargando..."<<endl;
			cout<<"Gracias por su compra, vuelva pronto..."<<endl;
		}
		else
		{
			cout<<"Se le cobrara en su domicilio"<<endl;
		}
		
	}
}
//funciones
int pizza_tradicional()
{
	string acum;
	int i,ingredientes[4],Cingredientes;
	cout<<"Usted a ingresado a la seleccion de ingredientese para una pizza tradicional"<<endl;
	cout<<"Ingrese cuantos ingredientes llevara su pizza"<<endl;
	do
	{
	cin>>Cingredientes;
	}
	while(Cingredientes<2 || Cingredientes>4);
	cout<<"seleccione sus ingredientes"<<endl;
	cout<<"(1) Carnes frías"<<endl;
	cout<<"(2) Piña"<<endl;
	cout<<"(3) Jalapeños"<<endl;
	cout<<"(4) Extra queso"<<endl;
	for(i=0;i<Cingredientes;i++)
	{
		cin>>ingredientes[i];
		if(ingredientes[i]<1 || ingredientes[i]>4)
		{
			i=i-1;
		}
	}
	for(i=0;i<Cingredientes;i++)
	{
		switch(ingredientes[i])
		{
			case 1: 
				acum=acum+"Carnes frías"+", ";
				break;
			case 2: 
				acum=acum+"Piña"+", ";
				break;
			case 3:
				acum=acum+"Jalapeños"+", ";
				break;
			case 4:
				acum=acum+"Extra queso"+", ";
				break;
			default:
				cout<<"Tipo de pizza no encontrado";
		}
	}
	cout<<"Tu pizza es de "<<acum<<endl;
	}
int pizza_especial()
{
	string acum;
	int ingredientes[4];
	int i,Cingredientes;
	cout<<"Usted a ingresado a la seleccion de ingredientese para una pizza especial"<<endl;
	cout<<"Ingrese cuantos ingredientes llevara su pizza"<<endl;
	do
	{
	cin>>Cingredientes;
	}
	while(Cingredientes<2 || Cingredientes>4);
	cout<<"seleccione sus ingredientes"<<endl;
	cout<<"(1) Pollo"<<endl;
	cout<<"(2) Tocino"<<endl;
	cout<<"(3) Piña"<<endl;
	cout<<"(4) Salsa mango habanero"<<endl;
	
	for(i=0;i<Cingredientes;i++)
	{
		cin>>ingredientes[i];
		if(ingredientes[i]<1 || ingredientes[i]>4)
		{
			i=i-1;
		}
	}
	for(i=0;i<Cingredientes;i++)
	{
		switch(ingredientes[i])
		{
			case 1: 
				acum=acum+"Pollo"+", ";
				break;
			case 2: 
				acum=acum+"Tocino"+", ";
				break;
			case 3: 
				acum=acum+"Piña"+", ";
				break;
			case 4:
				acum=acum+"Salsa mango habanero"+", ";
				break;	
			default:
				cout<<"Tipo de pizza no encontrado";
		}
	}
	cout<<"Tu pizza es de "<<acum<<endl;
	}
int pizza_ligera()
{
	string acum;
	int ingredientes[4];
	int i,Cingredientes;
	cout<<"Usted a ingresado a la seleccion de ingredientese para una pizza ligera"<<endl;
	cout<<"Ingrese cuantos ingredientes llevara su pizza"<<endl;
	do
	{
	cin>>Cingredientes;
	}
	while(Cingredientes<2 || Cingredientes>4);
	cout<<"Seleccione sus ingredientes"<<endl;
	cout<<"(1) Pimiento"<<endl;
	cout<<"(2) Champiñones"<<endl;
	cout<<"(3) Aceitunas"<<endl;
	cout<<"(4) Cebolla"<<endl;
	for(i=0;i<Cingredientes;i++)
	{
		cin>>ingredientes[i];
		if(ingredientes[i]<1 || ingredientes[i]>4)
		{
			i=i-1;
		}
	}
	for(i=0;i<Cingredientes;i++)
	{
		switch(ingredientes[i])
		{
			case 1: 
				acum=acum+"Pimiento"+" ";
				break;
			case 2: 
				acum=acum+"Champiñones"+", ";
				break;
			case 3: 
				acum=acum+"Aceitunas"+", ";
			break;
			case 4:
				acum=acum+"Cebolla"+", ";
				break;	
			default:
				cout<<"Tipo de pizza no encontrado";
		}
	}
	cout<<"Tu pizza es de "<<acum<<endl;
}
int productos_adicionales(int Cpizza, int Tpizza)
{
	int vuelta=0,acum=0, producto1, producto2, Cproducto, desicion3;
	float productos;
	acum=acum+Cpizza;
	do
	{
		desicion3=2;
		vuelta=vuelta+1;
		cout<<"Seleccione su producto"<<endl;
		cout<<"(1) Papas a la francesa"<<endl;
		cout<<"(2) Bebidas"<<endl;
		do
		{
			cin>>producto1;
			if(vuelta==2)
			{
				producto2=producto1;
			}
		}
		while(producto1!=1 && producto1!=2);
		do
		{
			if(acum>3)
			{
				acum=acum-Cproducto;
			}
			cout<<"cuantos productos requieres"<<endl;
			cin>>Cproducto;
			acum=acum+Cproducto;
		}
		while(acum>3);
		if(acum<3)
		{
			cout<<"requiere algun otro producto"<<endl;
			cout<<"(1)SI (2)NO"<<endl;
			do
			{
				cin>>desicion3;
			}
			while(desicion3!=1 && desicion3!=2);
		}
	}
	while(desicion3==1);
	productos=precio_producto( producto1, producto2, Cproducto, vuelta);
	return productos;
}

float preciopizzas(int Tpizza, int Cpizza)
{
	float tradicional=189.5, especial=199, ligera=175.99;
	float precio1;
	switch(Tpizza)
	{
		case 1:
			precio1=Cpizza*tradicional;
			break;
		case 2:
			precio1=Cpizza*especial;
			break;
		case 3:
			precio1=Cpizza*ligera;
			break;
		default:
			cout<<"";
	}
	return precio1;
}
float precio_producto(int producto1, int producto2, int Cproducto, int vuelta)
{
	int bebidas=35, papas_francesas=50;
	float precioproductos;
	if(vuelta==2)
	{
		precioproductos=bebidas+papas_francesas;
	}
	else
	{
		if(producto1==1)
		{
			precioproductos=papas_francesas*Cproducto;
		}
		else
		{
			precioproductos=bebidas*Cproducto;
		}
	}
	return precioproductos;
}

