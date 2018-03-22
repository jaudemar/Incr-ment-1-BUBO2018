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
/* Compilation :
g++ Collecteur.cpp BDD.cpp /usr/lib/libcgicc.a -std=c++11 -o Collecteur.cgi -l sqlite3 */
//	sqlite3_stmt *statement; 
//	string selectSql = "SELECT title FROM list";
//	sqlite3_prepare_v2(db,selectSql.c_str(), -1, &statement, NULL);

std::vector<Enregistrement> BDD::selectData(string requetesql){
   /* int rc = sqlite3_prepare_v2(db,requetesql, strlen(requetesql), &requetesql, NULL );
    if(!rc){
        //Vérifie qu'il y a des lignes disponinles
        while(rc == SQLITE_OK || rc == SQLITE_ROW){
            //Récupératiion d'une ligne
            rc = sqlite3_step(requetesql);
            if(rc == SQLITE_OK || rc == SQLITE_ROW){
                    Enregistrement enreg = new Enregistrement();
                    //Mettre les valeurs dans l'objet enreg
                    //Pour récup (letype) sqlite3_column_text(requete, numdelacolonne)

                    //Une fois fait sauvegarder enreg dans resultat
                    //resultat.push_back(enreg)
            }
        }
        sqlite3_finalize(requetesql);
    }else{

    }
    return resultat;*/
}

std::vector<Enregistrement> BDD::obtenirListeDesEnregistrements()
{
    string req = "SELECT * FROM Enregistrements";
    return selectData(req);
}


std::vector<Enregistrement> BDD::obtenirDonneesEnregistrement(double latitude,double longitude)
{
   /*char* req = "SELECT * FROM Enregistrements WHERE latitude BETWEEN "+(latitude - 0.00005)+" AND "+(latitude + 0.00005)+" AND longitude BETWEEN "+(longitude - 0.00005)+ " AND " +(latitude + 0.0005);
   return selectData(req);*/
   //Fait appel a la methode plus haut
}

Enregistrement BDD::obtenirDonneesEnregistrement(string aLatitude, string aLongitude)
{

}


