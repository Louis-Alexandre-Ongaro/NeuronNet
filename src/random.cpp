#include "random.h"
#include <string>

RandomNumbers::RandomNumbers(unsigned long int s) {
	seed = s; 
	rng = std::mt19937(seed);

};

void RandomNumbers::uniform_double(std::vector<double>& tab, double lower, double upper) {
	if(tab.size() != 0) {
		for(unsigned int i=0; i < tab.size(); ++i) {
			tab[i] = uniform_double(lower, upper);
		}
	}
};

double RandomNumbers::uniform_double(double lower, double upper) {
	std::uniform_real_distribution<> d_uni(lower, upper);
	return d_uni(rng);
};

void RandomNumbers::normal(std::vector<double>& tab, double mean, double sd) {
	if(tab.size() != 0) {
		for(unsigned int i=0; i < tab.size(); ++i) {
			tab[i] = normal(mean, sd);
		}
	}
};

double RandomNumbers::normal(double mean, double sd) {
	std::normal_distribution<double> d_norm(mean, sd);
	return d_norm(rng);
};

void RandomNumbers::poisson(std::vector<int>& tab, double mean) {
	if(tab.size() != 0) {
		for(unsigned int i=0; i < tab.size(); ++i) {
			tab[i] = poisson(mean);
		}
	}
};

int RandomNumbers::poisson(double mean) {
	std::poisson_distribution<> d_pois(mean);
	return d_pois(rng);
};
