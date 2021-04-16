//============================================================================
// Name        : contattoBusiness.cpp
// Version     :
// Copyright   :
// Description : Rubrica in C++
//============================================================================

#include <iostream>
#include "contattoBusiness.h"	// Inclusione header classe ContattoBusiness
#include "../utilita/utilita.h"	// Inclusione header per alcune funzioni utili

/**
 * Costruttore di ContattoBusiness.
 * ContattoBusiness eredita da ContattoLavoro che eredita da Contatto.
 * ContattoBusiness eredita anche da BusinessCard che eredita da Contatto.
 * Ereditarietà a "diamante".
 */
ContattoBusiness::ContattoBusiness(std::string numero, std::string nome, std::string azienda, std::string indirizzo, std::string partIva):Contatto(numero, nome), ContattoLavoro(numero, nome, azienda), BusinessCard(numero, nome, indirizzo, partIva) {
	type = "Business";
}

/**
 * Distruttore di ContattoBusiness.
 */
ContattoBusiness::~ContattoBusiness() {}

/**
 * Funzione membro di ContattoBusiness per ritornare
 * come stringa i contenuti dei ContattoBusiness.
 * Fa overriding della funzione membro toStringContatto
 * di BusinessCard, ContattoLavoro e infine Contatto.
 */
std::string ContattoBusiness::toStringContatto() {
	std::string result = "Tel: ";
	for (int i = 0; i < Utilita::maxNumLength - (int) num.size(); i++) {
		result = result + " ";
	}
	result = result + num + " , Nome: ";
	for (int i = 0; i < Utilita::maxNameLength - (int) name.size(); i++) {
		result = result + " ";
	}
	result = result + name + " , Tipo:  Business , Azienda:   ";
	for (int i = 0; i < Utilita::maxCompanyLength - (int) company.size(); i++) {
		result = result + " ";
	}
	result = result + company + " , Indirizzo: ";
	for (int i = 0; i < Utilita::maxAddressLength - (int) address.size(); i++) {
		result = result + " ";
	}
	result = result + address + " , P_Iva: ";
	for (int i = 0; i < Utilita::maxPivaLength - (int) partitaIva.size(); i++) {
		result = result + " ";
	}
	result = result + partitaIva;
	return result;
}