std::vector<Enregistrement*>BDD:: sauvegarderDonneesEnregistrement(Enregistrement *enregistrement,string identifiantCollecteur)
{
	cout << "Enregistrements"<<endl;

	char *zErrMsg = 0;
	int  rc;
	string typeA;
  	string typeL;
	float hauteur;
	int ULOR;
	int puissance;
	float albedo;
	float fluxLum;
	int nbrePhotos;
	char date [7];
	char heure;
	char longitude[10];
	char latitude[10];
	vector<Enregistrement*> leRetour;
	string identifiantE;
	string  agglomeration;
	string  rue;
	string notes;



	enregistrement->getLampadaire(typeL,hauteur,ULOR,albedo);
	enregistrement->getAmpoule(typeA,fluxLum,puissance);
	enregistrement->getGalerie(nbrePhotos);
	enregistrement->getHorodatage(date);
	string laDate="";

	for (int i=0;i<6;i++)
	{
		laDate=laDate+date[i];
	}

	laDate=laDate+'\0';

	enregistrement->getGeolocalisation(latitude,longitude);

	string laLongitude="";
	for (int i=0;i<10;i++)
	{
		laLongitude=laLongitude+longitude[i];
	}

	laLongitude=laLongitude+'\0';
cout<< "BDd longi : "<<laLongitude<<endl;
	string laLatitude="";
cout<<"Bdd latitu : "<<laLatitude<<endl;
	for (int i=0;i<10;i++)
	{
		laLatitude=laLatitude+latitude[i];
	}

	laLatitude=laLatitude+'\0';

	identifiantE = enregistrement->getIdentifiant();

	agglomeration = enregistrement->getAgglomeration();
	rue = enregistrement->getRue();
	notes=enregistrement->getNotes();

	/*---------------------------------*/

	sqlite3_stmt *stmt;
	const char *pzTest;

	std::string sql="INSERT INTO Enregistrements(power,albedo,flux,idrecord,idrasp,lamp,streetlight,height,latitude,longitude,nbimages,town,street,ulor,date,notes) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
	rc = sqlite3_prepare(db, sql.c_str(), sql.length(), &stmt, &pzTest);

		if( rc == SQLITE_OK ) 
		{
			 // bind the value
			sqlite3_bind_int(stmt, 1, puissance); 
			sqlite3_bind_double(stmt, 2, albedo);
			sqlite3_bind_double(stmt, 3, fluxLum);
			sqlite3_bind_text(stmt, 4, identifiantE.c_str(), identifiantE.length(), 0);
			sqlite3_bind_text(stmt, 5, identifiantCollecteur.c_str(), identifiantCollecteur.length(), 0);
			sqlite3_bind_text(stmt, 6, typeA.c_str(), typeA.length(), 0);
			sqlite3_bind_text(stmt, 7, typeL.c_str(), typeL.length(), 0);
			sqlite3_bind_double(stmt,8, hauteur);
			sqlite3_bind_text(stmt, 9 ,laLatitude.c_str(), laLatitude.length(), 0);
			sqlite3_bind_text(stmt, 10,laLongitude.c_str(), laLongitude.length(), 0);
			sqlite3_bind_int(stmt, 11, nbrePhotos);
			sqlite3_bind_text(stmt, 12 ,agglomeration.c_str(), agglomeration.length(), 0);
			sqlite3_bind_text(stmt, 13 ,rue.c_str(), rue.length(), 0);
			sqlite3_bind_int(stmt, 14, ULOR);
			sqlite3_bind_text(stmt,15, laDate.c_str(), laDate.length(), 0);
			sqlite3_bind_text(stmt,16, notes.c_str(), notes.length(), 0);

		 	// commit
		 	sqlite3_step(stmt);
		 	sqlite3_finalize(stmt);
				cout << "Insertion effectuÃ©e"<<endl;
		}

/*
    std::string sql1="SELECT * FROM Enregistrements; ";
vector <string>vec;
	rc =sqlite3_exec(db, sql,int  callback, 0, int &err_msg);

if (rc != SQLITE_OK) {

cout<<"Failed to select data"<<endl;
cout<<"SQL error: "<<err_msg<<endl; //revoir la ligne

sqlite3_free(err_msg);
sqlite3_close(db);

return 1 ;
}

sqlite3_close(db);

return 0;

}

int callback (void *NotUsed, int argc, char **argv,char **azColName) {
NotUsed = 0;
for (int i=0; i<argc; i++){
vec.push_back(std::string( (char *)sqlite3_column_text(stmt, i)) );
}

cout<<"test fin "<<endl;
 return 0 ;

}
*/

/*
	//rc = sqlite3_exec(db, sql1.c_str(), NULL, 0, &zErrMsg);
	//	std::vector< std::vector < std:: string > > result;	//ici vecteur de vecteur!!!probablement  une erreur ici!!!
vector<vector<string> >vec;//instance du vecteur
vector <string>vec2; //bcle de 17 ds la suite 
    	sqlite3_prepare( db, sql1.c_str(), sql1.length(), &stmt, NULL );//preparing the statement

 	sqlite3_step( stmt );//executing the statement
cout<<"bdd3"<<endl;
	while( sqlite3_column_text( stmt, 0 ) )
	{
	cout<<"bdd 4"<<endl;
		for(int i=0; i<17;i++)
		{
			cout<<"test 4.1:  "<<std::string( (char *)sqlite3_column_text(stmt, i)) <<endl;
//			vec2.push_back(std::string( (char *)sqlite3_column_text(stmt, i)) );//Add column to all rows
        	}
	cout<<"bdd 5"<<endl;

	vec.push_back(vec2);

	vec.clear();

	}


	/*while( sqlite3_column_text( stmt, 0 ) )

	{

 		for(int i = 0; i <= 17; i++ )
		{
			cout<<"BDD test 5"<<endl;
 				result[i].push_back( std::string( (char *)sqlite3_column_text( stmt, i ) ));//il y a un pb a resoudre entre le for et cette ligne
			cout<<"BDD test 6"<<endl;

		}
		sqlite3_step( stmt );
	}*/

    		sqlite3_finalize(stmt);
    		//sqlite3_close(db);
		leRetour.push_back(enregistrement);

		return leRetour;

}


