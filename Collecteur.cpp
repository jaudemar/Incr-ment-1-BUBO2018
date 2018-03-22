#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>
#include <string>

#include <stdio.h>

//#include "cgicc/CgiDefs.h"
//#include "cgicc/Cgicc.h"
//#include "cgicc/HTTPHTMLHeader.h"
//#include "cgicc/HTMLClasses.h"
//#include <cgicc/CgiEnvironment.h>
//#include <cgicc/FormEntry.h>




#include "Geolocalisation.h"
#include "Collecteur.h"
#include "BDD.h"
#include "Enregistrement.h"
#include "Logger.h"
#include "Lampadaire.h"
#include "Galerie.h"
#include "Ampoule.h"
#include "Horodatage.h"
#include "GPS.h"

using namespace std;
using namespace cgicc;



int Collecteur::recupererIdentifiantRaspberry() {

	FILE * pFile;
    char buffer[1200]; 
    size_t result=0, posSerial=0;
	string match;

	pFile =fopen("/proc/cpuinfo", "r");
	if (pFile==NULL) {
		return PBACCESIDENT;
	}


    result = fread (buffer, 1, sizeof (buffer),pFile);
    if (result <=0 ) {
		return PBLECTUREIDENT;
	}

	buffer[result] == '\0';

	match=string(buffer);
	posSerial = match.find("Serial");

	_identifiant = match.substr(posSerial + 10,16);

	fclose (pFile);
	return 1;
}

string Collecteur::getIdentifiant()
{
	return _identifiant;
}

Collecteur::Collecteur()
{
	unGPS=new GPS();
}
string Collecteur::creerEnregistrement()
{
	this->listeEnregistrements.push_back(new Enregistrement(unGPS));
	if (!listeEnregistrements.empty()) {
		listeEnregistrements.back()->creerIdentifiant();
	}
}

string Collecteur::geolocaliser()
{
	char laLatitude[10];
	char laLongitude[10];
	int erreur=0;
	string retour;
	if (!listeEnregistrements.empty()) {
		erreur = listeEnregistrements.back()->localiser(laLatitude, laLongitude);
	}
    switch (erreur)
	{
		case MAUVAISETRAME : retour ="MAUVAISE TRAME ";
			break;
		case ALERTE : retour ="ALERTE GPS non prêt  ";
			break;
		case ERREURCHECKSUM : retour ="ERREUR DE CHECKSUM ";
			break;
		case ECHECCAPTURE : retour ="ECHEC CAPTURE ";
			break;
		case ERREURACCESPORT : retour ="ERREUR ACCES PORT ";
			break;
		default :
			retour = "{\n\t\"LATITUDE\":"+string(laLatitude)+",\n" + "\t\"LONGITUDE\":"+string(laLongitude)+"\n}\n";
			break;
	}
	return retour;
}

string Collecteur::geolocaliser(int identifiant)
{
	char laLatitude[10];
	char laLongitude[10];
	int erreur=0;
	string retour;
	if (!listeEnregistrements.empty()) {
		erreur = listeEnregistrements.back()->localiser(laLatitude, laLongitude);
	}
    switch (erreur)
	{
		case MAUVAISETRAME : retour ="MAUVAISE TRAME ";
			break;
		case ALERTE : retour ="ALERTE GPS non prêt  ";
			break;
		case ERREURCHECKSUM : retour ="ERREUR DE CHECKSUM ";
			break;
		case ECHECCAPTURE : retour ="ECHEC CAPTURE ";
			break;
		case ERREURACCESPORT : retour ="ERREUR ACCES PORT ";
			break;
		default :
			retour = "{\n\t\"LATITUDE\":"+string(laLatitude)+",\n" + "\t\"LONGITUDE\":"+string(laLongitude)+"\n}\n";
			break;
	}
	return retour;
}

string Collecteur::obtenirIntensiteLumineuse()
{
	float lIntensiteLumineuse;
	int erreur=0;
	if (!listeEnregistrements.empty()) {
		erreur = listeEnregistrements.back()->caracteriserAmpoule(lIntensiteLumineuse);
	}
	return "{\"luminosite\":\"" + to_string(lIntensiteLumineuse) +  "\"}";
}

string Collecteur::obtenirIntensiteLumineuse(int identifiant)
{

	return "eeeeeeeeeeeeeeeee";
}


