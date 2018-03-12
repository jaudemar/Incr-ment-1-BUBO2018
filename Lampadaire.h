#include <string>
using namespace std;

#ifndef __Lampadaire_h__
#define __Lampadaire_h__

// #include "Enregistrement.h"


	class Lampadaire
	{
		private: string _type;
		private: float _hauteur;
		private: int _uLOR;
		private: float _albedo;


		public: void setType(string aType);

		public: string getType();

		public: void setHauteur(float aHauteur);

		public: float getHauteur();

		public: void setULOR(int aULOR);

		public: int getULOR();

		public: void setAlbedo(float aAlbedo);

		public: float getAlbedo();
	};

#endif
