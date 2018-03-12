#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cstdlib>

#include "GPS.h"

int  GPS::lire () 
{
	int retour = 0;
	char character[1] = {0};

	termios T_new;

	int fd=open("/dev/ttyUSB0",O_RDONLY|O_NDELAY);

	if(fd == -1){
		fd=open("/dev/ttyUSB1",O_RDONLY|O_NDELAY);
		if(fd == -1){
		return ERREURACCESPORT;
		}
	}
	
	T_new.c_cflag = (B4800|CS8);
	retour = tcsetattr(fd, TCSANOW, &T_new);
	if(retour != 0){
		return retour;
	}

	do
	{
		/* Lecture sur le port GPS des caract�res re�us, caract�re par caract�re*/
		do{
			retour = read(fd, character, 1);
		} while(retour<=0);
		/* Si le caract�re lu est un caract�re ASCII du protocole NMEA alors on l'enregistre
		sinon on ne fait rien */
		if ((character[0]>=0x24) && (character[0]<=0x5A))
		{
			salve.push_back(character[0]);
		}
	}
	while (salve.size()<600);
	close(fd);
	return retour;
}
std::vector<char> GPS::getSalve()
{
	return salve;
}

bool GPS::verifierChecksum (std::vector<char> trameRMC)
{
	std::vector<char>::const_iterator	lit(trameRMC.begin()), 
								lend(trameRMC.end()); 
	short Checksum=0;
	char leChecksum[2];
	/*le checksum pr�c�d� du signe * repr�sente le OR exclusif de tous 
	les caract�res compris entre $ et * (sauf les bornes $ et *). 
	lit est donc incr�ment� pour exclure le $
	lend est donc d�cr�ment� 3 fois pour exclure le Chekcum est le * */
	++lit;
	--lend;--lend;--lend;

	for (;lit!=lend;++lit)
	{
		Checksum = Checksum^*lit;
	}
	/*le checksum est transform� en hexad�cimal puis en ASCII pour comparaison
	� celui de la trame re�ue*/
	sprintf(leChecksum, "%X",Checksum);
	lit = trameRMC.end();
	if ((leChecksum[1]!=*--lit) || (leChecksum[0]!=*--lit)) return false;

	return true;
}

/* extraction de la trame RMC dans une liste de messages re�us */
int GPS::extraireRMC(std::vector<char> &trameRMC)
{
	std::vector<char>::const_iterator	lit(salve.begin()), 
								lend(salve.end()); 
	std::vector<char> GPRMC={'$','G','P','R','M','C'};
	bool MauvaiseTrame = false;
	/*Dans la salve r�cup�r�e, on cherche la trame RMC qui correspond
	� la trame contenant la date, l'heure et la position*/
	do
	{
		lit = find(lit, lend,'R');
		if (lit==lend) return ECHECCAPTURE;
		if ((*(++lit)!='M')||(*(++lit)!='C')) MauvaiseTrame = true;
		else 
		{
			/*Si on est bien sur une trame RMC alors on place les identifiants trame au d�but de la trame � retourner*/
			trameRMC.insert(trameRMC.begin(),GPRMC.begin(),GPRMC.end());
		}
	}
	while (MauvaiseTrame==true);
	/*On se place au niveau du caract�re qui suit le dernier caract�re
	de l'identifiant de trame*/
	lit = ++find(lit, lend,'C');
	/*On rempli trameRMC � retourner avec tous les caract�res qui suivent jusqu'au caract�re $
	qui marque le d�but de la trame suivante*/
	for (;lit!=lend;++lit)
	{
		if (*lit!='$')
		{
			trameRMC.push_back(*lit);
		}
		else break;
	}
	/*On v�rifie qu'il s'agit bien d'une trame RMC valide :  
	Alerte du logiciel de navigation ( A = OK, V = warning (alerte))*/
	lit = find(trameRMC.begin(), trameRMC.end(),'V');
	if (lit!=trameRMC.end()) return ALERTE;
	/*On v�rifie que le Checksum est correct*/
	if (!verifierChecksum(trameRMC)) return ERREURCHECKSUM ;

	return 1;
}

/* extraction d'une trame sp�cifi�e par l'utilisateur
Le format de GPXXX est : {'$','X','X','Y','Y','Y'} 
ou X repr�sente les diff�rentes lettre de l'identifiant du r�cepteur
et Y repr�sente  les 3 lettres pour l'identifiant de la trame */
int GPS::extraire(std::vector<char> &trame,std::vector<char> messages, std::vector<char> GPYYY)
{
	std::vector<char>::const_iterator	lit(messages.begin()), 
								lend(messages.end()),
								trameIT(GPYYY.begin());
	bool mauvaiseTrame=false;
	/* Dans un premier temps, on recherche dans la liste pass�e en param�tre
	l'identifiant de la trame recherch�e*/
	advance(trameIT,2);
	char identifiant[3];
	for (int i=0;i<3;i++)
	{
		identifiant[i] =*++trameIT;
	}

	/*Dans la salve r�cup�r�e, on cherche la trame demand�e via
	son identifiant*/
	do
	{
		lit = find(lit, lend,identifiant[0] );
		if ((*(++lit)!=identifiant[1])||(*(++lit)!=identifiant[2])) 
			{
				mauvaiseTrame=true;
			}
		else mauvaiseTrame=false;
		if (lit==lend) return MAUVAISETRAME;
	}
	while(mauvaiseTrame);
	/*On rempli � retourner avec tous les caract�res qui suivent jusqu'au caract�re $
	qui marque le d�but de la trame suivante*/
	trame.insert(trame.begin(),GPYYY.begin(),GPYYY.end());
	lit = ++find(lit, lend,identifiant[2]);
	for (;lit!=lend;++lit)
	{
		if (*lit!='$')
		{
			trame.push_back(*lit);
		}
		else break;
	}

	if (!verifierChecksum(trame)) return ERREURCHECKSUM ;

	return 1;
}
GPS::GPS()
{
	
}