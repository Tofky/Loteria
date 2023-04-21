#include<iostream>
#include<chrono>
#include<random>
#include<iomanip>
#include<windows.h>
int sortee_premio(int maxNum){ // Genera un numero aleatorio hasta el numero maximo indicado siendo este inclusivo
	Sleep(30);
	std::mt19937 gen(std::chrono :: high_resolution_clock :: now().time_since_epoch().count());
	std::uniform_int_distribution<> dis(0, maxNum);	 				
	return dis(gen);
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
int premios_disponibles(int i,int premio_0,int premio_1,int premio_2,int premio_3,int premio_4,int premio_5,int premio_6){
	int premiosRestantes;
	switch(i){
	case 0:
		premiosRestantes = 10 - premio_0;
		break;
	case 1:
		premiosRestantes = 10 - premio_1;
		break;
	case 2:
		premiosRestantes = 16 - premio_2;
		break;
	case 3:
		premiosRestantes = 10 - premio_3;
		break;
	case 4:
		premiosRestantes = 2 - premio_4;
		break;
	case 5:
		premiosRestantes = 1 - premio_5;
		break;
	case 6:
		premiosRestantes = 1 - premio_6;
		break;
	}
	return premiosRestantes;
}
int monto_acumulado(int numeroSorteo){ // Brinda el monto del acumulado, en base al numero de sorteo 
	int montoAcumulado = 0;
	
	if(numeroSorteo >= 1 && numeroSorteo < 11){
		montoAcumulado = 20;
	}
	else if(numeroSorteo >= 11 && numeroSorteo <=20){
		montoAcumulado = 30;
	}
	return montoAcumulado;
}	
int bolas_restantes(int premiosTotales,int premio_0,int premio_1,int premio_2,int premio_3,int premio_4,int premio_5,int premio_6){
	int bolas_totales = 0;
	for(int i = 0; i < premiosTotales;i++){
		bolas_totales += premios_disponibles(i,premio_0,premio_1,premio_2,premio_3,premio_4,premio_5,premio_6);
	}
	return bolas_totales;
}
std::string seleccionar_premio(int numeroPremio,std::string tipo){
	std::string premio;
	switch(numeroPremio){
	case 0:
		if (tipo == "T"){
			premio = "2.000.000";
		}
		else if(tipo == "N"){
			premio = " 2";
		}
		break;
	case 1:
		if (tipo == "T"){
			premio = "2.500.000";
		}
		else if(tipo == "N"){
			premio = "2.5";
		}
		break;	
	case 2:
		if (tipo == "T"){
			premio = "3.000.000";
		}
		else if(tipo == "N"){
			premio = "3";
		}
		break;
	case 3:
		if (tipo == "T"){
			premio = "5.000.000";
		}
		else if(tipo == "N"){
			premio = "5";
		}
		break;
	case 4:
		if (tipo == "T"){
			premio = "10.000.000";
		}
		else if(tipo == "N"){
			premio = "10";
		}
		break;
	case 5:
		if (tipo == "T"){
			premio = "15.000.000";
		}
		else if(tipo == "N"){
			premio = "15";
		}
		break;
	case 6:
		premio = "Acumulado";
		break;
	}
	return premio;
}
int actualiza_acumulado(int premiosTotales,int opcion,int numeroSorteo,int numeroPremio,int premio_0,int premio_1,int premio_2,int premio_3,int premio_4,int premio_5,int premio_6){
	int valor;
	switch(opcion){
	case 1:
		valor = numero_bolas(numeroSorteo);
		break;
	case 2: 
		valor = premios_disponibles(numeroPremio,premio_0,premio_1,premio_2,premio_3,premio_4,premio_5,premio_6);
		break;
	case 3:
		valor = monto_acumulado(numeroSorteo);
		break;
	case 4:
		valor = bolas_restantes(premiosTotales,premio_0,premio_1,premio_2,premio_3,premio_4,premio_5,premio_6);
		break;
	}
	return valor;
}
int main (int argc, char *argv[]) {
	const int premiosTotales = 7;
	const int bolasMaximas = 60;
	const int monto_inicial_acumulado = 100;
	int opcion;
	int premiosRestantes = 0;
	int numeroSorteo = 1;
	int numeroSerie = 1001;
	int numeroPremio = 0;
	int monto_total_acumulado = monto_inicial_acumulado;
	int premio_0 = 0;
	int premio_1 = 0;
	int premio_2 = 0;
	int premio_3 = 0;
	int premio_4 = 0;
	int premio_5 = 0;
	int premio_6 = 0;
	int validador;
	std::string tipoPremio;
	do{
		int bolasExtra = actualiza_acumulado(premiosTotales,4,numeroSorteo,0,premio_0,premio_1,premio_2,premio_3,premio_4,premio_5,premio_6)-1;
		int numeroBolas = actualiza_acumulado(premiosTotales,1,numeroSorteo,0,premio_0,premio_1,premio_2,premio_3,premio_4,premio_5,premio_6);
		std::system("CLS");
		std::cout << "        Sorteo # " << numeroSorteo << " del Premio Acumulado de la Lotería Nacional No. " << numeroSerie <<std::endl;
		std::cout << " ****************************************************************************" << std::endl;
		std::cout << " *                Monto Acumulado: " <<   monto_total_acumulado << " millones de colones                  *" << std::endl;
		std::cout << " *            Bolitas de Acumulado: " << numeroBolas << " Bolitas Premio Extra: " << bolasExtra <<"              *"<<std::endl;
		std::cout << " ****************************************************************************" << std::endl;
		std::cout << std:: endl;
		std::cout << " Premios Disponibles en la Tómbola " << std::endl;
		std::cout << " Cantidad " << std::setfill(' ') << std::setw(11) << "Monto" << std::endl;
		for(int i = 0; i < premiosTotales ; i++ ){
			premiosRestantes = actualiza_acumulado(premiosTotales,2,numeroSorteo,i,premio_0,premio_1,premio_2,premio_3,premio_4,premio_5,premio_6);
			tipoPremio = seleccionar_premio(i,"T");
			std::cout << std::setfill(' ')<< std::setw(5) << premiosRestantes;; 
			if (tipoPremio != "Acumulado"){
				std::cout << std::setfill(' ') << std::setw(18)<< tipoPremio << std::endl;
			}else {
				std::cout << std::setfill(' ') << std::setw(18) << tipoPremio << std::endl;
			}
				
		}
		monto_total_acumulado += actualiza_acumulado(premiosTotales,3,numeroSorteo,0,premio_0,premio_1,premio_2,premio_3,premio_4,premio_5,premio_6);
		for(int i = 0; i < numeroBolas;i++){
			if(numeroBolas != bolasMaximas){
				do{
					numeroPremio = sortee_premio(5);
					validador = actualiza_acumulado(premiosTotales,2,numeroSorteo,numeroPremio,premio_0,premio_1,premio_2,premio_3,premio_4,premio_5,premio_6);
					tipoPremio = seleccionar_premio(numeroPremio,"N");
				}while(validador == 0);
				switch(numeroPremio){
				case 0:
					premio_0 += 1;
					break;
				case 1:
					premio_1 += 1;
					break;
				case 2:
					premio_2 += 1;
					break;
				case 3:
					premio_3 += 1;
					break;
				case 4:
					premio_4 += 1;
					break;
				case 5:
					premio_5 += 1;
					break;
				case 6:
					premio_6 += 1;
					break;
				}
				if (tipoPremio != "Acumulado"){
					std::cout << " Premio: " << tipoPremio << " millones de colones." << std::endl;
				}else {
					std::cout << " Premio: " << tipoPremio << std::endl;
				}
				std::cout << std::endl;
				std::cout << " Numero: " << std::setfill('0')<< std::setw(2) << sortee_premio(99) << " Serie : " << std::setfill('0')<< std::setw(3) << sortee_premio(999) << std::endl;
				std::cout << std:: endl;
				if (tipoPremio == "Acumulado"){
					std::cout << "Muchas gracias por haber participado en el sorteo de La Junta de Proteccion Social." << std::endl;
					std::cout << "Lo invitamos a seguir participando." << std::endl;
					opcion == 2;
					return 0;
				}
			}
			else if(numeroBolas == bolasMaximas ){
				for(int i = 1; i <= bolasMaximas;i++){
					if (i == 1){
						std::cout << "Premio: " << monto_total_acumulado/bolasMaximas << " millones de colones." << std::endl;
						std::cout << std::endl;
					}
					std::cout << "Ganador #" << i ;
					std::cout << "  Numero: " << std::setfill('0')<< std::setw(2) << sortee_premio(99) << " Serie : " << std::setfill('0')<< std::setw(3) << sortee_premio(999) << std::endl;
					std::cout << std::endl; 
				}
				i = bolasMaximas;
				std::cout << "Muchas gracias por haber participado en el sorteo de La Junta de Proteccion Social." << std::endl;
				std::cout << "Lo invitamos a seguir participando." << std::endl;
			}
			
			
		}
		if (numeroSorteo <= 20){
			std::cout << " ¡¡¡ El premio acumulado se incrementa en " << monto_acumulado(numeroSorteo) << " millones para el próximo sorteo!!!" << std::endl;
			std::cout << std:: endl;
			std::cout << " Monto del Acumulado para el proximo sorteo: " << monto_total_acumulado << " millones de colones."<< std::endl;
			std::cout << std:: endl;
			std::cout << std:: endl;
			do {
				std::cout << " Digite < 1 > para realizar el proximo sorteo" << std::endl;
				std::cout << " Digite < 2 > para terminar"<< std::endl;	
				std::cout << "Opcion: ";
				std::cin >> opcion;
			}while(opcion != 1 && opcion !=2);
		}
		else if (numeroSorteo >  20 || opcion == 2){
			break;
		}
		numeroSorteo++;
		numeroSerie++;
	}while(opcion == 1);

	return 0;
}

