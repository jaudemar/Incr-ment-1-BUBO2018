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

		public: void modifierEnregistrement(int aId, int puissance, float aAlbedo, float aFluxLum, string aIdEnregistrement, string aIdRaspbery, string aTypeAmpoule, string aTypeLampadaire, int aHauteur, double aLatitude, double aLongitude, int aNbImages, string aAgglo, string aRue, int aUlor, string aDate,string aNotes);

		private: void execute(string aRequetesql);

		private: vector<Enregistrement> selectData(string aRequetesql);
	};


#endif
