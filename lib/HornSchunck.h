
#ifndef HORNSCHUNCK_H

#include "DenseMotionExtractor.h"

#include "CImg_config.h"
#include <CImg.h>
#include <string>

using namespace cimg_library;
using namespace std;

/// Implements single-resolution Proesmans motion extractor.
/**
 * This implementation is based on the following article:
 * 
 * M. Proesmans, L. Van Gool, E. Pauwels, and A. Oosterlinck, 
 * Determination of optical ﬂow and its discontinuities using 
 * non-linear diffusion, in 3rd European Conference on Computer 
 * Vision, ECCV’94, 1994, Vol. 2, pp. 295–304.
 *
 * and the C-implementation found at http://of-eval.sourceforge.net
 */
class HornSchunck : public DenseMotionExtractor
{
public:
  enum BoundaryConditions { DIRICHLET, NEUMANN };
  
  /// Default constructor.
  /**
   * Constructs a Proesmans motion extractor with the default parameters.
   * - number of iterations = 200
   * - lambda = 100
   * - boundary conditions = Neumann
   */
  HornSchunck();
  
  /// Parametrized constructor.
  HornSchunck(int numIterations_,
              double alpha_,
              double relaxCoeff_,
              BoundaryConditions boundaryConditions_);
  
  void compute(const CImg< unsigned char > &I1,
               const CImg< unsigned char > &I2,
               CImg< double > &V);
  
  double getAlpha() const { return ALPHA_; }
  
  BoundaryConditions getBoundaryConditions() const { return BOUNDARY_CONDITIONS_; }
  
  string getName() const;
  
  int getNumIterations() const { return NUM_ITERATIONS_; }
  
  int getNumResultQualityChannels() const { return 1; }
  
  double getRelaxCoeff() const { return RELAX_COEFF_; }
  
  bool isDual() const { return false; }
  
  void printInfoText() const;
private:
  const double ALPHA_;
  const BoundaryConditions BOUNDARY_CONDITIONS_;
  const double INTENSITY_SCALE_;
  const int NUM_ITERATIONS_;
  const double RELAX_COEFF_;
  
  CImg< unsigned char > I_[2];
  CImg< double > Gx_, Gy_, Gt_;
  //CImg< double > V_;
  
  int width_, height_;
  
  void computeGradients_(const CImg< unsigned char > &I1,
                         const CImg< unsigned char > &I2);
  
  void printProgressBar_(double pct);
  
  void repairEdges_(CImg< double > &V);
};

#define HORNSCHUNCK_H

#endif
