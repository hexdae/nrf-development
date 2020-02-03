#include "unity.h"

#include "algorithms.h"


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
	static const uint8_t NUM_ATTEMPTS = 10;
    TEST_ASSERT_EQUAL(NUM_ATTEMPTS, retry(&always_false, NUM_ATTEMPTS));
}

void test_algorithms_RetryNoAttemptsOnTrue(void)
{
	static const uint8_t NUM_ATTEMPTS = 10;
    TEST_ASSERT_EQUAL(0, retry(&always_true, NUM_ATTEMPTS));
}