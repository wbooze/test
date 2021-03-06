
#ifndef _PACKTREE_H_
#define _PACKTREE_H_


#include "packtree_base.h"
#include "packdata_list.h"
#include "packcontainer.h"
#include "liftbase.h"


/** \file

  The documentation in this file is formatted for doxygen
  (see www.doxygen.org).

<h4>
   Copyright and Use
</h4>

<p>
   You may use this source code without limitation and without
   fee as long as you include:
</p>
<blockquote>
     This software was written and is copyrighted by Ian Kaplan, Bear
     Products International, www.bearcave.com, 2002.
</blockquote>
<p>
   This software is provided "as is", without any warranty or
   claim as to its usefulness.  Anyone who uses this source code
   uses it at their own risk.  Nor is any support provided by
   Ian Kaplan and Bear Products International.
<p>
   Please send any bug fixes or suggested source changes to:
<pre>
     iank@bearcave.com
</pre>

  @author Ian Kaplan

 */

/**

  The packtree object constructs a wavelet packet tree

  The constructor is passed a vector of doubles, the length of the
  vector (which must be a power of two) and a pointer to a wavelet
  lifting scheme class that will be used in calculating the wavelet
  transform step.  If the vector passed to the constructor contains N
  double vaues, the result of the constructor will be a wavelet packet
  tree with log<sub>2</sub>(N) levels.

 */

class packtree : public packtree_base {
public:

  /** Found original data marked as part of the best basis.
      This means that the best basis function failed (or
      that the original data is the most compact representation
      relative to the cost function used).  */
  bool foundOriginalData;
  /** found a best basis value in the wavelet packet tree */
  bool foundBestBasisVal; 
  
public:
  /** disallow the copy constructor */
  packtree( const packtree &rhs ) {};
  /** disallow the default constructor */
  packtree() {};

  double bestBasisWalk( packnode<double> *root );

  void buildBestBasisList( packnode<double> *root, 
			   packdata_list<double> &list );

  void checkBestBasis( packnode<double> *root );

  void cleanTree(packnode<double> *root, bool removeMark );

public:

  packtree( const double *vec, 
            const size_t n, 
            liftbase<packcontainer, double> *w );

  /** destructor does nothing */
  ~packtree() {}

  void prCost();
  void prBestBasis();

  void bestBasis();

  bool bestBasisOK();

  packdata_list<double> getBestBasisList();

}; // packtree

#endif