void  BDD::execute(string requetesql)
{

	char* messageError;
	int rc = sqlite3_exec(db, requetesql.c_str(), NULL, 0, &messageError);

	if(rc != SQLITE_OK)
	{
        	fprintf(stderr, "SQL error: %s\n", messageError);
		sqlite3_free(messageError);
	}

	else
	{
		fprintf(stdout,"Table created successfully \n");
	}
}



void BDD::modifierEnregistrement(int aId, int puissance, float aAlbedo, float aFluxLum, string aIdEnregistrement, string aIdRaspbery, string aTypeAmpoule, string aTypeLampadaire, int aHauteur, double aLatitude, double aLongitude, int aNbImages, string aAgglo, string aRue , int aUlor, string aDate, string aNotes)
{

 sqlite3_stmt *stmt;
    const char *pzTest;


std :: string sql = "UPDATE Enregistrements SET power=?, albedo=?, flux=? , idrasp=?, lamp=?, streetlight=?, height=?, latitude=?, longitude=?, nbimages=?, town=?, street=?, ulor=?, date=?, notes=? where id=?";

cout<<"test requete"<<endl;     
int rc = sqlite3_prepare(db,sql.c_str(), sql.length(), &stmt, &pzTest);
cout<<"test rc : "<< rc<<endl;
if ( rc == SQLITE_OK) {
cout<<"test1"<<endl;
sqlite3_bind_int(stmt,1,puissance);
        sqlite3_bind_double(stmt,2,aAlbedo);
        sqlite3_bind_double(stmt,3,aFluxLum);
        sqlite3_bind_text(stmt,4,aIdRaspbery.c_str(),aIdRaspbery.length(),0);
        sqlite3_bind_text(stmt,5,aTypeAmpoule.c_str(),aTypeAmpoule.length(),0);
        sqlite3_bind_text(stmt,6,aTypeLampadaire.c_str(),aTypeLampadaire.length(),0);
        sqlite3_bind_double(stmt,7,aHauteur);
        sqlite3_bind_double(stmt,8,aLatitude);
        sqlite3_bind_double(stmt,9,aLongitude);
        sqlite3_bind_int(stmt,10,aNbImages);
        sqlite3_bind_text(stmt,11,aAgglo.c_str(),aAgglo.length(),0);
        sqlite3_bind_text(stmt,12,aRue.c_str(),aRue.length(),0);
        sqlite3_bind_int(stmt,13,aUlor);
        sqlite3_bind_text(stmt,14,aDate.c_str(),aDate.length(),0);
        sqlite3_bind_text(stmt,15,aNotes.c_str(),aNotes.length(),0);
        sqlite3_bind_int(stmt,16,aId);
        cout<<"ok"<<endl;

        rc =sqlite3_step(stmt);
        cout<<"test step:"<<rc<<endl;
        rc=sqlite3_finalize(stmt);
        cout<<"test finalize :"<<rc<<endl;
        cout << "Insertion effectuÃ©e1"<<endl;

      }
        sqlite3_close(db);
}


void BDD::supprimerEnregistrement(int id){
        std::string requetesql = "DELETE FROM Enregistrements WHERE id="+id;
        execute(requetesql);
}

