#include <exception>
#include <string>
#include <vector>
#include <sqlite3.h> 
using namespace std;

#ifndef __BDD_h__
#define __BDD_h__

#include "Enregistrement.h"


	class BDD
	{
		private: string _baseDeDonnees;
		private: bool _conOk;
		private: char* _msgError;
				 sqlite3 * db;

		public: BDD();
				~BDD();
		public: vector<Enregistrement> obtenirListeDesEnregistrements();

		public: vector<Enregistrement> obtenirDonneesEnregistrement(double latitude,double longitude);

		public: Enregistrement obtenirDonneesEnregistrement(string aLatitude, string aLongitude);

		public: void supprimerEnregistrement(int aId);

		public: vector<Enregistrement*> sauvegarderDonneesEnregistrement(Enregistrement *enregistrement,string identifiantCollecteur);

		public: void modifierEnregistrement(int id, float albedo, float fluxLum, string idEnregistrement, string idRaspbery, string typeAmpoule, string typeLampadaire, int hauteur, double latitude, double longitude, int nbImages, string agglo, string rue, int ulor, string date,string notes);

		private: void execute(string aRequetesql);

		private: vector<Enregistrement> selectData(string aRequetesql);
	};


#endif
