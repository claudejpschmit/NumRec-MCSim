//
//  MyFileReader.cpp
//  
//  A minimal I/O package to read data from a text file.
//  The text file needs to be a set of (any number of) columns separated by whitespace, eg:
//
//  1.0  0.1 
//  2.0  0.2
//  3.0  0.3
//
//  It is presented to the user in the form of a nxm matrix where 
//    n = number of rows = number of line in file 
//    m = number of columns = number of entries on each line
//
//  The user can also ask for individual columns.
//
//  For use in Numerical Recipes course.
//
//  Created by PeterClarke on 30/07/2013.
//
//  Changed to use armadillo package by Claude Schmit on 28/09/2013

#include "MyFileReader.h"

// Constructor
MyFileReader::MyFileReader( string filename )
	:
	m_isValid(false)
{
	vector<double> list;
	ifstream file;
	char buffer[256];

	int nrows=0;
	int ncols=0;

	try { file.open(filename.c_str()); }
	catch( int e ) { cout << "Exception " << filename << " not open" << endl; }

	//string text = NULL;

	

	while (!file.eof()) {
		nrows++;
		file.getline(buffer, 256);
		string line(buffer);
		istringstream line_stream(line);


		do {
			ncols++;
			double element;
			line_stream >> element;
			list.push_back(element);
		} while (line_stream);
		ncols--;
		list.pop_back();
	}
	ncols = ncols/nrows;
	m_M = new mat( nrows, ncols );
	m_isValid= true ;

	for( int irow=0; irow<nrows; ++irow ) {
		for( int icol=0; icol< ncols; ++icol ) {
			int ind = irow*ncols+icol ;
			m_M->at(irow,icol) = list[ind];
			//m_M->setElement(irow,icol,list[ind]) ;
		}
	}

	if ( file != NULL ) file.close();

}

//Get a column
mat MyFileReader::getColumn( int icol)
{
	if( (icol >= 0) && (icol < m_M->n_cols) ) {
		return m_M->col(icol) ;
		
	}
	else {
		return NULL;
	}
}


// Print out data set
void MyFileReader::print() {
	if( m_isValid ) {
		string msg = "Dataset rows= ";
		cout << msg << endl;

		cout << *m_M << endl;
		//m_M->printIt();
	}
	else
		cout << "Data set is not valid" << endl;
}


