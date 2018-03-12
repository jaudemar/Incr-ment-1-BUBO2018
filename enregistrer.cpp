#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "Enregistrement.h"
#include "BDD.h"
#include "Collecteur.h"
using namespace std;
using namespace cgicc;

int main()
{    /*   //DÃ©claration des variables
	string identifiantCollecteur;
	string  aIdEnregistrement;
	int aId;
	float aAlbedo;
	float aFluxLum;
	string aIdRaspberry;
	string aTypeAmpoule;
	string aTypeLampadaire;
	float aHauteur;
	int puissance;
	double aLatitude;
	double aLongitude;
	int aNbImages;
	string aAgglo;
	string aNotes;
	string aRue;
	int aUlor;
	string aDate;
	//------------------------

	//DÃ©claration des CGI
	Cgicc cgi;
	const CgiEnvironment& env = cgi.getEnvironment();
	//-----------------------------------
	string mon_fichier = "/home/pi/test.txt";
    ofstream fichier(mon_fichier.c_str(),  ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier
	cout<<HTTPHTMLHeader();
    if(fichier)  // si l'ouverture a réussi
        {
			//--------------------------Récupération latitude -------------------------
			form_iterator fvalue = cgi.getElement("latitude"); //RÃ©cupÃ©ration valeur du champs "lattitude" 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) {
				fichier << "La latitude est : " << **fvalue << endl;
				aLatitude = atof((**fvalue).c_str()); // atof => convertit un string en double 
			} 
			else 
				fichier << "No text entered for latitude" << endl; //Retourne ce texte si aucune valeur n'est entrÃ©e 
			//--------------------------Récupération Identifiant -------------------------
			fvalue = cgi.getElement("identifiant"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "L'identifiant est : " << **fvalue << endl; 
				aId = atoi((**fvalue).c_str());
			} 
			else 
				fichier << "No text entered for identifiant" << endl; 
			//--------------------------Récupération longitude -------------------------
			fvalue = cgi.getElement("longitude"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "La longitude est : " << **fvalue << endl; 
				aLongitude = atof((**fvalue).c_str()); // atof => convertit un string en double 
			} 
			else 
				fichier << "No text entered for longitude" << endl; 
			//--------------------------Récupération typeLampadaire -------------------------
			fvalue = cgi.getElement("typeLampadaire"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "Le typeLampadaire est : " << **fvalue << endl; 
				aTypeLampadaire = **fvalue;
			} 
			else 
				fichier << "No text entered for typeLampadaire" << endl; 			
			//--------------------------Récupération ulor -------------------------
			fvalue = cgi.getElement("ulor"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "L'ulor est : " << **fvalue << endl;
				aUlor = atoi((**fvalue).c_str()); // atoi => convertit un string en int  
			} 
			else 
				fichier << "No text entered for ulor" << endl; 

			//--------------------------Récupération typeAmpoule -------------------------
			fvalue = cgi.getElement("typeAmpoule"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "Le typeAmpoule est : " << **fvalue << endl; 
				aTypeAmpoule = **fvalue; 
			} 
			else 
				fichier << "No text entered for typeAmpoule" << endl; 			
			//--------------------------Récupération hauteur -------------------------
			fvalue = cgi.getElement("hauteur"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "La hauteur est : " << **fvalue << endl; 
				aHauteur = stof((**fvalue).c_str()); // stof => convertit string en float
			} 
			else 
				fichier << "No text entered for hauteur" << endl; 
			//--------------------------Récupération puissance -------------------------
			fvalue = cgi.getElement("puissance"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "La puissance est : " << **fvalue << endl;
				puissance = atoi((**fvalue).c_str()); // atoi => convertit un string en int 
			} 
			else 
				fichier << "No text entered for puissance" << endl; 			
			//--------------------------Récupération albedo -------------------------
			fvalue = cgi.getElement("albedo"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "L'albedo est : " << **fvalue << endl; 
				aAlbedo = stof((**fvalue).c_str()); // stof => convertit string en float
			} 
			else 
				fichier << "No text entered for albedo" << endl; 

			//--------------------------Récupération agglomeration -------------------------
			fvalue = cgi.getElement("agglomeration"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "L'agglomeration est : " << **fvalue << endl; 
				aAgglo = **fvalue;
			} 
			else 
				fichier << "No text entered for agglomeration" << endl; 			
			//--------------------------Récupération rue -------------------------
			fvalue = cgi.getElement("rue"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "La rue est : " << **fvalue << endl; 
				aRue = **fvalue;
			} 
			else 
				fichier << "No text entered for rue" << endl; 
			//--------------------------Récupération notes -------------------------
			fvalue = cgi.getElement("notes"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "Les notes sont : " << **fvalue << endl; 
				aNotes = **fvalue;
			} 
			else 
				fichier << "No text entered for notes" << endl; 			
			//--------------------------Récupération fluxlum -------------------------
			fvalue = cgi.getElement("fluxlum"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "Le fluxlum est : " << **fvalue << endl;
				aFluxLum = stof((**fvalue).c_str()); // stof => convertit string en float 
			} 
			else 
				fichier << "No text entered for fluxlum" << endl; 

			//--------------------------Récupération nbImage -------------------------
			fvalue = cgi.getElement("nbImage"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "Le nbImage est : " << **fvalue << endl; 
				aNbImages = atoi((**fvalue).c_str()); // atoi => convertit un string en int
			} 
			else 
				fichier << "No text entered for nbImage" << endl; 

			//fichier<<"\r\n" << env.getPostData(); no treated

			//Instanciation des classes Enregistrement.cpp BDD.cpp et Collecteur.cpp
			Enregistrement* enregistrement = new Enregistrement(aAlbedo, aFluxLum, aIdEnregistrement,  aIdRaspberry,  aTypeAmpoule,  aTypeLampadaire,aHauteur, aLatitude,  aLongitude, aNbImages, aAgglo,  aRue,  aUlor, aDate, aNotes, puissance);
			BDD* maBDD = new BDD();
			Collecteur* monCollecteur = new Collecteur();
			//----------------------------------------------------------------------

			//RÃ©cupÃ©ration ID de la R-PI
			monCollecteur->recupererIdentifiantRaspberry();
			identifiantCollecteur = monCollecteur->getIdentifiant();
			fichier <<"Identifiant : " << identifiantCollecteur<<endl;
			//----------------------------------------------------------------------

			//Enregistrement dans la BDD
			maBDD->sauvegarderDonneesEnregistrement(enregistrement,identifiantCollecteur);
			//----------------------------------------------------------------------
			fichier<<endl;
			fichier<<"ENREGISTREMENT EFFECTUÃ‰"<<endl;
	           fichier.close();  // on referme le fichier
        }
    else  // sinon
         cerr << "Pb pour ouvrir le fichier!" << endl;
*/
		cout<<"{"<<endl;
		cout<<	"""ID"":""1"<<endl;
		cout<<	"PUISSANCE: "<<endl;
		cout<<	"ALBEDO:0.5"<<endl;
		cout<<	"FLUXLUM:50.0"<<endl;
		cout<<	"IDENREGISTREMENT:170616145635"<<endl;
		cout<<	"IDRASP:00000000cc5e85f7"<<endl;
		cout<<	"AMPTYPE:SHP400"<<endl;
		cout<<	"LAMPTYPE:Candï¿½labre de style"<<endl;
		cout<<	"HAUTEUR:4.0"<<endl;
		cout<<	"LATITUDE:1.30933330"<<endl;
		cout<<	"LONGITUDE:43.6158080"<<endl;
		cout<<	"NBIMAGES:0"<<endl;
		cout<<	"AGGLOMERATION:sones"<<endl;
		cout<<	"RUE:des haricots"<<endl;
		cout<<	"ULOR:5"<<endl;
		cout<<	"DATE:170616"<<endl;
		cout<<	"NOTES:"<<endl;
		cout<<"}"<<endl;


  //  return 0;
}
