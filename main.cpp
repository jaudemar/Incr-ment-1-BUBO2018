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

#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"




#include "Geolocalisation.h"
#include "Collecteur.h"
#include "BDD.h"
#include "Horodatage.h"

using namespace std;
using namespace cgicc;

int main(){
        Cgicc cgi;
        const CgiEnvironment& env = cgi.getEnvironment();
        vector<char> messages;
        vector<char> trameRMC;
        int erreur=0;
        char latitude[10] = {0};
        char longitude[10] = {0};
        char date [6] = {0};
        char heure [6] = {0};
	char aDate;
        string requete;
        vector<char>::const_iterator    lit,lend;
        cout <<HTTPHTMLHeader();

        GPS * unGPS = new GPS();
        Geolocalisation * maGeo = new Geolocalisation(unGPS);

        erreur = maGeo->localiser(latitude,longitude);

        switch (erreur)
        {
                case MAUVAISETRAME : cout<<"MAUVAISE TRAME "<< " error" <<endl;
                        break;          
                case ALERTE : cout<<"ALERTE GPS non pr�t  "<< " error" <<endl;
                        this_thread::sleep_for (chrono::seconds(1));
                        break;          
                case ERREURCHECKSUM : cout<< "ERREUR DE CHECKSUM "<< " error"<<endl;
                        break;
                case ECHECCAPTURE : cout<<"ECHEC CAPTURE "<< " error" <<endl;
                        break;
                case ERREURACCESPORT : cout<<"ERREUR ACCES PORT "<< " error" <<endl;
                        break;
                default : 
cout<<"{\n\t\"LATITUDE\":"<<latitude<<",\n";
cout<<"\t\"LONGITUDE\":"<<longitude<<",\n";
//-------------------------------------------------------//
	Horodatage* horodatage = new Horodatage(unGPS);
	horodatage->dater(heure,date);
	for(int i=0;i<6;i++)
 	{
	date[i];
	}
	cout<<"\t\"DATE\":"<<date<<"\n}\n";


/*	for (int i=0;i<6;i++)
	{
	heure[i];
	}
	cout<<"\t\"HEURE\":"<<heure<<"\n}\n"; */
//-----------------------------------------------------//
                      break;
        }

	return 0;
}
