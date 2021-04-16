//============================================================================
// Name        : businessCard.cpp
// Version     :
// Copyright   :
// Description : Rubrica in C++
//============================================================================

#include <iostream>
#include "businessCard.h"		// Inclusione header classe BusinessCard
#include "../utilita/utilita.h"	// Inclusione header per alcune funzioni utili

/**
 * Costruttore di BusinessCard. Eredita da Contatto
 * con modalita virtual public.
 */
BusinessCard::BusinessCard(std::string numero, std::string nome, std::string indirizzo, std::string partIva):Contatto(numero, nome) {
	type = "BCard";
	address = indirizzo;
	partitaIva = partIva;
}

/**
 * Distruttore di BusinessCard.
 */
BusinessCard::~BusinessCard() {}

/**
 * Funzione membro di BusinessCard per ritornare
 * come stringa i contenuti dei BusinessCard.
 * Fa overriding della funzione membro toStringContatto
 * di Contatto.
 */
std::string BusinessCard::toStringContatto() {
	std::string result = "Tel: ";
	for (int i = 0; i < Utilita::maxNumLength - (int) num.size(); i++) {
		result = result + " ";
	}
	result = result + num + " , Nome: ";
	for (int i = 0; i < Utilita::maxNameLength - (int) name.size(); i++) {
		result = result + " ";
	}
	result = result + name + " , Tipo:  BCard    , Indirizzo: ";
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
