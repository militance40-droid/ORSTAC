//+------------------------------------------------------------------+
//|                                              Sample DLL for MQL4 |
//|                             Copyright 2000-2021, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
//---
#define MT4_EXPFUNC __declspec(dllexport)
//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
#pragma pack(push,1)
struct RateInfo
  {
   __int64           ctm;
   double            open;
   double            low;
   double            high;
   double            close;
   unsigned __int64  vol_tick;
   int               spread;
   unsigned __int64  vol_real;
  };
#pragma pack(pop)
//---
struct MqlStr
  {
   int               len;
   char             *string;
  };
static int CompareMqlStr(const void *left,const void *right);
//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
/**
 * @brief Entry point for the DLL.
 *
 * This function is called by the system when the DLL is loaded or unloaded.
 *
 * @param hModule Handle to the DLL module.
 * @param ul_reason_for_call Reason for calling the function (e.g., DLL_PROCESS_ATTACH).
 * @param lpReserved Reserved for future use.
 * @return TRUE if successful, FALSE otherwise.
 */
BOOL APIENTRY DllMain(HANDLE hModule,DWORD ul_reason_for_call,LPVOID lpReserved)
  {
//---
   switch(ul_reason_for_call)
     {
      case DLL_PROCESS_ATTACH:
      case DLL_THREAD_ATTACH:
      case DLL_THREAD_DETACH:
      case DLL_PROCESS_DETACH:
         break;
     }
//---
   return(TRUE);
  }
//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
/**
 * @brief Example function returning an integer.
 *
 * Prints the input integer to the standard output and returns it.
 *
 * @param ipar The integer input value.
 * @return The same integer value.
 */
MT4_EXPFUNC int __stdcall GetIntValue(const int ipar)
  {
   printf("GetIntValue takes %d\n",ipar);
   return(ipar);
  }
//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
/**
 * @brief Example function returning a double.
 *
 * Prints the input double to the standard output and returns it.
 *
 * @param dpar The double input value.
 * @return The same double value.
 */
MT4_EXPFUNC double __stdcall GetDoubleValue(const double dpar)
  {
   printf("GetDoubleValue takes %.8lf\n",dpar);
   return(dpar);
  }
//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
/**
 * @brief Example function returning a string.
 *
 * Prints the input string to the standard output and returns it.
 *
 * @param spar The string input value.
 * @return The same string pointer.
 */
MT4_EXPFUNC wchar_t* __stdcall GetStringValue(wchar_t *spar)
  {
   wprintf(L"GetStringValue takes \"%s\"\n",spar);
   return(spar);
  }
//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
/**
 * @brief Retrieves a value from a double array.
 *
 * @param arr Pointer to the double array.
 * @param arraysize The size of the array.
 * @param nitem The index of the item to retrieve.
 * @return The value at the specified index, or 0.0 if invalid.
 */
MT4_EXPFUNC double __stdcall GetArrayItemValue(const double *arr,const int arraysize,const int nitem)
  {
//---
   if(arr==NULL)
     {
      printf("GetArrayItemValue: NULL array\n");
      return(0.0);
     }
   if(arraysize<=0)
     {
      printf("GetArrayItemValue: wrong arraysize (%d)\n", arraysize);
      return(0.0);
     }
   if(nitem<0 || nitem>=arraysize)
     {
      printf("GetArrayItemValue: wrong item number (%d)\n", nitem);
      return(0.0);
     }
//---
   return(arr[nitem]);
  }
//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
/**
 * @brief Sets a value in a double array.
 *
 * @param arr Pointer to the double array.
 * @param arraysize The size of the array.
 * @param nitem The index of the item to set.
 * @param value The value to assign.
 * @return True if successful, False if parameters are invalid.
 */
MT4_EXPFUNC bool _stdcall SetArrayItemValue(double *arr,const int arraysize,const int nitem,const double value)
  {
//---
   if(arr==NULL)
     {
      printf("GetArrayItemValue: NULL array\n");
      return(FALSE);
     }
   if(arraysize<=0)
     {
      printf("GetArrayItemValue: wrong arraysize (%d)\n", arraysize);
      return(FALSE);
     }
   if(nitem<0 || nitem>=arraysize)
     {
      printf("GetArrayItemValue: wrong item number (%d)\n", nitem);
      return(FALSE);
     }
//---
   arr[nitem]=value;
   return(TRUE);
  }
