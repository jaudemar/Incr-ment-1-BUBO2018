#include <exception>
#include <string>
#include <vector>
#include <sqlite3.h> 
#include <iostream>


#include "BDD.h"
#include "Enregistrement.h"
#include "Lampadaire.h"
#include "Ampoule.h"
#include "Galerie.h"
#include "Geolocalisation.h"
#include "Horodatage.h"


using namespace std;



std::vector<Enregistrement*>BDD:: sauvegarderDonneesEnregistrement(Enregistrement *enregistrement,string identifiantCollecteur)
{
        string mon_fichier = "/home/pi/test2.txt";
    ofstream fichierBDD(mon_fichier.c_str(),  ios::out | ios::trunc);
	fichierBDD << "ENREGISTREMENT BASE DE DONNÉS"<<endl;
fichierBDD.close();
vector<Enregistrement*> leRetour;
return leRetour;
}


BDD::BDD()
{
}

BDD::~BDD(){
}


