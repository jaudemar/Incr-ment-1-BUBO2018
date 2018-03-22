#include <exception>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

#include "Enregistrement.h"
#include "Collecteur.h"
#include "Lampadaire.h"
#include "Galerie.h"
#include "Geolocalisation.h"
#include "Ampoule.h"
#include "Horodatage.h"
#include "GPS.h"
#include"Logger.h" //x
//Logger *monLogger=new Logger();


Enregistrement::Enregistrement(string aIdRaspberry, GPS * unGPS) {
//monLogger->saveLog("tes");
	horodatage = new Horodatage(unGPS);
	geolocalisation = new Geolocalisation(unGPS);
	ampoule = new Ampoule();
	lampadaire = new Lampadaire();
	galerie=new Galerie();
}


Enregistrement::Enregistrement(GPS * unGPS) {
	horodatage = new Horodatage(unGPS);
	geolocalisation = new Geolocalisation(unGPS);
	ampoule = new Ampoule();
	_identifiant="";
	lampadaire = new Lampadaire();
	galerie=new Galerie();
}


Enregistrement::Enregistrement(int aId, float aAlbedo, float aFluxLum, string aIdEnregistrement, string aIdRaspberry, string aTypeAmpoule, string aTypeLampadaire, int aHauteur, double aLatitude, double aLongitude, int aNbImages, string aAgglo, string aRue, int aUlor, string aDate, string aNotes, int puissance){

}

Enregistrement::Enregistrement( float aAlbedo, float aFluxLum, string aIdEnregistrement, string aIdRaspberry, string aTypeAmpoule, string aTypeLampadaire, int aHauteur, double aLatitude, double aLongitude, int aNbImages, string aAgglo, string aRue, int aUlor, string aDate, string aNotes, int aPuissance){
  	 horodatage = new Horodatage();
        geolocalisation = new Geolocalisation();
        ampoule = new Ampoule();
        _identifiant="";
        lampadaire = new Lampadaire();
        galerie=new Galerie();

//il faut instancier et mettre les attributs de enregistrer dans les attributs private de enregistrement.h:

char Latitude[10];
char Longitude[10];

	lampadaire->setAlbedo(aAlbedo) ;                         //dans lampadaire.h
	lampadaire->getAlbedo();
		cout<<"Albedo : "<< lampadaire->getAlbedo()<<endl;

	lampadaire->setHauteur(aHauteur);                       //dans lampadaire.h
	lampadaire->getHauteur();
		cout<<"Hauteur : "<< lampadaire->getHauteur() <<endl;
	lampadaire->setULOR(aUlor);                             //dans lampadaire.h
	lampadaire->getULOR();
		cout<<"ULOR : "<< lampadaire->getULOR()<<endl;
	lampadaire->setType(aTypeLampadaire);                   //dans lampadaire.h
	lampadaire->getType();
		cout<<"Type de lampadaire : "<< lampadaire->getType()<<endl;
	ampoule->setIntensiteLumineuse(aFluxLum);                  // ampoule.h
	ampoule->getIntensiteLumineuse();
		cout<<"Intensite lumineuse : "<< ampoule->getIntensiteLumineuse()<<endl;
	_identifiant=aIdEnregistrement;                          // enregistrement.h

	ampoule->setType(aTypeAmpoule);                             //  ampoule.h
	ampoule->getType();
		cout<<"Type d'ampoule : "<< ampoule->getType()<<endl;

	int recup= sprintf(Latitude,"%f",aLatitude);		//conversion du double en char
	//cout<<"donnée de  sprintf pour la latitude : "<<recup<<endl;

	geolocalisation->setLatitude(Latitude);                    // dans geolocalisation.h
	geolocalisation->getLatitude(Latitude);
		cout<<"Latitude : "<<Latitude <<endl;

	int recup2= sprintf(Longitude,"%f", aLongitude);                   //Conversion du double en char
	//cout<<"donneé de sprintf pour la longitude : "<<recup2<<endl;

    	geolocalisation->setLongitude(Longitude);               // dans geolocalisation.h
	geolocalisation->getLongitude(Longitude);
		cout<<"Longitude : "<<Longitude<<endl;

    	galerie->setNbrePhotos(aNbImages);                      //dans galerie.h
	galerie->getNbrePhotos();
		cout<<"nombre d'images : "<< galerie->getNbrePhotos()<<endl;

	_agglomeration=aAgglo;                                  // enregistrement.h

	_rue =aRue;                                             // enregistrement.h


	const char* X;   //cree la variable X de type const char *
	X=aDate.c_str();      // fait une conversion de aDate qui est de type string en const char*

	char Date[6];   // On cree un tableau "Date" de 6
	strcpy( Date, X); //on convertit X qui est de type const char * en Date qui est de type char*

        horodatage->setDate(Date);                              //dans horodatage.h
	horodatage->getDate(Date);
	cout<<"affiche Date : "<<Date<<endl;

	_notes=aNotes;                                      // enregistrement.h


	ampoule->setPuissance(aPuissance);                        //dans ampoule.h
	ampoule->getPuissance();
		cout<<"Puissance : " << ampoule->getPuissance()<<endl;

}


