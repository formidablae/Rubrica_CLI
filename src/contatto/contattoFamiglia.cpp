//============================================================================
// Name        : contattoFamiglia.cpp
// Version     :
// Copyright   :
// Description : Rubrica in C++
//============================================================================

#include <iostream>
#include "contattoFamiglia.h"	// Inclusione header classe ContattoFamiglia
#include "../utilita/utilita.h"	// Inclusione header per alcune funzioni utili

/**
 * Costruttore di ContattoFamiglia. Eredita da Contatto
 * in modo public.
 */
ContattoFamiglia::ContattoFamiglia(std::string numero, std::string nome, std::string relazione):Contatto(numero, nome) {
	type = "Famiglia";
	relationship = relazione;
}

/**
 * Distruttore di ContattoFamiglia.
 */
ContattoFamiglia::~ContattoFamiglia() {}

/**
 * Funzione membro di ContattoFamiglia per ritornare
 * come stringa i contenuti dei ContattoFamiglia.
 * Fa overriding della funzione membro toStringContatto
 * di Contatto.
 */
std::string ContattoFamiglia::toStringContatto() {
	std::string result = "Tel: ";
	for (int i = 0; i < Utilita::maxNumLength - (int) num.size(); i++) {
		result = result + " ";
	}
	result = result + num + " , Nome: ";
	for (int i = 0; i < Utilita::maxNameLength - (int) name.size(); i++) {
		result = result + " ";
	}
	result = result + name + " , Tipo:  Famiglia , Relazione: ";
	for (int i = 0; i < Utilita::maxRelationLength - (int) relationship.size(); i++) {
		result = result + " ";
	}
	result = result + relationship;
	return result;
}
