#include "catch.hpp"
#include "Fortuity.hpp"

#include <set>


TEST_CASE("getRandom(int,int) scope checking", "[Fortuity], [RandomNumbers]") {

    GIVEN("std::set<int>Container for storing results") {
        std::set<int> results;

        // --------------------------------------------------------------------
        WHEN("ScopeValues are Positive and Ordered") {
            const int first = 0;
            const int last = 16;
            const int quantity = 256;

            REQUIRE(first < last);
            REQUIRE(quantity >= 256);
            REQUIRE(results.empty() == true);

            for (size_t i = 0; i < quantity; ++i) {
                results.insert(Fortuity::getRandom(first, last));
            }

            THEN("Each ResultValue is within the ScopeValues") {
                for (const auto& value : results) {
                    REQUIRE(value >= first);
                    REQUIRE(value <= last);
                }
            }
            THEN("Every possible value occur") {
                for (int i = first; i <= last; ++i) {
                    CHECK(results.find(i) != results.end());
                }
            }
        }

        // --------------------------------------------------------------------
        WHEN("ScopeValues are Positive and Unordered") {
            const int first = 0;
            const int last = 16;
            const int quantity = 256;

            REQUIRE(first < last);
            REQUIRE(quantity >= 256);
            REQUIRE(results.empty() == true);

            for (size_t i = 0; i < quantity; ++i) {
                results.insert(Fortuity::getRandom(last, first));
            }

            THEN("Each ResultValue is within the ScopeValues") {
                for (const auto& value : results) {
                    REQUIRE(value >= first);
                    REQUIRE(value <= last);
                }
            }
            THEN("Every possible value occur") {
                for (int i = first; i <= last; ++i) {
                    CHECK(results.find(i) != results.end());
                }
            }
        }

        // --------------------------------------------------------------------
        WHEN("ScopeValues are Ordered") {
            const int first = -16;
            const int last = 16;
            const int quantity = 512;

            REQUIRE(first < last);
            REQUIRE(quantity >= 512);
            REQUIRE(results.empty() == true);

            for (size_t i = 0; i < quantity; ++i) {
                results.insert(Fortuity::getRandom(first, last));
            }

            THEN("Each ResultValue is within the ScopeValues") {
                for (const auto& value : results) {
                    REQUIRE(value >= first);
                    REQUIRE(value <= last);
                }
            }
            THEN("Every possible value occur") {
                for (int i = first; i <= last; ++i) {
                    CHECK(results.find(i) != results.end());
                }
            }
        }

        // --------------------------------------------------------------------
        WHEN("ScopeValues are Unordered") {
            const int first = -16;
            const int last = 16;
            const int quantity = 512;

            REQUIRE(first < last);
            REQUIRE(quantity >= 512);
            REQUIRE(results.empty() == true);

            for (size_t i = 0; i < quantity; ++i) {
                results.insert(Fortuity::getRandom(last, first));
            }

            THEN("Each ResultValue is within the ScopeValues") {
                for (const auto& value : results) {
                    REQUIRE(value >= first);
                    REQUIRE(value <= last);
                }
            }
            THEN("Every possible value occur") {
                for (int i = first; i <= last; ++i) {
                    CHECK(results.find(i) != results.end());
                }
            }
        }

        // --------------------------------------------------------------------
        WHEN("ScopeValues are Negative and Ordered") {
            const int first = -1024;
            const int last = -1008;
            const int quantity = 256;

            REQUIRE(first < last);
            REQUIRE(quantity >= 256);
            REQUIRE(results.empty() == true);

            for (size_t i = 0; i < quantity; ++i) {
                results.insert(Fortuity::getRandom(first, last));
            }

            THEN("Each ResultValue is within the ScopeValues") {
                for (const auto& value : results) {
                    REQUIRE(value >= first);
                    REQUIRE(value <= last);
                }
            }
            THEN("Every possible value occur") {
                for (int i = first; i <= last; ++i) {
                    CHECK(results.find(i) != results.end());
                }
            }
        }

        // --------------------------------------------------------------------
        WHEN("ScopeValues are Negative and Unordered") {
            const int first = -1024;
            const int last = -1008;
            const int quantity = 256;

            REQUIRE(first < last);
            REQUIRE(quantity >= 256);
            REQUIRE(results.empty() == true);

            for (size_t i = 0; i < quantity; ++i) {
                results.insert(Fortuity::getRandom(last, first));
            }

            THEN("Each ResultValue is within the ScopeValues") {
                for (const auto& value : results) {
                    REQUIRE(value >= first);
                    REQUIRE(value <= last);
                }
            }
            THEN("Every possible value occur") {
                for (int i = first; i <= last; ++i) {
                    CHECK(results.find(i) != results.end());
                }
            }
        }

        // --------------------------------------------------------------------
        WHEN("ScopeValues are Equal Zero") {
            const int scopeValue = 0;
            const int quantity = 32;

            REQUIRE(quantity >= 32);
            REQUIRE(results.empty() == true);

            for (size_t i = 0; i < quantity; ++i) {
                results.insert(Fortuity::getRandom(scopeValue, scopeValue));
            }

            THEN("Each ResultValue is within the ScopeValues") {
                for (const auto& value : results) {
                    REQUIRE(value >= scopeValue);
                    REQUIRE(value <= scopeValue);
                }
            }

            THEN("Every possible value occur") {
                REQUIRE(results.find(scopeValue) != results.end());  
            }
        }

        // --------------------------------------------------------------------
        WHEN("ScopeValues are Equal MinusOne") {
            const int scopeValue = -1;
            const int quantity = 32;

            REQUIRE(quantity >= 32);
            REQUIRE(results.empty() == true);

            for (size_t i = 0; i < quantity; ++i) {
                results.insert(Fortuity::getRandom(scopeValue, scopeValue));
            }

            THEN("Each ResultValue is within the ScopeValues") {
                for (const auto& value : results) {
                    REQUIRE(value >= scopeValue);
                    REQUIRE(value <= scopeValue);
                }
            }

            THEN("Every possible value occur") {                
                REQUIRE(results.find(scopeValue) != results.end());                
            }
        }

        // --------------------------------------------------------------------
        WHEN("ScopeValues are Equal NegativeValue") {
            const int scopeValue = -2048;
            const int quantity = 32;

            REQUIRE(quantity >= 32);
            REQUIRE(results.empty() == true);

            for (size_t i = 0; i < quantity; ++i) {
                results.insert(Fortuity::getRandom(scopeValue, scopeValue));
            }

            THEN("Each ResultValue is within the ScopeValues") {
                for (const auto& value : results) {
                    REQUIRE(value >= scopeValue);
                    REQUIRE(value <= scopeValue);
                }
            }

            THEN("Every possible value occur") {                
                REQUIRE(results.find(scopeValue) != results.end());                
            }
        }

        // --------------------------------------------------------------------
        WHEN("ScopeValues are Equal PositiveValue") {
            const int scopeValue = 2048;
            const int quantity = 32;

            REQUIRE(quantity >= 32);
            REQUIRE(results.empty() == true);

            for (size_t i = 0; i < quantity; ++i) {
                results.insert(Fortuity::getRandom(scopeValue, scopeValue));
            }

            THEN("Each ResultValue is within the ScopeValues") {
                for (const auto& value : results) {
                    REQUIRE(value >= scopeValue);
                    REQUIRE(value <= scopeValue);
                }
            }

            THEN("Every possible value occur") {                
                REQUIRE(results.find(scopeValue) != results.end());                
            }
        }
    }
}