#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

struct Statystyka
{
  double dobra;
  double zla;
};

void dobra_odp (Statystyka &s);
void zla_odp (Statystyka &s);
double procent (Statystyka s);
void statystyka (Statystyka s);

#endif
