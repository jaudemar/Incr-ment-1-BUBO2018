all :
	g++   Enregistrement.cpp Logger.cpp  Horodatage.cpp Lampadaire.cpp Ampoule.cpp Galerie.cpp GPS.cpp Geolocalisation.cpp BDD.cpp Collecteur.cpp -o Collecteur -std=c++11 -lsqlite3 -lcgicc
