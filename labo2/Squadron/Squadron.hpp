//
// Created by Valentin Kaelin on 17.03.22.
//

#ifndef SQUADRON_SQUADRON_HPP
#define SQUADRON_SQUADRON_HPP

#include "Ship.hpp"

class Squadron {
   friend std::ostream& operator<<(std::ostream& lhs, const Squadron& rhs);

   friend Squadron operator+(const Ship& ship);

   friend Squadron operator-(const Ship& ship);

public:
   Squadron(const std::string& name);

   Squadron(const Squadron& squad);

   Squadron& operator+=(const Ship& ship);

   Squadron& operator-=(const Ship& ship);

   Ship& operator[](unsigned index);

   void setName(const std::string& name);

   void setLeader(const Ship& ship);

   void removeLeader();

   unsigned computeConsumption(double distance, double speed);

private:
   struct Member {
      Ship& ship;
      Member* next;
   };

   std::string name;
   size_t size;
   Member* leader;
   Member* head;
};

#endif //SQUADRON_SQUADRON_HPP
