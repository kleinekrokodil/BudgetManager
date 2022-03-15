#pragma once
#include "date.h"

std::vector<std::string_view> SplitIntoWords(std::string_view str);

class Query{
public:
    explicit Query(std::string_view query)
    :query_(SplitIntoWords(query)){
        type_ = query_[0];
        from_ = Date::FromString(query_[1]);
        to_ = Date:: FromString(query_[2]);
        if(query_.size() == 4){
            modificator_ = std::stod({query_[3].data(), query_[3].size()});
        }
    }

    std::string GetType() const{
        return type_;
    }
    Date GetdateFrom() const{
        return from_;
    }
    Date GetDateTo() const{
        return to_;
    }
    double GetModificator() const{
        return modificator_;
    }


private:
    std::vector<std::string_view> query_;
    std::string type_;
    Date from_;
    Date to_;
    double modificator_;
};

