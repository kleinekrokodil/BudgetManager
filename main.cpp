#include "budget_manager.h"
#include "parser.h"
#include <iostream>
#include <string_view>

using namespace std;

void ParseAndProcessQuery(BudgetManager& manager, string_view line) {
    Query query(line);
    if(query.GetType() == "ComputeIncome"sv){
        manager.ComputeIncome(query.GetdateFrom(), query.GetDateTo());
    }
    if(query.GetType() == "Earn"sv){
        manager.Earn(query.GetdateFrom(), query.GetDateTo(), query.GetModificator());
    }
    if(query.GetType() == "PayTax"sv){
        manager.PayTax(query.GetdateFrom(), query.GetDateTo(), static_cast<int>(query.GetModificator()));
    }
    if(query.GetType() == "Spend"sv){
        manager.Spend(query.GetdateFrom(), query.GetDateTo(), query.GetModificator());
    }
}

int ReadNumberOnLine(istream& input) {
    std::string line;
    std::getline(input, line);
    return std::stoi(line);
}

int main() {
    BudgetManager manager;

    const int query_count = ReadNumberOnLine(cin);

    for (int i = 0; i < query_count; ++i) {
        std::string line;
        std::getline(cin, line);
        ParseAndProcessQuery(manager, line);
    }
}
