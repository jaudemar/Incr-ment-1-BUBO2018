#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <cstdlib>

#include <stdio.h>


#include "cgicc/CgiDefs.h"

#include "cgicc/Cgicc.h"

#include "cgicc/HTTPHTMLHeader.h"

#include "cgicc/HTMLClasses.h"


using namespace std;
using namespace cgicc;


int main(){

	cout<<HTTPHTMLHeader();
    cout << "{\n\t\"SUCCESS\" : \"OK\",\n\t\"IDENTIFIANT\" : \"" << "180224175102" << "\"\n}";

	return 0;
}