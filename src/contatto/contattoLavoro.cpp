//============================================================================
// Name        : contattoLavoro.cpp
// Version     :
// Copyright   :
// Description : Rubrica in C++
//============================================================================

#include <iostream>
#include "contattoLavoro.h"		// Inclusione header classe ContattoLavoro
#include "../utilita/utilita.h"	// Inclusione header per alcune funzioni utili

/**
 * Costruttore di ContattoLavoro. Eredita da Contatto
 * con modalità virtual public.
 */
ContattoLavoro::ContattoLavoro(std::string numero, std::string nome, std::string azienda):Contatto(numero, nome) {
	type = "Lavoro";
	company = azienda;
}

/**
 * Distruttore di ContattoLavoro.
 */
ContattoLavoro::~ContattoLavoro() {}

/**
 * Funzione membro di ContattoLavoro per ritornare
 * come stringa i contenuti dei contatti lavoro.
 * Fa overriding della funzione membro toStringContatto
 * di Contatto.
 */
std::string ContattoLavoro::toStringContatto() {
	std::string result = "Tel: ";
	for (int i = 0; i < Utilita::maxNumLength - (int) num.size(); i++) {
		result = result + " ";
	}
	result = result + num + " , Nome: ";
	for (int i = 0; i < Utilita::maxNameLength - (int) name.size(); i++) {
		result = result + " ";
	}
	result = result + name + " , Tipo:  Lavoro   , Azienda:   ";
	for (int i = 0; i < Utilita::maxCompanyLength - (int) company.size(); i++) {
		result = result + " ";
	}
	result = result + company;
	return result;
}
