#include "unity.h"

#include "algorithms.h"

static const uint8_t MAX_ATTEMPTS = 10;

bool always_false()
{
	return false;
}

bool always_true()
{
	return true;
}

void setUp(void)
{
}

void tearDown(void)
{
}

void test_algorithms_RetryAllAttemptsOnFalse(void)
{
    TEST_ASSERT_EQUAL(MAX_ATTEMPTS, retry(&always_false, MAX_ATTEMPTS));
}

void test_algorithms_RetryNoAttemptsOnTrue(void)
{
    TEST_ASSERT_EQUAL(0, retry(&always_true, MAX_ATTEMPTS));
}

void test_algorithms_RetryFourTimes(void)
{
	bool retry_four_times() { static int i = 0; i++; if (i > 4) return true; else return false; }
	TEST_ASSERT_EQUAL(4, retry(&retry_four_times, MAX_ATTEMPTS));
}
