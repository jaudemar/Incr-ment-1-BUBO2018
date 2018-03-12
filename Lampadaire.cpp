#include <string>
using namespace std;

#include "Lampadaire.h"
#include "Enregistrement.h"

void  Lampadaire::setType(string aType) {
	this->_type = aType;
}

string  Lampadaire::getType() {
	return this->_type;
}

void  Lampadaire::setHauteur(float aHauteur) {
	this->_hauteur = aHauteur;
}

float  Lampadaire::getHauteur() {
	return this->_hauteur;
}

void  Lampadaire::setULOR(int aULOR) {
	this->_uLOR = aULOR;
}

int  Lampadaire::getULOR() {
	return this->_uLOR;
}

void  Lampadaire::setAlbedo(float aAlbedo) {
	this->_albedo = aAlbedo;
}

float  Lampadaire::getAlbedo() {
	return this->_albedo;
}

