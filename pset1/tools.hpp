// -*- mode:c++; tab-width:4 -*-
// modified September 2011; July 2022; September 2024; September 2025
// file: tools.hpp ---------------------------------------------------
// Header file for the tools library.
// -------------------------------------------------------------------
// Local definitions and portability code.
// Please enter your own name and class.
// -------------------------------------------------------------------
#pragma once
#define NAME "Michael Fischer"
#define CLASS "CPSC 4270/5270"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <cctype> // for isspace() and isdigit()
#include <cmath>
#include <cstdlib> // for rand() and srand()()
#include <ctime>
// #include <cstdio> // for NULL
// #include <cstring>
// #include <cstdarg>
using namespace std;
// -------------------------------------------------------------------
// Macros for debugging.
// -------------------------------------------------------------------
#define DUMPp(p) \
"\n" << " " #p " @ " << &p << " value = " << p \
<< " " #p " --> " << *p
#define DUMPv(k) "\n" << " " #k " @ " << &k << " value = " << k
// -------------------------------------------------------------------
// I/O Extension.
// -------------------------------------------------------------------
istream& cleanline(istream& is); // discards remainder of line
istream& flush(istream& is); // Use: cin >> x >> flush;
ostream& general(ostream& os); // Use: cout <<fixed <<x <<general<<y;
// -------------------------------------------------------------------
// Routine output labeling. ------------------------------------------
// -------------------------------------------------------------------
void fbanner(ostream& fout);
void banner();
void bye(void);
// -------------------------------------------------------------------
// Error handling ----------------------------------------------------
// -------------------------------------------------------------------
void fatal(const string& msg);
// -------------------------------------------------------------------
// time and date. ----------------------------------------------------
// -------------------------------------------------------------------
void when(string& date, string& hour);
string today();
string oclock();
// ---------------------------------------------------------------------
// Menu handling
// ---------------------------------------------------------------------
// Display a menu then read an alphabetic menu choice character.
char menu_c(string title, int n, const string menu[],
const string valid);
int menu(const char* title, int n, const string menu[]);