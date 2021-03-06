#include <vector>
#include <algorithm>
#include <iostream>
#include "GPS.h"
#include "Horodatage.h"
#include "string"
using namespace std;



int Horodatage::dater(char _heure[6],char _date[6])
{
	vector<char> trameRMC;
	int erreur=0;
	vector<char>::const_iterator	lit,lend;

	///*Vidage complet des salves messages et de la trame RMC*/
	//messages.erase(messages.begin(),messages.end());
	//trameRMC.erase(trameRMC.begin(),trameRMC.end());

	/*Lecture d'une salve de trames sur le port du GPS*/
	erreur = leGPS->lire ();
	if (erreur < 0) return erreur ;

	/* Extraction de la trame RMC */
	erreur = leGPS->extraireRMC( trameRMC);
	if (erreur<=0) return erreur;



	/* si la trame est correcte ((A) + Checksum OK) extraire la Latitude puis la longitude*/
	extraireDateRMC(trameRMC,date);
	for (int i=0;i<6;i++)
	{
		_date[i]=date[i];
	}
	extraireHeureRMC(trameRMC,heure);
	for (int i=0;i<6;i++)
	{
		_heure[i]=heure[i];
	}

	return 1;
}
int Horodatage::extraireDateRMC(std::vector<char>trameRMC, char date[6] )
{
	vector<char>::const_iterator	lit,lend;
	// On atteind le champs "ALERTE"
	lit= find(trameRMC.begin(), trameRMC.end(),'A');
	// On passe le champs "ALERTE"
	advance(lit,2);
	lend = trameRMC.end();
	// On saute le champs "latitude"
	lit= find(lit, lend,',');

	// On passe le champs "direction" en latitude par rapport � l'�quateur
	advance(lit,3);

	// On passe le champs "Longitude"
	lit= find(lit, lend,',');

	// On passe le nouveau champs "direction" en longitude par rapport � GreenWich
	advance(lit,3);

	// On passe le champs "vitesse sol" en Noeuds
	lit= find(lit, lend,',');

	advance(lit,2);

	// On passe le champs "cap"	
	lit= find(lit, lend,',');

	// le champs "date" est copi� dans le tableau date
	char buffer[6];
	for (int i=0;i<6;i++)
	{
		buffer[i]=*++lit;
	}

	date[5] = buffer[1];
	date[4] = buffer[0];
	date[3] = buffer[3];
	date[2] = buffer[2];
	date[1] = buffer[5];
	date[0] = buffer[4];

	return 1;
}
int Horodatage::extraireHeureRMC(std::vector<char>trameRMC, char heure [6])
{
	vector<char>::const_iterator	lit,lend;
	// On saute l'identifiant de r�cepteur et de trame
	lit= find(trameRMC.begin(), trameRMC.end(),',');


	// le champs "heure" est copi� dans le tableau heure
	for (int i=0;i<6;i++)
	{
		heure[i]=*++lit;
	}

	return 1;
}

void Horodatage::setDate(char laDate[6]){
	for (int i=0;i<6;i++)
	{
		date[i]=laDate[i];
	}
}


Horodatage::Horodatage(GPS *unGPS)
{
	Horodatage::leGPS = unGPS;
}

Horodatage::Horodatage()
{
	
}

void Horodatage::getDate(char aDate[6])
{
	for (int i=0;i<6;i++)
	{
		aDate[i]=date[i];
	}
}
