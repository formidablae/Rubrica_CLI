//============================================================================
// Name        : contatto.cpp
// Version     :
// Copyright   :
// Description : Rubrica in C++
//============================================================================

#include "contatto.h"			// Inclusione header classe Contatto generico
#include "../utilita/utilita.h"	// Inclusione header per alcune funzioni utili

/**
 * Costruttore di Contatto.
 */
Contatto::Contatto(std::string numero, std::string nome) {
	num = numero;
	name = nome;
	type = "Generico";
}

/**
 * Distruttore di Contatto.
 */
Contatto::~Contatto() {}

/**
 * Funzione per accedere/ottenere il nome di un contatto
 */
std::string Contatto::getNome() {
	return name;
}

/**
 * Funzione per accedere/ottenere il numero di un contatto
 */
std::string Contatto::getNumero() {
	return num;
}

/**
 * Funzione per accedere al tipo di un contatto
 */
//std::string Contatto::getTipo() {
//	return type;
//}

/**
 * Funzione per modificare contatti
 */
//Contatto Contatto::modContatto() {
//	std::string userInput = "";
//	int menuSelection = 0;
//	std::string nuovoNumero = num;
//	std::string nuovoNome = name;
//	std::cout <<
//			"| >  Si sta modificando questo contatto |\n| >  "
//			<< toStringContatto() << "  |" << std::endl;
//	userInput = Utilita::getInput(
//			"| >  Inserire                           |\n"
//			"| >  1 per modificare solo il numero    |\n"
//			"| >  2 per modificare solo il nome      |\n"
//			"| >  3 per modificare numero e nome     |\n"
//			"| >  altro per annullare l'operazione   |\n| >  ");
//	menuSelection = Utilita::isNumber(userInput) ? stoi(userInput) : -1;
//
//	if (menuSelection == 1) {
//		userInput = Utilita::getInput(
//				"| >  Inserire il nuovo numero           |\n| >  ");
//		nuovoNumero = userInput;
//	} else if (menuSelection == 2) {
//		userInput = Utilita::getInput(
//				"| >  Inserire il nuovo nome             |\n| >  ");
//		nuovoNome = userInput;
//	} else if (menuSelection == 3) {
//		userInput = Utilita::getInput(
//				"| >  Inserire il nuovo numero           |\n| >  ");
//		nuovoNumero = userInput;
//		userInput = Utilita::getInput(
//				"| >  Inserire il nuovo nome             |\n| >  ");
//		nuovoNome = userInput;
//	} else {
//		std::cout << "Operazione annullata." << std::endl;
//	}
//	return Contatto(nuovoNumero, nuovoNome);
//}

/**
 * Funzione membro di Contatto per ritornare
 * come stringa i contenuti dei contatti generici.
 * Viene ereditata dalle classi derivate da Contatto.
 */
std::string Contatto::toStringContatto() {
	std::string result = "Tel: ";
	for (int i = 0; i < Utilita::maxNumLength - (int) num.size(); i++) {
		result = result + " ";
	}
	result = result + num + " , Nome: ";
	for (int i = 0; i < Utilita::maxNameLength - (int) name.size(); i++) {
		result = result + " ";
	}
	result = result + name + " , Tipo:  Generico";
	return result;
}
