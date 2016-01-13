#include "md4.h"

static inline uint32_t if32(uint32_t x, uint32_t y, uint32_t z)
{
  return ((x & y) | (~x & z));
}

static inline uint32_t maj32(uint32_t x, uint32_t y, uint32_t z)
{
  return ((x & y) | (x & z) | (y & z));
}

static inline uint32_t xor332(uint32_t x, uint32_t y, uint32_t z)
{
  return (x ^ y ^ z);
}

static inline uint32_t rot32l(uint32_t x, int r)
{
  uint32_t msb = x << r;
  uint32_t lsb = x >> (32 - r);

  return (msb | lsb);
}

static inline uint32_t round1_quickie(uint32_t in0, uint32_t in1, uint32_t in2, uint32_t in3,  uint32_t messw, uint8_t rotfl)
{
  return rot32l((in0 + if32(in1, in2, in3) + messw), rotfl);
}

static inline uint32_t round2_quickie(uint32_t in0, uint32_t in1, uint32_t in2, uint32_t in3,  uint32_t messw, uint8_t rotfl)
{
  return rot32l((in0 + maj32(in1, in2, in3) + messw + 0x5A827999), rotfl);
}

static inline uint32_t round3_quickie(uint32_t in0, uint32_t in1, uint32_t in2, uint32_t in3,  uint32_t messw, uint8_t rotfl)
{
  return rot32l((in0 + xor332(in1, in2, in3) + messw + 0x6ED9EBA1), rotfl);
}

void cMD4(uint32_t chv[4], uint32_t mess[16], uint32_t out[4])
{
  // INIT
  out[0] = chv[0];
  out[1] = chv[1];
  out[2] = chv[2];
  out[3] = chv[3];

  // ROUND 1
  out[0] = round1_quickie(out[0], out[1], out[2], out[3], mess[ 0],  3);
  out[3] = round1_quickie(out[3], out[0], out[1], out[2], mess[ 1],  7);
  out[2] = round1_quickie(out[2], out[3], out[0], out[1], mess[ 2], 11);
  out[1] = round1_quickie(out[1], out[2], out[3], out[0], mess[ 3], 19);

  out[0] = round1_quickie(out[0], out[1], out[2], out[3], mess[ 4],  3);
  out[3] = round1_quickie(out[3], out[0], out[1], out[2], mess[ 5],  7);
  out[2] = round1_quickie(out[2], out[3], out[0], out[1], mess[ 6], 11);
  out[1] = round1_quickie(out[1], out[2], out[3], out[0], mess[ 7], 19);

  out[0] = round1_quickie(out[0], out[1], out[2], out[3], mess[ 8],  3);
  out[3] = round1_quickie(out[3], out[0], out[1], out[2], mess[ 9],  7);
  out[2] = round1_quickie(out[2], out[3], out[0], out[1], mess[10], 11);
  out[1] = round1_quickie(out[1], out[2], out[3], out[0], mess[11], 19);

  out[0] = round1_quickie(out[0], out[1], out[2], out[3], mess[12],  3);
  out[3] = round1_quickie(out[3], out[0], out[1], out[2], mess[13],  7);
  out[2] = round1_quickie(out[2], out[3], out[0], out[1], mess[14], 11);
  out[1] = round1_quickie(out[1], out[2], out[3], out[0], mess[15], 19);

  // ROUND 2
  out[0] = round2_quickie(out[0], out[1], out[2], out[3], mess[ 0],  3);
  out[3] = round2_quickie(out[3], out[0], out[1], out[2], mess[ 4],  5);
  out[2] = round2_quickie(out[2], out[3], out[0], out[1], mess[ 8],  9);
  out[1] = round2_quickie(out[1], out[2], out[3], out[0], mess[12], 13);

  out[0] = round2_quickie(out[0], out[1], out[2], out[3], mess[ 1],  3);
  out[3] = round2_quickie(out[3], out[0], out[1], out[2], mess[ 5],  5);
  out[2] = round2_quickie(out[2], out[3], out[0], out[1], mess[ 9],  9);
  out[1] = round2_quickie(out[1], out[2], out[3], out[0], mess[13], 13);

  out[0] = round2_quickie(out[0], out[1], out[2], out[3], mess[ 2],  3);
  out[3] = round2_quickie(out[3], out[0], out[1], out[2], mess[ 6],  5);
  out[2] = round2_quickie(out[2], out[3], out[0], out[1], mess[10],  9);
  out[1] = round2_quickie(out[1], out[2], out[3], out[0], mess[14], 13);

  out[0] = round2_quickie(out[0], out[1], out[2], out[3], mess[ 3],  3);
  out[3] = round2_quickie(out[3], out[0], out[1], out[2], mess[ 7],  5);
  out[2] = round2_quickie(out[2], out[3], out[0], out[1], mess[11],  9);
  out[1] = round2_quickie(out[1], out[2], out[3], out[0], mess[15], 13);

  // ROUND 3
  out[0] = round3_quickie(out[0], out[1], out[2], out[3], mess[ 0],  3);
  out[3] = round3_quickie(out[3], out[0], out[1], out[2], mess[ 8],  9);
  out[2] = round3_quickie(out[2], out[3], out[0], out[1], mess[ 4], 11);
  out[1] = round3_quickie(out[1], out[2], out[3], out[0], mess[12], 15);

  out[0] = round3_quickie(out[0], out[1], out[2], out[3], mess[ 2],  3);
  out[3] = round3_quickie(out[3], out[0], out[1], out[2], mess[10],  9);
  out[2] = round3_quickie(out[2], out[3], out[0], out[1], mess [6], 11);
  out[1] = round3_quickie(out[1], out[2], out[3], out[0], mess[14], 15);

  out[0] = round3_quickie(out[0], out[1], out[2], out[3], mess[ 1],  3);
  out[3] = round3_quickie(out[3], out[0], out[1], out[2], mess[ 9],  9);
  out[2] = round3_quickie(out[2], out[3], out[0], out[1], mess[ 5], 11);
  out[1] = round3_quickie(out[1], out[2], out[3], out[0], mess[13], 15);

  out[0] = round3_quickie(out[0], out[1], out[2], out[3], mess[ 3],  3);
  out[3] = round3_quickie(out[3], out[0], out[1], out[2], mess[11],  9);
  out[2] = round3_quickie(out[2], out[3], out[0], out[1], mess[ 7], 11);
  out[1] = round3_quickie(out[1], out[2], out[3], out[0], mess[15], 15);

  out[0] += chv[0];
  out[1] += chv[1];
  out[2] += chv[2];
  out[3] += chv[3];

  return;
}
