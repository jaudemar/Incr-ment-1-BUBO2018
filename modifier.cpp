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
#include "BDD.h"
#include <stdio.h>
#include "Lampadaire.h"


#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"
#include <cgicc/CgiEnvironment.h>
#include <cgicc/FormEntry.h>





using namespace std;

int main(){
/*
float albedo=0.6;
float fluxLum=20.0;
string typeAmpoule="LED";
string typeLampadaire="Poto";
int hauteur=4;
double latitude=1.55555;
double longitude=1.66666666;
int nbImages=0;
string agglo="toulouse";
string rue="perd";
int ulor=5;
string date="190318";
string notes="Bonjour les amis";
int puissance=10;
string idEnregistrement="205566331155";
string idRaspberry="111111111";
int id=2;
*/

float albedo;
float fluxLum;
string typeAmpoule;
string typeLampadaire;
int hauteur;
double latitude;
double longitude;
int nbImages;
string agglo;
string rue;
int ulor;
string date;
string notes;
int puissance;
string idEnregistrement;
string idRaspberry;
int id;

BDD laBDD;


laBDD.modifierEnregistrement(id,puissance,albedo,fluxLum,idEnregistrement,idRaspberry,typeAmpoule,typeLampadaire,hauteur,latitude,longitude,nbImages,agglo,rue,ulor,date,notes);
cout<<"test de l'execution"<<endl;
}





//modifierEnregistrement * onmodifierEnregistrement = new modifierEnregistrement (id,puissance,albedo,fluxLum,idEnregistrement,idRaspbery,typeAmpoule,typeLampadaire,hauteur,latitude,longitude,nbImages,agglo,rue,ulor,date,notes);
