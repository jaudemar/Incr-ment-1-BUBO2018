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

Collecteur::Collecteur () {
}
