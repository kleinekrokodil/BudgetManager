#pragma once
#include "date.h"
#include <vector>

class BudgetManager {
public:
    inline static const Date START_DATE{2000, 1, 1};
    inline static const Date END_DATE{2100, 1, 1};

    struct DailyBudget{
        double earned_;
    };

    BudgetManager()
    : budget_(START_DATE.ComputeDistance(START_DATE, END_DATE), DailyBudget()){
    }

    void ComputeIncome(const Date& first, const Date& last);
    void Earn(const Date& first, const Date& last, double income);
    void PayTax(const Date& first, const Date& last);


private:
    std::vector<DailyBudget> budget_;
};
