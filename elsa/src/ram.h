#ifndef __RAM_H
#define __RAM_H

#include <iostream>
#include "options.h"

class Ram : public Options {
  public:
    Ram(std::string name, double cost, int gb);
    virtual ~Ram();
    std::string to_string() const override;
    Ram(std::istream& ist);    // Open
    void save(std::ostream& ost) override;  // Save
    virtual Options* clone(); 
  protected:
    int _gb;
};

#endif 
