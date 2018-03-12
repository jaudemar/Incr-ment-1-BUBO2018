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

/*
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
*/
Enregistrement::Enregistrement( float aAlbedo, float aFluxLum, string aIdEnregistrement, string aIdRaspberry, string aTypeAmpoule, string aTypeLampadaire, int aHauteur, double aLatitude, double aLongitude, int aNbImages, string aAgglo, string aRue, int aUlor, string aDate, string aNotes, int puissance){
string mon_fichier = "/home/pi/test1.txt";
    ofstream fichier(mon_fichier.c_str(),  ios::out | ios::trunc);  //dï¿½clarati$
    if(fichier)  // si l'ouverture a rï¿½ussi
        {
		fichier<< "Enregistrement OK" <<endl;
	}
/* //il faut instancier et mettre les attributs de enregistrer dans les attributs private de enregistrement.h:
cout<<"test1"<<endl;
char Latitude[10];
char Longitude[10];
//monLogger->saveLog("test1");
cout<<"test2"<<endl;
    lampadaire->setAlbedo(aAlbedo) ;                         //dans lampadaire.h
cout<<"test3"<<endl;
    lampadaire->setHauteur(aHauteur);                       //dans lampadaire.h
cout<<"test4"<<endl;
    lampadaire->setULOR(aUlor);                             //dans lampadaire.h
cout<<"test5"<<endl;
    lampadaire->setType(aTypeLampadaire);                   //dans lampadaire.h
cout<<"test6"<<endl;
   ampoule->setIntensiteLumineuse(aFluxLum);                  // ampoule.h
cout<<"test7"<<endl;
    _identifiant=aIdEnregistrement;                          // enregistrement.h
cout<<"test8"<<endl;
    ampoule->setType(aTypeAmpoule);                             //  ampoule.h
cout<<"test9"<<endl;
//monLogger->saveLog("test2");
   sprintf(Latitude,"%1.111111f",aLatitude);		//conversion du double en char
cout<<"alatitu"<<aLatitude<<endl;
   geolocalisation->setLatitude(Latitude);                    // dans geolocalisation.h
   sprintf(Longitude,"%1.111111f", aLongitude);                   //Conversion du double en char
    geolocalisation->setLongitude(Longitude);               // dans geolocalisation.h
    galerie->setNbrePhotos(aNbImages);                      //dans galerie.h
    _agglomeration=aAgglo;                                  // enregistrement.h
    _rue =aRue;                                             // enregistrement.h
//monLogger->saveLog("test3");
cout<<"testENre2"<<endl;
    const char* X;   //cree la variable X de type const char *
    X=aDate.c_str();      // fait une conversion de aDate qui est de type string en const char*

    char Date[6];   // On cree un tableau "Date" de 6
   strcpy( Date, X); //on convertit X qui est de type const char * en Date qui est de type char*
//monLogger->saveLog("test4");
cout<<"testENre3"<<endl;

        horodatage->setDate(Date);                              //dans horodatage;h
    _notes=aNotes;                                      // enregistrement.h
    ampoule->setPuissance(puissance);                        //dans ampoule.h
//monLogger->saveLog("test5");
*/
}

/*
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
/////////////////////////get Composés//////////////////////////////
void Enregistrement::getAmpoule(string &type, float &intensiteLumineuse, int &puissance){
	type = this->ampoule->getType();
	intensiteLumineuse = this->ampoule->getIntensiteLumineuse();
	puissance = this->ampoule->getIntensiteLumineuse();
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
	this->geolocalisation->getLatitude(aLatitude_ );
	this->geolocalisation->getLongitude(aLongitude);
}
*/
