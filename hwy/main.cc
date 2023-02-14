#include <stdio.h>
#include <assert.h>
#include <sys/time.h>
#include "hwy/highway.h"

HWY_BEFORE_NAMESPACE();
#include "hwy/contrib/algo/find-inl.h"
namespace hwy {
  namespace HWY_NAMESPACE {
    uint32_t hwy_find(uint32_t target, uint32_t *ptr, uint32_t len) {
	    CappedTag<uint32_t, 8> vec;
        size_t ln = Lanes(vec); printf("vec lanes: %ld\n", ln);
        return Find(vec, target, ptr, len); 
    }
  }
}
HWY_AFTER_NAMESPACE();
using namespace hwy::HWY_NAMESPACE;

uint32_t dataLen = 1024 * 1024 * 256;
uint32_t * dataPtr;

inline uint64_t getusec()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return (uint64_t)(1000000*tv.tv_sec) + tv.tv_usec;
}

void init()
{
	dataPtr = (uint32_t *)aligned_alloc(16, sizeof(uint32_t) * dataLen);
	assert(dataPtr);
	for(uint32_t idx = 0; idx < dataLen; idx++) {
		dataPtr[idx] = idx;
	}
}

int main(int ac, char *av[])
{
    init();
    uint32_t pos = hwy_find(10, dataPtr, dataLen);
	printf("pos = %d\n", pos);
}
