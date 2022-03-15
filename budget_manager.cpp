#include "budget_manager.h"
#include <iostream>

void BudgetManager::ComputeIncome(const Date& first, const Date& last) {
    int dist_from_start_first = first.ComputeDistance(START_DATE, first);
    int dist_from_start_last = last.ComputeDistance(START_DATE, last);
    double income = 0.0;
    for(int i = dist_from_start_first; i <= dist_from_start_last; ++i){
        income += budget_[i].earned_;
    }
    std::cout << income << std::endl;
}

void BudgetManager::Earn(const Date& first, const Date& last, double income) {
    int dist_from_start_first = first.ComputeDistance(START_DATE, first);
    int dist_from_start_last = last.ComputeDistance(START_DATE, last);
    int period_length = first.ComputeDistance(first, last) + 1;
    for(int i = dist_from_start_first; i <= dist_from_start_last; ++i){
        budget_[i].earned_ += income / period_length;
    }
}

void BudgetManager::PayTax(const Date& first, const Date& last) {
    int dist_from_start_first = first.ComputeDistance(START_DATE, first);
    int dist_from_start_last = last.ComputeDistance(START_DATE, last);
    for(int i = dist_from_start_first; i <= dist_from_start_last; ++i){
        budget_[i].earned_ *= 0.87;
    }
}

