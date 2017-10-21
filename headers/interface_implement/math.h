//exploration of header files and how they work
/**
 *  -   exercise: set up interface and implement a simple library
 *  -   declare all the possible functions here 
 *  -   also covers functions/protoypes/overloading
*/
//--------------------------------------------------------------

//--------------------------------------------------------------
//these makes sure header is not included more than one
/**
 *  -   #pragma once - prevent source being copied more than once
 *  -   #ifndef #endif (include guard)
 *      -   checks the definition of tokens earlier in the file
 *      -   if value !defined -> it defines the value
 *      -   else it fails -> creates blank file
 * 
 *  -   pragma once is compiler compatible
 *  -   include gaurds may also be used
 * 
*/

// #pragma once

// use the include gaurds as demonstration
#ifndef MATH_H
#define MATH_H

//
#include <iostream>
#include <cstdio>

//the interface for our math header file

//two functions with overloaded params 
/**
 *  -   one sums two numbers the other will sum an array
*/
int sum(int a, int b);
int sum(int *arr, int length);

#endif
//--------------------------------------------------------------