void Enregistrement::getDonneesCommunes() {
	throw "Not yet implemented";
}

void Enregistrement::calculerIdentifiant(char heure[6],char date[6]) {

	for (int i=0;i<6;i++)
	_identifiant=_identifiant+date[i];
	for (int i=0;i<6;i++)
	_identifiant=_identifiant+heure[i];
}

string Enregistrement::creerIdentifiant() {
	char heure [6];
	char date [6];

	horodatage->dater(heure,date);
	this->calculerIdentifiant(heure,date);
}

int Enregistrement::caracteriserAmpoule(float aIntensiteLumineuse) {
	aIntensiteLumineuse = ampoule->mesurerILux();
	return 0;
}


void Enregistrement::getPosition(char aLatitude[10], char aLongitude[10]) {
	geolocalisation->getLatitude(aLatitude);
	geolocalisation->getLongitude(aLongitude);
}

void Enregistrement::setPosition(char aLatitude[10], char aLongitude[10]) {
	geolocalisation->getLatitude(aLatitude);
	geolocalisation->getLongitude(aLongitude);
}

int Enregistrement::localiser(char aLatitude_[10], char aLongitude[10]) {
	return geolocalisation->localiser(aLatitude_,aLongitude);
}

int Enregistrement::localiser(char aLatitude_[10], char aLongitude[10], GPS * unGPS){
	geolocalisation = new Geolocalisation(unGPS);
	return geolocalisation->localiser(aLatitude_,aLongitude);
}

string Enregistrement::getIdentifiant() {
	return _identifiant;
}


void Enregistrement::setAgglomeration(string aAgglomeration) {
	this->_agglomeration = aAgglomeration;
}

string Enregistrement::getAgglomeration() {
	return this->_agglomeration;
}

void Enregistrement::setNotes(string aNotes) {
	this->_notes = aNotes;
}

string Enregistrement::getNotes() {
	return this->_notes;
}

void Enregistrement::setRue(string aRue) {
	this->_rue = aRue;
}

string Enregistrement::getRue() {
	return this->_rue;
}

void Enregistrement::setAmpoule(string type, float intensiteLumineuse, int puissance){
    ampoule->setIntensiteLumineuse(intensiteLumineuse);
    ampoule->setPuissance(puissance);
    ampoule->setType(type);
}

void Enregistrement::setLampadaire(string type, float hauteur, int ulor, float albedo)
{
    lampadaire->setType(type);
    lampadaire->setHauteur(hauteur);
    lampadaire->setULOR(ulor);
    lampadaire->setAlbedo(albedo);    
}

void Enregistrement::setGalerie(int nbrePhotos)
{
    galerie->setNbrePhotos(nbrePhotos);
}


void Enregistrement::setHorodatage(char date[6])
{
    horodatage->setDate(date);
    
}

void Enregistrement::setGeolocalisation(char aLatitude_[10], char aLongitude[10])
{
    geolocalisation->setLatitude(aLatitude_);
    geolocalisation->setLongitude(aLongitude);
}
/////////////////////////get Compos�s//////////////////////////////
void Enregistrement::getAmpoule(string &type, float &intensiteLumineuse, int &puissance){
	type = this->ampoule->getType();
	intensiteLumineuse = this->ampoule->getIntensiteLumineuse();
	puissance = this->ampoule->getPuissance();
}

void Enregistrement::getLampadaire(string &type, float &hauteur, int &ulor, float &albedo)
{
	type = this->lampadaire->getType();
	hauteur = this->lampadaire->getHauteur();
	ulor = this->lampadaire->getULOR();
	albedo = this->lampadaire->getAlbedo();
}

void Enregistrement::getGalerie(int &nbrePhotos)
{
	nbrePhotos = this->galerie->getNbrePhotos();
}


void Enregistrement::getHorodatage(char date[6])
{
	this->horodatage->getDate(date);	
 
}

void Enregistrement::getGeolocalisation(char aLatitude_[10], char aLongitude[10])
{
	this->geolocalisation->getLatitude(aLatitude_);
	this->geolocalisation->getLongitude(aLongitude);
}
