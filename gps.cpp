#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"

using namespace std;
using namespace cgicc;


int main()
{
	string latitude = "43.523336";
	string longitude = "1.3122833";
	cout<<HTTPHTMLHeader();
	cout<<"{\n\t\"LATITUDE\":"<<latitude<<",\n";
	cout<<"\t\"LONGITUDE\":"<<longitude<<"\n}\n";
	return 0;
}




