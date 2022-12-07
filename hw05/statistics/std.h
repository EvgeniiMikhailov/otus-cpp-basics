#pragma once

#include <cmath>
#include <limits>
#include <vector>

#include "isstatistics.h"

class Std : public IStatistics {
public:
    void update(double next) override {
        m_nums.push_back(next);
        m_sum += next;
        double mean = m_sum / m_nums.size();
        double subtraction_pow = 0.;
        for (double num : m_nums) {
            subtraction_pow += std::pow(num - mean, 2);
        }
        variance = subtraction_pow / m_nums.size();
    }

    double eval() const override {
        return std::sqrt(variance);
    }

    const char * name() const override {
        return "std";
    }

private:
    double m_sum = 0.0;
    std::vector<double> m_nums;
    double variance = 0.0;
};
