//-------------------------------------------------------
// lfsr.cpp implements linear feedback shift register
// to generate white noise,
// Electronics Magazine 5/27/'76, p. 107
// started 5/19/'03, M. Williamsen
// nested loops to find max sequences 6/5/'03 MSW
//-------------------------------------------------------
#include <iostream>

int
main (int argc, const char *argv[])
{
  long long int len = 0;
  long long int tap = 0;

  for (len = 7; len <= 33; len++)
    for (tap = 1; tap < len; tap++)
      {
	// initialize variables
	long long int sr = 0; // the shift register (64 bits max)
	long long int count = 0LL; // iteration counter
	bool fb = false; // linear feedback bit
	bool done = false; // exit flag

	// set up mask bits
	long long int mask1 = 1LL << (tap - 1LL); // mask for tap bit
	long long int mask2 = 1LL << (len - 1LL); // mask for most significant bit
	long long int mask4 = mask2 | (mask2 - 1LL); // mask for all sr bits
	sr = mask4;

	// start generating outputs
	// done when initial value comes around again
	while (!done)
	  {
	    // generate feedback bit
	    fb = !(sr & mask1) xor !(sr & mask2); // ! casts to boolean

	    // shift and mask sr
	    sr = (sr << 1LL) & mask4;

	    // apply feedback
	    if (fb)
	      {
		sr |= 1LL;
	      }

	    // check for exit on '0' or '-1'
	    done = (!sr) || (sr == mask4);

	    // check if maximum length reached
	    if (++count == mask4)
	      {
		std::cout << "(" << tap << ", " << len << ")" << std::endl;
		done = true;
	      }
	  }
      }

  // return success
  return 0;
}

