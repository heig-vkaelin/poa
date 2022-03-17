//
// Created by Valentin Kaelin on 17.03.22.
//
#include "Squadron.hpp"

using namespace std;

Squadron::Squadron(const string& name) : name(name), size(0), leader(nullptr), first(nullptr),
                                         last(nullptr) {}

Squadron& Squadron::operator+=(const Ship& ship) {
   Member* member = new Member{ship, nullptr};

   if (first != nullptr) {
      last->next = member;
      last = last->next;
   } else {
      first = member;
      last = member;
   }

   size++;
   return *this;
}

void Squadron::setName(const string& name) {
   this->name = name;
}

// TODO : A tester lorsque operator== sera implémenté
void Squadron::setLeader(const Ship& ship) {
//   if (leader && leader->ship == ship)
//      return;

   Member* iter = first;
   while (iter) {
//      if (iter->ship == ship) {
//         leader = iter;
//         return;
//      }
      iter = iter->next;
   }

   *this += ship;
   leader = last;
}
