//
//  MyFileReader.h
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
//  Created by Greig Cowan on 19/09/2013.
//

#pragma once

#include "Preamble.h"


class MyFileReader {
	
	private:
		mat * m_M ;
		bool m_isValid;
	
	// Constructor
	public:
		MyFileReader ( string );
	
		// is it valid
		bool isValid() {
			return m_isValid ;
		}
	
		// Get number of rows
		int getRowDimension() {
			//return m_M.getRowDimension();
			return m_M->n_rows;
		}

		// Get number of columns
		int getColumnDimension() {
			//return m_M.getColumnDimension();
			return m_M->n_cols;
		}
	
		//Get the whole matrix
		mat * getMatrix() {
			return m_M ;
		}

		//Get a column
		mat getColumn( int icol );
	
		// Print out data set
		void print();

};


