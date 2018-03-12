#include <exception>
#include <string>
#include <vector>
using namespace std;

#ifndef __Collecteur_h__
#define __Collecteur_h__

#include "Enregistrement.h"
#include "GPS.h"
#define PBACCESIDENT -1
#define PBLECTUREIDENT -2
#define IDENTNOTFIND -3

	class Collecteur
	{
		private: string _identifiant;
				 GPS *unGPS;
		private: std::vector<Enregistrement*> _lampadairesProches;
		public: std::vector<Enregistrement*> listeEnregistrements;
		public: Collecteur();
		public: int recupererIdentifiantRaspberry();

		public: string creerEnregistrement();

		public: string geolocaliser();

		public: string geolocaliser(int identifiant);

		public: string obtenirIntensiteLumineuse();

		public: string obtenirIntensiteLumineuse(int identifiant);

		public: string chercherEnregistrements();

		public: void comparerPosition();

		public: void ajouterLampadairesProches();

		public: string getDonneesEnregistrement(char aLatitude[], char aLongitude[]);

		public: int modifier(int aId, float aAlbedo, float aFluxLum, string aIdEnregistrement, string aIdRaspberry, string aTypeAmpoule, string aTypeLampadaire, int aHauteur, double aLatitude, char aIndicLat, double aLongitude, char aIndicLong, int aNbImages, string aAgglo, string aRue, int aUlor, string aDate, string aNotes);

		public: void modf2(Enregistrement aDonnee);

		public: void supprimer();
				string getIdentifiant();
	};


#endif