//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
/**
 * @brief Retrieves a specific field value from a RateInfo array item.
 *
 * @param rates Pointer to the RateInfo array.
 * @param rates_total The total number of rates in the array.
 * @param shift The shift index (reverse index from the end).
 * @param nrate The field identifier (0: time, 1: open, 2: low, 3: high, 4: close, 5: tick volume).
 * @return The value of the requested field as a double, or 0.0 if invalid.
 */
MT4_EXPFUNC double __stdcall GetRatesItemValue(const RateInfo* rates,const int rates_total,const int shift,const int nrate)
  {
//---
   if(rates==NULL)
     {
      printf("GetRatesItemValue: NULL array\n");
      return(0.0);
     }
//---
   if(rates_total<0)
     {
      printf("GetRatesItemValue: wrong rates_total number (%d)\n", rates_total);
      return(0.0);
     }
//---
   if(shift<0 || shift>=rates_total)
     {
      printf("GetRatesItemValue: wrong shift number (%d)\n", shift);
      return(0.0);
     }
//---
   if(nrate<0 || nrate>5)
     {
      printf("GetRatesItemValue: wrong rate index (%d)\n", nrate);
      return(0.0);
     }
//---
   int nitem=rates_total-1-shift;
   switch(nrate)
     {
      case 0: return double(rates[nitem].ctm);
      case 1: return rates[nitem].open;
      case 2: return rates[nitem].low;
      case 3: return rates[nitem].high;
      case 4: return rates[nitem].close;
      case 5: return double(rates[nitem].vol_tick);
     }
//---
   return(0.0);
  }
//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
/**
 * @brief Sorts an array of MqlStr structures.
 *
 * Uses qsort to sort the array based on the string content.
 *
 * @param arr Pointer to the MqlStr array.
 * @param arraysize The size of the array.
 * @return The size of the array if successful, or -1 on failure.
 */
MT4_EXPFUNC int __stdcall SortStringArray(MqlStr *arr,const int arraysize)
  {
//---
   if(arr==NULL)
     {
      printf("SortStringArray: NULL array\n");
      return(-1);
     }
   if(arraysize<=0)
     {
      printf("SortStringArray: wrong arraysize (%d)\n", arraysize);
      return(-1);
     }
//---
   qsort(arr,arraysize,sizeof(MqlStr),CompareMqlStr);
//---
   return(arraysize);
  }
//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
/**
 * @brief Concatenates adjacent strings in an MqlStr array.
 *
 * Iterates through the array and appends the string of the next element to the current element,
 * provided there is enough allocated memory.
 *
 * @param arr Pointer to the MqlStr array.
 * @param arraysize The size of the array.
 * @return The size of the array if successful, or -1 on failure.
 */
MT4_EXPFUNC int __stdcall ProcessStringArray(MqlStr *arr,const int arraysize)
  {
   int   len1,len2;
//---
   if(arr==NULL)
     {
      printf("ProcessStringArray: NULL array\n");
      return(-1);
     }
   if(arraysize<=0)
     {
      printf("ProcessStringArray: wrong arraysize (%d)\n", arraysize);
      return(-1);
     }
//---
   for(int i=0; i<arraysize-1; i++)
     {
      if(arr[i].string==NULL)
         len1=0;
      else
         len1=strlen(arr[i].string);

      if(arr[i+1].string==NULL)
         len2=0;
      else
         len2=strlen(arr[i+1].string);
      //--- uninitialized string
      if(arr[i+1].string==NULL)
         continue;
      //--- destination string is uninitialized and cannot be allocated within dll
      if(arr[i].string==NULL)
         continue;
      //--- memory piece is less than needed and cannot be reallocated within dll
      if(arr[i].len<len1+len2)
         continue;
      //--- final processing
      strcat(arr[i].string,arr[i+1].string);
     }
//---
   return(arraysize);
  }
//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
/**
 * @brief Comparison function for MqlStr structures.
 *
 * Used by qsort to compare two MqlStr objects based on their string content.
 *
 * @param left Pointer to the first MqlStr object.
 * @param right Pointer to the second MqlStr object.
 * @return An integer less than, equal to, or greater than zero if the first argument is considered to be respectively less than, equal to, or greater than the second.
 */
int CompareMqlStr(const void *left,const void *right)
  {
   MqlStr *leftstr=(MqlStr *)left;
   MqlStr *rightstr=(MqlStr *)right;
//---
   if(leftstr->string==NULL) 
      return(-1);
   if(rightstr->string==NULL) 
      return(1);
//---
   return(strcmp(leftstr->string,rightstr->string));
  }
//+------------------------------------------------------------------+
