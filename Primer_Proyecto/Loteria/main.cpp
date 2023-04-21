#include<iostream>
#include<chrono>
#include<random>
#include<iomanip>
#include<windows.h>
int sortear_numero(int maxNum){ // Genera un numero aleatorio hasta el numero maximo indicado siendo este inclusivo
	Sleep(60);
	std::mt19937 gen(std::chrono :: high_resolution_clock :: now().time_since_epoch().count());
	std::uniform_int_distribution<> dis(0, maxNum);	 				
	return dis(gen);
}
int premios_disponibles(int numGanador){//Da el numero de premios disponibles. 
	int cantidadPremios = 0;
	switch(numGanador){
	case 0: 
		cantidadPremios = 10;
		break;
	case 1: 
		cantidadPremios = 10;
		break;
	case 2:
		cantidadPremios = 16;
		break;
	case 3: 
		cantidadPremios = 10;
		break;
	case 4:
		cantidadPremios = 2;
		break;
	case 5:
		cantidadPremios = 1;
		break;
	case 6:
		cantidadPremios = 1;
		break;
	}
	return cantidadPremios;
}
int numero_bolas(int numeroSorteo){// Brinda el numero de bolas, segun el numero del sorteo.
	int numeroBolas = 0;
	if(numeroSorteo<= 10){
		numeroBolas = 1;
	}
	else if(numeroSorteo<=20){
		numeroBolas = 2;
	}
	else if(numeroSorteo == 21){
		numeroBolas = 60;
	}
	return numeroBolas;
}
int monto_acumulado(int numeroSorteo){ // Brinda el monto del acumulado, en base al numero de sorteo 
	int montoAcumulado = 0;
	
	if(numeroSorteo >= 1 && numeroSorteo < 11){
		montoAcumulado = 20;
	}
	else if(numeroSorteo >= 11 && numeroSorteo <=20){
		montoAcumulado = 30;
	}
	else if(numeroSorteo == 21){
		montoAcumulado = 60;
	}
	return montoAcumulado;
}	
int bolas_restantes(int premiosTotales){ //Entrega el numero total de bolas 
	int extraPrize = 0;
	for(int i=0;i < premiosTotales-1;i++){
		extraPrize += premios_disponibles(i);
	}
	return extraPrize;
}
/*int premios_restantes(int i){ 
	return premios_disponibles(i)-=1;
}*/
int main (int argc, char *argv[]) {
	const int premiosTotales = 7;
	const int bolasMaximas = 60;
	const int monto_inicial_acumulado = 100;
	int opcion;
	int numeroSorteo = 1;
	int numeroSerie = 1001;
	int numeroGanador = 0;
	int monto_total_acumulado = monto_inicial_acumulado;
	
	do{
		std::system("CLS");
		std::cout << "        Sorteo # " << numeroSorteo << " del Premio Acumulado de la Lotería Nacional No. " << numeroSerie <<std::endl;
		std::cout << " ****************************************************************************" << std::endl;
		std::cout << " *                Monto Acumulado: " <<   monto_total_acumulado<< " millones de colones                  *" << std::endl;
		std::cout << " *            Bolitas de Acumulado: " << numero_bolas(numeroSorteo) << " Bolitas Premio Extra: " << bolas_restantes(premiosTotales) <<"              *"<<std::endl;
		std::cout << " ****************************************************************************" << std::endl;
		std::cout << std:: endl;
		std::cout << " Premios Disponibles en la Tómbola " << std::endl;
		std::cout << " Cantidad " << std::setfill(' ') << std::setw(10) << "Monto" << std::endl;
		for(int i = 0; i < premiosTotales ; i++ ){
			std::cout << std::setfill(' ')<< std::setw(5) << premios_disponibles(i) << std::setfill(' ') << std::setw(18) << 20 << std::endl;
		}
		monto_total_acumulado += monto_acumulado(numeroSorteo);
		if (numeroSorteo <= 20){
			std::cout << " ¡¡¡ El premio acumulado se incrementa en " << monto_acumulado(numeroSorteo) << " millones para el próximo sorteo!!!" << std::endl;
			std::cout << std:: endl;
			std::cout << " Monto del Acumulado para el proximo sorteo: " << monto_total_acumulado << " millones de colones."<< std::endl;
			std::cout << std:: endl;
			std::cout << std:: endl;	
			std::cout << " Digite < 1 > para realizar el proximo sorteo" << std::endl;
			std::cout << " Digite < 2 > para terminar"<< std::endl;
			std::cout << "Opcion: ";
			std::cin >> opcion;
		}
		
		numeroSorteo++;
		numeroSerie++;
	}while(opcion = 1);

	return 0;
}

