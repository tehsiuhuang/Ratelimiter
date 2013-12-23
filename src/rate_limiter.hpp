#ifndef _rate_limiter_h_
#define _rate_limiter_h_

#include <mutex>
#include "rate_limiter_interface.hpp" 

class RateLimiter : public RateLimiterInterface {
public:
	void aquire();
	void aquire(int permits);

	bool try_aquire(int timeouts);
	bool try_aquire(int permits, int timeout);

	double get_rate() const;
	void set_rate(double rate);
private:	
	std::chrono::microseconds claim_next(double permits);
private:
	double interval_;	
	double max_permits_;
	double stored_permits_;

	long next_free_;
	
	std::mutex mut_;
};


#endif