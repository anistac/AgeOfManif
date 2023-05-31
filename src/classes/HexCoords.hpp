typedef struct HexCoords{
  int q, r, s;
  HexCoords(int q, int r) : q(q), r(r), s(-q-r) {}
  HexCoords(): q(0), r(0), s(0) {}
} HexCoords;


