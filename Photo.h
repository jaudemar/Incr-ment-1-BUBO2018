#include <exception>
#include <string>
#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
using namespace std;

#ifndef __Photo_h__
#define __Photo_h__

// #include "Galerie.h"

	class Photo
	{
		/**
		 * Les photos sont identifi�es par leur nom qui est d�riv� de l�identifiant unique de l�enregistrement auquel elles sont associ�es (avec un num�ro incr�ment� pour les distinguer le cas �ch�ant)
		 */
		private: string _identifiant;
				 string photoRepertoire;
			     string IMG_EXTENSION = ".jpg";

		public: void uploadPhoto(string aPhoto, string aIdentifiant);
		public:
			Photo(std::string l);
			~Photo();
			bool supprime(std::string nom);
			bool ajoute(cgicc::FormFile fichier, std::string enregistrement);

		private:

			int getNbPhoto(std::string directory);

		public: void setIdentifiant(string aIdentifiant);

		public: string getIdentifiant();
	};

#endif
