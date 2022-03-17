//
// Created by Valentin Kaelin on 17.03.22.
//
#include "Squadron.hpp"

using namespace std;

Squadron::Squadron(const string& name) : name(name), size(0), leader(nullptr), head(nullptr),
                                         tail(nullptr) {}

Squadron& Squadron::operator+=(const Ship& ship) {
   Member* member = new Member{ship, nullptr};

   if (head != nullptr) {
      tail->next = member;
      tail = tail->next;
   } else {
      head = member;
      tail = member;
   }

   size++;
   return *this;
}

void Squadron::setName(const string& name) {
   this->name = name;
}