BDD::BDD()
{
	//Chemin d'accÃ©s a la base de donnÃ©es
	_baseDeDonnees="/home/pi/bdd/Enregistrement.db";
	int rc;
	char * zErrMsg;

	/*Ouverture d'un accÃ©s a la base de donnÃ©es via son chemin d'accÃ©s
	* Si le fichier n'existe pas, la fonction sqlite3_open crÃ©e une
	* autre base avec ce nom
	*/
	rc = sqlite3_open(_baseDeDonnees.c_str(), &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));

   }
   else{
      fprintf(stdout, "Opened database successfully\n");

	sqlite3_stmt *statement; 
	string selectSql = "SELECT * FROM Enregistrements";
	sqlite3_prepare_v2(db,selectSql.c_str(), selectSql.length() ,&statement, NULL);
		int countColumn= sqlite3_column_count(statement);
	if(!countColumn)
		{
			std::string selectSql ="CREATE TABLE IF NOT EXISTS Enregistrements(id  INTEGER PRIMARY KEY AUTOINCREMENT  ,power INTEGER, albedo REAL,flux REAL,idrecord TEXT NOT NULL ,idrasp TEXT NOT NULL,lamp TEXT  ,streetlight TEXT ,height REAL,latitude REAL NOT NULL,longitude REAL NOT NULL,nbimages int ,town TEXT,street TEXT,ulor INTEGER, date TEXT, notes TEXT );";
			//CrÃ©e une table appelÃ©e Enregistrements qui a comme parametres toutes les donnÃ©es liÃ©es a l'enregistrement si elle existe pas deja.
			 rc = sqlite3_exec(db, selectSql.c_str(), NULL, 0, &zErrMsg);
			 if( rc != SQLITE_OK ){
				fprintf(stderr, "SQL error: %s\n", zErrMsg);
				sqlite3_free(zErrMsg);
			}
			 else{
				fprintf(stdout, "Table created successfully\n");
			}
        }
	}
}


BDD::~BDD(){
    sqlite3_close(db);
}

//vector<Enregistrement> BDD::obtenirListeDesEnregistrements() {
//	throw "Not yet implemented";
//}
//
//Enregistrement BDD::obtenirDonneesEnregistrement(string aLatitude, string aLongitude) {
//	throw "Not yet implemented";
//}
//
//void BDD::supprimer(int aId) {
//	throw "Not yet implemented";
//}
//
//vector<Enregistrement> BDD::sauverDonneesEnregistrement(Enregistrement aEnregistrement) {
//	throw "Not yet implemented";
//}
//
//void BDD::modifierEnregistrement(Enregistrement aEnregistrement) {
//	throw "Not yet implemented";
//}
//
//void BDD::execute(char* aRequetesql) {
//	throw "Not yet implemented";
//}
//
//vector<Enregistrement> BDD::selectData(char* aRequetesql) {
//	throw "Not yet implemented";
//}
//BDD::BDD() {
//	//Chemin d'accès à la base de données
//	_baseDeDonnees="/home/pi/Documents/Enregistrement.db";
//	int rc;
//	char * zErrMsg;
//
//	/*Ouverture d'un accès à la base de données via son chemin d'accès
//	* Si le fichier n'existe pas, la fonction sqlite3_open créé une
//	* autre base avec ce nom
//	*/
//	rc = sqlite3_open(_baseDeDonnees.c_str(), &db);
//   if( rc ){
//      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//
//   }else{
//      fprintf(stdout, "Opened database successfully\n");
//   }
//	sqlite3_stmt *statement; 
//	string selectSql = "SELECT title FROM list";
//	sqlite3_prepare_v2(db,selectSql.c_str(), -1, &statement, NULL);
//	int countColumn = sqlite3_column_count(statement);
//	if (!countColumn)
//	{
//		 selectSql= " CREATE TABLE IF NOT EXISTS SRCLUMI(" 
//		"ID INTEGER PRIMARY   KEY  AUTOINCREMENT,"
//		"IDENREGISTREMENT TEXT NOT NULL,"
//		"IDCOLLECTEUR TEXT NOT NULL,"
//		"LATITUDE REAL NOT NULL ,"
//		"LONGITUDE REAL NOT NULL,"
//		"LAMPTYPE TEXT  ,"
//		"ULOR INTEGER ,"
//		"AMPTYPE TEXT  ,"
//		"HAUTEUR FLOAT ,"
//		"PUISSANCE INTEGER ,"
//		"ALBEDO REAL  ,"
//		"AGGLOMERATION TEXT,"
//		"RUE TEXT,"
//		"NOTES TEXT,"
//		"FLUXLUM REAL ,"
//		"DATE TEXT ,"		
//		"NBIMAGES INT DEFAULT '0'); " ;	
//		 rc = sqlite3_exec(db, selectSql.c_str(), NULL, 0, &zErrMsg);
//		 if( rc != SQLITE_OK ){
//		fprintf(stderr, "SQL error: %s\n", zErrMsg);
//		sqlite3_free(zErrMsg);
//		}else{
//		fprintf(stdout, "Table created successfully\n");
//		}
//
//	}
//}

