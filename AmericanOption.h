#pragma once
#include "Option.h"
class AmericanOption :
    public Option
{
public:
    bool isAmericanOption() override;
};

