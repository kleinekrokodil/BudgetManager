#include "budget_manager.h"
#include <iostream>

std::pair<int, int> BudgetManager::ComputeDateIterators(const Date& first, const Date& last){
    int dist_from_start_first = first.ComputeDistance(START_DATE, first);
    int dist_from_start_last = last.ComputeDistance(START_DATE, last);
    return {dist_from_start_first, dist_from_start_last};
}

void BudgetManager::ComputeIncome(const Date& first, const Date& last) {
    auto period = ComputeDateIterators(first, last);
    double income = 0.0;
    for(int i = period.first; i <= period.second; ++i){
        income += budget_[i].earned_;
        income -= budget_[i].spent_;
    }
    std::cout << income << std::endl;
}

void BudgetManager::Earn(const Date& first, const Date& last, double income) {
    auto period = ComputeDateIterators(first, last);
    int period_length = first.ComputeDistance(first, last) + 1;
    for(int i = period.first; i <= period.second; ++i){
        budget_[i].earned_ += income / period_length;
    }
}

void BudgetManager::PayTax(const Date& first, const Date& last, int tax) {
    auto period = ComputeDateIterators(first, last);
    double on_hand = 1.0 - (tax / 100.0);
    for(int i = period.first; i <= period.second; ++i){
        budget_[i].earned_ *= on_hand;
    }
}

void BudgetManager::Spend(const Date &first, const Date &last, double spent) {
    auto period = ComputeDateIterators(first, last);
    int period_length = first.ComputeDistance(first, last) + 1;
    for(int i = period.first; i <= period.second; ++i){
        budget_[i].spent_ += spent / period_length;
    }
}

