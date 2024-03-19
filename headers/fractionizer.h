/*************************************************************/
/* Fractionizer         						             */
/*-----------------------------------------------------------*/
/* Module            : fractionizer.h                        */
/* Numéro de version : 0.0.23                                */
/* Date              : 24/08/2015                            */
/* Auteurs           : ajneu                                 */
/*************************************************************/

#ifndef FRACTIONIZER_H
#define FRACTIONIZER_H



#include <cmath>  // std::modf
#include <vector>


/* uncomment one of the following */
//#define OWN_LIMITS
#undef  OWN_LIMITS


#ifndef OWN_LIMITS
#include <limits>
using std::numeric_limits;

#else

#include <cfloat> // FLT_EPSILON, DBL_EPSILON, LDBL_EPSILON

// just for fun
namespace own {
  template <typename Tfl> // Tfl should be a floating point type (preferably double or long double)
    struct numeric_limits {
      static constexpr Tfl min() {
	return get_min(Tfl{});
      }
      static constexpr Tfl epsilon() {
	return get_epsilon(Tfl{});
      }
    private:
      static constexpr float       get_min(float)       { return FLT_MIN; }
      static constexpr double      get_min(double)      { return DBL_MIN; }
      static constexpr long double get_min(long double) { return LDBL_MIN;}

      static constexpr float       get_epsilon(float)       { return FLT_EPSILON; }
      static constexpr double      get_epsilon(double)      { return DBL_EPSILON; }
      static constexpr long double get_epsilon(long double) { return LDBL_EPSILON;}
    };
}

using own::numeric_limits;

#endif




class Fractionizer {
 public:
  template <typename Tfl, typename Tfl2> // Tfl should be a floating point type (preferably double or long double)
    static std::vector<Tfl> fractionize(const Tfl val, Tfl2 &num, Tfl2 &denom)
    {
      Tfl n;
      Tfl d;
      std::vector<Tfl> vec;
      Tfl i;
      Tfl v = val;
      goto label_begin;
      do {
	v = 1/v;
      label_begin:
	//std::cout << "v == " << v << '\t';
	v = std::modf(v, &i);
	//std::cout << "i == " << i << '\t';
	vec.push_back(i);
	//std::cout << "calc == " << Fractionizer::calc_frac<Tfl>(vec, n, d) << std::endl;
      }
      //while (std::abs((Fractionizer::calc_frac<Tfl>(vec, n, d) - val)/val) > numeric_limits<Tfl>::min());
      while (Fractionizer::calc_frac<Tfl>(vec, n, d) != val);
      //assert((n/d) == val);
      num   = n;
      denom = d;
      return vec;
    }
  
  template <typename Tfl, typename Tfl2> // Tfl should be a floating point type (preferably double or long double)
  static Tfl calc_frac(const std::vector<Tfl> &vec, Tfl2 &num, Tfl2 &denom)
   // {2,     3,  4}
   //  2 + 1/(3+1/4)
    {
      if (!vec.empty()) {
	Tfl n = 1.0; // num
	Tfl d = 0.0; // denom

	auto it_end = vec.cend();
	const auto it_beg = vec.cbegin();
	do {
	  --it_end;

	  std::swap(n, d);
	  n += *it_end * d;
	} while (it_end != it_beg);
	num   = n;
	denom = d;
	return n/d;
      }
      num   = 0.0;
      denom = 1.0;
      return 0.0;
    }

};


#endif