#include <iostream>
using namespace std;

template <typename F, typename S>
class Pair;

template <typename F, typename S>
ostream& operator<<(ostream&, const Pair<F,S>&);

template <typename F, typename S = F>
class Pair
{
public:
  Pair(F fst, S snd) : fst_{fst}, snd_{snd} {}
  F fst() const { return fst_; }
  S snd() const { return snd_; }

private:
  F fst_;
  S snd_;
  friend ostream& operator<<(ostream& out, const Pair<F,S>& rp) {
    out << "(" << rp.fst_ << "," << rp.snd_ << ")";
    return out;
  }
};