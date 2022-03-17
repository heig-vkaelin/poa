//
// Created by Valentin Kaelin on 17.03.22.
//
#include "Squadron.hpp"

using namespace std;

Squadron::Squadron(const string& name) : name(name), size(0), leader(nullptr), head(nullptr),
														next(nullptr) {}
